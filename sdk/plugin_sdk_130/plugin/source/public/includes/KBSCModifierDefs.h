//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/KBSCModifierDefs.h $
//  
//  Owner: lance bushore
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
#ifndef __KBSCModifierDefs__
#define __KBSCModifierDefs__

// KBSC modifiers
#define kNoKBSCModifier				0x0
#define kControl					0x1
#define kShift						0x10
#define kOption						0x100
#define kMacControl					0x1000
#define kControlShift				kControl|kShift
#define kControlOption				kControl|kOption
#define kShiftOption				kShift|kOption
#define kControlShiftOption			kControl|kShift|kOption

#endif // __KBSCModifierDefs__