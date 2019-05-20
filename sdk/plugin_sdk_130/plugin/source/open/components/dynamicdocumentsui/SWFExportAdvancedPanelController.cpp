//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFExportAdvancedPanelController.cpp $
//  
//  Owner: DBerggren
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"
#include "SWFExportAdvancedPanelController.h"

// ----- Interface files -----

#include "IActiveContext.h"
#include "IDropDownListController.h"
#include "IEventWatcher.h"
#include "IFlashSWFExportFacade.h"
#include "IPageRange.h"
#include "IPanelControlData.h"
#include "ISelectableDialogSwitcher.h"
#include "ISWFExportPreferences.h"
#include "IWidgetParent.h"
#include "IWorkspace.h"

// ----- Include files -----

// ----- Utility files -----

#include "DynamicDocumentsUIUtils.h"
#include "Utils.h"

// ----- ID files -----

#include "DynamicDocumentsUIID.h"

CREATE_PMINTERFACE(SWFExportAdvancedPanelController, kSWFExportAdvancedPanelControllerImpl)

SWFExportAdvancedPanelController::SWFExportAdvancedPanelController(IPMUnknown *boss) :
	Inherited(boss)
{
}

SWFExportAdvancedPanelController::~SWFExportAdvancedPanelController()
{
}

//--------------------------------------------------------------------------------------------------------------------
// InitializeDialogFields
//--------------------------------------------------------------------------------------------------------------------
void SWFExportAdvancedPanelController::InitializeDialogFields(IActiveContext* ac)
{
 	Inherited::InitializeDialogFields(ac);

	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

	// get the dialog preferences
	InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
	InterfacePtr<IPageRange> iPageRange((IPageRange*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPAGERANGE));

	// set frame rate
	InitializeFrameRate(iData);

	// set export text
	InitializeExportText(iData);

	// Check rasterize pages
	if ( iData->GetRasterizePages() && 
		(iPageRange->GetPageRangeFormat() == IPageRange::kBySelection || 
		iData->GetDynamicMediaHandling() == flash_export::kIncludeAll ||
		iData->GetHasTransparentBackground()) )
		iData->SetRasterizePages(kFalse);

	// Check flatten XP
	if ( iData->GetTransparencyHandling() == flash_export::kFlattenTransparency &&
		(iData->GetHasTransparentBackground() || 
		 iData->GetDynamicMediaHandling() == flash_export::kIncludeAll ||
		 iData->GetRasterizePages()) )
		iData->SetTransparencyHandling(flash_export::kIgnoreTransparency);

	// set flatten XP
	SetTriStateControlData(kFlattenXPCheckboxWID, iData->GetTransparencyHandling() == flash_export::kFlattenTransparency ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected);
	ddui_utils::SetWidgetState(iPanelData, kFlattenXPCheckboxWID, !iData->GetRasterizePages());

	// set the warning icon
	IControlView *iControlView = iPanelData->FindWidget (kFlattenWarningIconWidgetId);
	iControlView->ShowView(iData->GetTransparencyHandling() == flash_export::kFlattenTransparency);

	// set rasterize pages
	SetTriStateControlData(kRastorizeCheckboxWID, iData->GetRasterizePages() ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected);
	ddui_utils::SetWidgetState(iPanelData, kRastorizeCheckboxWID, iPageRange->GetPageRangeFormat() != IPageRange::kBySelection);

	// set the warning icon
	iControlView = iPanelData->FindWidget (kRastorizeWarningIconWidgetId);
	iControlView->ShowView(iData->GetRasterizePages());

	// set image handling
	InitializeImageHandling(iData);

	// ** Event watcher **
	InterfacePtr<IEventWatcher> eventWatcher(this, UseDefaultIID());
	eventWatcher->StartWatching();
}

//--------------------------------------------------------------------------------------------------------------------
// ResetDialogFields
//--------------------------------------------------------------------------------------------------------------------
void SWFExportAdvancedPanelController::ResetDialogFields(IActiveContext* ac)
{
	// initialize the dialog prefs from the application prefs
	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
	InterfacePtr<IWorkspace> ws(GetExecutionContextSession()->QueryWorkspace());
	InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
	InterfacePtr<IPageRange> iPageRange((IPageRange*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPAGERANGE));
	
	// copy the workspace prefs to the dialog prefs
	Utils<Facade::IFlashSWF_ExportFacade>()->GetWorkspacePreferences(ws, iData);

	// copy the workspace Page Range info to the dialog
	PMString pageRange;
	IPageRange::RangeFormat pageRangeFormat(IPageRange::kAllPages);
	Utils<Facade::IFlashSWF_ExportFacade>()->GetPageRangeInfo(ws, pageRange, pageRangeFormat);
	iPageRange->SetPageRange(pageRange);
	iPageRange->SetPageRangeFormat(pageRangeFormat);

	// this will cause InitializeDialogFields to be called
	Inherited::ResetDialogFields(ac);
}

