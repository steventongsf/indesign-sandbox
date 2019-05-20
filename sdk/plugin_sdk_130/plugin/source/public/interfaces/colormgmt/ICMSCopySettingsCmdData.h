//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/colormgmt/ICMSCopySettingsCmdData.h $
//  
//  Owner: Matt Phillips
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

#ifndef __ICMSCopySettingsCmdData__
#define __ICMSCopySettingsCmdData__

#if PRAGMA_ONCE
#pragma once
#endif

#include "ColorMgmtID.h"
#include "IPMUnknown.h"
#include "UIDRef.h" 

class ICMSCopySettingsCmdData : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_ICMSCOPYSETTINGSCMDDATA };
		
		virtual void Set(const UIDRef& srcItem, const UIDRef& dstItem, int32 itemUseCmdFlags) = 0;
		virtual UIDRef GetSrcItem() const = 0;
		virtual UIDRef GetDstItem() const = 0;
		virtual int32 GetItemUseCmdFlags() const = 0;
};

#endif // __ICMSCopySettingsCmdData__

// End, ICMSCopySettingsCmdData.h.
