//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/components/server/sampleclient/MRendezvousClient.h $
//  
//  Owner: Peter Boctor
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

#ifndef __MRendezvousClient__
#define __MRendezvousClient__

#error "is this file obsolete? - I see no implementation"

#include <CarbonEvents.h>

class RendezvousClient
{
public:

	virtual void ListClients();
	virtual char* FindClient(const char* clientName);

private:

	static void ListClientBrowserCallback(CFNetServiceBrowserRef browser, CFOptionFlags flags, CFTypeRef domainOrService, CFStreamError* error, void* info);

	static void	FindClientBrowserCallback(CFNetServiceBrowserRef browser, CFOptionFlags flags, CFTypeRef domainOrService, CFStreamError* error, void* info);
	static void FindClientResolveCallback(CFNetServiceRef service, CFStreamError* error, void* info);
	
	// FIXME_DECARB: Carbon dependency
	static void InstallEventHandlers();
	static pascal void TimerAction(EventLoopTimerRef theTimer, EventLoopIdleTimerMessage inAction, void* userData);
	
	static void CancelBrowsing();
	static void CancelResolving();
	
	static CFStringRef fFindClientName;
	static char fFoundClientIP[64];
	static CFNetServiceBrowserRef fServiceBrowserRef;
	static CFNetServiceRef fServiceBeingResolved;
};

#endif
