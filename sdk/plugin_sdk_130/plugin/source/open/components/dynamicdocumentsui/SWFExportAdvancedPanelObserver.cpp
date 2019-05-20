//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFExportAdvancedPanelObserver.cpp $
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

// ----- Interfaces -----

#include "IControlView.h"
#include "IDialogController.h"
#include "IDropDownListController.h"
#include "IPanelControlData.h"
#include "ISWFExportPreferences.h"
#include "ISubject.h"
#include "IWidgetParent.h"

// ----- Includes -----

#include "AbstractDialogObserver.h"
#include "DynamicDocumentsUIID.h"
#include "DynamicDocumentsUIUtils.h"
#include "SWFExportAdvancedPanelController.h"

//====================================================================================================================
// Class SWFExportAdvancedPanelObserver
//====================================================================================================================
class SWFExportAdvancedPanelObserver : public AbstractDialogObserver
{
	typedef AbstractDialogObserver Inherited;

public:
	SWFExportAdvancedPanelObserver(IPMUnknown* boss);
	virtual ~SWFExportAdvancedPanelObserver();
	virtual void AutoAttach();
	virtual void AutoDetach();
	virtual void Update(const ClassID& theChange, ISubject* theSubject, const PMIID& protocol, void* changedBy);	

private:
	int32 fTextPopupIndexSaved;
	bool fFlattenXPSaved;

	void FramesPerSecEditChanged(const ClassID& changeId);
	void TextPopupChanged(const ClassID& changeId);
	void FlattenXPCheckboxChanged(const ClassID& changeId);
	void RasterizePagesCheckboxChanged(const ClassID& changeId);
	void ImageCompPopupChanged(const ClassID& changeId, ISubject* iSubject);
	void JPEGQualityPopupChanged(const ClassID& changeId, ISubject* iSubject);
	void ResolutionEditChanged(const ClassID& changeId);

	void SetSetting(const WidgetID& wid, bool16 bSetting);
	flash_export::RasterCompression GetCompressionSelection() const;
	flash_export::JPEGQuality GetJPEGQualitySelection() const;
};


CREATE_PMINTERFACE(SWFExportAdvancedPanelObserver, kSWFExportAdvancedPanelObserverImpl)

//--------------------------------------------------------------------------------------------------------------------
// SWFExportAdvancedPanelObserver Constructor/Destructor
//--------------------------------------------------------------------------------------------------------------------
SWFExportAdvancedPanelObserver::SWFExportAdvancedPanelObserver(IPMUnknown* boss)
	: Inherited(boss),
	fTextPopupIndexSaved(SWFExportAdvancedPanelController::kFlashTextIndex),
	fFlattenXPSaved(false)
{
}

SWFExportAdvancedPanelObserver::~SWFExportAdvancedPanelObserver()
{
}

//--------------------------------------------------------------------------------------------------------------------
// AutoAttach
//--------------------------------------------------------------------------------------------------------------------
void SWFExportAdvancedPanelObserver::AutoAttach() 
{
	Inherited::AutoAttach();
	
	InterfacePtr<IPanelControlData>	iPanelData(this, UseDefaultIID());
	if (iPanelData)
	{
		AttachToWidget(kFramesPerSecEditWidgetID, IID_ITEXTCONTROLDATA, iPanelData);
		AttachToWidget(kTextPopupWID, IID_ISTRINGLISTCONTROLDATA, iPanelData);
		AttachToWidget(kFlattenXPCheckboxWID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kRastorizeCheckboxWID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kCompressionPopupWID, IID_ISTRINGLISTCONTROLDATA, iPanelData);
		AttachToWidget(kJPEGQualityPopupWID, IID_ISTRINGLISTCONTROLDATA, iPanelData);
		AttachToWidget(kResolutionComboWID, IID_ITEXTCONTROLDATA, iPanelData);

		// intialize the saved values
		IControlView* iTextPopupView = iPanelData->FindWidget (kTextPopupWID);
		InterfacePtr<IDropDownListController> iTextPopupController(iTextPopupView, UseDefaultIID());
		fTextPopupIndexSaved = iTextPopupController->GetSelected();
		InterfacePtr<IDialogController> iDialogController(this, UseDefaultIID());
		fFlattenXPSaved = iDialogController->GetTriStateControlData(kFlattenXPCheckboxWID) == ITriStateControlData::kSelected;
	}
}

