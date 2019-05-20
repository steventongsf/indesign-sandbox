//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/wavetool/WaveTrackerRegister.cpp $
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

#include "VCPlugInHeaders.h"

// Interface includes:
#include "ITrackerRegister.h"
#include "ITrackerFactory.h"
#include "ISession.h"

// General includes:
#include "HelperInterface.h"

// Project includes:
#include "WavTlID.h"
#include "LayoutUIID.h"

/**	Registers this plug-in's trackers with the application. 

	
	@ingroup wavetool
*/
class WaveTrackerRegister : public ITrackerRegister
{
public:
	/** Constructor.
	 */
	WaveTrackerRegister(IPMUnknown *boss) :
		HELPER_METHODS_INIT(boss)
		{}

	/**Register the trackers with the application tracker factory. 
	 */
	void Register(ITrackerFactory *factory);
	
	DECLARE_HELPER_METHODS()
};

/* Make the implementation available to the application.
*/
CREATE_PMINTERFACE(WaveTrackerRegister, kWavTlTrackerRegisterImpl)

/* Provide implementations for the standard IPMUnkown methods.
*/
DEFINE_HELPER_METHODS(WaveTrackerRegister)

/*
*/
void WaveTrackerRegister::Register(ITrackerFactory* factory)
{
	factory->InstallTracker(kLayoutWidgetBoss, kSawWaveToolBoss, kSawWaveTrackerBoss);
	factory->InstallTracker(kLayoutWidgetBoss, kSineWaveToolBoss, kSineWaveTrackerBoss);
}

// End, WaveTrackerRegister.cpp.



