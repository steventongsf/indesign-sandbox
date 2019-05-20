//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/precomp/common/AATPlugInBuildFlags.h $
//  
//  Owner: Lonnie Millett
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
//  ADOBE CONFIDENTIAL
//  
//========================================================================================

#pragma once
#include "GeneralBuildFlags.h"

#ifndef AATLIB_DECL
	#define AATLIB_DECL DLL_IMPORT_DECL
#endif

#ifndef PLUGIN_DECL
	#define PLUGIN_DECL DLL_EXPORT_DECL
#endif

// PLUGIN enables correct resource and quickdraw global access.
// While a plugin is in fact a shared library, PLUGIN is considered
// less strict than using the symbol SHAREDLIBRARY, which is also
// used to turn off some application specific behavior in plugins
// (such as the installation of test menus).
//#define PLUGIN 1
