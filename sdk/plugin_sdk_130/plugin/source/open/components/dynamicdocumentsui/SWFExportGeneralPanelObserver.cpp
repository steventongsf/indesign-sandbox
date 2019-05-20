//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFExportGeneralPanelObserver.cpp $
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

#include "IActiveContext.h"
#include "IControlView.h"
#include "ISubject.h"
#include "IDocument.h"
#include "IDropDownListController.h"
#include "IDynDocsPublicUtils.h"
#include "IPageTransitionFacade.h"
#include "IPageList.h"
#include "IPageRange.h"
#include "IPanelControlData.h"
#include "IStringListControlData.h"
#include "ISWFExportPreferences.h"
#include "ITextControlData.h"
#include "ITriStateControlData.h"
#include "IUIDListData.h"
#include "IWidgetParent.h"
#include "IWidgetUtils.h"

// ----- Includes -----

#include "AbstractDialogObserver.h"
#include "DynamicDocumentsUIID.h"
#include "DynamicDocumentsUIUtils.h"
#include "SWFExportGeneralPanelController.h"

//====================================================================================================================
// Class SWFExportGeneralPanelObserver
//====================================================================================================================
class SWFExportGeneralPanelObserver : public AbstractDialogObserver
{
	typedef	AbstractDialogObserver Inherited;

public:
	SWFExportGeneralPanelObserver(IPMUnknown* boss);
	virtual ~SWFExportGeneralPanelObserver();
	virtual void AutoAttach();
	virtual void AutoDetach();
	virtual void Update(const ClassID& theChange, ISubject* theSubject, const PMIID& protocol, void* changedBy);	

private:
	PMPoint fWidthHeight;
	PMPoint fSelectedWidthHeight;
	PMPoint fSpreadWidthHeight;
	bool16 fbSelectionChosen;
	WidgetID fSelectedWidgetID;
	bool fViewAfterSaved;
	bool fPageCurlSaved;

	void PagesRadioChanged(const ClassID& changeId, const WidgetID& widgetID);
	void PageRangeEditChanged(const ClassID& changeId);
	void GenerateHTMLCheckboxChanged(const ClassID& changeId);
	void SizeRadioChanged(const ClassID& changeId, const WidgetID& widgetID);
	void FitToPopupChanged();
	void WidthEditChanged(const ClassID& changeId, ISubject* iSubject);
	void HeightEditChanged(const ClassID& changeId, ISubject* iSubject);
	void ScalePopupChanged();
	void TransparentBackgroundRadioChanged(const ClassID& changeId);
	void IncludeAllRadioChanged(const ClassID& changeId);
	void PageTransitionPopupChanged();

	void GetWidthAndHeight(uint32& width, uint32& height) const;
	void GetWidthAndHeightFitTo(uint32& width, uint32& height) const;
	void GetWidthAndHeightScale(uint32& width, uint32& height) const;
	void SetWidthAndHeight(uint32& width, uint32& height) const;
	void SetScale(uint32 width, uint32 height) const;
	void UpdatePageAndSpreadSize(IDocument* iDocument, bool16 bPageRange);
	void UpdateWidthHeightAndScale() const;

	void SetSetting(const WidgetID& wid, bool16 bSetting);
	flash_export::FitToSelection GetFitToSelection() const;
	PMReal GetTextValue(const WidgetID& wid) const;
};


CREATE_PMINTERFACE(SWFExportGeneralPanelObserver, kSWFExportGeneralPanelObserverImpl)

//--------------------------------------------------------------------------------------------------------------------
// SWFExportGeneralPanelObserver Constructor/Destructor
//--------------------------------------------------------------------------------------------------------------------
SWFExportGeneralPanelObserver::SWFExportGeneralPanelObserver(IPMUnknown* boss)
	: Inherited(boss),
	fSelectedWidthHeight(0, 0),
	fSpreadWidthHeight(1024, 768),
	fbSelectionChosen(kFalse),
	fSelectedWidgetID(kInvalidWidgetID),
	fViewAfterSaved(true),
	fPageCurlSaved(true)
{
}

SWFExportGeneralPanelObserver::~SWFExportGeneralPanelObserver()
{
}

