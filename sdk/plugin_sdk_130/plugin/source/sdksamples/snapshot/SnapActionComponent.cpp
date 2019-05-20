//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/snapshot/SnapActionComponent.cpp $
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

// General includes:
#include "CActionComponent.h"
#include "CAlert.h"

// Project includes:
#include "SnapID.h"


/** SnapActionComponent
	implements the actions that are executed when the plug-in's
	menu items are selected. 
  
	
	@ingroup snapshot
*/
class SnapActionComponent : public CActionComponent
{
	public:
		/**
			Constructor.
			@param boss interface ptr from boss object on which this interface is aggregated.
		*/
		SnapActionComponent(IPMUnknown* boss);

		/** Called by the framework when the action is to be performed.
			@param ac context in which action is to be performed.
			@param actionID identifies the action that was selected.
			@param mousePoint contains the global mouse location at time of event causing action
			(e.g. context menus). kInvalidMousePoint if not relevant.
		 */
		virtual void	DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget);
};

/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its 
 ImplementationID making the C++ code callable by the 
 application.
*/
CREATE_PMINTERFACE(SnapActionComponent, kSnapActionComponentImpl)

/* SnapActionComponent Constructor
*/
SnapActionComponent::SnapActionComponent(IPMUnknown* boss)
: CActionComponent(boss)
{
}

/* DoAction
*/
void SnapActionComponent::DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget)
{
	switch (actionID.Get())
	{
		case kSnapAboutActionID:
		{
			CAlert::ModalAlert
			(
			   kSnapAboutBoxStringKey,				// Alert string
			   kOKString, 							// OK button
			   kNullString, 						// No second button
			   kNullString, 						// No third button
			   1,									// Set OK button to default
			   CAlert::eInformationIcon				// Information icon.
			);
			break;
		}	

		default:
		{
			break;
		}
	}
}

// End, SnapActionComponent.cpp.




