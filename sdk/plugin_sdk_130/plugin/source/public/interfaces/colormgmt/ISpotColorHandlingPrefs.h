//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/colormgmt/ISpotColorHandlingPrefs.h $
//  
//  Owner: Reena Agrawal
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  Copyright 2014 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#ifndef __ISpotColorHandlingPrefs__
#define __ISpotColorHandlingPrefs__

#if PRAGMA_ONCE
#pragma once
#endif

#include "IPMUnknown.h"
#include "ColorMgmtID.h"

//========================================================================================
// CLASS ISpotColorHandlingPrefs
//========================================================================================

class ISpotColorHandlingPrefs : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_ISPOTCOLORHANDLINGPREFS };
	
	virtual bool16 GetUseIncomingSpotDefinition() = 0;
	virtual void SetUseIncomingSpotDefinition(bool16 useIncomingSpotDefinition) = 0;
};

#endif // __ISpotColorHandlingPrefs__

// End, ISpotColorHandlingPrefs.h.
