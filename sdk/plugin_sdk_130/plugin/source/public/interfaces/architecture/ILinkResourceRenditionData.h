//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/ILinkResourceRenditionData.h $
//  
//  Owner: Sanyam Jain
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
//  Description:
//  This class defines an interface used to maintain and access a linked resource.
//  
//========================================================================================

#pragma once
#ifndef __ILinkResourceRenditionData__
#define __ILinkResourceRenditionData__

// ----- Includes -----
#include "IPMUnknown.h"
#include "LinksID.h"

#include "ILinkResource.h"

/**
Experimental interface - will be modified/documented in future.
*/
class ILinkResourceRenditionData : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_ILINKRESOURCERENDITIONDATA };

	enum ResourceRenditionType
	{
		/* For placement only - usually a low-res replacement for a high-res original */
		kFPO,
		
		/* The original linked asset */
		kOriginal,
	};

	/**
	 Returns the resource's rendition type. \\
	 @return Resource's rendition type.
	 */ 
	virtual ResourceRenditionType GetRenditionType() const = 0;

	/**
	 Sets the resource's rendition type.
	 @param renditionType [IN] rendition type of the resource.
	 */ 
	virtual void SetRenditionType(ResourceRenditionType renditionType) = 0;
};

#endif // __ILinkResourceRenditionData__
