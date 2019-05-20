//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/cjk/ITextAttrKinsokuType.h $
//  
//  Owner: Shinji Hiramatsu
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
#ifndef __ITextAttrKinsokuType__
#define __ITextAttrKinsokuType__

#include "IPMUnknown.h"
#include "ICompositionStyle.h"
#include "IMojikumiStyle.h"
#include "TextAttrID.h"


/** Interface for a text attribute whose value is the type of Kinsoku processing to occur (japanese line breaking rules).
	@see IMojikumiStyle::KinsokuType
	@ingroup text_attr
*/
class ITextAttrKinsokuType : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_IKINSOKUTYPE };

		typedef IMojikumiStyle::KinsokuType		ValueType;

		/** */
		ValueType Get() const { return GetKinsokuType(); }
		/** */
		void Set(ValueType val) { SetKinsokuType(val); }

		/** */
		virtual void SetKinsokuType(IMojikumiStyle::KinsokuType dq) = 0;
		/** */
		virtual IMojikumiStyle::KinsokuType GetKinsokuType() const = 0;
};

#endif
