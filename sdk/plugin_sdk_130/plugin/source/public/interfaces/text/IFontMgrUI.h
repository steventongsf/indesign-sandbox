//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/IFontMgrUI.h $
//  
//  Owner: emenning
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
#ifndef __IFontMgrUI__
#define __IFontMgrUI__

#include "FontUsageDialogID.h"

//----------------------------------------------------------------------------------------
// Interface IFontMgrUI
//----------------------------------------------------------------------------------------

/** Handles UI related to the font manager.
	@ingroup text_font
*/
class IFontMgrUI : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_IFONTMGRUI };

		
		/**
			Update the font UI to reflect the font currently on the system.
		*/
		virtual void UpdateFontUI() = 0;
};
 
#endif
