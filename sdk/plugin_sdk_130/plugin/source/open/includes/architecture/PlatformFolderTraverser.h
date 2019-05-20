//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/includes/architecture/PlatformFolderTraverser.h $
//  
//  Owner: Matt Joss
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  ADOBE CONFIDENTIAL
//  
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  All information contained herein is, and remains
//  the property of Adobe Systems Incorporated and its suppliers,
//  if any.  The intellectual and technical concepts contained
//  herein are proprietary to Adobe Systems Incorporated and its
//  suppliers and may be covered by U.S. and Foreign Patents,
//  patents in process, and are protected by trade secret or copyright law.
//  Dissemination of this information or reproduction of this material
//  is strictly forbidden unless prior written permission is obtained
//  from Adobe Systems Incorporated.
//  
//========================================================================================

#pragma once
#ifdef MACINTOSH
#include "MFolderTraverser.h"

typedef MFolderTraverser PlatformFolderTraverser;
#endif


#ifdef WINDOWS
#include "WFolderTraverser.h"

typedef WFolderTraverser PlatformFolderTraverser;
#endif