//--------------------------------------------------------------------------------------------------------------------
// AutoDetach
//--------------------------------------------------------------------------------------------------------------------
void SWFExportAdvancedPanelObserver::AutoDetach() 
{
	InterfacePtr<IPanelControlData>	iPanelData(this, UseDefaultIID());
	if (iPanelData)
	{
		DetachFromWidget(kFramesPerSecEditWidgetID, IID_ITEXTCONTROLDATA, iPanelData);
		DetachFromWidget(kTextPopupWID, IID_ISTRINGLISTCONTROLDATA, iPanelData);
		DetachFromWidget(kFlattenXPCheckboxWID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kRastorizeCheckboxWID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kCompressionPopupWID, IID_ISTRINGLISTCONTROLDATA, iPanelData);
		DetachFromWidget(kJPEGQualityPopupWID, IID_ISTRINGLISTCONTROLDATA, iPanelData);
		DetachFromWidget(kResolutionComboWID, IID_ITEXTCONTROLDATA, iPanelData);
	}
	
	Inherited::AutoDetach();
}

//--------------------------------------------------------------------------------------------------------------------
// Update
//--------------------------------------------------------------------------------------------------------------------
void SWFExportAdvancedPanelObserver::Update(const ClassID& changeId, ISubject* iSubject, const PMIID& protocolId, void* changedBy)
{
	InterfacePtr<IControlView> theControlView(iSubject, UseDefaultIID());
	if (theControlView != nil) 
	{
		WidgetID widgetID = theControlView->GetWidgetID();
		switch (widgetID.Get()) 
		{
			case kFramesPerSecEditWidgetID:
				FramesPerSecEditChanged(changeId);
				break;
			case kTextPopupWID:
				TextPopupChanged(changeId);
				break;
			case kFlattenXPCheckboxWID:
				FlattenXPCheckboxChanged(changeId);
				break;
			case kRastorizeCheckboxWID:
				RasterizePagesCheckboxChanged(changeId);
				break;
			case kCompressionPopupWID:
				ImageCompPopupChanged(changeId, iSubject);
				break;
			case kJPEGQualityPopupWID:
				SetSetting(kJPEGQualityPopupWID, kTrue);
				break;
			case kResolutionComboWID:
				ResolutionEditChanged(changeId);
				break;
			default:
				break;
		}
	}
}

//========================================================================================
// SWFExportAdvancedPanelObserver::FramesPerSecEditChanged
//========================================================================================
void SWFExportAdvancedPanelObserver::FramesPerSecEditChanged(const ClassID& changeId)
{
	if (changeId == kEditBoxKeyStrokeMessage || changeId == kTextChangeStateMessage) 
	{
		// find the widget
		InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
		IControlView* iControlView = iPanelData->FindWidget (kFramesPerSecEditWidgetID);
		InterfacePtr<ITextValue> textValue(iControlView, UseDefaultIID());

		// get the preferences from the dialog
		InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
		InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));

		// save the setting
		iData->SetFrameRate(::ToUInt32(textValue->GetTextAsValue()));
	}
}

//========================================================================================
// SWFExportAdvancedPanelObserver::TextPopupChanged
//========================================================================================
void SWFExportAdvancedPanelObserver::TextPopupChanged(const ClassID& changeId)
{
	if (changeId == kPopupChangeStateMessage) 
	{
		// figure out what is selected
		InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
		IControlView* iTextPopupView = iPanelData->FindWidget (kTextPopupWID);
		InterfacePtr<IDropDownListController> iTextPopupController(iTextPopupView, UseDefaultIID());
		int32 selected = iTextPopupController->GetSelected();

		// get the preferences from the dialog
		InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
		InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));

		// save off the setting
		if (selected == SWFExportAdvancedPanelController::kVectorTextIndex)
			iData->SetTextExportPolicy(flash_export::kVectorizeText);
		else if (selected == SWFExportAdvancedPanelController::kFlashTextIndex)
			iData->SetTextExportPolicy(flash_export::kLiveText);
		else // if (selected == SWFExportAdvancedPanelController::kRasterTextIndex)
			iData->SetTextExportPolicy(flash_export::kRasterizeText);
	}
}

