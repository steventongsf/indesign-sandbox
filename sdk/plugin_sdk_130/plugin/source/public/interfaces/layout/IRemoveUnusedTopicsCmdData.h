//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/layout/IRemoveUnusedTopicsCmdData.h $
//  
//  Owner: Bertrand Lechevalier
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

#pragma once
#ifndef __IRemoveUnusedTopicsCmdData__
#define __IRemoveUnusedTopicsCmdData__

#include "IPMUnknown.h"
#include "IndexingID.h"
#include "UIDRef.h" 

/** Command data interface associated with kRemoveUnusedTopicsCmdBoss.
	@see kRemoveUnusedTopicsCmdBoss
	@ingroup layout_index
*/
class IRemoveUnusedTopicsCmdData : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_IREMOVEUNUSEDTOPICSCMDDATA };

		/** Gets the target topic list for the command.
			@return the UIDRef of the target topic list.
		*/
		virtual const UIDRef& GetTopicListUIDRef() const = 0;

		/** Sets the target topic list for the command.
			@param topicListUIDRef [IN] - the UIDRef of the target topic list.
		*/
		virtual void SetTopicListUIDRef(const UIDRef& topicListUIDRef) = 0;
};

#endif	// __IRemoveUnusedTopicsCmdData__