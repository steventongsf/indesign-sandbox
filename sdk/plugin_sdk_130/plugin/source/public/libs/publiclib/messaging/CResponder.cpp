//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/libs/publiclib/messaging/CResponder.cpp $
//  
//  Owner: Robin briggs
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

#include "VCPublicHeaders.h"
#include "CResponder.h"


DEFINE_HELPER_METHODS(CResponder)

CResponder::CResponder(IPMUnknown *boss) :
   HELPER_METHODS_INIT(boss)
{
}

void CResponder::Respond(ISignalMgr* signalMgr)
{
}


void CResponder::SignalFailed(ISignalMgr* signalMgr)
{
}


ServiceID CResponder::GetResponderService()
{	
		// Should be overridden by the derived class, if the
		// derived class uses the generic responder service provider.
	return kInvalidService;
}

