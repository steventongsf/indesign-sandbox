//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/interfaces/ui/IEVEUtils.h $
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
#ifndef __IEVEUtils__
#define __IEVEUtils__

#include "DialogLayoutID.h"
#include "IPMUnknown.h"

/**	Utilities related to automatic EVE dialog layout.
*/
class IEVEUtils : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IEVEUTILS };

	virtual bool16 CanApplyEveLayout(const IControlView* panel) const = 0;
	virtual void ApplyEveLayout(IControlView* panel) = 0;
};

#endif // __IEVEUtils__
