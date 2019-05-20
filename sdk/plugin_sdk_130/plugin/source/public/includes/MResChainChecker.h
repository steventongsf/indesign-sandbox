//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/MResChainChecker.h $
//  
//  Owner: Dave Burnard
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
#ifndef __MResChainChecker__
#define __MResChainChecker__

#include "PMTypes.h"
#include <string>

#ifdef DEBUG

// Used to verify that the resource chain hasn't been corrupted
class PUBLIC_DECL MResChainChecker
{       
public:
    MResChainChecker(const char* msg);
    
    ~MResChainChecker();
    
    static bool IsEnabled();
    
private:
    short fOldCurRes;
    std::string fMsg;
    static bool kResChainCheckerEnabled; // Off by Default    
};
#endif /* DEBUG */    

#endif // __MResChainChecker__
