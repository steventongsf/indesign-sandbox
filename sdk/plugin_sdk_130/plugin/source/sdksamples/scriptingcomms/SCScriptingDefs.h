//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/scriptingcomms/SCScriptingDefs.h $
//  
//  Owner: Timothy Brand-Spencer
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================


#ifndef __SCScriptingDefs_h__
#define __SCScriptingDefs_h__

#define kCPrefs_CLSID { 0x8d448fe0, 0x8194, 0x11d3, { 0xa6, 0x53, 0x0, 0xe0, 0x98, 0x71, 0xa, 0x6f } }
DECLARE_GUID(CPrefs_CLSID, kCPrefs_CLSID);

// Note: 4-char IDs below must be unique.
// See ScriptingDefs.h for further information.

// Method IDs
enum SCScriptEvents
{
	e_Speak		= 'eSpk'
};

// Property IDs
enum SCScriptProperties
{
	p_Said		= 'pSed',
	p_Response		= 'pRsp'
};


#endif // __SCScriptingDefs_h__