//--------------------------------------------------------------------------------------------------------------------
// ClosingDialog
//--------------------------------------------------------------------------------------------------------------------
void SWFExportAdvancedPanelController::ClosingDialog(IActiveContext* lastChanceToUseMyContext)
{
	// ** Event watcher **
	InterfacePtr<IEventWatcher> eventWatcher(this, UseDefaultIID());
	eventWatcher->StopWatching();
}

//--------------------------------------------------------------------------------------------------------------------
// InitializeFrameRate
//--------------------------------------------------------------------------------------------------------------------
void SWFExportAdvancedPanelController::InitializeFrameRate(ISWFExportPreferences* iData) const
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IControlView* iControlView = iPanelData->FindWidget (kFramesPerSecEditWidgetID);
	InterfacePtr<ITextValue> textValue(iControlView, UseDefaultIID());
	textValue->SetTextFromValue(iData->GetFrameRate(), kTrue, kFalse);
}

//--------------------------------------------------------------------------------------------------------------------
// InitializeExportText
//--------------------------------------------------------------------------------------------------------------------
void SWFExportAdvancedPanelController::InitializeExportText(ISWFExportPreferences* iData) const
{
	// set text selection popup
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IControlView* iControlView = iPanelData->FindWidget (kTextPopupWID);
	InterfacePtr<IDropDownListController> iListController(iControlView, UseDefaultIID ());

	// if rasterize pages is on, set to raster
	if (iData->GetRasterizePages())
		iListController->Select (kRasterTextIndex, kTrue, kFalse);
	else if (iData->GetTextExportPolicy() == flash_export::kLiveText)
		iListController->Select (kFlashTextIndex, kTrue, kFalse);
	else if (iData->GetTextExportPolicy() == flash_export::kVectorizeText)
		iListController->Select (kVectorTextIndex, kTrue, kFalse);
	else // if (iData->GetTextExportPolicy() == flash_export::kRasterizeText)
		iListController->Select (kRasterTextIndex, kTrue, kFalse);

	// disable control if rasterize pages is turned on
	ddui_utils::SetWidgetState(iPanelData, kTextPopupWID, iData->GetRasterizePages() == kFalse);
}

//--------------------------------------------------------------------------------------------------------------------
// InitializeImageHandling
//--------------------------------------------------------------------------------------------------------------------
void SWFExportAdvancedPanelController::InitializeImageHandling(ISWFExportPreferences* iData) const
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

	// set image compression popup
	IControlView* iControlView = iPanelData->FindWidget (kCompressionPopupWID);
	InterfacePtr<IDropDownListController> iListController(iControlView, UseDefaultIID ());
	if (iData->GetRasterCompression() == flash_export::kJPEGCompression)
		iListController->Select (kJPGIndex, kTrue, kFalse);
	else if (iData->GetRasterCompression() == flash_export::kLosslessCompression)
		iListController->Select (kPNGIndex, kTrue, kFalse);
	else // if (iData->GetRasterCompression() == flash_export::kAutomaticCompression)
		iListController->Select (kAutoIndex, kTrue, kFalse);

	// set quality popup
	iControlView = iPanelData->FindWidget (kJPEGQualityPopupWID);
	iListController = InterfacePtr<IDropDownListController>(iControlView, UseDefaultIID ());
	if (iData->GetJPEGQuality() == flash_export::kJPEGQuality_Minimum)
		iListController->Select (kMinQualityIndex, kTrue, kFalse);
	else if (iData->GetJPEGQuality() == flash_export::kJPEGQuality_Low)
		iListController->Select (kLowQualityIndex, kTrue, kFalse);
	else if (iData->GetJPEGQuality() == flash_export::kJPEGQuality_Medium)
		iListController->Select (kMedQualityIndex, kTrue, kFalse);
	else if (iData->GetJPEGQuality() == flash_export::kJPEGQuality_High)
		iListController->Select (kHighQualityIndex, kTrue, kFalse);
	else // if (iData->GetJPEGQuality() == flash_export::kJPEGQuality_Maximum)
		iListController->Select (kMaxQualityIndex, kTrue, kFalse);

	// disable quality popup if Lossless (PNG) selected
	ddui_utils::SetWidgetState(iPanelData, kJPEGQualityPopupWID, iData->GetRasterCompression() != flash_export::kLosslessCompression);

	// set Resolution Combo
	iControlView = iPanelData->FindWidget (kResolutionComboWID);
    InterfacePtr<ITextValue> textValue(iControlView, UseDefaultIID());
    textValue->SetTextFromValue(iData->GetRasterResolution(), kTrue, kFalse);
}
