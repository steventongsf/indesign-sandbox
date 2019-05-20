//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/actionpanel/BehaviorsTreeViewEH.cpp $
//  
//  Owner: Michele Stutzman
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

// ----- Interfaces -----

#include "IControlView.h"
#include "ITreeViewMgr.h"
#include "ITreeNodeIDData.h"
#include "ITreeViewHierarchyAdapter.h"
#include "IWorkspace.h"

// ----- Includes -----

#include "CActionComponent.h"
#include "CTreeViewController.h"
#include "TreeNodeTraverser.h"
#include "TreeViewEventHandler.h"

// ----- Utility files -----

#include "EventUtilities.h"
#include "IPalettePanelUtils.h"
#include "UserInterfaceUtils.h"

// ----- ID.h files -----

#include "widgetid.h"
#include "FormFieldUIID.h"


class BehaviorsTreeViewEH : public TreeViewEventHandler
{
public:
    BehaviorsTreeViewEH(IPMUnknown *boss) : TreeViewEventHandler(boss) {}
	virtual ~BehaviorsTreeViewEH() {}

	virtual bool16 LButtonDn(IEvent* e);
	virtual bool16 RButtonDn(IEvent* e);
};

// =============================================================================
// *** BehaviorsTreeViewEH impl ***
// -----------------------------------------------------------------------------

CREATE_PMINTERFACE (BehaviorsTreeViewEH, kBehaviorsTreeViewEHImpl)

// -----------------------------------------------------------------------------
//	Note: This is basically the same as the TreeViewEventHandler, except that it ensure
//	at least one is selected at all time.

bool16 BehaviorsTreeViewEH::LButtonDn(IEvent* e)
{
	return kFalse;
} // end LButtonDn()

// -----------------------------------------------------------------------------

bool16 BehaviorsTreeViewEH::RButtonDn(IEvent* e)
{
	return kFalse;
} // end RButtonDn()
