//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFExportGeneralPanelController.cpp $
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
#include "SWFExportGeneralPanelController.h"

// ----- Interface files -----

#include "IActiveContext.h"
#include "IBoolData.h"
#include "IDropDownListController.h"
#include "IFlashSWFExportFacade.h"
#include "IPageRange.h"
#include "IPageTransitionFacade.h"
#include "IPanelControlData.h"
#include "ISelectableDialogSwitcher.h"
#include "IStringListControlData.h"
#include "ISWFExportPreferences.h"
#include "ITextControlData.h"
#include "IUIDListData.h"
#include "IWidgetParent.h"
#include "IWorkspace.h"

// ----- Include files -----

#include "CAlert.h"

// ----- Utility files -----

#include "DynamicDocumentsUIUtils.h"
#include "IEVEUtils.h"
#include "Utils.h"

// ----- ID files -----

#include "DynamicDocumentsUIID.h"

CREATE_PMINTERFACE(SWFExportGeneralPanelController, kSWFExportGeneralPanelControllerImpl)

//====================================================================================================================
// SWFExportGeneralPanelController
//====================================================================================================================
SWFExportGeneralPanelController::SWFExportGeneralPanelController(IPMUnknown *boss) :
	Inherited(boss)
{
}

SWFExportGeneralPanelController::~SWFExportGeneralPanelController()
{
}

//--------------------------------------------------------------------------------------------------------------------
// InitializeDialogFields
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelController::InitializeDialogFields( IActiveContext* ac)
{
 	Inherited::InitializeDialogFields(ac);

	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

	// get the dialog preferences
	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
	InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
	InterfacePtr<IPageRange> iPageRange((IPageRange*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPAGERANGE));

	// set page range
	InitializePageRange(ac, iPageRange);

	// set generate html
	SetTriStateControlData(kGenHTMLCheckboxWID, iData->GetGenerateHTML() ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected);

	// set view after export
	SetTriStateControlData(kViewSWFAfterExportingCheckboxWID, iData->GetViewAfterExport() ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected);
	ddui_utils::SetWidgetState(iPanelData, kViewSWFAfterExportingCheckboxWID, iData->GetGenerateHTML());

	// set size/scale
	InitializeScale(iData, iPageRange);

	// set background
	if (iData->GetHasTransparentBackground())
		SetTriStateControlData(kTransparent_RadioButtonWidgetID, ITriStateControlData::kSelected);
	else
		SetTriStateControlData(kPaperColor_RadioButtonWidgetID,  ITriStateControlData::kSelected);

	// set dynamic media
	if (iData->GetDynamicMediaHandling() == flash_export::kIncludeAll)
		SetTriStateControlData(kIncludeAll_RadioButtonWidgetID, ITriStateControlData::kSelected);
	else
		SetTriStateControlData(kAppearanceOnly_RadioButtonWidgetID, ITriStateControlData::kSelected);

	// set page transitions
	InitializePageTransitions(iData, iPageRange);

	// set apply page curl checkbox
	ISWFExportPreferences::BookControlSettings bookControlSettings;
	iData->GetBookControlSettings(bookControlSettings);
	SetTriStateControlData(kPageCurlWidgetID, bookControlSettings.fUseBookControl ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected);
	bool bEnable = (iPageRange->GetPageRangeFormat() != IPageRange::kBySelection) &&
					(iData->GetHasTransparentBackground() == kFalse);
	ddui_utils::SetWidgetState(iPanelData, kPageCurlWidgetID, bEnable);

	// initialize the OK button
	InitializeOKButton();
}

//--------------------------------------------------------------------------------------------------------------------
// ResetDialogFields
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelController::ResetDialogFields(IActiveContext* ac)
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
// ValidateDialogFields
//--------------------------------------------------------------------------------------------------------------------
WidgetID SWFExportGeneralPanelController::ValidateDialogFields(IActiveContext* myContext)
{
	WidgetID id = Inherited::ValidateDialogFields(myContext);
	if (id != kNoInvalidWidgets)
		return id;

	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
	InterfacePtr<IPageRange> iPageRange((IPageRange*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPAGERANGE));
	if (iPageRange && iPageRange->GetPageRangeFormat() == IPageRange::kUseRange)
	{
		PMString pageRangeStr(iPageRange->GetPageRange());
		if (pageRangeStr.IsEmpty()) 
		{
			CAlert::WarningAlert("The page range is empty.");	// warning string from PDFUI
			return kPagesPageRangeEditWID;
		}
	}

	return kNoInvalidWidgets;
}

