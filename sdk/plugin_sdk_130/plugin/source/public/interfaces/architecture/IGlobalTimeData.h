//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IGlobalTimeData.h $
//  
//  Owner: robin briggs
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
#ifndef __IGlobalTimeData__
#define __IGlobalTimeData__

#include "IPMUnknown.h"
#include "CommandID.h"

/** Data interface for storing integers.
	@ingroup arch_coredata
*/
class IGlobalTimeData : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_IGLOBALTIMEDATA };

		typedef GlobalTime		ValueType;

		/** Set the value.
			@param i	new value of the integer
		*/
		virtual void Set(const ValueType& i) = 0;

		/** Get the value.
			@return value of the interface
		*/
		virtual const ValueType& GetGlobalTime() const = 0;

		/** Get the value.
			@return value of the interface
		*/
		const ValueType& Get() const
			{ return GetGlobalTime(); }
};



#endif // __IGlobalTimeData__
