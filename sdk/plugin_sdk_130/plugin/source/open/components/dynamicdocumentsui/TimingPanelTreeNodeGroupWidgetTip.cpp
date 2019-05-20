//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/TimingPanelTreeNodeGroupWidgetTip.cpp $
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

#include "AbstractTip.h"
#include "ITreeNodeIDData.h"
#include "IWidgetParent.h"

// ----- Includes -----

#include "PMString.h"
#include "TimingPanelTreeNodeID.h"

// ----- Utils -----

// ----- ID.h files -----

#include "DynamicDocumentsUIID.h"

class TimingPanelTreeNodeGroupWidgetTip : public AbstractTip
{			
	public:
		TimingPanelTreeNodeGroupWidgetTip( IPMUnknown *boss ) : AbstractTip( boss ) { }
		virtual ~TimingPanelTreeNodeGroupWidgetTip() { }

		virtual PMString  GetTipText(const PMPoint& mouseLocation);
};

CREATE_PMINTERFACE(TimingPanelTreeNodeGroupWidgetTip, kTimingPanelTreeNodeGroupWidgetTipImpl)

PMString TimingPanelTreeNodeGroupWidgetTip::GetTipText(const PMPoint& mouseLocation)
{
	PMString tipString("");

	InterfacePtr<IWidgetParent>	iWidgetParent(this, UseDefaultIID());
	InterfacePtr<ITreeNodeIDData> iHolderData(iWidgetParent->GetParent(), UseDefaultIID());
	if (iHolderData)
	{
		NodeID nodeIDHolder = iHolderData->Get();	
		TreeNodePtr<TimingPanelTreeNodeID> itemNode(nodeIDHolder);
		if (itemNode && itemNode->IsGroupItem())
			tipString = PMString("kTimingPanelLinkedItemGroupWidgetTip");  
	}

	return tipString;
} 

