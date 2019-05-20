//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFExportDlgObserver.cpp $
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
//  ADOBE CONFIDENTIAL
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
#include "CSelectableDialogObserver.h"

// ----- Interface files -----

#include "IBoolData.h"
#include "IControlView.h"
#include "IDialogController.h"
#include "IDocument.h"
#include "IDocumentFontUsage.h"
#include "IFontFamily.h"
#include "ILayoutUIUtils.h"
#include "IListBoxAttributes.h"
#include "IListBoxController.h"
#include "IPanelControlData.h"
#include "IPMFont.h"
#include "ISelectableDialogSwitcher.h"
#include "ISubject.h"
#include "ITextControlData.h"
#include "IURLAccess.h"
#include "IViewListBoxControlData.h"

// ----- ID files -----

#include "AboutBoxID.h"
#include "CoreResTypes.h" 
#include "DynamicDocumentsUIID.h"
#include "FontUsageDialogID.h"
#include "FontUsageDefs.h"
#include "HyperlinkID.h" 
#include "LocaleSetting.h"
#include "RsrcSpec.h"
#include "IconRsrcDefs.h"


//====================================================================================================================
// Class SWFExportDlgObserver
//====================================================================================================================
class SWFExportDlgObserver : public CSelectableDialogObserver
{
	typedef	CSelectableDialogObserver Inherited;

public:
	SWFExportDlgObserver(IPMUnknown* boss);
	virtual ~SWFExportDlgObserver();
					
	virtual void Update(const ClassID& theChange, ISubject* theSubject, const PMIID &protocol, void* changedBy);

	virtual void AutoAttach();
	virtual void AutoDetach();

protected: 
    void RebuildFontList();
	void SetFontInfo();
    void SetWidgetText(WidgetID whichWidget,const PMString& newText); 
	IControlView* CreateInitFontWidget(const PMString& fontString, bool16 isMissing, bool16 isGraphic,PMReal listboxWidth, IPMFont::FontType fontType, bool16 isTKDFont, bool16 isSVGFont);

	void DoFontInfoButton();
 };


CREATE_PMINTERFACE(SWFExportDlgObserver, kSWFExportDlgObserverImpl)

SWFExportDlgObserver::SWFExportDlgObserver(IPMUnknown* boss)
	: Inherited (boss)
{
}

SWFExportDlgObserver::~SWFExportDlgObserver(void)
{
}

