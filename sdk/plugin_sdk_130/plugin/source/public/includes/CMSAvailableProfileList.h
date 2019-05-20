//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/CMSAvailableProfileList.h $
//  
//  Owner: Matt Phillips
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
#ifndef __CMSAvailableProfileList__
#define __CMSAvailableProfileList__
#include "ICMSProfile.h"

class CMSAvailableProfileList
{
public:
	virtual ~CMSAvailableProfileList() {};

	virtual bool32 		GetNthAvailableProfileName(int32 index, PMString& theName) = 0;		
	virtual bool32 		GetNthAvailableProfileFile(int32 index, PMString& theName) = 0;		
	virtual bool32 		GetNthAvailableProfileSpaceAndClass(int32 index, ICMSProfile::profileSpace* pSpace, ICMSProfile::profileClass* pClass) = 0;
	virtual int32 			NumAvailableProfiles() = 0;
	virtual int32			FindAvailableProfile(const PMString& theName) = 0;
};

#endif