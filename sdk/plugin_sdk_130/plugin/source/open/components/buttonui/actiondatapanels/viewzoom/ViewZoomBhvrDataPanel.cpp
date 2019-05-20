//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/actiondatapanels/viewzoom/ViewZoomBhvrDataPanel.cpp $
//  
//  Owner: Steve Dowd
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

// ----- Interface Includes -----

#include "IBehaviorDataPanel.h"
#include "ISession.h"
#include "IControlView.h"

// ----- Implementation Includes -----

#include "BehaviorUIID.h"
#include "BehaviorUIDefs.h"
#include "FormFieldUIID.h"
#include "CPMUnknown.h"
#include "CreateObject.h"
#include "CoreResTypes.h"
#include "DVUtilities.h"
#include "RsrcSpec.h"

//========================================================================================
// CLASS ViewZoomBehaviorDataPanel
//========================================================================================

class ViewZoomBehaviorDataPanel : public CPMUnknown<IBehaviorDataPanel>
{
public:
	ViewZoomBehaviorDataPanel(IPMUnknown *boss);
	virtual ~ViewZoomBehaviorDataPanel();

	virtual IPMUnknown* CreatePanel(const PMLocaleId& localeId, const PMIID& iid) const;
};	

//========================================================================================
// METHODS ViewZoomBehaviorDataPanel
//========================================================================================

CREATE_PMINTERFACE(ViewZoomBehaviorDataPanel, kViewZoomBehaviorDataPanelImpl)

//----------------------------------------------------------------------------------------
// ViewZoomBehaviorDataPanel::ViewZoomBehaviorDataPanel
//----------------------------------------------------------------------------------------

ViewZoomBehaviorDataPanel::ViewZoomBehaviorDataPanel(IPMUnknown *boss) :
	CPMUnknown<IBehaviorDataPanel>(boss)
{
}

//----------------------------------------------------------------------------------------
// ViewZoomBehaviorDataPanel::~ViewZoomBehaviorDataPanel
//----------------------------------------------------------------------------------------

ViewZoomBehaviorDataPanel::~ViewZoomBehaviorDataPanel()
{
}

//----------------------------------------------------------------------------------------
// ViewZoomBehaviorDataPanel::CreatePanel
//----------------------------------------------------------------------------------------

IPMUnknown* ViewZoomBehaviorDataPanel::CreatePanel(const PMLocaleId& localeId, const PMIID& iid) const
{
	/* degupta - CreateObject is creating the controlview and also calling the DoPostCreate(), breaking this into 
	 * CreateObjectNoInit() and DoPostCreate() so that theme can be set on the view before DoPostCreate() is called.
	 */
	IPMUnknown *returnVal = ::CreateObjectNoInit (::GetDataBase(GetExecutionContextSession()),
		RsrcSpec(localeId, kFormFieldUIPluginID, kViewRsrcType, kViewZoomPanelRsrcID),
		IID_ICONTROLVIEW,
		GetObjectModelInstance());
	ASSERT_MSG(returnVal, "Cannot create the appropriate control view.");
	IControlView* panel = InterfacePtr<IControlView>(returnVal, UseDefaultIID());
	ASSERT_MSG(panel, "Cannot create the appropriate control view.");
	// Set the drover theme on the Panel View and call the DoPostCreate()
	if(panel)
	{
		dv_utils::SetThemeForView(panel, dv_utils::kIDPanelTheme);
		panel->DoPostCreate();
	}
	return panel;
}