//--------------------------------------------------------------------------------------------------------------------
// ApplyDialogFields
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelController::ApplyDialogFields(IActiveContext* myContext, const WidgetID& widgetId)
{
	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());

	InterfacePtr<IBoolData> iSavePreviewSettings((IBoolData*)iWidgetParent->QueryParentFor(IID_ISAVEPREVIEWSETTINGS));
	InterfacePtr<IBoolData> dialogWasOKed((IBoolData*)iWidgetParent->QueryParentFor(IID_IBOOLDATA));

	if (iSavePreviewSettings && iSavePreviewSettings->GetBool())
		dialogWasOKed->Set(kFalse);
	else
		dialogWasOKed->Set(kTrue);

	InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
	InterfacePtr<IPageRange> iPageRange((IPageRange*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPAGERANGE));
	ASSERT (iData && iPageRange);

	// Use the facade to save the dialog preferences into the application workspace
 	ErrorCode result = Utils<Facade::IFlashSWF_ExportFacade>()->SetWorkspacePreferences(iData, iPageRange);
	ASSERT_MSG(result == kSuccess, "SWFExportGeneralPanelController::ApplyDialogFields failed to set application preferences!");
}

//--------------------------------------------------------------------------------------------------------------------
// InitializePageRange
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelController::InitializePageRange(IActiveContext* ac, IPageRange* iPageRange)
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IDocument* iDoc = ac->GetContextDocument();

	// set page range edit box
	if (!ddui_utils::InitializeRangeEdit(iPageRange, iDoc, iPanelData) &&
		iPageRange->GetPageRangeFormat() == IPageRange::kUseRange)
		iPageRange->SetPageRangeFormat(IPageRange::kAllPages);

	// save off the string
	IControlView* iControlView = iPanelData->FindWidget (kPagesPageRangeEditWID);
	InterfacePtr<ITextControlData> textData(iControlView, UseDefaultIID());
	iPageRange->SetPageRange(textData->GetString());

	// see if there are any page items selected, if not disable the control
	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
	InterfacePtr<IUIDListData> iUIDListData((IUIDListData*)iWidgetParent->QueryParentFor(IID_IUIDLISTDATA));
	const UIDList *itemsUIDList(nil);
	if (iUIDListData)
		itemsUIDList = iUIDListData->GetRef();
	if (itemsUIDList && itemsUIDList->size() == 0 && iPageRange->GetPageRangeFormat() == IPageRange::kBySelection)
		iPageRange->SetPageRangeFormat(IPageRange::kAllPages);
	ddui_utils::SetWidgetState(iPanelData, kSelection_RadioButtonWidgetID, itemsUIDList && itemsUIDList->size() != 0);

	// set pages radio button 
	if (iPageRange->GetPageRangeFormat() == IPageRange::kUseRange)
	{
		SetTriStateControlData(kSelection_RadioButtonWidgetID, kFalse);
		SetTriStateControlData(kAll_RadioButtonWidgetID, kFalse);
		SetTriStateControlData(kRange_RadioButtonWidgetID, kTrue);
	}
	else if (iPageRange->GetPageRangeFormat() == IPageRange::kBySelection)
	{
		SetTriStateControlData(kSelection_RadioButtonWidgetID, kTrue);
		SetTriStateControlData(kAll_RadioButtonWidgetID, kFalse);
		SetTriStateControlData(kRange_RadioButtonWidgetID, kFalse);
	}
	else // if (iPageRange->GetPageRangeFormat() == IPageRange::kAllPages)
	{
		SetTriStateControlData(kAll_RadioButtonWidgetID, kTrue);
		SetTriStateControlData(kRange_RadioButtonWidgetID, kFalse);
		SetTriStateControlData(kSelection_RadioButtonWidgetID, kFalse);
	}
}

