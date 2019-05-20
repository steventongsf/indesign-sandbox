//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/graphics/LineID.h $
//  
//  Owner: Robin_Briggs
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
//  Contains IDs used by the group item plug-in
//  
//========================================================================================

#ifndef __LINEID__
#define __LINEID__
#include "CrossPlatformTypes.h"
#include "IDFactory.h"

#define kLinePrefix	 RezLong(0xB00)

// <Start IDC>
// PluginID
#define kLinePluginName 			"Line"
DECLARE_PMID(kPlugInIDSpace, kLinePluginID, kLinePrefix + 1)

// <Class ID>
// ClassIDs
DECLARE_PMID(kClassIDSpace, kLineToolBoss, kLinePrefix + 1)
DECLARE_PMID(kClassIDSpace, kLineTrackerBoss, kLinePrefix + 2)
DECLARE_PMID(kClassIDSpace, kLineTrackerRegisterBoss, kLinePrefix + 3)


// <Implementation ID>
// Implementation IIDs
DECLARE_PMID(kImplementationIDSpace, kLineToolImpl, kLinePrefix + 1)
DECLARE_PMID(kImplementationIDSpace, kLineTrackerImpl, kLinePrefix + 2)
DECLARE_PMID(kImplementationIDSpace, kLineTrackerRegisterImpl, kLinePrefix + 3)

// <Widget ID>
// Widget IDs
DECLARE_PMID(kWidgetIDSpace, kLineToolWidgetId, kLinePrefix + 1)

// <Action ID>
// Action IDs
DECLARE_PMID(kActionIDSpace, kLineToolActionID, kLinePrefix + 1)

#endif // __LineID__