//========================================================================================
// SWFExportAdvancedPanelObserver::FlattenXPCheckboxChanged
//========================================================================================
void SWFExportAdvancedPanelObserver::FlattenXPCheckboxChanged(const ClassID& changeId)
{
	// save the setting
	SetSetting(kFlattenXPCheckboxWID, changeId == kTrueStateMessage);

	if (changeId == kTrueStateMessage)
	{
		// if flatten XP turned on, set Background to Paper Color and Dynamic Media to Appearance Only
		InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
		InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
		iData->SetHasTransparentBackground(kFalse);
		iData->SetDynamicMediaHandling(flash_export::kAppearanceOnly);
	}

	// set the warning icon
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IControlView *iControlView = iPanelData->FindWidget (kFlattenWarningIconWidgetId);
	iControlView->ShowView(changeId == kTrueStateMessage);
}

//========================================================================================
// SWFExportAdvancedPanelObserver::RasterizePagesCheckboxChanged
//========================================================================================
void SWFExportAdvancedPanelObserver::RasterizePagesCheckboxChanged(const ClassID& changeId)
{
	// save the setting
	SetSetting(kRastorizeCheckboxWID, changeId == kTrueStateMessage);

	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	InterfacePtr<IDialogController> iDialogController(this, UseDefaultIID());
	IControlView* iTextPopupView = iPanelData->FindWidget (kTextPopupWID);
	InterfacePtr<IDropDownListController> iTextPopupController(iTextPopupView, UseDefaultIID());

	if (changeId == kTrueStateMessage)
	{
		// turn off and disable flatten XP checkbox
		fFlattenXPSaved = iDialogController->GetTriStateControlData(kFlattenXPCheckboxWID) == ITriStateControlData::kSelected;
		iDialogController->SetTriStateControlData(kFlattenXPCheckboxWID, ITriStateControlData::kUnselected);

		// set the text popup to be rasterize text
		fTextPopupIndexSaved = iTextPopupController->GetSelected();
		iTextPopupController->Select(SWFExportAdvancedPanelController::kRasterTextIndex);

		// set the background to paper color and the dynamic media handling to be appearance only
		InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
		InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
		iData->SetHasTransparentBackground(kFalse);
		iData->SetDynamicMediaHandling(flash_export::kAppearanceOnly);
	}
	else
	{
		iDialogController->SetTriStateControlData(kFlattenXPCheckboxWID, fFlattenXPSaved ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected);
		iTextPopupController->Select(fTextPopupIndexSaved);
	}

	// set the flatten XP enable/disable
	ddui_utils::SetWidgetState(iPanelData, kFlattenXPCheckboxWID, changeId != kTrueStateMessage);

	// set the text popup enable/disable
	ddui_utils::SetWidgetState(iPanelData, kTextPopupWID, changeId != kTrueStateMessage);

	// set the warning icon
	IControlView *iControlView = iPanelData->FindWidget (kRastorizeWarningIconWidgetId);
	iControlView->ShowView(changeId == kTrueStateMessage);
}

//========================================================================================
// SWFExportAdvancedPanelObserver::ImageCompPopupChanged
//========================================================================================
void SWFExportAdvancedPanelObserver::ImageCompPopupChanged(const ClassID& changeId, ISubject* iSubject)
{
	if (changeId == kPopupChangeStateMessage) 
	{
		InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

		// save the setting
		SetSetting(kCompressionPopupWID, kTrue);

		// disable JPEG quality if PNG (lossless) compression selected
		ddui_utils::SetWidgetState(iPanelData, kJPEGQualityPopupWID, GetCompressionSelection() != flash_export::kLosslessCompression);
	}
}

