//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/graphics/IStrokeChangePreference.h $
//  
//  Owner: jargast
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
#ifndef __IStrokeChangePreference__
#define __IStrokeChangePreference__

#include "IPMUnknown.h"
#include "GraphicStylesID.h"

class IStrokeChangePreference : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_ISTROKECHANGEPREFERENCE };

	// Default value for this preference is kFalse.
	virtual void SetStrokeChangesBoundingBox (bool8 changeVal) = 0;
	
	virtual bool8 GetStrokeChangesBoundingBox() const = 0;
};


#endif
