//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IRecentDocStyleInfo.h $
//  
//  Owner: Michael Easter
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  Copyright 2015 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//  
//  Description:
//  
//  
//========================================================================================


#pragma once
#ifndef __IRecentDocStyleInfo__
#define __IRecentDocStyleInfo__

// ----- Includes -----
#include "IPMUnknown.h"
#include "DocFrameworkID.h"
#include "IDTime.h"

/**
Interface used to hold file info for a document style.
*/

class IRecentDocStyleInfo : public IPMUnknown
{
public:
	

	enum {
		kDefaultIID = IID_IRECENTDOCSTYLEINFO
	};

	/**
	Sets last used time when this preset was used.
	@param fileInfo	IN Document file info.
	*/
	virtual void SetLastUsedTime(const IDTime& v) = 0;

	/**
	Returns the file thumbnail info.
	@param fileInfo	OUT Document file info.
	*/
	virtual IDTime GetLastUsedTime() const = 0;
};

#endif	// __IRecentDocStyleInfo__
