//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/framelabel/FrmLblResponder.cpp $
//  
//  Owner: Adobe Developer Technologies
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

// Interface includes:
#include "isignalmgr.h"
#include "IDocumentSignalData.h"
#include "INewPISignalData.h"
#include "IDocument.h"
#include "IWorkspace.h"
#include "iuicolorutils.h"

// General  includes:
#include "CResponder.h"
#include "Trace.h"
#include "UIDList.h"
#include "ShuksanID.h"
#include "Utils.h"

// project includes:
#include "FrmLblID.h"
#include "IFrmLblData.h"
#include "IFrmLblDataFacade.h"
#include "FrmLblType.h"

/** Implements a responder, IResponder based on CResponder, that sets up default IFrmLblData
	when a new document is created, and when a new page item is created.

	
	@ingroup framelabel
*/
class FrmlLblResponder : public CResponder
{
	public:
		/** Constructor.
			@param boss object this object is aggregated on.
		*/
		FrmlLblResponder(IPMUnknown* boss);

		/** Destructor.
		 */
		virtual ~FrmlLblResponder() {}

		/** Sets up default IFrmLblData.
			On receiving a new document signal the application default
			IFrmLblData is copied into the document default. On receiving
			a new page item signal the document default IFrmLblData is 
			copied into the page item.
			@param signalMgr provides information about the signal.
		 */
		virtual void Respond(ISignalMgr* signalMgr);

	private:
		/** Copies document default IFrmLblData from kDocWorkspaceBoss
			into the new page item.
			@param signalMgr provides information about the signal.
		 */
		void HandleNewPISignal(ISignalMgr* signalMgr);

		/** Copies default IFrmLblData from kWorkspaceBoss
			into the new document, kDocWorkspaceBoss.
			@param signalMgr provides information about the signal.
		 */
		void HandleNewDocSignal(ISignalMgr* signalMgr);

};

/* Makes the implementation available to the application.
*/
CREATE_PMINTERFACE(FrmlLblResponder, kFrmLblResponderImpl)

/*
*/
FrmlLblResponder::FrmlLblResponder(IPMUnknown* boss) :
	CResponder(boss)
{
}

/*
*/
void FrmlLblResponder::Respond(ISignalMgr* signalMgr)
{
//	TRACEFLOW(kFrmLblPluginName, "FrmlLblResponder::Respond()-->In\n");
	do {
		const ServiceID serviceID = signalMgr->GetServiceID();
		if (serviceID == kNewPISignalResponderService) {
			this->HandleNewPISignal(signalMgr);
		}
		else if(serviceID == kAfterNewDocSignalResponderService) {
			this->HandleNewDocSignal(signalMgr);
		}
		else {
			ASSERT_FAIL("FrmlLblResponder::Respond called with invalid signal");
		}
	} while(false);
//	TRACEFLOW(kFrmLblPluginName, "FrmlLblResponder::Respond()-->Out\n");
}

/*
*/
void FrmlLblResponder::HandleNewPISignal(ISignalMgr* signalMgr)
{
//	TRACEFLOW(kFrmLblPluginName, "FrmLblResponder::Respond()-->In\n");
	do {
		// Get a reference to the page item from the signal.
		ASSERT(signalMgr != nil);
		if (signalMgr == nil) {
			break;
		}

		InterfacePtr<INewPISignalData> newPISignalData(signalMgr, UseDefaultIID());
		ASSERT(newPISignalData != nil);
		if (newPISignalData == nil) {
			break;
		}

		// Check the page item has IFrmLblData.
		UIDRef pageItemRef = newPISignalData->GetPageItem();
		InterfacePtr<IFrmLblData> frmLblData(pageItemRef, UseDefaultIID());
		if (frmLblData == nil) {
			break;
		}

		IDataBase* database = pageItemRef.GetDataBase();
		UID rootUID = database->GetRootUID();
		InterfacePtr<IDocument> document(database, rootUID, UseDefaultIID());
		ASSERT(document);
		if (!document) {
			break;
		}
		InterfacePtr<IFrmLblData> defaultFrmLblData(document->GetDocWorkSpace(), UseDefaultIID());
		if (!defaultFrmLblData) {
			break;
		}

		// Get the document's default IFrmLblData.
		FrmLblInfo defaultData = defaultFrmLblData->Get();

		FrmLblInfo itemData;
		if(Utils<IFrmLblDataFacade>()->GetFrameLabelProperties(pageItemRef, itemData) != kSuccess)
		{
			break;
		}

		if(itemData.label.empty() && (itemData.label != defaultData.label))
		{
			Utils<IFrmLblDataFacade>()->UpdateFrameLabelProperties(pageItemRef, defaultData);
		}

	} while(false);
//	TRACEFLOW(kFrmLblPluginName, "FrmLblResponder::HandleNewPISignal()-->Out\n");
}

void FrmlLblResponder::HandleNewDocSignal(ISignalMgr* signalMgr)
{
	do {
		// Get reference to the document from the signal.
		InterfacePtr<IDocumentSignalData> documentSignalData(signalMgr, UseDefaultIID());
		ASSERT(documentSignalData != nil);
		if (documentSignalData == nil) {
			break;
		}
		InterfacePtr<IDocument> document(documentSignalData->GetDocument(), UseDefaultIID());
		if (!document) {
			break;
		}

		// Get the application defaults.
		InterfacePtr<IWorkspace> workspace(GetExecutionContextSession()->QueryWorkspace());
		if (!workspace) {
			break;
		}
		InterfacePtr<IFrmLblData> appDefaultFrmLblData(workspace, UseDefaultIID());
		ASSERT(appDefaultFrmLblData);
		if (!appDefaultFrmLblData) {
			break;
		}

		FrmLblInfo appDefaultData = appDefaultFrmLblData->Get();
		int32 colorIndex = Utils<IUIColorUtils>()->GetUIColorIndex(appDefaultData.fontColor, nil);
		appDefaultData.fontColor = (colorIndex >= 0) ? Utils<IUIColorUtils>()->GetUIColor(colorIndex, document).GetUID() : kInvalidUID;
		Utils<IFrmLblDataFacade>()->SetFrameLabelPreference(document->GetDocWorkSpace(), appDefaultData);

	} while(false);
}


