//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/IKashidaAttr.h $
//  
//  Owner: prubini
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
//  
//  Usage rights licenced to Adobe Inc. 1993 - 2007.
//  
//========================================================================================

#ifndef __IKashidaAttr__
#define __IKashidaAttr__

#include "IPMUnknown.h"
#include "WorldReadyID.h"

class IKashidaAttr : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_IKASHIDAATTR };

		typedef enum {	kKashidaDefault = 0,
						kKashidaOff } Kashidas;

		typedef IKashidaAttr::Kashidas		ValueType;

		virtual void Set(ValueType val) = 0;
		virtual	ValueType Get() const = 0;
};

#endif

