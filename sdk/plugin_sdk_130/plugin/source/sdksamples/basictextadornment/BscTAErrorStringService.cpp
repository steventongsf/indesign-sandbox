//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/basictextadornment/BscTAErrorStringService.cpp $
//  
//  Owner: Adobe Developer Technologies
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

// Interface includes:
// none.

// General includes:
#include "CErrorStringService.h"

// Project includes:
#include "BscTAID.h"

/** From SDK sample; Provides error string service for BasicTextAdornment that 
	maps this plug-in's ErrorCode's to error strings defined in the 
	UserErrorTable ODFRez statement in BscTA.fr.

	@ingroup basictextadornment
*/
class BscTAErrorStringService : public CErrorStringService
{
public:
	/** Constructor; this is where we specify the pluginID and the resourceID for the 
		UserErrorTable resource that is associated with this implementation.
		@param boss interface pointer from boss object on which this interface is aggregated.
	 */
	BscTAErrorStringService(IPMUnknown* boss):
		CErrorStringService(boss, kBscTAPluginID, kSDKDefErrorStringResourceID) {}

	/** Destructor 
	 */
	virtual ~BscTAErrorStringService(void) {}
};

/* Make the implementation available to the application.
*/
CREATE_PMINTERFACE(BscTAErrorStringService, kBscTAErrorStringServiceImpl)

// End, BscTAErrorStringService.cpp.
