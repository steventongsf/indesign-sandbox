//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/ShutdownUtils.h $
//  
//  Owner: daan Strebe
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
//  
//  Application include declarations
//  
//========================================================================================

#ifndef __ShutdownUtils_h__
#define __ShutdownUtils_h__

/**
 *	InDesign Server Only
 *
 *	Provides a mechanism for cleanly shutting down the server. There may be
 *	pending requests. These utilities take into account those requests and
 *	wait to shutdown until they complete.
 */

class PUBLIC_DECL ShutdownUtils
{
public:
	
	/**
	 * Request a shutdown.
	 */
	static void RequestShutdown();

	/**
	 * Cancel a shutdown request.
	 */
	static void CancelShutdown();

	/**
	 * It there currently a pending shutdown request?
	 */
	static bool ShutdownRequested();

private:
	static bool ts_ShutdownRequested;
};

#endif
