//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IPMRectData.h $
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

#pragma once
#ifndef __IPMRectData__
#define __IPMRectData__

#include "IPMUnknown.h"
#include "CommandID.h"
#include "PMRect.h"

/** Data interface for storing a rectangle (PMRect).
	@ingroup arch_coredata 
*/
class IPMRectData : public IPMUnknown {
public:
	enum { kDefaultIID = IID_IPMRECTDATA };
	
	/** Set the value of the rectangle.
		@param theRect	new value
	*/
	virtual void SetRect(const PMRect& theRect) = 0;

	/** Return the rectangle.
		@return return the rectangle
	*/
	virtual const PMRect& GetRect() const = 0;
};

#endif
