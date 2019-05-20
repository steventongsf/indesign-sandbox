//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/colormgmt/ICMSRenderingIntentData.h $
//  
//  Owner: James Jardee-Borquist
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

#ifndef __ICMSRenderingIntentData__

#define __ICMSRenderingIntentData__



#if PRAGMA_ONCE

#pragma once

#endif



#include "ICMSSettings.h"

#include "IPMUnknown.h"



#include "ACEColorMgmtID.h"



//========================================================================================

// CLASS ICMSRenderingIntentData

//========================================================================================



class ICMSRenderingIntentData : public IPMUnknown

{

public:

	enum { kDefaultIID = IID_ICMSRENDERINGINTENTDATA };

	

	virtual void Set(ICMSSettings::renderingIntent category) = 0;

	virtual ICMSSettings::renderingIntent GetRenderingIntent() const = 0;

};



#endif // __ICMSRenderingIntentData__



// End, ICMSRenderingIntentData.h.

