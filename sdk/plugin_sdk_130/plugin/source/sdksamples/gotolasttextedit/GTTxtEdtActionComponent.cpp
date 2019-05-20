//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/gotolasttextedit/GTTxtEdtActionComponent.cpp $
//  
//  Owner: Adrian O'Lenskie
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
#include "IGTTxtEdtUtils.h"
#include "ISelectionManager.h"
#include "IDocument.h"
#include "IActiveContext.h"
#include "IGTTxtEdtSnapshotInterface.h"

// General includes:
#include "CActionComponent.h"
#include "CAlert.h"
#include "Utils.h"

// Project includes:
#include "GTTxtEdtID.h"

/** Implements IActionComponent; performs the actions that are executed when the plug-in's
menu items are selected.

@ingroup gotolasttextedit
*/
class GTTxtEdtActionComponent : public CActionComponent
{
public:
	/**
	Constructor.
	@param boss interface ptr from boss object on which this interface is aggregated.
	*/
	GTTxtEdtActionComponent(IPMUnknown* boss);

	/** The action component should perform the requested action.
	This is where the menu item's action is taken.
	When a menu item is selected, the Menu Manager determines
	which plug-in is responsible for it, and calls its DoAction
	with the ID for the menu item chosen.

	@param actionID identifies the menu item that was selected.
	@param ac active context
	@param mousePoint contains the global mouse location at time of event causing action (e.g. context menus). kInvalidMousePoint if not relevant.
	@param widget contains the widget that invoked this action. May be nil. 
	*/
	virtual void DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget);

private:
	/** Encapsulates functionality for the about menu item. */
	void DoAbout();
	/** Given the current context, find the last used text edit position and reset the cursor */
	void DoFindLastUsed(IActiveContext* pActiveContext);


};

/* CREATE_PMINTERFACE
Binds the C++ implementation class onto its
ImplementationID making the C++ code callable by the
application.
*/
CREATE_PMINTERFACE(GTTxtEdtActionComponent, kGTTxtEdtActionComponentImpl)

/* GTTxtEdtActionComponent Constructor
*/
GTTxtEdtActionComponent::GTTxtEdtActionComponent(IPMUnknown* boss)
: CActionComponent(boss)
{
}

/* DoAction
*/
void GTTxtEdtActionComponent::DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget)
{
	switch (actionID.Get())
	{

	case kGTTxtEdtAboutActionID:
		{
			this->DoAbout();
			break;
		}

	case kGTTxtEdtLastUsedActionID:
		{
			// this functionality is driven through the observer, though having the action makes sense.
			this->DoFindLastUsed(ac);
			break;
		}


	default:
		{
			break;
		}
	}
}

/* DoAbout
*/
void GTTxtEdtActionComponent::DoAbout()
{
	CAlert::ModalAlert
		(
		kGTTxtEdtAboutBoxStringKey,				// Alert string
		kOKString, 						// OK button
		kNullString, 						// No second button
		kNullString, 						// No third button
		1,							// Set OK button to default
		CAlert::eInformationIcon				// Information icon.
		);
}

/*
*/
void GTTxtEdtActionComponent::DoFindLastUsed(IActiveContext* pActiveContext)
{
	do {
		IDocument* iDocument = pActiveContext->GetContextDocument();
		if (iDocument == nil){
			break;
		}

		InterfacePtr<IGTTxtEdtSnapshotInterface> iGTTxtEdtSnapshotInterface(iDocument,UseDefaultIID());
		if (iGTTxtEdtSnapshotInterface == nil){
			break;
		}
		UIDRef storyUIDRef = iGTTxtEdtSnapshotInterface->GetStory();
		if (storyUIDRef!=UIDRef::gNull){
			ISelectionManager* iSelectionManager = pActiveContext->GetContextSelection();
			if (iSelectionManager==nil){
				ASSERT_FAIL("No selection manager for my context?");
				break;
			}
			Utils<IGTTxtEdtUtils>()->ActivateStory(iSelectionManager,storyUIDRef);
		}
	} while (kFalse);
}


//  Code generated by DollyXs code generator
