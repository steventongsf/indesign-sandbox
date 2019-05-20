//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IPMPointData.h $
//  
//  Owner: Lonnie Millett
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
#ifndef __IPMPOINTDATA__
#define __IPMPOINTDATA__

#include "IPMUnknown.h"
#include "CommandID.h"
#include "PMPoint.h"

/** Data interface for storing a point (PMPoint).
	@ingroup arch_coredata 
*/
class IPMPointData : public IPMUnknown {
public:
	enum { kDefaultIID = IID_IPMPOINTDATA };

	/**	Set the point.
		@param thePoint is the new point.
	*/
	virtual void Set(const PMPoint& thePoint) = 0;
	/**	@return the point.
	*/
	virtual const PMPoint& GetPMPoint() const = 0;
};

#endif
