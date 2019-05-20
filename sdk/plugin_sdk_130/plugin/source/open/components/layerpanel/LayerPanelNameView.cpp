//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/layerpanel/LayerPanelNameView.cpp $
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

// ----- Interfaces -----

#include "InLineEditView.h"
#include "LayerPanelID.h"

#ifdef DEBUG
#include "ITextControlData.h"
#include "DebugClassUtils.h"
#include "LayerTreeUIDNodeID.h"
#include "Utils.h"
#include "LayerPanelUtils.h"
#include "IDocument.h"
#endif

class LayerPanelNameView : public InLineEditView
{
	public:
		LayerPanelNameView(IPMUnknown *boss);
		virtual ~LayerPanelNameView();
};



CREATE_PERSIST_PMINTERFACE(LayerPanelNameView, kLayerPanelNameViewImpl)

LayerPanelNameView::LayerPanelNameView(IPMUnknown *boss) :
	InLineEditView(boss)
{
}


LayerPanelNameView::~LayerPanelNameView()
{
}