//--------------------------------------------------------------------------------------------------------------------
// Update
//--------------------------------------------------------------------------------------------------------------------
void SWFExportDlgObserver::Update(const ClassID& theChange, ISubject* theSubject, const PMIID &protocol, void* changedBy)
{
	if (theChange == kListSelectionChangedByUserMessage || theChange == kListSelectionChangedMessage)
	{
		SetFontInfo();
		return;
	}
    else if (protocol == IID_IBOOLEANCONTROLDATA && theChange == kTrueStateMessage) 
    {                 
        InterfacePtr<IControlView> view(theSubject, IID_ICONTROLVIEW); 
        if (view && view->GetWidgetID() == kFontInfoWidgetID) 
        { 
            DoFontInfoButton();
			return;
        }
	}

	Inherited::Update(theChange, theSubject, protocol, changedBy);
	
	InterfacePtr<IControlView> view(theSubject, UseDefaultIID());
	
	if (view)
	{
		InterfacePtr<ISelectableDialogSwitcher>switcher(this, UseDefaultIID());
		ASSERT(switcher);

		// since we use preferences on the dialog as backing storage, and since
		// settings in one panel can affect settings in the other panel, we need
		// to ensure the panel we are switching to is initialized each time...
		WidgetID widgetID = view->GetWidgetID();
		if ((widgetID == switcher->GetSelectionListWidgetID()) &&
			(theChange == kSelectedTabChangedMessage))
		{
	        WidgetID widPanel = switcher->GetPanelWidgetID(switcher->GetCurrentPanelIndex());
			IControlView* viewPanel = switcher->GetDialogPanel(widPanel);
			InterfacePtr<IDialogController> ctlPanel( viewPanel, IID_IDIALOGCONTROLLER );
			if ( ctlPanel )
				ctlPanel->InitializeDialog(GetExecutionContextSession()->GetActiveContext());
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------
// AutoAttach
//--------------------------------------------------------------------------------------------------------------------
void SWFExportDlgObserver::AutoAttach()
{
	Inherited::AutoAttach();
	
	RebuildFontList();
	SetFontInfo();

	// attach to the General and Advanced panels, so we are notified when panels change
	InterfacePtr<IPanelControlData> panelData(this, UseDefaultIID());
	if (!panelData)
		return;

	InterfacePtr<ISubject> subject(panelData->FindWidget(kSWFExportGeneralParentWidgetId), IID_ISUBJECT);
	if (subject)
		subject->AttachObserver(this, IID_IBOOLEANCONTROLDATA);
	subject = InterfacePtr<ISubject>(panelData->FindWidget(kSWFExportAdvancedParentWidgetId), IID_ISUBJECT);
	if (subject)
		subject->AttachObserver(this, IID_IBOOLEANCONTROLDATA);

	IControlView *listboxWidget = panelData->FindWidget(kEmbeddedFontsListBoxWidgetID);
	InterfacePtr<ISubject> listSubject(listboxWidget, IID_ISUBJECT);
	if (listSubject != nil)
		listSubject->AttachObserver(this, IID_ILISTCONTROLDATA, IID_IOBSERVER);

    IControlView *showFileButtonWidget = panelData->FindWidget(kFontInfoWidgetID); 
    InterfacePtr<ISubject> showFileButtonSubject(showFileButtonWidget, IID_ISUBJECT); 
    if (showFileButtonSubject) 
            showFileButtonSubject->AttachObserver(this, IID_IBOOLEANCONTROLDATA); 
}

//--------------------------------------------------------------------------------------------------------------------
// AutoDetach
//--------------------------------------------------------------------------------------------------------------------
void SWFExportDlgObserver::AutoDetach()
{
	InterfacePtr<IPanelControlData> panelData(this, UseDefaultIID());
	if (panelData)
	{	
		InterfacePtr<ISubject> subject(panelData->FindWidget(kSWFExportGeneralParentWidgetId), IID_ISUBJECT);
		if (subject)
			subject->DetachObserver(this, IID_IBOOLEANCONTROLDATA);
		subject = InterfacePtr<ISubject>(panelData->FindWidget(kSWFExportAdvancedParentWidgetId), IID_ISUBJECT);
		if (subject)
			subject->DetachObserver(this, IID_IBOOLEANCONTROLDATA);

		IControlView *listboxWidget = panelData->FindWidget(kEmbeddedFontsListBoxWidgetID);
		InterfacePtr<ISubject> listSubject(listboxWidget, IID_ISUBJECT);
		if (listSubject != nil)
			listSubject->DetachObserver(this, IID_ILISTCONTROLDATA, IID_IOBSERVER);

		IControlView *showFileButtonWidget = panelData->FindWidget(kFontInfoWidgetID); 
		InterfacePtr<ISubject> showFileButtonSubject(showFileButtonWidget, IID_ISUBJECT); 
		if (showFileButtonSubject) 
				showFileButtonSubject->DetachObserver(this, IID_IBOOLEANCONTROLDATA); 

	}	
	

	Inherited::AutoDetach();
}


void SWFExportDlgObserver::RebuildFontList()
{
	//find all the fonts used in the document.
	IDocument *doc = Utils<ILayoutUIUtils>()->GetFrontDocument();
	IDataBase *dataBase = ::GetDataBase( doc );
	
	InterfacePtr<IDocumentFontUsage> docFonts(doc,UseDefaultIID());
	docFonts->UpdateFontList();
	
	InterfacePtr <IFontMgr>		fontMgr (doc?
										static_cast <IPMUnknown const *> (doc):
										static_cast <IPMUnknown const *> (GetExecutionContextSession()),
									UseDefaultIID());

	InterfacePtr<IPanelControlData> dialogPanelData(this,UseDefaultIID());
	IControlView *listboxWidget = dialogPanelData->FindWidget(kEmbeddedFontsListBoxWidgetID);

	InterfacePtr< IViewListBoxControlData > listData(listboxWidget,IID_ILISTCONTROLDATA);
	InterfacePtr<IListBoxController> listCntl( listData, IID_ILISTBOXCONTROLLER );
	
	// wipe out the current contents of the listbox.
	listData->Clear(kFalse,kFalse);
	listCntl->Deselect(); // make the notify happen(has to be after Clear() so when the notify happens there isn't a selection)
	
	InterfacePtr<IListBoxAttributes> listAttr(listboxWidget, IID_ILISTBOXATTRIBUTES);
	PMReal listboxWidth = listboxWidget->GetFrame().Width() - listAttr->GetVerticalScrollBarWidth();
	
	for(int32 j = 0; j < docFonts->GetNumUsedFonts(); j++)
	{
		PMString fontString = docFonts->GetNthUsedFontString(j);
		fontString.SetTranslatable(kFalse);

		InterfacePtr<IFontFamily> fontFamily( dataBase, docFonts->GetNthUsedFontUID(j),UseDefaultIID());
		IPMFont::FontType fontType = fontFamily->GetFontType(docFonts->GetNthUsedFontFaceString(j));
		InterfacePtr<IPMFont> font(fontFamily->QueryFace(docFonts->GetNthUsedFontFaceString(j)));
		bool16 isTKDFont = font && font->IsTypekitDesktopFont();
		bool16 isSVGFont = font && font->IsColorFont();

		InterfacePtr<IControlView> fontView(CreateInitFontWidget(fontString,kFalse,kFalse,listboxWidth,fontType, isTKDFont, isSVGFont));
		listData->Add(fontView, IViewListBoxControlData::kEnd, kFalse, kFalse);	
	}

	listData->Refresh();

	PMString fontInfo("Total Fonts:  ", PMString::kTranslateDuringCall);
	fontInfo.AppendNumber(listData->Length());
	fontInfo.SetTranslated();
	SetWidgetText(kTotalEmbeddedFontsWidgetID,fontInfo);
}


void SWFExportDlgObserver::SetFontInfo()
{
	InterfacePtr<IPanelControlData> panelData(this,UseDefaultIID());
	IControlView *fontListboxWidget = panelData->FindWidget(kEmbeddedFontsListBoxWidgetID);
	InterfacePtr<IListBoxController> listCntl(fontListboxWidget,IID_ILISTBOXCONTROLLER);	
	IControlView *fontInfoButton = panelData->FindWidget(kFontInfoWidgetID);
	
	K2Vector<int32> selectionList;
	listCntl->GetSelected(selectionList);
	// we don't want to show any info if there is no selection, multiple selection, and we don't want to waste time
	// figuring out what to show if the panel isn't showing.
	if(selectionList.size() == 1) 
	{
		int32 usedFontIndex = selectionList[0];

		InterfacePtr<IDocumentFontUsage> docFonts(Utils<ILayoutUIUtils>()->GetFrontDocument(),UseDefaultIID());
	
		PMString fontInfo("kEmbeddedFontName", PMString::kTranslateDuringCall);
		fontInfo.Append(docFonts->GetNthUsedFontString(usedFontIndex));

		InterfacePtr<IFontFamily> fontFamily(::GetDataBase(Utils<ILayoutUIUtils>()->GetFrontDocument()),docFonts->GetNthUsedFontUID(usedFontIndex),UseDefaultIID());		
		if(fontFamily)
		{
			PMString const &	faceString (docFonts->GetNthUsedFontFaceString (usedFontIndex));
			InterfacePtr<IPMFont> font(fontFamily->QueryFace(faceString));
			if (font)
			{
				fontInfo.Append(PMString(L"\n"));
				fontInfo.Append(PMString ("kEmbeddedVendorID", PMString::kTranslateDuringCall));
				font->AppendVendorID(fontInfo);
				fontInfo.Append(PMString(L"\n"));
				font->AppendCopyrightString(fontInfo);
				fontInfo.Append(PMString(L"\n"));
				font->AppendLicenseInfoURL(fontInfo);
			}
		}
 
		SetWidgetText(kEmbeddedFontDescWidgetID,fontInfo);
		fontInfoButton->Enable(kTrue);
	}
	else
	{
		SetWidgetText(kEmbeddedFontDescWidgetID, kNullString);
		//disable font info button
		fontInfoButton->Enable(kFalse);
	}
}


void SWFExportDlgObserver::SetWidgetText(WidgetID whichWidget,const PMString & newText)
{
	InterfacePtr<IPanelControlData> panelData(this,UseDefaultIID());
	IControlView *widget = panelData->FindWidget(whichWidget);
	InterfacePtr<ITextControlData> widgetText(widget,UseDefaultIID());
	widgetText->SetString(newText);
}


IControlView* SWFExportDlgObserver::CreateInitFontWidget( const PMString& fontString, bool16 isMissing, bool16 isGraphic,PMReal listboxWidth, IPMFont::FontType fontType, bool16 isTKDFont, bool16 isSVGFont )
{
	IControlView * fontPanelView = static_cast<IControlView *>(::CreateObject ( 
									::GetDataBase(this), 
									RsrcSpec ( 
										LocaleSetting::GetLocale(), 
										kFontUsageDialogPluginID, 
										kViewRsrcType, 
										kFontUsedListElementRsrcID), 
										IID_ICONTROLVIEW)); 

    InterfacePtr<IPanelControlData> panelData(fontPanelView,UseDefaultIID()); 
    IControlView* labelView = panelData->FindWidget(kFontUsageFontStringWidgetID); 
	InterfacePtr<ITextControlData> textData(labelView,UseDefaultIID()); 
	textData->SetString(fontString);

	PMRect rightIconFrame (listboxWidth-20.0, 1.0, listboxWidth-4.0,  17.0);
	PMRect graphicIconFrame(listboxWidth-40.0, 1.0, listboxWidth-24.0, 17.0);
	PMRect missingIconFrame(listboxWidth-40.0 - isGraphic*18.0, 1.0, listboxWidth-24 - isGraphic*18.0, 17.0);
	// if the font is missing, add the missing icon
	if(isMissing)
	{
	    IControlView* missingView = panelData->FindWidget(kFontUsageMissingFontIconWidgetID); 
		missingView->Init(kFontUsageMissingFontIconWidgetID, missingIconFrame, kFontUsageMissingIconRsrcID);
		missingView->ShowView();
	}

	// if the font is in a graphic, add the graphic icon
	if(isGraphic)
	{
	    IControlView* graphicView = panelData->FindWidget(kFontUsageGraphicFontIconWidgetID); 
		graphicView->Init(kFontUsageGraphicFontIconWidgetID, graphicIconFrame, kFontUsageGraphicIconRsrcID);
		graphicView->ShowView();
	}
	
	// set the icon for the font technology.
	RsrcID fontTypeRsrcID =  0;
	WidgetID fontTypeWidgetID =  0;
	

	if (isSVGFont)
	{
		fontTypeRsrcID = kSVGFontIconRsrcID;
		fontTypeWidgetID = kFontUsageSVGFontIconWidgetID;
	}

	else if(isTKDFont)
	{
		fontTypeRsrcID =  kTypekitGreenMediumIconRsrcID;
		fontTypeWidgetID =  kFontUsageTypekitFontIconWidgetID;
	}
	else
	{
		switch(fontType)
		{
			case IPMFont::kOpenTypeCFFFontType: // a roman encoded, Opentype Adobe Type1 font
			case IPMFont::kOpenTypeTTFontType:	// a OpenType TrueType font
			case IPMFont::kOpenTypeCIDFontType:	// a OpenType CID-Keyed font
			{
				fontTypeRsrcID =  kOpenTypeFontIconRsrcID;
				fontTypeWidgetID =  kFontUsageOpenTypeFontIconWidgetID;
			}
			break;
			case IPMFont::kTrueTypeFontType:	// a TrueType font
			{
				fontTypeRsrcID =  kTrueTypeFontIconRsrcID;
				fontTypeWidgetID =  kFontUsageTrueTypeFontIconWidgetID;
			}
			break;
			case IPMFont::kType1FontType:		// a roman encoded, Adobe Type1 font
			{
				fontTypeRsrcID =  kType1FontIconRsrcID;
				fontTypeWidgetID =  kFontUsageType1FontIconWidgetID;
			}
			break;
			case IPMFont::kATCFontType:		// an Adobe Type Composer font (Rearranged CID font)
			{
				fontTypeRsrcID =  kATCFontIconRsrcID;
				fontTypeWidgetID =  kFontUsageATCFontIconWidgetID;
			}
			break;
			case IPMFont::kOCFFontType:		// an OCF font
			{
				fontTypeRsrcID =  kOCFFontIconRsrcID;
				fontTypeWidgetID =  kFontUsageOCFFontIconWidgetID;
			}
			break;
			case IPMFont::kCIDFontType:		// a non OTF CID font
			{
				fontTypeRsrcID =  kCIDFontIconRsrcID;
				fontTypeWidgetID =  kFontUsageCIDFontIconWidgetID;
			}
			break;
			case IPMFont::kUnknownFontType:
			break;//leave values invalid so no icon is drawn

			default:
			ASSERT_FAIL("Unknown font type");
			break;
		
		}
	}

	// only add the widget if we have an icon.
	if(fontTypeRsrcID && fontTypeWidgetID.IsValid())
	{
	    IControlView* typeView = panelData->FindWidget(kFontUsageOpenTypeFontIconWidgetID); 
		typeView->Init(fontTypeWidgetID, rightIconFrame, fontTypeRsrcID);
		typeView->ShowView();
	}

	return fontPanelView;
}

void SWFExportDlgObserver::DoFontInfoButton()
{
	InterfacePtr<IPanelControlData> panelData(this,UseDefaultIID());
	IControlView *fontListboxWidget = panelData->FindWidget(kEmbeddedFontsListBoxWidgetID);
	InterfacePtr<IListBoxController> listCntl(fontListboxWidget,IID_ILISTBOXCONTROLLER);
	
	K2Vector<int32> selectionList;
	listCntl->GetSelected(selectionList);

	//nothing to do. should not even be enabled
	if (selectionList.size() < 1)
		return;

	InterfacePtr<IDocumentFontUsage> docFonts(Utils<ILayoutUIUtils>()->GetFrontDocument(),UseDefaultIID());
	int32 usedFontIndex = selectionList[0];
	InterfacePtr<IFontFamily> fontFamily(::GetDataBase(Utils<ILayoutUIUtils>()->GetFrontDocument()),docFonts->GetNthUsedFontUID(usedFontIndex),UseDefaultIID());		
	if(!fontFamily)
		return;
	PMString const &	faceString (docFonts->GetNthUsedFontFaceString (usedFontIndex));
	InterfacePtr<IPMFont> font(fontFamily->QueryFace(faceString));

    PMString url (L"http://www.adobe.com/go/font_vendor_id");

	if (font)
	{
		url.Append(PMString(L"?"));

		//add fullname
		url.Append(PMString(L"Name="));
		font->AppendFullName(url);

		//add postscriptname
		url.Append(PMString(L"&PSName="));
		font->AppendFontName(url);

		//add vendor id
		PMString vendorID;
		if (font->AppendVendorID(vendorID) && !vendorID.empty())
		{
			vendorID.StripWhiteSpace(PMString::kTrailingWhiteSpace);
			url.Append(PMString(L"&ID="));
			url.Append(vendorID);
		}
	}

	InterfacePtr<IURLAccess> urlAccess(GetExecutionContextSession(), IID_IURLACCESS); 
    if (urlAccess) 
        urlAccess->GoToURL(&url); 

}
