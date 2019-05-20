//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/libs/widgetbin/includes/DVControlEventHandler.h $
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
//  ADOBE CONFIDENTIAL
//  
//  Copyright 1997-2008 Adobe Systems Incorporated. All rights reserved.
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
#ifndef __DVControlEventHandler__
#define __DVControlEventHandler__
	

#include "DVHostedWidgetEH.h"

#ifdef DV_WIDGET_BUILD
#pragma export on
#endif

class DV_WIDGET_DECL DVControlEventHandler : public DVHostedWidgetEH
{
	typedef DVHostedWidgetEH inherited;
public:

	// ----- Initialization -----

	DVControlEventHandler(IPMUnknown *boss); 
	virtual ~DVControlEventHandler();
		
	virtual const char* class_name()			{static const char* name = "DVControlEventHandler"; return name;}
};

#pragma export off

#endif