//--------------------------------------------------------------------------------------------------------------------
// InitializeScale
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelController::InitializeScale(ISWFExportPreferences* iData, IPageRange* iPageRange)
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

	flash_export::SizeAndFitSettings sizeFitSettings;
	iData->GetSizeAndFitSettings(sizeFitSettings);

	// always set scale radio button
	if (sizeFitSettings.fSizeSelection != flash_export::kScale)
	{
		sizeFitSettings.fSizeSelection = flash_export::kScale;
		iData->SetSizeAndFitSettings(sizeFitSettings);
	}
	SetTriStateControlData(kScale_RadioButtonWidgetID, ITriStateControlData::kSelected);

	// set fit to popup
	ddui_utils::SetWidgetState(iPanelData, kFitTo_RadioButtonWidgetID, iPageRange->GetPageRangeFormat() != IPageRange::kBySelection);

	IControlView* iControlView = iPanelData->FindWidget (kFitToPopupWID);
	InterfacePtr<IDropDownListController> iListController(iControlView, UseDefaultIID ());
	if (sizeFitSettings.fFitToSelection == flash_export::k1280x800)
		iListController->Select (k1280x800Index, kTrue, kFalse);
	else if (sizeFitSettings.fFitToSelection == flash_export::k1240x620)
		iListController->Select (k1240x620Index, kTrue, kFalse);
	else if (sizeFitSettings.fFitToSelection == flash_export::k1024x768)
		iListController->Select (k1024x768Index, kTrue, kFalse);
	else if (sizeFitSettings.fFitToSelection == flash_export::k984x588)
		iListController->Select (k984x588Index, kTrue, kFalse);
	else if (sizeFitSettings.fFitToSelection == flash_export::k800x600)
		iListController->Select (k800x600Index, kTrue, kFalse);
	else if (sizeFitSettings.fFitToSelection == flash_export::k760x420)
		iListController->Select (k760x420Index, kTrue, kFalse);
	else if (sizeFitSettings.fFitToSelection == flash_export::k640x480)
		iListController->Select (k640x480Index, kTrue, kFalse);
	else // if (sizeFitSettings.fFitToSelection == flash_export::k600x300)
		iListController->Select (k600x300Index, kTrue, kFalse);
	iControlView->Disable();

	// set width popup - NOTE: the values are set in the observer
	ddui_utils::SetWidgetState(iPanelData, kWidth_RadioButtonWidgetID, iPageRange->GetPageRangeFormat() != IPageRange::kBySelection);
	ddui_utils::SetWidgetState(iPanelData, kWidthPopupWID, false);

	// set height popup - NOTE: the values are set in the observer
	ddui_utils::SetWidgetState(iPanelData, kHeightWidgetID, iPageRange->GetPageRangeFormat() != IPageRange::kBySelection);
	ddui_utils::SetWidgetState(iPanelData, kHeightPopupWID, false);

	// set height width chain icon - NOTE: always ON and disabled
	SetTriStateControlData(kHeight_Width_ConstrainWID, ITriStateControlData::kSelected);
	ddui_utils::SetWidgetState(iPanelData, kHeight_Width_ConstrainWID, false);

	// set scale popup 
	iControlView = iPanelData->FindWidget (kScalePopupWID);
	iControlView->Enable();
	InterfacePtr<ITextValue> textValue(iControlView, UseDefaultIID());
	textValue->SetTextFromValue(sizeFitSettings.fScaleAmount);
}

