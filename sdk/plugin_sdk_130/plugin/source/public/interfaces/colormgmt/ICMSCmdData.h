//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/colormgmt/ICMSCmdData.h $
//  
//  Owner: fhaberma
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

#ifndef __ICMSCmdData__
#define __ICMSCmdData__

#if PRAGMA_ONCE
#pragma once
#endif

#include "ColorMgmtID.h"
#include "IPMUnknown.h"
#include "UIDRef.h"

class ICMSCmdData : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_ICMSCMDDATA };
		
		virtual void Set(const UIDRef& doc, ClassID whichCMSMgr = 0) = 0;
		virtual UIDRef GetDocument() const = 0;
		virtual ClassID GetCMSMgr() const = 0;	// If this is 0, assume they mean the default CMSMgr
};

#endif // __ICMSCmdData__

// End, ICMSCmdData.h.