//--------------------------------------------------------------------------------------------------------------------
// AutoAttach
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::AutoAttach() 
{
	Inherited::AutoAttach();
	
	InterfacePtr<IPanelControlData>	iPanelData(this, UseDefaultIID());
	if (iPanelData)
	{
		// we need to keep track of the selection/all pages/range radio buttons
		// because they are not in a group
		if (fSelectedWidgetID == kInvalidWidgetID)
		{
            IControlView *widget = iPanelData->FindWidget(kSelection_RadioButtonWidgetID);
            InterfacePtr<ITriStateControlData> triData(widget,IID_ITRISTATECONTROLDATA);
			if (triData && triData->IsSelected())
			{
				fbSelectionChosen = kTrue;
				fSelectedWidgetID = kSelection_RadioButtonWidgetID;
			}
			else
			{
				fbSelectionChosen = kFalse;
				widget = iPanelData->FindWidget(kRange_RadioButtonWidgetID);
				triData = InterfacePtr<ITriStateControlData>(widget,IID_ITRISTATECONTROLDATA);
				if (triData && triData->IsSelected())
					fSelectedWidgetID = kRange_RadioButtonWidgetID;
				else 
					fSelectedWidgetID = kAll_RadioButtonWidgetID;
			}
		}

		AttachToWidget(kSelection_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kAll_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kRange_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kPagesPageRangeEditWID, IID_ITEXTCONTROLDATA, iPanelData);
		AttachToWidget(kGenHTMLCheckboxWID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kViewSWFAfterExportingCheckboxWID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kFitTo_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kFitToPopupWID, IID_ISTRINGLISTCONTROLDATA, iPanelData);
		AttachToWidget(kWidth_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kWidthPopupWID, IID_ITEXTCONTROLDATA, iPanelData);
		AttachToWidget(kHeightPopupWID, IID_ITEXTCONTROLDATA, iPanelData);
		AttachToWidget(kScale_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kScalePopupWID, IID_ITEXTCONTROLDATA, iPanelData);
		AttachToWidget(kTransparent_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kIncludeAll_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		AttachToWidget(kPageTransPopupWID, IID_ISTRINGLISTCONTROLDATA, iPanelData);
		AttachToWidget(kPageCurlWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);

		IActiveContext *activeContext = GetExecutionContextSession()->GetActiveContext();
		if (!activeContext) return;
		IDocument *contextDoc = activeContext->GetContextDocument();
		if (!contextDoc) return;

		InterfacePtr<IDialogController> iDialogController(this, UseDefaultIID());
		bool16 bPageRange = iDialogController->GetTriStateControlData(kRange_RadioButtonWidgetID) == ITriStateControlData::kSelected;

		// initialize the saved settings
		fViewAfterSaved = iDialogController->GetTriStateControlData(kViewSWFAfterExportingCheckboxWID) == ITriStateControlData::kSelected;
		fPageCurlSaved = iDialogController->GetTriStateControlData(kPageCurlWidgetID) == ITriStateControlData::kSelected;

		// update to the new page range
		UpdatePageAndSpreadSize(contextDoc, bPageRange);

		// update the width and height
		UpdateWidthHeightAndScale();
	}
}


//--------------------------------------------------------------------------------------------------------------------
// AutoDetach
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::AutoDetach() 
{
	fbSelectionChosen = kFalse;
	fSelectedWidgetID = kInvalidWidgetID;
	fSelectedWidthHeight = PMPoint(0, 0);

	InterfacePtr<IPanelControlData>	iPanelData(this, UseDefaultIID());
	if (iPanelData)
	{
		DetachFromWidget(kSelection_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kAll_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kRange_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kPagesPageRangeEditWID, IID_ITEXTCONTROLDATA, iPanelData);
		DetachFromWidget(kGenHTMLCheckboxWID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kViewSWFAfterExportingCheckboxWID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kFitTo_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kFitToPopupWID, IID_ISTRINGLISTCONTROLDATA, iPanelData);
		DetachFromWidget(kWidth_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kWidthPopupWID, IID_ITEXTCONTROLDATA, iPanelData);
		DetachFromWidget(kHeightPopupWID, IID_ITEXTCONTROLDATA, iPanelData);
		DetachFromWidget(kScale_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kScalePopupWID, IID_ITEXTCONTROLDATA, iPanelData);
		DetachFromWidget(kTransparent_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kIncludeAll_RadioButtonWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
		DetachFromWidget(kPageTransPopupWID, IID_ISTRINGLISTCONTROLDATA, iPanelData);
		DetachFromWidget(kPageCurlWidgetID, IID_ITRISTATECONTROLDATA, iPanelData);
	}
	
	Inherited::AutoDetach();
}

//--------------------------------------------------------------------------------------------------------------------
// Update
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::Update(const ClassID& changeId, ISubject* iSubject, const PMIID& protocolId, void* changedBy)
{
	InterfacePtr<IControlView> theControlView(iSubject, UseDefaultIID());
	if (theControlView != nil) 
	{
		WidgetID widgetID = theControlView->GetWidgetID();
		switch (widgetID.Get()) 
		{
			case kSelection_RadioButtonWidgetID:
			case kAll_RadioButtonWidgetID:
			case kRange_RadioButtonWidgetID:
				PagesRadioChanged(changeId, widgetID);
				break;
			case kPagesPageRangeEditWID:
				PageRangeEditChanged(changeId);
				break;
			case kGenHTMLCheckboxWID:
				GenerateHTMLCheckboxChanged(changeId);
				break;
			case kViewSWFAfterExportingCheckboxWID:
				SetSetting(kViewSWFAfterExportingCheckboxWID, changeId == kTrueStateMessage);
				break;
			case kFitTo_RadioButtonWidgetID:
			case kScale_RadioButtonWidgetID:
			case kWidth_RadioButtonWidgetID:
				SizeRadioChanged(changeId, widgetID);
				break;
			case kFitToPopupWID:
				FitToPopupChanged();
				break;
			case kWidthPopupWID:
				WidthEditChanged(changeId, iSubject);
				break;
			case kHeightPopupWID:
				HeightEditChanged(changeId, iSubject);
				break;
			case kScalePopupWID:
				ScalePopupChanged();
				break;
			case kTransparent_RadioButtonWidgetID:
				TransparentBackgroundRadioChanged(changeId);
				break;
			case kIncludeAll_RadioButtonWidgetID:
				IncludeAllRadioChanged(changeId);
				break;
			case kPageTransPopupWID:
				PageTransitionPopupChanged();
				break;
			case kPageCurlWidgetID:
				SetSetting(kPageCurlWidgetID, changeId == kTrueStateMessage);
				break;
			default:
				break;
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------
// PagesRadioChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::PagesRadioChanged(const ClassID& changeId, const WidgetID& widgetID)
{
	InterfacePtr<IDialogController> iDialogController(this, UseDefaultIID());
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

	if(widgetID == fSelectedWidgetID && changeId == kFalseStateMessage)
	{
		//can't let this happen - it must stay selected
		IControlView* iView = iPanelData->FindWidget (widgetID);
		InterfacePtr<ITriStateControlData> triData(iView, IID_ITRISTATECONTROLDATA);
		if(triData)
			triData->Select();
	}

	if (changeId == kTrueStateMessage) 
	{
		InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
		InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
		InterfacePtr<IPageRange> iPageRange((IPageRange*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPAGERANGE));
		fSelectedWidgetID = widgetID;

		// start with the radio buttons, and re-enabling everything
		iDialogController->SetTriStateControlData(kSelection_RadioButtonWidgetID, widgetID == kSelection_RadioButtonWidgetID ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected, iPanelData, kTrue, kFalse);
		iDialogController->SetTriStateControlData(kAll_RadioButtonWidgetID, widgetID == kAll_RadioButtonWidgetID ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected, iPanelData, kTrue, kFalse);
		iDialogController->SetTriStateControlData(kRange_RadioButtonWidgetID, widgetID == kRange_RadioButtonWidgetID ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected, iPanelData, kTrue, kFalse);

		// special case the selection radio button
		if (widgetID == kSelection_RadioButtonWidgetID)
		{
			fbSelectionChosen = kTrue;
			fWidthHeight = fSelectedWidthHeight;

			// save the setting
			iPageRange->SetPageRangeFormat(IPageRange::kBySelection);

			// disable fit to and width radio buttons and the height label
			ddui_utils::SetWidgetState(iPanelData, kFitTo_RadioButtonWidgetID, false);
			ddui_utils::SetWidgetState(iPanelData, kWidth_RadioButtonWidgetID, false);
			ddui_utils::SetWidgetState(iPanelData, kHeightWidgetID, false);

			// turn off and disable page curl
			InterfacePtr<IControlView> pPageCurlControl( (IControlView*)Utils<IWidgetUtils>()->QueryRelatedWidget(this, kPageCurlWidgetID, IID_ICONTROLVIEW));
			if (pPageCurlControl && pPageCurlControl->IsEnabled())
				fPageCurlSaved = iDialogController->GetTriStateControlData(kPageCurlWidgetID) == ITriStateControlData::kSelected;
			iDialogController->SetTriStateControlData(kPageCurlWidgetID, ITriStateControlData::kUnselected);
			ddui_utils::SetWidgetState(iPanelData, kPageCurlWidgetID, false);

			// disable page transitions
			ddui_utils::SetWidgetState(iPanelData, kPageTransPopupWID, false);

			// turn off and disable rasterize checkbox - since this is in the Advanced panel,
			// we turn it off in the data
			iData->SetRasterizePages(kFalse);

			// force scale radio button, and set to 100% if scale was not chosen before
			IControlView* scaleView = iPanelData->FindWidget (kScale_RadioButtonWidgetID);
			InterfacePtr<ITriStateControlData> scaleTriData(scaleView, IID_ITRISTATECONTROLDATA);
			if (scaleTriData->IsDeselected())
			{
				scaleTriData->Select(kTrue, kTrue);
				IControlView* scaleAmt = iPanelData->FindWidget(kScalePopupWID);
				scaleAmt->Enable();
				InterfacePtr<ITextValue> scaleText(scaleAmt, UseDefaultIID());
				scaleText->SetTextFromValue(100);
			}
		}
		else	// either all pages or page range chosen
		{
			fbSelectionChosen = kFalse;

			// save the setting
			iPageRange->SetPageRangeFormat(widgetID == kRange_RadioButtonWidgetID ? IPageRange::kUseRange : IPageRange::kAllPages);

			// re-enable the fit to and width radio buttons
			ddui_utils::SetWidgetState(iPanelData, kFitTo_RadioButtonWidgetID, true);
			ddui_utils::SetWidgetState(iPanelData, kWidth_RadioButtonWidgetID, true);
			ddui_utils::SetWidgetState(iPanelData, kHeightWidgetID, true);

			// only reenable if background is not transparent
			if (iData->GetHasTransparentBackground() == kFalse)
			{
				iDialogController->SetTriStateControlData(kPageCurlWidgetID, fPageCurlSaved ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected);
				ddui_utils::SetWidgetState(iPanelData, kPageCurlWidgetID, true);
				ddui_utils::SetWidgetState(iPanelData, kPageTransPopupWID, true);
			}
		}

		IActiveContext *activeContext = GetExecutionContextSession()->GetActiveContext();
		if (!activeContext) return;
		IDocument *contextDoc = activeContext->GetContextDocument();
		if (!contextDoc) return;

		// update to the new page range
		UpdatePageAndSpreadSize(contextDoc, widgetID.Get() == kRange_RadioButtonWidgetID);

		// update the width and height
		UpdateWidthHeightAndScale();
	}
}

//--------------------------------------------------------------------------------------------------------------------
// PageRangeEditChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::PageRangeEditChanged(const ClassID& changeId)
{
	// find the widget
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IControlView* iControlView = iPanelData->FindWidget (kPagesPageRangeEditWID);
	InterfacePtr<ITextControlData> textData(iControlView, UseDefaultIID());

	// get the dialog preferences
	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
	InterfacePtr<IPageRange> iPageRange((IPageRange*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPAGERANGE));
	
	// save off the string
	iPageRange->SetPageRange(textData->GetString());

	InterfacePtr<IDialogController> iDialogController(this, UseDefaultIID());
	if (changeId == kEditBoxKeyStrokeMessage) 
	{
		// set the page range radio button
		iDialogController->SetTriStateControlData(kRange_RadioButtonWidgetID, ITriStateControlData::kSelected);
	}
	else if (changeId == kTextChangeStateMessage)
	{
		// set the page range radio button
		iDialogController->SetTriStateControlData(kRange_RadioButtonWidgetID, ITriStateControlData::kSelected);

		IActiveContext *activeContext = GetExecutionContextSession()->GetActiveContext();
		if (!activeContext) return;
		IDocument *contextDoc = activeContext->GetContextDocument();
		if (!contextDoc) return;

		// update to the new page range
		UpdatePageAndSpreadSize(contextDoc, kTrue);

		// update the width and height
		UpdateWidthHeightAndScale();
	}
}

//--------------------------------------------------------------------------------------------------------------------
// GenerateHTMLCheckboxChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::GenerateHTMLCheckboxChanged(const ClassID& changeId)
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

	// save off the setting
	SetSetting(kGenHTMLCheckboxWID, changeId == kTrueStateMessage);

	// if create HTML turned off, also turn off and disable View After checkbox
	InterfacePtr<IDialogController> iDialogController (this, UseDefaultIID());
	if (changeId == kFalseStateMessage)
	{
		fViewAfterSaved = iDialogController->GetTriStateControlData(kViewSWFAfterExportingCheckboxWID) == ITriStateControlData::kSelected;
		iDialogController->SetTriStateControlData(kViewSWFAfterExportingCheckboxWID, ITriStateControlData::kUnselected);
	}
	else
	{
		iDialogController->SetTriStateControlData(kViewSWFAfterExportingCheckboxWID, fViewAfterSaved ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected);
	}

	ddui_utils::SetWidgetState(iPanelData, kViewSWFAfterExportingCheckboxWID, changeId == kTrueStateMessage);
}

//--------------------------------------------------------------------------------------------------------------------
// SizeRadioChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::SizeRadioChanged(const ClassID& changeId, const WidgetID& widgetID)
{
	if (changeId == kTrueStateMessage) 
	{
		InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

		// save the setting
		SetSetting(widgetID, kTrue);

		// enable/disable different popups
		ddui_utils::SetWidgetState(iPanelData, kFitToPopupWID, widgetID.Get() == kFitTo_RadioButtonWidgetID);
		ddui_utils::SetWidgetState(iPanelData, kScalePopupWID, widgetID.Get() == kScale_RadioButtonWidgetID);
		ddui_utils::SetWidgetState(iPanelData, kWidthPopupWID, widgetID.Get() == kWidth_RadioButtonWidgetID);
		ddui_utils::SetWidgetState(iPanelData, kHeightPopupWID, widgetID.Get() == kWidth_RadioButtonWidgetID);

		// we only need to update width, height and scale if Fit To is selected
		uint32 width, height;
		if (widgetID.Get() == kFitTo_RadioButtonWidgetID)
			GetWidthAndHeightFitTo(width, height);
		else
			return;

		// set the width and height
		SetWidthAndHeight(width, height);

		// set the scale percentage
		SetScale(width, height);
	}
}

//--------------------------------------------------------------------------------------------------------------------
// FitToPopupChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::FitToPopupChanged()
{
	InterfacePtr<IDialogController> iDialogController(this, UseDefaultIID());

	// save setting
	SetSetting(kFitToPopupWID, kTrue);

	// set the fit to radio button
	iDialogController->SetTriStateControlData(kFitTo_RadioButtonWidgetID, ITriStateControlData::kSelected);

	// get the new values and set them in width and height
	uint32 width, height;
	GetWidthAndHeightFitTo(width, height);
	SetWidthAndHeight(width, height);

	// set the scale percentage
	SetScale(width, height);
}

//--------------------------------------------------------------------------------------------------------------------
// WidthEditChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::WidthEditChanged(const ClassID& changeId, ISubject* iSubject)
{
	if (changeId == kTextChangeStateMessage) 
	{
		InterfacePtr<IDialogController> iDialogController(this, UseDefaultIID());
		InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

		// get the new value for the width
		InterfacePtr<ITextValue> textValueX(iSubject, UseDefaultIID());
		uint32 targetWidth = ::ToUInt32(textValueX->GetTextAsValue());

		// calculate the new value for the height
		uint32 destHeight;
		ddui_utils::CalculateHeightFromWidth(	fWidthHeight.X(), fWidthHeight.Y(), 
												targetWidth,
												destHeight );

		// boundary checking
		if (destHeight < kMinSize)
		{
			destHeight = kMinSize;
			ddui_utils::CalculateWidthFromHeight(	fWidthHeight.X(), fWidthHeight.Y(),
													destHeight,
													targetWidth );
			textValueX->SetTextFromValue(targetWidth, /*invalidate*/ kTrue, /*notifyOfChange*/ kFalse);
		}
		else if (destHeight > kMaxSize)
		{
			destHeight = kMaxSize;
			ddui_utils::CalculateWidthFromHeight(	fWidthHeight.X(), fWidthHeight.Y(),
													destHeight,
													targetWidth );
			textValueX->SetTextFromValue(targetWidth, /*invalidate*/ kTrue, /*notifyOfChange*/ kFalse);
		}

		// set height popup
		IControlView* iView = iPanelData->FindWidget (kHeightPopupWID);
		InterfacePtr<ITextValue> textValueY(iView, UseDefaultIID());
		textValueY->SetTextFromValue(destHeight, /*invalidate*/ kTrue, /*notifyOfChange*/ kFalse);

		// set the scale percentage
		SetScale(targetWidth, destHeight);

		// save setting
		SetSetting(kWidthPopupWID, kTrue);
		SetSetting(kHeightPopupWID, kTrue);
	}
}

//--------------------------------------------------------------------------------------------------------------------
// HeightEditChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::HeightEditChanged(const ClassID& changeId, ISubject* iSubject)
{
	if (changeId == kTextChangeStateMessage) 
	{
		InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

		// get the new value for the height
		InterfacePtr<ITextValue> textValueY(iSubject, UseDefaultIID());
		uint32 targetHeight = ::ToUInt32(textValueY->GetTextAsValue());

		// calculate the new value for the width
		uint32 destWidth;
		ddui_utils::CalculateWidthFromHeight(	fWidthHeight.X(), fWidthHeight.Y(),
												targetHeight,
												destWidth );

		// boundary checking
		if (destWidth < kMinSize)
		{
			destWidth = kMinSize;
			ddui_utils::CalculateHeightFromWidth(	fWidthHeight.X(), fWidthHeight.Y(),
													destWidth,
													targetHeight );
			textValueY->SetTextFromValue(targetHeight, /*invalidate*/ kTrue, /*notifyOfChange*/ kFalse);
		}
		else if (destWidth > kMaxSize)
		{
			destWidth = kMaxSize;
			ddui_utils::CalculateHeightFromWidth(	fWidthHeight.X(), fWidthHeight.Y(),
													destWidth,
													targetHeight );
			textValueY->SetTextFromValue(targetHeight, /*invalidate*/ kTrue, /*notifyOfChange*/ kFalse);
		}

		// set width popup
		IControlView* iView = iPanelData->FindWidget (kWidthPopupWID);
		InterfacePtr<ITextValue> textValueX(iView, UseDefaultIID());
		textValueX->SetTextFromValue(destWidth, /*invalidate*/ kTrue, /*notifyOfChange*/ kFalse);

		// set the scale percentage
		SetScale(destWidth, targetHeight);

		// save setting
		SetSetting(kHeightPopupWID, kTrue);
		SetSetting(kWidthPopupWID, kTrue);
	}
}

//--------------------------------------------------------------------------------------------------------------------
// ScalePopupChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::ScalePopupChanged()
{
	// get the new values and set them in width and height
	uint32 width, height;
	GetWidthAndHeightScale(width, height);
	SetWidthAndHeight(width, height);

	// save setting
	SetSetting(kScalePopupWID, kTrue);
}

//--------------------------------------------------------------------------------------------------------------------
// TransparentBackgroundRadioChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::TransparentBackgroundRadioChanged(const ClassID& changeId)
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	InterfacePtr<IDialogController> iDialogController (this, UseDefaultIID());

	// save off the setting
	SetSetting(kTransparent_RadioButtonWidgetID, changeId == kTrueStateMessage);

	// if changeId == kTrueStateMessage, means Transparent background chosen
	if (changeId == kTrueStateMessage)
	{
		// disable page transition popup
		ddui_utils::SetWidgetState(iPanelData, kPageTransPopupWID, false);

		// turn off and disable page curl checkbox
		InterfacePtr<IControlView> pPageCurlControl( (IControlView*)Utils<IWidgetUtils>()->QueryRelatedWidget(this, kPageCurlWidgetID, IID_ICONTROLVIEW));
		if (pPageCurlControl && pPageCurlControl->IsEnabled())
			fPageCurlSaved = iDialogController->GetTriStateControlData(kPageCurlWidgetID) == ITriStateControlData::kSelected;
		iDialogController->SetTriStateControlData(kPageCurlWidgetID, ITriStateControlData::kUnselected);
		ddui_utils::SetWidgetState(iPanelData, kPageCurlWidgetID, false);

		// turn off flatten transparency (Advanced panel) by setting the data directly
		InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
		InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
		iData->SetTransparencyHandling(flash_export::kIgnoreTransparency);
		iData->SetRasterizePages(kFalse);
	}
	else if (!fbSelectionChosen)
	{
		// re-enable page transition and page curl, if page selection not chosen
		iDialogController->SetTriStateControlData(kPageCurlWidgetID, fPageCurlSaved ? ITriStateControlData::kSelected : ITriStateControlData::kUnselected);
		ddui_utils::SetWidgetState(iPanelData, kPageTransPopupWID, true);
		ddui_utils::SetWidgetState(iPanelData, kPageCurlWidgetID, true);
	}
}

//--------------------------------------------------------------------------------------------------------------------
// IncludeAllRadioChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::IncludeAllRadioChanged(const ClassID& changeId)
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

	// save off the setting
	SetSetting(kIncludeAll_RadioButtonWidgetID, changeId == kTrueStateMessage);

	if (changeId == kTrueStateMessage)
	{
		// turn off rasterize pages (in Advanced panel) by changing the data directly
		InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
		InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
		iData->SetTransparencyHandling(flash_export::kIgnoreTransparency);
		iData->SetRasterizePages(kFalse);
	}
}

//--------------------------------------------------------------------------------------------------------------------
// PageTransitionPopupChanged
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::PageTransitionPopupChanged()
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());

	// set the page transitions
	ClassID pageTrans(kPageTransitionFromDocument);
	IControlView* iControlView = iPanelData->FindWidget (kPageTransPopupWID);
	InterfacePtr<IDropDownListController>iListController (iControlView, UseDefaultIID ());
	int32 selected = iListController->GetSelected();
	if (selected == SWFExportGeneralPanelController::kPageTransitionFromDocumentIndex)
		pageTrans = kPageTransitionFromDocument;
	else if (selected == SWFExportGeneralPanelController::kPageTransitionNoneIndex)
		pageTrans = kInvalidClass;
	else
	{
		InterfacePtr<IStringListControlData> iStringListControlData(iControlView, UseDefaultIID());
		PMString selectedString(iStringListControlData->GetString(selected));
		pageTrans = Utils<Facade::IPageTransitionFacade>()->GetPageTransitionClassID(selectedString);
	}

	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
	InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
	iData->SetPageTransitionOverride(pageTrans);
}