//========================================================================================
// SWFExportAdvancedPanelObserver::JPEGQualityPopupChanged
//========================================================================================
void SWFExportAdvancedPanelObserver::JPEGQualityPopupChanged(const ClassID& changeId, ISubject* iSubject)
{
	if (changeId == kPopupChangeStateMessage) 
	{
		// save the setting
		SetSetting(kJPEGQualityPopupWID, kTrue);
	}
}

//========================================================================================
// SWFExportAdvancedPanelObserver::ResolutionEditChanged
//========================================================================================
void SWFExportAdvancedPanelObserver::ResolutionEditChanged(const ClassID& changeId)
{
	if (changeId == kEditBoxKeyStrokeMessage || changeId == kTextChangeStateMessage) 
	{
		// find the widget
		InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
		IControlView* iControlView = iPanelData->FindWidget (kResolutionComboWID);
		InterfacePtr<ITextValue> textValue(iControlView, UseDefaultIID());

		// save the setting
		InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
		InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
		iData->SetRasterResolution(::ToUInt32(textValue->GetTextAsValue()));
	}
}

//========================================================================================
// SWFExportAdvancedPanelObserver::SetSetting
//========================================================================================
void SWFExportAdvancedPanelObserver::SetSetting(const WidgetID& wid, bool16 bSetting)
{
	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
	InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));

	switch (wid.Get())
	{
		case kFlattenXPCheckboxWID:
			iData->SetTransparencyHandling(bSetting ? flash_export::kFlattenTransparency : flash_export::kIgnoreTransparency);
			break;
		case kRastorizeCheckboxWID:
			iData->SetRasterizePages(bSetting);
			break;
		case kCompressionPopupWID:
			iData->SetRasterCompression(GetCompressionSelection());
			break;
		case kJPEGQualityPopupWID:
			iData->SetJPEGQuality(GetJPEGQualitySelection());
			break;
		default:
			break;
	}
}

//========================================================================================
// SWFExportAdvancedPanelObserver::GetCompressionSelection
//========================================================================================
flash_export::RasterCompression SWFExportAdvancedPanelObserver::GetCompressionSelection() const
{
	// find the widget
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IControlView* iControlView = iPanelData->FindWidget (kCompressionPopupWID);
	InterfacePtr<IDropDownListController> iListController(iControlView, UseDefaultIID ());
	int32 selected = iListController->GetSelected();

	// decode the index
	if (selected == SWFExportAdvancedPanelController::kJPGIndex)
		return flash_export::kJPEGCompression;
	else if (selected == SWFExportAdvancedPanelController::kPNGIndex)
		return flash_export::kLosslessCompression;
	else // if (selected == SWFExportAdvancedPanelController::kAutoIndex)
		return flash_export::kAutomaticCompression;
}

//========================================================================================
// SWFExportAdvancedPanelObserver::GetJPEGQualitySelection
//========================================================================================
flash_export::JPEGQuality SWFExportAdvancedPanelObserver::GetJPEGQualitySelection() const
{
	// find the widget
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IControlView* iControlView = iPanelData->FindWidget (kJPEGQualityPopupWID);
	InterfacePtr<IDropDownListController> iListController(iControlView, UseDefaultIID ());
	int32 selected = iListController->GetSelected();

	// decode the index
	if (selected == SWFExportAdvancedPanelController::kMinQualityIndex)
		return flash_export::kJPEGQuality_Minimum;
	else if (selected == SWFExportAdvancedPanelController::kLowQualityIndex)
		return flash_export::kJPEGQuality_Low;
	else if (selected == SWFExportAdvancedPanelController::kMedQualityIndex)
		return flash_export::kJPEGQuality_Medium;
	else if (selected == SWFExportAdvancedPanelController::kHighQualityIndex)
		return flash_export::kJPEGQuality_High;
	else // if (selected == SWFExportAdvancedPanelController::kMaxQualityIndex)
		return flash_export::kJPEGQuality_Maximum;
}

