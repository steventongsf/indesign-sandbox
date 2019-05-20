//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/IFrameThreadPrefsCmdData.h $
//  
//  Owner: Tom Taylor
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
#ifndef __IFRAMETHREADPREFSCMDDATA__
#define __IFRAMETHREADPREFSCMDDATA__

#include "IPMUnknown.h"
#include "TextID.h"
#include "UIDRef.h" 

/** @ingroup text_layout
*/
class IFrameThreadPrefsCmdData : public IPMUnknown
{
public:
	virtual void Set(const	UIDRef&	doc, const	bool16	shown) = 0;
	virtual const UIDRef& GetDocument() const = 0;
	virtual const bool16 GetFrameThreadsShown() const = 0;
};


#endif
