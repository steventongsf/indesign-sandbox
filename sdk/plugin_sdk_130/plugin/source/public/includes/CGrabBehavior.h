//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/CGrabBehavior.h $
//  
//  Owner: 
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
#ifndef __CGrabBehavior__
#define __CGrabBehavior__

#include "IPMUnknown.h"
#include "IGrabBehavior.h"
#include "ContentDropperID.h"

/** Generic Implementation to IGrabBehavior
	Subclasses to override functionality as per pageitem.
*/
class CGrabBehavior : public CPMUnknown<IGrabBehavior>
{
public:	

	CGrabBehavior(IPMUnknown *boss);
	virtual ~CGrabBehavior();

	/** Can the source item be grabbed as NeedfulSet 
		@return true if "this" could have items in NeedfulSet
	*/
	virtual bool16		CanFormNeedfulSet() const;	

	/** Returns UIDList of elements that would be part of the NeedfulSet for this item.
		It does not include the item's own UID. 
		Only the items that should be part of set for this item are returned
	*/

	virtual UIDList		GetNeedfulSet() const;


	/** Returns UID of the outermost element that has IID_IGRABBEHAVIOR interface defined on it
	*/
	virtual UID			GetRootUID() const;

};

#endif //__CGrabBehavior__
