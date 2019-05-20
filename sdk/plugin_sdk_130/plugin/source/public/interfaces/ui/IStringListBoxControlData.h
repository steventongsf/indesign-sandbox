//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/ui/IStringListBoxControlData.h $
//  
//  Owner: Bob Freeman
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
#ifndef __IStringListBoxControlData_h__
#define __IStringListBoxControlData_h__

#include "IListControlData.h"
#include "K2Vector.h"

/** Interface representing a PMString based listbox data-model. 
*/
class IStringListBoxControlData : public IListControlData
{
public:	
	// ----- Constants -----
	
	enum { kBeginning = 0, kEnd = -2 };

	// ----- List maintainence -----

  	/** Add an item to the list.
		@param item entity to add to the list
		@param at position to add item at
		@param invalidate specifies whether control should be invalidated
		@param notifyOfChange specifies whether registered observers should be notified of this change to the data model
	*/
	virtual void		Add(const PMString& item, int32 at = kEnd, bool16 invalidate = kTrue, bool16 notifyOfChange = kTrue) = 0;
							 
 	/** Add a list of items to the list.
		@param items collection of new items to add into list
		@param invalidate specifies whether control should be invalidated
		@param notifyOfChange specifies whether registered observers should be notified of this change to the data model
	*/
	virtual void		Add(const K2Vector<PMString>& items, bool16 invalidate = kTrue, bool16 notifyOfChange = kTrue) = 0;
							 
 	/** Replace the nth item.	
		@param item specifies new item 
		@param index specifies position where item to be replaced is
		@param invalidate specifies whether control should be invalidated
		@param notifyOfChange specifies whether registered observers should be notified of this change to the data model
	*/
	virtual void		Replace(const PMString& item, int32 index, bool16 invalidate = kTrue, bool16 notifyOfChange = kTrue) = 0;
							
 	/** Return the nth item.
		@return item at given position in the list
	*/
	virtual PMString			operator[](int32 index) const = 0;
							
 	/** Return the id of the nth item. ID's are a unique integer assigned to the string when it is added. This id is used
 	      by the underlying tree control to track tree nodes in the list.
		@return item at given position in the list
	*/
	virtual int32			GetIDAt(int32 index) const = 0;
};

#endif
