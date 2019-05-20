//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IHTTPLinkResourceStateBatchUpdater.h $
//  
//  Owner: Ramnik Singh
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
//  Copyright 2016 Adobe 
//  All Rights Reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in 
//  accordance with the terms of the Adobe license agreement accompanying 
//  it. If you have received this file from a source other than Adobe, 
//  then your use, modification, or distribution of it requires the prior 
//  written permission of Adobe.
//  
//========================================================================================

#pragma once
#ifndef __IHTTPLinkResourceStateBatchUpdater__
#define __IHTTPLinkResourceStateBatchUpdater__

#include "IPMUnknown.h"
#include "LinksID.h"
#include "IHTTPLinkResourceServerAPIWrapper.h"
#include "UIDList.h"

/*
 AdobePatentID="P7137-US"
 AdobePatentID="P7225-US"
 AdobePatentID="P7609-US"
 */

/**
Experimental interface - will be modified/documented in future.
*/
class IHTTPLinkResourceStateBatchUpdater : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IHTTPLINKRESOURCESTATEBATCHUPDATER };

	/*
	Queue the batch update request for the given Link resource UID.
	@param resourceUID					[IN] UID of the link resource who request is to be batched.
	@param updateLinkResourceStateData	[IN] Link Resource State Data.
	@return kSuccess if operation is successful otherwise kFailure
	*/
	virtual ErrorCode QueueLinkResourceUpdateRequestForBatch(const UID& resourceUID,  const HTTPLinkSubsystemTypes::UpdateLinkResourceStateClientData& updateLinkResourceStateData) = 0;
	
	/*
	Do synchronous batch update for the list of Link Resources 
	@param resourceUIDs					[IN] List of UIDs of the Link resource whose sync batch request is to be initiated
	@param updateLinkResourceStateData	[IN] Link Resource State Data.
	@return kSuccess if operation is successful otherwise kFailure
	*/
	virtual ErrorCode DoSynchrononousBatchUpdate(const UIDList& resourceUIDs, const HTTPLinkSubsystemTypes::UpdateLinkResourceStateClientData& updateLinkResourceStateData) = 0;
};

#endif	// __IHTTPLinkResourceStateBatchUpdater__
