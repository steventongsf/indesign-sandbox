//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/ui/IPageTabController.h $
//  
//  Owner: Brendan O'Shea
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
#ifndef __IPageTabController__
#define __IPageTabController__

#include "IPMUnknown.h"

class IPageTabController : public IPMUnknown
{
public:
	virtual bool16 AssignPageToWidget_( const UIDRef& newPage, PMReal pageTabWidth, PMReal pageTabHeight, PMReal corner, bool16 bInval) = 0;
	virtual UIDRef GetAssignedPage() = 0;
	virtual void GetPageTabDimensions_( PMReal* width, PMReal* height, PMReal* corner) = 0;
};

#endif
