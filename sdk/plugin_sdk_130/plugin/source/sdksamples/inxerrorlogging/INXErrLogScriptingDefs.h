//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/inxerrorlogging/INXErrLogScriptingDefs.h $
//  
//  Owner: ???
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
#ifndef _INXErrLogScriptingDefs_h_
#define _INXErrLogScriptingDefs_h_


// ScriptIDs
// New ScriptIDs must be registered with Adobe Developer Support to prevent conflict with other scriptable plug-ins.
// See the Making Your Plug-in Scriptable tech note.

// Property ScriptIDs
enum INXErrLogScriptProperties
{
	p_INXErrLogOnOff = 'IXlo', 		// INXError log on off setting
	p_INXErrLogPath = 'IXlp',			// INXError log path setting

};


#endif  //_INXErrLogScriptingDefs_h_

// End INXErrLogScriptingDefs.h
