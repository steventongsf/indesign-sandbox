//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/OwnedItemDataList.h $
//  
//  Owner: dwaterfa
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
#ifndef __OwnedItemDataList__
#define __OwnedItemDataList__

#include "IPMUnknown.h"
#include "K2Vector.h"


/**
	This data structure encapsulates information about the location where an owned item is referenced,
	its uid, and its class id.

	@ingroup text_story
*/
struct OwnedItemData
{
	typedef base_type	data_type;

	OwnedItemData() : fAt(0) { }
	OwnedItemData(TextIndex at, UID uid, ClassID classID) :
		fAt(at), fUID(uid), fClassID(classID) { }

	UID GetInlineID() const { return fUID; }

	TextIndex			fAt;
	UID					fUID;
	ClassID				fClassID;

	int32 operator==(const OwnedItemData&) const
	{ ASSERT_FAIL("shouldn't be called"); return -1;}

};

typedef K2Vector<OwnedItemData>	OwnedItemDataList;


#endif	// __OwnedItemDataList__

