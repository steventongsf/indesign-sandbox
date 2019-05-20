//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/private/toolkit/includes/DiagnosticLogUtils.h $
//  
//  Owner: Gang Xiao
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
#ifndef DiagnosticLogUtils_h
#define DiagnosticLogUtils_h

/**
	DiagnosticLog public utilities
*/
class PUBLIC_DECL DiagnosticLogUtils
{
public:
	/**
		Turn on all info collector so that they start sending out information to each logger.
		This function should be called from DiagnosticLog plugIn after all the logger has been
		initialized.
	*/
	static void DiagnosticLogStartup();

	/**
		Turn off all info collector and clean up. This function should be called from 
		DiagnosticLog plugIn before shut down all the logger.
	*/
	static void DiagnosticLogShutdown();
};

#endif 	// DiagnosticLogUtils_h