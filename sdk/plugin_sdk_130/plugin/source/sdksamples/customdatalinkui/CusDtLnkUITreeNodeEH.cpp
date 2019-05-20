//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/customdatalinkui/CusDtLnkUITreeNodeEH.cpp $
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

// Interfaces
#include "ITreeNodeIDData.h"
#include "ILayoutUIUtils.h"
#include "IDocument.h"
#include "ICusDtLnkFacade.h"
#include "ITreeViewMgr.h"
#include "IControlView.h"
#include "IPanelControlData.h"
#include "IWidgetParent.h"
#include "ICusDtLnkUITreeDataModel.h"
#include "IDialogController.h"
// General includes:

#include "Utils.h"
#include "CEventHandler.h"
#include "CAlert.h"
#include "SDKFileHelper.h"
// Project includes:
#include "CusDtLnkUIID.h"
#include "CusDtLnkUIFileNodeID.h"
#include "CusDtLnkUITreeDataNode.h"
//#include "CusDtLnkUITreeUtils.h"

/** 
	Implements IEventHandler; allows this plug-in's code 
	to catch the double-click events without needing 
	access to the implementation headers.

	
	@ingroup customdatalinkui
*/

class CusDtLnkUITreeNodeEH : public CEventHandler
{
public:

	/** Constructor.
		@param boss interface ptr on the boss object to which the interface implemented here belongs.
	*/	
	CusDtLnkUITreeNodeEH(IPMUnknown* boss);
	
	/** Destructor
	*/	
	virtual ~CusDtLnkUITreeNodeEH(){}

	/**  Window has been activated. Traditional response is to
		activate the controls in the window.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 Activate(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->Activate(e);  return retval; }
		
	/** Window has been deactivated. Traditional response is to
		deactivate the controls in the window.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 Deactivate(IEvent* e) 
	{ bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->Deactivate(e);  return retval; }
	
	/** Application has been suspended. Control is passed to
		another application. 
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 Suspend(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->Suspend(e);  return retval; }
	
	/** Application has been resumed. Control is passed back to the
		application from another application.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 Resume(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->Resume(e);  return retval; }
		
	/** Mouse has moved outside the sensitive region.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 MouseMove(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->MouseMove(e);  return retval; } 
		 
	/** User is holding down the mouse button and dragging the mouse.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 MouseDrag(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->MouseDrag(e);  return retval; }
		 
	/** Left mouse button (or only mouse button) has been pressed.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/ 
	virtual bool16 LButtonDn(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->LButtonDn(e);  return retval; }
		 
	/** Right mouse button (or second button) has been pressed.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 RButtonDn(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->RButtonDn(e);  return retval; }
		 
	/** Middle mouse button of a 3 button mouse has been pressed.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 MButtonDn(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->MButtonDn(e);  return retval; }
		
	/** Left mouse button released.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 LButtonUp(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->LButtonUp(e);  return retval; } 
		 
	/** Right mouse button released.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 RButtonUp(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->RButtonUp(e);  return retval; } 
		 
	/** Middle mouse button released.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 MButtonUp(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->MButtonUp(e);  return retval; } 
		 
	/** Double click with any button; this is the only event that we're interested in here-
		on this event we load the placegun with an asset if it can be imported.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 ButtonDblClk(IEvent* e);
	/** Triple click with any button.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 ButtonTrplClk(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->ButtonTrplClk(e);  return retval; }
		 
	/** Quadruple click with any button.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 ButtonQuadClk(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->ButtonQuadClk(e);  return retval; }
		 
	/** Quintuple click with any button.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 ButtonQuintClk(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->ButtonQuintClk(e);  return retval; }
		 
	/** mouse scroll wheel
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 MouseWheel(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->MouseWheel(e);  return retval; }
		 
	/** Event for a particular control. Used only on Windows.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 ControlCmd(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->ControlCmd(e);  return retval; } 
		
		
	// Keyboard Related Events
	
	/** Keyboard key down for every key.  Normally you want to override KeyCmd, rather than KeyDown.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 KeyDown(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->KeyDown(e);  return retval; }
		 
	/** Keyboard key down that generates a character.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 KeyCmd(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->KeyCmd(e);  return retval; }
		
	/** Keyboard key released.
		@param e [IN] event of interest
		@return kTrue if event has been handled and should not be further dispatched, kFalse otherwise (pass event to next handler)
	*/
	virtual bool16 KeyUp(IEvent* e) { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->KeyUp(e);  return retval; }
		 
	
	// Keyboard Focus Related Functions
	
