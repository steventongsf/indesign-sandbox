//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/ui/IOwnerDrawItem.h $
//  
//  Owner: Dave Burnard
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
#ifndef __IOwnerDraw__
#define __IOwnerDraw__

#include "PMTypes.h"
#include "widgetid.h"

//========================================================================================
// CLASS IOwnerDrawItem
//========================================================================================

class IOwnerDrawItem : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IOWNERDRAWITEM };

	virtual void MeasureItem(int32 itemID,  uint16& itemWidth, uint16& itemHeight) = 0;
	virtual bool16 IsItemEnabled(int32 itemID) = 0;

	/** Determibe if current item being drawn is inside drop down widget or in the popup menu.
		The return value is only meaningful during drawing process.
		@return kTrue if inside widget, kFalse otherwise.
	*/
	virtual bool16 IsItemBeingDrawnInsideWidget() = 0;

	virtual void MeasureItemHeight(int32 itemID, uint16& itemHeight) = 0;
};

#endif
