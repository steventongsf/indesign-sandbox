//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/libs/widgetbin/includes/TouchControlBarPriorityDefs.h $
//  
//  Owner: Rahul Jain.
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
//  Touch Control Bar widgets priority definitions. Used in TouchControl.fh.
//  
//========================================================================================

#pragma once
#ifndef __TOUCHCONTROLBARPRIORITYDEFS__
#define __TOUCHCONTROLBARPRIORITYDEFS__

// Priorities
const PMReal kColorPickerTouchControlPriority		= 1.0;
const PMReal kStrokeTouchControlPriority			= 2.0;
const PMReal kXPTouchControlPriority				= 3.0;
const PMReal kAlignTouchControlPriority				= 4.0;
const PMReal kTextTouchControlPriority				= 5.0;
const PMReal kCCLibraryTouchControlPriority			= 6.0;
const PMReal kContextMenuTouchControlPriority 		= 100.0;

#endif // __TOUCHCONTROLBARPRIORITYDEFS__