//--------------------------------------------------------------------------------------------------------------------
// GetWidthAndHeight
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::GetWidthAndHeight(uint32& width, uint32& height) const
{
	InterfacePtr<IPanelControlData> iPanelData(this, UseDefaultIID());

	// get the new scale value
	IControlView* iControlView = iPanelData->FindWidget (kWidthPopupWID);
	InterfacePtr<ITextValue> textValueX(iControlView, UseDefaultIID());
	iControlView = iPanelData->FindWidget (kHeightPopupWID);
	InterfacePtr<ITextValue> textValueY(iControlView, UseDefaultIID());
	flash_export::SizeAndFitSettings settings;
	settings.fSizeSelection = flash_export::kWidthAndHeight;
	settings.fWidthAmount = ::ToUInt32(textValueX->GetTextAsValue());
	settings.fHeightAmount = ::ToUInt32(textValueY->GetTextAsValue());

	Utils<IDynDocsPublicUtils>()->CalculateWidthAndHeightForExport(fWidthHeight.X(), fWidthHeight.Y(), settings, width, height);

	// boundary check
	ASSERT(width >= kMinSize && width <= kMaxSize);
	ASSERT(height >= kMinSize && height <= kMaxSize);
}

//--------------------------------------------------------------------------------------------------------------------
// GetWidthAndHeightFitTo
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::GetWidthAndHeightFitTo(uint32& width, uint32& height) const
{
	// figure out what is chosen
	flash_export::SizeAndFitSettings settings;
	settings.fSizeSelection = flash_export::kFitTo;
	settings.fFitToSelection = GetFitToSelection();

	// calculate the width and height
	Utils<IDynDocsPublicUtils>()->CalculateWidthAndHeightForExport(fWidthHeight.X(), fWidthHeight.Y(), settings, width, height);
}

