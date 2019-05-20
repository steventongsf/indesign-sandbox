//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/xmedia/XSLEnablerID.h $
//  
//  Owner: Michael Burbidge
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
//  Info:	Contains IDs used by the XSLEnabler plugin for access to AXE.
//  
//========================================================================================

#ifndef __XSLEnablerID__
#define __XSLEnablerID__

#include "CrossPlatformTypes.h"
#include "IDFactory.h"

#define kXSLEnablerPrefix	 					RezLong(0x1A900)
#define kXSLEnablerPluginName 					"XSLEnabler"

// <Plugin ID>
DECLARE_PMID(kPlugInIDSpace, kXSLEnablerPluginID, kXSLEnablerPrefix + 1)

// <Class ID>
DECLARE_PMID(kClassIDSpace, kXSLEnablerServiceBoss, kXSLEnablerPrefix + 1)

// <Interface ID>

// <Service ID>

// <Implementation ID>

#endif
