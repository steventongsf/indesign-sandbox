//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/wavetool/WavTlActionComponent.cpp $
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
#include "WavTlID.h"


/** Implements the actions that are executed when the plug-in's
	menu items are selected.

	
	@ingroup wavetool
*/
class WavTlActionComponent : public CActionComponent
{
	public:
		/** Constructor.
			@param boss interface ptr from boss object on which this interface is aggregated.
		 */
		WavTlActionComponent(IPMUnknown* boss);

		/**	This is where the menu item's action is taken.
			When a menu item is selected, the Menu Manager determines
			which plug-in is responsible for it, and calls its DoAction
			with the ID for the menu item chosen. 

			@param actionID identifies the menu item that was selected.
			@see CActionComponent::DoAction
		 */
		void DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint = kInvalidMousePoint, IPMUnknown* widget = nil);

	private:
		/** Pops the about this plug-in alert. 
		 */
		void DoAbout();

};

/* Make the implementation available to the application.
*/
CREATE_PMINTERFACE(WavTlActionComponent, kWavTlActionComponentImpl)

/*
*/
WavTlActionComponent::WavTlActionComponent(IPMUnknown* boss)
: CActionComponent(boss)
{
}

/*
*/
void WavTlActionComponent::DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget)
{
	switch (actionID.Get())
	{
		case kWavTlAboutActionID:
		{
			this->DoAbout();
			break;
		}	

		default:
		{
			break;
		}
	}
}

/*
*/
void WavTlActionComponent::DoAbout()
{
	CAlert::ModalAlert
	(
	   kWavTlAboutBoxStringKey,			// Alert string
	   kOKString, 							// OK button
	   kNullString, 						// No second button
	   kNullString, 						// No third button
	   1,									// Set OK button to default
	   CAlert::eInformationIcon				// Information icon.
	);
}

// End, WavTlActionComponent.cpp.



