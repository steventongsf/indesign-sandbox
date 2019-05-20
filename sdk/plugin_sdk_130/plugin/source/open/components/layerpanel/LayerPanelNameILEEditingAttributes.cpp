//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/layerpanel/LayerPanelNameILEEditingAttributes.cpp $
//  
//  Owner: kphilbri 
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
//  
//  Owner
//  
//========================================================================================

#include "VCPlugInHeaders.h"

#include "InLineEditEditingAttributes.h"
#include "IWidgetParent.h"
#include "ITreeNodeIDData.h"
#include "ITreeViewController.h"

#include "UIDNodeID.h"

// ----- Interface Includes -----

// ----- Implementation Includes -----
#include "LayerPanelID.h"

class LayerPanelNameILEEditingAttributes : public InLineEditEditingAttributes
{
public:	
	LayerPanelNameILEEditingAttributes(IPMUnknown *boss);
	~LayerPanelNameILEEditingAttributes();

	virtual bool16 IsSelected() const;
	virtual bool16 GetFitEditBoxtoText() const { return kTrue; }
};

CREATE_PERSIST_PMINTERFACE(LayerPanelNameILEEditingAttributes, kLayerPanelNameILEEditingAttributesImpl)

//========================================================================================
// CLASS LayerPanelNameILEEditingAttributes
//========================================================================================

LayerPanelNameILEEditingAttributes::LayerPanelNameILEEditingAttributes(IPMUnknown *boss) :
	InLineEditEditingAttributes(boss)
{
}

LayerPanelNameILEEditingAttributes::~LayerPanelNameILEEditingAttributes()
{
}

//----------------------------------------------------------------------------------------
// LayerPanelNameILEEditingAttributes::IsSelected
//----------------------------------------------------------------------------------------
bool16 LayerPanelNameILEEditingAttributes::IsSelected() const
{
	InterfacePtr<const IWidgetParent> wp(this, UseDefaultIID());

	InterfacePtr<const ITreeNodeIDData> data((ITreeNodeIDData*)wp->QueryParentFor(ITreeNodeIDData::kDefaultIID));
	NodeID widgetNode = data->Get();
	
	InterfacePtr<const ITreeViewController> iTreeCntrller((ITreeViewController*)wp->QueryParentFor(IID_ITREEVIEWCONTROLLER));

	if (iTreeCntrller->IsSelected(data->Get()))
		return kTrue;

	return kFalse;
}