//--------------------------------------------------------------------------------------------------------------------
// InitializePageTransitions
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelController::InitializePageTransitions(ISWFExportPreferences* iData, IPageRange* iPageRange)
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

	// set Page Transition popup
	PMString selectedPageTransName;
	ClassID pageTrans = iData->GetPageTransitionOverride();
	if (pageTrans != kPageTransitionFromDocument && pageTrans != kInvalidClass)
		selectedPageTransName = Utils<Facade::IPageTransitionFacade>()->GetPageTransitionName(pageTrans);
	IControlView* iControlView = iPanelData->FindWidget (kPageTransPopupWID);

	// add the page transitions to the popup
    InterfacePtr<IStringListControlData> iStringListControlData(iControlView, UseDefaultIID());
    iStringListControlData->Clear(kFalse, kFalse);
    iStringListControlData->AddString("kFromDocument", IStringListControlData::kEnd, kFalse, kFalse);
    iStringListControlData->AddString("kNone", IStringListControlData::kEnd, kTrue, kFalse);
    iStringListControlData->AddString("-", IStringListControlData::kEnd, kTrue, kFalse);

	uint32 pageTransCount = Utils<Facade::IPageTransitionFacade>()->GetPageTransitionCount();
	int32 selectedIndex(kPageTransitionFromDocumentIndex);
	for (int32 i = 0; i < pageTransCount; i++)
	{
		PMString pageTransName(Utils<Facade::IPageTransitionFacade>()->GetNthPageTransitionName(i));
		if (pageTransName == selectedPageTransName)
			selectedIndex = iStringListControlData->Length();
		iStringListControlData->AddString(pageTransName, IStringListControlData::kEnd, kTrue, kFalse);
	}

	// now select the right one
	InterfacePtr<IDropDownListController> iListController(iControlView, UseDefaultIID ());
	if (pageTrans == kPageTransitionFromDocument)
		iListController->Select (kPageTransitionFromDocumentIndex, kTrue, kFalse);
	else if (pageTrans == kInvalidClass)
		iListController->Select (kPageTransitionNoneIndex, kTrue, kFalse);
	else
		iListController->Select (selectedIndex, kTrue, kFalse);

	// enable / disable based on selection export
	bool16 bEnable = (iPageRange->GetPageRangeFormat() != IPageRange::kBySelection) &&
					 (iData->GetHasTransparentBackground() == kFalse);
	iControlView->Enable(bEnable);
}

//--------------------------------------------------------------------------------------------------------------------
// InitializeOKButton
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelController::InitializeOKButton()
{
	// this looks very strange because we are in a sub-panel, so we have
	// to work our way back up to the top in order to find the OK button...
	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
	if (!iWidgetParent) return;
	iWidgetParent = InterfacePtr<IWidgetParent>(iWidgetParent->GetParent(), UseDefaultIID());
	if (!iWidgetParent) return;
	iWidgetParent = InterfacePtr<IWidgetParent>(iWidgetParent->GetParent(), UseDefaultIID());
	if (!iWidgetParent) return;
	InterfacePtr<IPanelControlData> iPanelData(iWidgetParent->GetParent(), UseDefaultIID());
	if (!iPanelData) return;
	IControlView* iControlView = iPanelData->FindWidget(kOKButtonWidgetID);
	if (!iControlView) return;
	InterfacePtr<ITextControlData> iOKButtonTextData(iControlView, UseDefaultIID());
	if (!iOKButtonTextData) return;

	InterfacePtr<IBoolData> iSavePreviewSettings((IBoolData*)iWidgetParent->QueryParentFor(IID_ISAVEPREVIEWSETTINGS));
	if (iSavePreviewSettings && iSavePreviewSettings->GetBool())
	{
		PMString saveButtonString("kSaveButtonString", PMString::kTranslateDuringCall);
		iOKButtonTextData->SetString(saveButtonString, kTrue, kFalse);	
	}
	else
	{
		PMString okButtonString("OK", PMString::kTranslateDuringCall);
		iOKButtonTextData->SetString(okButtonString, kTrue, kFalse);	
	}

	// Watson 2563111 - make sure the two icons in the advanced panel are being shown
	// before calling ApplyEveLayout because EVE will incorrectly resize the icon widgets
	// if they are hidden. The correct setting is done in the advance panel controller.
	iControlView = iPanelData->FindWidget(kFlattenWarningIconWidgetId);
	if (iControlView)
		iControlView->ShowView(kTrue);
	iControlView = iPanelData->FindWidget(kRastorizeWarningIconWidgetId);
	if (iControlView)
		iControlView->ShowView(kTrue);

	// Use EVE to make the button widget wider or smaller to fit the new string. See bug #2482859.
	InterfacePtr<IControlView> iDialogView(iPanelData, UseDefaultIID());
	if (Utils<IEVEUtils>()->CanApplyEveLayout(iDialogView)) 
		Utils<IEVEUtils>()->ApplyEveLayout(iDialogView); 
}