//--------------------------------------------------------------------------------------------------------------------
// GetWidthAndHeightScale
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::GetWidthAndHeightScale(uint32& width, uint32& height) const
{
	InterfacePtr<IPanelControlData> iPanelData(this, UseDefaultIID());

	// get the new scale value
	IControlView* iControlView = iPanelData->FindWidget (kScalePopupWID);
	InterfacePtr<ITextValue> textValue(iControlView, UseDefaultIID());
	flash_export::SizeAndFitSettings settings;
	settings.fSizeSelection = flash_export::kScale;
	settings.fScaleAmount = textValue->GetTextAsValue();

	// calculate the width and height
	Utils<IDynDocsPublicUtils>()->CalculateWidthAndHeightForExport(fWidthHeight.X(), fWidthHeight.Y(), settings, width, height);

}

//--------------------------------------------------------------------------------------------------------------------
// SetWidthAndHeight
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::SetWidthAndHeight(uint32& width, uint32& height) const
{
	bool16 bNotifyOfChange = kFalse;
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IControlView* iView = iPanelData->FindWidget (kWidthPopupWID);
	InterfacePtr<ITextValue> textValueX(iView, UseDefaultIID());
	iView = iPanelData->FindWidget (kHeightPopupWID);
	InterfacePtr<ITextValue> textValueY(iView, UseDefaultIID());
	if (!textValueX || !textValueY)
		return;

	// boundary check
	if (width < kMinSize)
	{
		width = kMinSize;
		bNotifyOfChange = kTrue;
	}
	else if (width > kMaxSize)
	{
		width = kMaxSize;
		bNotifyOfChange = kTrue;
	}

	// set the value into the widget
	textValueX->SetTextFromValue(width, /*invalidate*/ kTrue, bNotifyOfChange);

	// if we notified about a change, get the width and height again
	if (bNotifyOfChange)
	{
		width = ::ToUInt32(textValueX->GetTextAsValue());
		height = ::ToUInt32(textValueY->GetTextAsValue());
	}

	// boundary check
	bNotifyOfChange = kFalse;
	if (height < kMinSize)
	{
		height = kMinSize;
		bNotifyOfChange = kTrue;
	}
	else if (height > kMaxSize)
	{
		height = kMaxSize;
		bNotifyOfChange = kTrue;
	}

	// set the value into the widget
	textValueY->SetTextFromValue(height, /*invalidate*/ kTrue, bNotifyOfChange);

	// if we notified about a change, get the width and height again
	if (bNotifyOfChange)
	{
		width = ::ToUInt32(textValueX->GetTextAsValue());
		height = ::ToUInt32(textValueY->GetTextAsValue());
	}
}

