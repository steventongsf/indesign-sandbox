//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/tables/ITableAttrUID.h $
//  
//  Owner: Joe Shankar
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
//  Purpse: Data interface that holds a reference to a UID.
//  
//========================================================================================

#ifndef __ITableAttrUID__
#define __ITableAttrUID__

#include "IPMUnknown.h"
#include "TablesID.h"

class ITableAttrUID : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_ITABLEATTRUID };
			
	virtual UID  Get() const = 0;
	virtual void Set(UID newUID) = 0;
};

#endif
