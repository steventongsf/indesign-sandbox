//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/tables/ICellTracker.h $
//  
//  Owner: Danielle Bessette
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
#ifndef __ICellTracker__
#define __ICellTracker__

#include "TablesID.h"
#include "ParcelKey.h"

class ITableFrame;
class ITracker;
class IControlView;
class IEvent;


/** 
 * 	Creates a tracker to perform actions on a table
 *  	@ingroup table_tracker
 */

class ICellTracker : public IPMUnknown
{

public:
    enum { kDefaultIID = IID_ICELLTRACKER };

	/**
		Creates a cell tracker to work on the passed in data
		@param	tableFrame		The table frame we are tracking in
		@param	parcelKey		The key of the parcel (cell) we are tracking
		@param	event			The event that spawned the tracker
		@param	view				The current view
		@param  isRowSelected	 The entire row is selected or not
		@param  isColumnSelected  The entire column is selected or not
		@return	ITracker			A tracker
	*/
	virtual ITracker* CreateTracker(const ITableFrame* tableFrame,
								ParcelKey parcelKey,
								const IEvent* event,
								IControlView *view,
								bool isRowSelected = false,
								bool isColumnSelected = false) const = 0;

};

#endif