	/** Called before getting focus onto the associated widget/window
		@param none
		@return none
	 */	
	virtual void PreGetKeyFocus() { InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER); delegate->PreGetKeyFocus(); }
	
	/** Called before giving up focus onto the associated widget/window
		@param none
		@return none
	 */
	virtual void PreGiveUpKeyFocus() { InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  delegate->PreGiveUpKeyFocus(); }
		
	/** Typically called before GiveUpKeyFocus() is called. Return kFalse
		to hold onto the keyboard focus.
		@return kFalse to hold onto the keyboard focus
	*/
	virtual bool16 WillingToGiveUpKeyFocus() { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->WillingToGiveUpKeyFocus();  return retval; }
		 
	/** The keyboard is temporarily being taken away. Remember enough state
		to resume where you left off. 
		@return kTrue if you really suspended
		yourself. If you simply gave up the keyboard, return kFalse.
	*/
	virtual bool16 SuspendKeyFocus() { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->SuspendKeyFocus();  return retval; }
		 
	/** The keyboard has been handed back. 
		@return kTrue if you resumed yourself. Otherwise, return kFalse.
	*/
	virtual bool16 ResumeKeyFocus() { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->ResumeKeyFocus();  return retval; }
		 
	/** Determine if this eventhandler can be focus of keyboard event 
		@return kTrue if this eventhandler supports being the focus
		of keyboard event
	*/
	virtual bool16 CanHaveKeyFocus() const { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->CanHaveKeyFocus();  return retval; }
		 
	/** Return kTrue if this event handler wants to get keyboard focus
		while tabbing through widgets. Note: For almost all event handlers
		CanHaveKeyFocus and WantsTabKeyFocus will return the same value.
		If WantsTabKeyFocus returns kTrue then CanHaveKeyFocus should also return kTrue
		for the event handler to actually get keyboard focus. If WantsTabKeyFocus returns
		kFalse then the event handler is skipped.
		@return kTrue if event handler wants to get focus during tabbing, kFalse otherwise
	*/
	virtual bool16 WantsTabKeyFocus() const { bool16 retval; InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  retval =  delegate->WantsTabKeyFocus();  return retval; }
		 		 
	/** Temporary.
	*/
	virtual void SetView(IControlView* view)
	{  
		InterfacePtr<IEventHandler> 
			delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER); 
		delegate->SetView(view);  
	}
};

/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its ImplementationID 
 making the C++ code callable by the application.
*/
CREATE_PMINTERFACE( CusDtLnkUITreeNodeEH, kCusDtLnkUITreeNodeEHImpl)

	
CusDtLnkUITreeNodeEH::CusDtLnkUITreeNodeEH(IPMUnknown* boss) :
	CEventHandler(boss)
{

}

bool16 CusDtLnkUITreeNodeEH::ButtonDblClk(IEvent* e) 
{
	do {
		InterfacePtr<IWidgetParent> widgetParent(this, UseDefaultIID());
		ASSERT(widgetParent);
		if(!widgetParent) {
			break;
		}
	
		InterfacePtr<IDialogController> dialogCon(static_cast<IDialogController*>(
			widgetParent->QueryParentFor(IDialogController::kDefaultIID)));
		if(dialogCon) {
			// If we're on dialog, do nothing on double click
			break;
		}

		InterfacePtr<ITreeNodeIDData> nodeData(this, UseDefaultIID());
		ASSERT(nodeData);
		if(!nodeData) {
			break;
		}
		TreeNodePtr<CusDtLnkUIFileNodeID> nodeID(nodeData->Get());
		ASSERT(nodeID);
		if(!nodeID) {
			break;
		}
		PMString uk(nodeID->GetUniqueKey());
		
	
		IControlView* treeWidget = nil;
		
		InterfacePtr<ICusDtLnkUITreeDataModel> model(
			static_cast<ICusDtLnkUITreeDataModel* >
				(widgetParent->QueryParentFor(ICusDtLnkUITreeDataModel::kDefaultIID)));
		ASSERT(model);
		if(!model) {
			break;
		}
		CusDtLnkUITreeDataNode* dataNode = model->GetNode(uk);
		ASSERT(dataNode);
		if(!dataNode) {
			break;
		}
		// If an asset, think about loading place gun
#if NEW_LINK_ARCHITECTURE
		if(dataNode->GetNodeType() == CusDtLnkUITreeDataNode::eAssetType) {
			URI uri = dataNode->GetURIFromNode();
			if(uri.VerifyURI()) {
				IDocument* doc = Utils<ILayoutUIUtils>()->GetFrontDocument();
				if(doc) {
					UIDRef docUIDRef = ::GetUIDRef(doc);
					UIDRef loadedImage = 
						Utils<ICusDtLnkFacade>()->ImportImageAndLoadPlaceGun(docUIDRef,
						uri);
				}
			}
		}
#else
		if(dataNode->GetNodeType() == CusDtLnkUITreeDataNode::eAssetType) {
			IDFile absPathIDFile = dataNode->ResolveAssetPath();

			SDKFileHelper assHelper(absPathIDFile);
			if(assHelper.IsExisting()) {
				IDocument* doc = Utils<ILayoutUIUtils>()->GetFrontDocument();
				if(doc) {
					UIDRef docUIDRef = ::GetUIDRef(doc);
					UIDRef loadedImage = 
						Utils<ICusDtLnkFacade>()->ImportImageAndLoadPlaceGun(docUIDRef,
						assHelper.GetPath(),
							uk);
				}
			}
		}
#endif
		// 
	} while(kFalse);
	
	bool16 retval; 
	InterfacePtr<IEventHandler> delegate(this,IID_ICUSDTLNKUITREESHADOWEVENTHANDLER);  		
	retval= delegate->ButtonDblClk(e); 
	return retval;
} 

//	end, File:	CusDtLnkUITreeNodeEH.cpp
