//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/appearancepanel/StateProxyDEHandler.cpp $
//  
//  Owner: Tim Wright
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
//  Implementation for a simple layer proxy exchange handler
//  
//  Based on LayerProxyDEHandler.cpp in Layer Panel Project
//  
//========================================================================================

#include "VCPlugInHeaders.h"

#include "FormFieldUIID.h"
#include "PMFlavorTypes.h"

#include "CDataExchangeHandlerFor.h"

//========================================================================
// Class StateProxyDEHandler
//========================================================================

class StateProxyDEHandler : public CDataExchangeHandlerFor
{
	public:
		StateProxyDEHandler(IPMUnknown *boss) : CDataExchangeHandlerFor(boss) {}
		virtual	~StateProxyDEHandler() {}

		virtual	PMFlavor 	GetFlavor() const { return kPMStateProxyFlavor; }
		
		virtual ErrorCode	Externalize(IPMDataObject* whichItem, ExternalPMFlavor toWhichFlavor, IPMStream* s);
};


//========================================================================================
// Implementation StateProxyDEHandler
//========================================================================================

CREATE_PMINTERFACE(StateProxyDEHandler, kStateProxyDEHandlerImpl)


//--------------------------------------------------------------------------------------
// Externalize
//--------------------------------------------------------------------------------------
ErrorCode StateProxyDEHandler::Externalize(IPMDataObject* whichItem, ExternalPMFlavor toWhichFlavor, IPMStream* s)
{
	return kFailure;
}