//--------------------------------------------------------------------------------------------------------------------
// SetScale
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::SetScale(uint32 width, uint32 height) const
{
	bool16 bNotifyOfChange = kFalse;
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IControlView* iView = iPanelData->FindWidget (kScalePopupWID);
	InterfacePtr<ITextValue> scaleValue(iView, UseDefaultIID());
	PMReal currentScale = scaleValue->GetTextAsValue();

	PMReal scale = std::min(width / fWidthHeight.X(), height / fWidthHeight.Y());
	scale *= 100;

	// boundary checking
	if (scale < kMinScale)
	{
		scale = kMinScale;
		bNotifyOfChange = kTrue;
	}
	else if (scale > kMaxScale)
	{
		scale = kMaxScale;
		bNotifyOfChange = kTrue;
	}

	// need to compare the rounded values here because of partial 
	// scale values - see Watson 1738333
	if (::Round(scale) != ::Round(currentScale))
		scaleValue->SetTextFromValue(scale, /*invalidate*/ kTrue, bNotifyOfChange);
}

//--------------------------------------------------------------------------------------------------------------------
// UpdatePageAndSpreadSize
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::UpdatePageAndSpreadSize(IDocument* iDocument, bool16 bPageRange)
{
	InterfacePtr<IDialogController> iDialogController(this, UseDefaultIID());
	InterfacePtr<IPageList> iPageList(iDocument, UseDefaultIID());

	UIDList pageUIDList(::GetDataBase(iDocument));

	// handle the page range case
	if (bPageRange)
	{
		InterfacePtr<IPanelControlData>	iPanelData(this, UseDefaultIID());
		IControlView* iControlView = iPanelData->FindWidget (kPagesPageRangeEditWID);
		InterfacePtr<ITextControlData> textData(iControlView, UseDefaultIID());
		PMString pageRangeText(textData->GetString());

		iPageList->PageRangeStringToUIDList(pageRangeText, &pageUIDList);
	}

	// handle the case where the range is invalid, or all pages are selected
	if (pageUIDList.Length() == 0)
	{
		for (int32 pageIndex = 0, pageCount = iPageList->GetPageCount(); pageIndex < pageCount; ++pageIndex)
			pageUIDList.Append(iPageList->GetNthPageUID(pageIndex));
	}

	// calculate the new page and spread sizes based on the uid list
	if (pageUIDList.Length() > 0 && Utils<IDynDocsPublicUtils>().Exists())
	{
		PMReal width, height;

		Utils<IDynDocsPublicUtils>()->CalculateTotalBounds(pageUIDList, true, width, height);
		fSpreadWidthHeight = PMPoint(width, height);

		// if we haven't initialized the selected width and height yet, do so
		if (fSelectedWidthHeight == PMPoint(0,0))
		{
			const UIDList *itemsUIDList(nil);
			InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
			InterfacePtr<IUIDListData> iUIDListData((IUIDListData*)iWidgetParent->QueryParentFor(IID_IUIDLISTDATA));
			if (iUIDListData)
				itemsUIDList = iUIDListData->GetRef();
			if (itemsUIDList && itemsUIDList->size() > 0)
			{
				Utils<IDynDocsPublicUtils>()->CalculateSelectedBounds(*itemsUIDList, width, height);
				fSelectedWidthHeight = PMPoint(width, height);
			}
			else
				fSelectedWidthHeight = fSpreadWidthHeight;
		}
	}

	if (fSelectedWidgetID == kSelection_RadioButtonWidgetID)
		fWidthHeight = fSelectedWidthHeight;
	else
		fWidthHeight = fSpreadWidthHeight;

}

