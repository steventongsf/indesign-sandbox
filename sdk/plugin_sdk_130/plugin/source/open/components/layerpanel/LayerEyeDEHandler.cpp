//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/layerpanel/LayerEyeDEHandler.cpp $
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
//  Implementation for a simple layer eye exchange handler
//  
//========================================================================================

#include "VCPlugInHeaders.h"

#include "LayerPanelID.h"

#include "CDataExchangeHandlerFor.h"

//========================================================================
// Class LayerEyeDEHandler
//========================================================================

class LayerEyeDEHandler : public CDataExchangeHandlerFor
{
	public:
		LayerEyeDEHandler(IPMUnknown *boss) : CDataExchangeHandlerFor(boss) {}
		virtual	~LayerEyeDEHandler() {}

		virtual	PMFlavor 	GetFlavor() const { return kPMLayerEyeFlavor; }
};

CREATE_PMINTERFACE(LayerEyeDEHandler, kLayerEyeDEHandlerImpl)
