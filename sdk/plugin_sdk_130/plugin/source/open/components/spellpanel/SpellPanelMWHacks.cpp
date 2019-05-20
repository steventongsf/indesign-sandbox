//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/spellpanel/SpellPanelMWHacks.cpp $
//  
//  Owner: Bernd Paradies
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
#include "InterfaceFactory.h"
#include "ClassFactory.h"

// -------------------------------------------------------------
// ::DontDeadStrip()
// -------------------------------------------------------------

void DontDeadStrip();

void DontDeadStrip()
{
	extern bool16 gFalse;
	if (gFalse)
	{
#include "SpellPanelFactoryList.h"
#include "SpellPanelClassFactoryList.h"
	}
}
