//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/incopy/IInCopyFileActionsSuite.h $
//  
//  Owner: Michele Goodwin
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
#ifndef __IInCopyFileActionsSuite__
#define __IInCopyFileActionsSuite__

#include "IPMUnknown.h"
#include "InCopyCoreID.h"

/**
	IInCopyFileActionsSuite

	This is a suite for the InCopy File Actions.
*/
class IInCopyFileActionsSuite : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_IINCOPYFILEACTIONSSUITE };

	/**	Can save the incopy story (text or graphic).
		@return bool16 
	 */
	virtual bool16 CanSaveStory() const = 0;

	/**	Do the story save (text or graphic story).
		@return ErrorCode 
	 */
	virtual ErrorCode DoSaveStory() = 0;

	/**	Can revert the incopy story (text or graphic).
		@return bool16 
	 */
	virtual bool16 CanRevertStory() const = 0;

	/**	Do the story revert (text or graphic story).
		@return ErrorCode 
	 */
	virtual ErrorCode DoRevertStory() = 0;
};

#endif // _IInCopyFileActionsSuite_
