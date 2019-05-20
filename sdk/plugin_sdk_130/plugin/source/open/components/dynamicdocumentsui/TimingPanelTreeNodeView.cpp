//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/TimingPanelTreeNodeView.cpp $
//  
//  Owner: Yeming Liu
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
#include "TreeNodeControlView.h"
#include "DynamicDocumentsUIID.h"

class TimingPanelTreeNodeView : public TreeNodeControlView
{
	typedef TreeNodeControlView inherited;

public:
	TimingPanelTreeNodeView(IPMUnknown *boss); 
	virtual ~TimingPanelTreeNodeView() { ; } 
	
};

#pragma mark TimingPanelTreeNodeView implementation

CREATE_PERSIST_PMINTERFACE(TimingPanelTreeNodeView, kTimingPanelTreeNodeViewImpl)


TimingPanelTreeNodeView::TimingPanelTreeNodeView(IPMUnknown *boss) 
: inherited(boss) 
{ 
	SetDrawNodeSeparatorOnOff(kFalse); 
}