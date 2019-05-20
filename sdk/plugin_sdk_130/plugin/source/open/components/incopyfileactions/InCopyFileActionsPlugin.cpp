//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/incopyfileactions/InCopyFileActionsPlugin.cpp $
//  
//  Owner: Chris Parrish
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

#include "VCPlugInHeaders.h"
#include "PlugIn.h"

static PlugIn gPlugIn;

// ----- This is the main entry point from the application to the plug-in.
//		 The application calls this function when the plug-in is installed 
//		 or loaded. This function is called by name, so it must be called 
//		 GetPlugIn, and defined as C linkage.

IPlugIn *GetPlugIn()
{
	return &gPlugIn;
}