//--------------------------------------------------------------------------------------------------------------------
// UpdateWidthHeightAndScale
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::UpdateWidthHeightAndScale() const
{
	InterfacePtr<IDialogController> iDialogController(this, UseDefaultIID());

	// get width and height based on selections
	uint32 width, height;
	if (iDialogController->GetTriStateControlData(kFitTo_RadioButtonWidgetID) == ITriStateControlData::kSelected)
		GetWidthAndHeightFitTo(width, height);
	else if (iDialogController->GetTriStateControlData(kScale_RadioButtonWidgetID) == ITriStateControlData::kSelected)
		GetWidthAndHeightScale(width, height);
	else
		GetWidthAndHeight(width, height);

	// set the width and height
	SetWidthAndHeight(width, height);

	// set the scale percentage
	SetScale(width, height);
}

//--------------------------------------------------------------------------------------------------------------------
// SetSetting
//--------------------------------------------------------------------------------------------------------------------
void SWFExportGeneralPanelObserver::SetSetting(const WidgetID& wid, bool16 bSetting)
{
	InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
	InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));

	// some initializations...
	flash_export::SizeAndFitSettings sizeFitSettings;
	iData->GetSizeAndFitSettings(sizeFitSettings);

	switch (wid.Get())
	{
		case kGenHTMLCheckboxWID:
			iData->SetGenerateHTML(bSetting);
			break;
		case kViewSWFAfterExportingCheckboxWID:
			iData->SetViewAfterExport(bSetting);
			break;
		case kFitTo_RadioButtonWidgetID:
			sizeFitSettings.fSizeSelection = flash_export::kFitTo;
			iData->SetSizeAndFitSettings(sizeFitSettings);
			break;
		case kScale_RadioButtonWidgetID:
			sizeFitSettings.fSizeSelection = flash_export::kScale;
			iData->SetSizeAndFitSettings(sizeFitSettings);
			break;
		case kWidth_RadioButtonWidgetID:
			sizeFitSettings.fSizeSelection = flash_export::kWidthAndHeight;
			iData->SetSizeAndFitSettings(sizeFitSettings);
			break;
		case kFitToPopupWID:
			sizeFitSettings.fFitToSelection = GetFitToSelection();
			iData->SetSizeAndFitSettings(sizeFitSettings);
			break;
		case kWidthPopupWID:
			sizeFitSettings.fWidthAmount = ::ToUInt32(GetTextValue(wid));
			iData->SetSizeAndFitSettings(sizeFitSettings);
			break;
		case kHeightPopupWID:
			sizeFitSettings.fHeightAmount = ::ToUInt32(GetTextValue(wid));
			iData->SetSizeAndFitSettings(sizeFitSettings);
			break;
		case kScalePopupWID:
			sizeFitSettings.fScaleAmount = GetTextValue(wid);
			iData->SetSizeAndFitSettings(sizeFitSettings);
			break;
		case kTransparent_RadioButtonWidgetID:
			iData->SetHasTransparentBackground(bSetting);
			break;
		case kIncludeAll_RadioButtonWidgetID:
			iData->SetDynamicMediaHandling(bSetting ? flash_export::kIncludeAll : flash_export::kAppearanceOnly);
			break;
		case kPageCurlWidgetID:
			{
				ISWFExportPreferences::BookControlSettings bookControlSettings;
				iData->GetBookControlSettings(bookControlSettings);
				bookControlSettings.fUseBookControl = bSetting;
				iData->SetBookControlSettings(bookControlSettings);
			}
			break;
		default:
			break;
	}
}

