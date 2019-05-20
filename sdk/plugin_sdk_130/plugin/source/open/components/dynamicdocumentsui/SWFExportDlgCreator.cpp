//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFExportDlgCreator.cpp $
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

// ----- Interface files -----

#include "IApplication.h"
#include "IDialogMgr.h"

// ----- Includes files -----

#include "CDialogCreator.h"
#include "cpanelcreator.h"
#include "DynamicDocumentsUIDefs.h"
#include "CoreResTypes.h"        // for kViewRsrcType
#include "LocaleSetting.h"
#include "RsrcSpec.h"

// ----- ID files -----

#include "DynamicDocumentsUIID.h"

//====================================================================================================================
// Class SWFExportDlgCreatorImpl
//====================================================================================================================
class SWFExportDlgCreatorImpl : public CDialogCreator
{
	typedef CDialogCreator Inherited;

	public:
		SWFExportDlgCreatorImpl(IPMUnknown *boss);
		virtual    ~SWFExportDlgCreatorImpl();

		IDialog*        CreateDialog();
		void            GetOrderedPanelIDs(K2Vector<ClassID>& classIDs);
		RsrcID          GetOrderedPanelsRsrcID() const;
};

CREATE_PMINTERFACE(SWFExportDlgCreatorImpl, kSWFExportDlgCreatorImpl)

SWFExportDlgCreatorImpl::SWFExportDlgCreatorImpl(IPMUnknown *boss) :
    Inherited(boss)
{
}

SWFExportDlgCreatorImpl::~SWFExportDlgCreatorImpl()
{
}

//--------------------------------------------------------------------------------------------------------------------
// CreateDialog
//--------------------------------------------------------------------------------------------------------------------
IDialog* SWFExportDlgCreatorImpl::CreateDialog()
{
    InterfacePtr<IApplication> iApp(GetExecutionContextSession()->QueryApplication());
    InterfacePtr<IDialogMgr> iDialogMgr(iApp, IID_IDIALOGMGR);

    // The dialog manager caches the dialog for us
    const PMLocaleId nLocale = LocaleSetting::GetLocale();
    const RsrcSpec aSpec(nLocale, kDynamicDocumentsUIPluginID, kViewRsrcType,  kSWFExportDialogRsrcID, kTrue);
    IDialog *dialog = iDialogMgr->CreateNewDialog(aSpec, IDialog::kMovableModal);

    return dialog;
}

//--------------------------------------------------------------------------------------------------------------------
// GetOrderedPanelIDs
//--------------------------------------------------------------------------------------------------------------------
void SWFExportDlgCreatorImpl::GetOrderedPanelIDs(K2Vector<ClassID>& classIDs)
{
    Inherited::GetOrderedPanelIDs(classIDs);
}

//--------------------------------------------------------------------------------------------------------------------
// GetOrderedPanelsRsrcID
//--------------------------------------------------------------------------------------------------------------------
RsrcID SWFExportDlgCreatorImpl::GetOrderedPanelsRsrcID() const
{
    return kSWFExportDialogOrderingRsrcID;
}

//====================================================================================================================
// Class SWFExportGeneralPanelCreator
//====================================================================================================================
class SWFExportGeneralPanelCreator : public CPanelCreator
{
	public:
		SWFExportGeneralPanelCreator(IPMUnknown *boss) : CPanelCreator(boss) { }
		virtual	~SWFExportGeneralPanelCreator() { }
		
		virtual	RsrcID		GetPanelRsrcID() const { return kSWFExportGeneralPanelCreatorRsrcID; }
};

CREATE_PMINTERFACE(SWFExportGeneralPanelCreator, kSWFExportGeneralPanelCreatorImpl)

//====================================================================================================================
// Class SWFExportAdvancedPanelCreator
//====================================================================================================================
class SWFExportAdvancedPanelCreator : public CPanelCreator
{
	public:
		SWFExportAdvancedPanelCreator(IPMUnknown *boss) : CPanelCreator(boss) { }
		virtual	~SWFExportAdvancedPanelCreator() { }
		
		virtual	RsrcID		GetPanelRsrcID() const { return kSWFExportAdvancedPanelCreatorRsrcID; }
};

CREATE_PMINTERFACE(SWFExportAdvancedPanelCreator, kSWFExportAdvancedPanelCreatorImpl)

