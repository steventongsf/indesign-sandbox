//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/layerpanel/LayerNameEH.cpp $
//  
//  Owner: Paul Sorrick
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
//  
//  Implementation of event handler that handles name double clicks
//  to bring up the Layer Options dialog.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

#include "IActionManager.h"
#include "IApplication.h"
#include "IDocumentLayer.h"
#include "IEvent.h"
#include "ILayerList.h"
#include "IMenuManager.h"
#include "IPanelControlData.h"
#include "ISession.h"

// ----- Includes -----

#include "InLineEditClickPauseClickEH.h"

// ----- Utility files -----

#include "EventUtilities.h"
#include "LayerPanelUtils.h"
#include "IPalettePanelUtils.h"

// ----- ID.h files -----

#include "LayerPanelID.h"


#define INHERITED InLineEditClickPauseClickEH

class LayerNameEH : public InLineEditClickPauseClickEH
{			
	public:
						LayerNameEH(IPMUnknown *boss);
		virtual 		~LayerNameEH();
			
		virtual bool16 LButtonDn(IEvent* e); 
		virtual bool16 RButtonDn(IEvent* e);
		virtual bool16 ButtonDblClk(IEvent* e);
		
	private:
		DECLARE_HELPER_METHODS()
};

//========================================================================
// Class LayerNameEH
//========================================================================
CREATE_PMINTERFACE(LayerNameEH, kLayerNameEHImpl)
DEFINE_HELPER_METHODS(LayerNameEH)

LayerNameEH::LayerNameEH(IPMUnknown *boss) :
	INHERITED(boss),
	HELPER_METHODS_INIT(boss)
{
}

LayerNameEH::~LayerNameEH()
{
}
	

//---------------------------------------------------------------
// LayerNameEH::LButtonDn
//---------------------------------------------------------------

bool16 LayerNameEH::LButtonDn(IEvent* e) 
{
	bool16 handled = kFalse;

	// Shortcut to select the items on the clicked layer is Option + click
	// Allow shortcut for list focus (Option + Command + click) to pass through.
	if (e->OptionAltKeyDown() && !e->CmdKeyDown())
	{
		handled = kTrue;

		// With shift key down, extend selection, otherwise replace it.
		LayerPanelUtils::DoSelectLayer(this, e->ShiftKeyDown(), e->OptionAltKeyDown());	
	}
	return INHERITED::LButtonDn(e);
}

//---------------------------------------------------------------
// LayerNameEH::RButtonDn
//---------------------------------------------------------------

bool16 LayerNameEH::RButtonDn(IEvent* e)
{
	InterfacePtr<IApplication> theApp(GetExecutionContextSession()->QueryApplication());
	InterfacePtr<IActionManager> actionMgr(theApp->QueryActionManager());
	InterfacePtr<IMenuManager> menuMgr(actionMgr, UseDefaultIID());
	
	menuMgr->HandlePopupMenu("RtMenuLayerPanelItem", e->GlobalWhere(), e->GlobalWhere(), kTrue, this);
	
	return kTrue;
}

//---------------------------------------------------------------
// LayerNameEH::ButtonDblClk
//---------------------------------------------------------------

bool16 LayerNameEH::ButtonDblClk(IEvent* e) 
{
	INHERITED::ButtonDblClk(e);

	bool16 handled = kTrue;

	// Get the IPanelControlData for the layer panel itself, operate on selected layers
	InterfacePtr<IPanelControlData> layerPanelData(Utils<IPalettePanelUtils>()->QueryPanelByWidgetID(kLayerParentWidgetId));
	LayerPanelUtils::InvokeLayerDialog(LayerPanelUtils::kLayerOptionsDialog, LayerPanelUtils::kAboveActive, layerPanelData, nil);

	return handled;
}