//--------------------------------------------------------------------------------------------------------------------
// GetFitToSelection
//--------------------------------------------------------------------------------------------------------------------
flash_export::FitToSelection SWFExportGeneralPanelObserver::GetFitToSelection() const
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IControlView* iControlView = iPanelData->FindWidget (kFitToPopupWID);
	InterfacePtr<IDropDownListController> iListController(iControlView, UseDefaultIID ());
	int32 selected = iListController->GetSelected();
	if (selected == SWFExportGeneralPanelController::k1280x800Index)
		return flash_export::k1280x800;
	else if (selected == SWFExportGeneralPanelController::k1240x620Index)
		return flash_export::k1240x620;
	else if (selected == SWFExportGeneralPanelController::k1024x768Index)
		return flash_export::k1024x768;
	else if (selected == SWFExportGeneralPanelController::k984x588Index)
		return flash_export::k984x588;
	else if (selected == SWFExportGeneralPanelController::k800x600Index)
		return flash_export::k800x600;
	else if (selected == SWFExportGeneralPanelController::k760x420Index)
		return flash_export::k760x420;
	else if (selected == SWFExportGeneralPanelController::k640x480Index)
		return flash_export::k640x480;
	else // if (selected == SWFExportGeneralPanelController::k600x300Index)
		return flash_export::k600x300;

}

//--------------------------------------------------------------------------------------------------------------------
// GetTextValue
//--------------------------------------------------------------------------------------------------------------------
PMReal SWFExportGeneralPanelObserver::GetTextValue(const WidgetID& wid) const
{
	InterfacePtr<IPanelControlData> iPanelData (this, UseDefaultIID());
	IControlView* iControlView = iPanelData->FindWidget (wid);
	if (!iControlView) return PMReal();
	InterfacePtr<ITextValue> textValue(iControlView, UseDefaultIID());
	if (!textValue) return PMReal();
	return textValue->GetTextAsValue();
}
