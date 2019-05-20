//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/inxerrorlogging/SDKFileUtils.h $
//  
//  Owner: Adobe Developer Technologies
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

#ifndef __SDKFILEUTILS_h__
#define __SDKFILEUTILS_h__

// General includes:
#include "PMString.h"

class SDKFileUtils
{
public:
	static void SetBaseFilePath(const PMString& path);
	static void GetBaseFilePath(PMString& path);

	static void GetNextFilePath(PMString& path);

private:

	static PMString fErrorLogFilePath;
	static int32 fNumFiles;
};

#endif // __IINXErrLogFacade_h__
