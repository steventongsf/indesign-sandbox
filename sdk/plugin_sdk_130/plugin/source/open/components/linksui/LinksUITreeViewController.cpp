//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/linksui/LinksUITreeViewController.cpp $
//  
//  Owner: lance bushore
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
#include "CTreeViewController.h"

//#include "IControlView.h"
//#include "ITreeNodeIDData.h"
//#include "LinksTreeUIDNodeID.h"
#include "LinksUIID.h"


class  LinksUITreeViewController : public CTreeViewController
{
public:
	LinksUITreeViewController(IPMUnknown *boss);
	~LinksUITreeViewController();

//	virtual void				ProcessSelectionRules(IEvent* event, UID nodeWidgetUID);
};


CREATE_PERSIST_PMINTERFACE(LinksUITreeViewController, kLinksUITreeViewControllerImpl)

LinksUITreeViewController::LinksUITreeViewController(IPMUnknown *boss)
: CTreeViewController(boss)
{
}

LinksUITreeViewController::~LinksUITreeViewController()
{
}

// we want to prevent selection of our 'header rows'
//void LinksUITreeViewController::ProcessSelectionRules(IEvent* event, UID nodeWidgetUID)
//{
//	CTreeViewController::ProcessSelectionRules(event,nodeWidgetUID);
//}

