//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/wlistboxcomposite/WLBCmpPenObserver.cpp $
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

// Implementation includes
#include "widgetid.h"

// Interface includes
#include "ISubject.h"
#include "ITriStateControlData.h"
// Implem includes
#include "CAlert.h"
#include "CObserver.h"
#include "WLBCmpID.h"


/**

	Observes the "pen" buttons in the widget list.

	@ingroup wlistboxcomposite
	
*/
class WLBCmpPenObserver : public CObserver
{
public:
	
	/**
		Constructor for WLBListBoxObserver class.
		@param interface ptr from boss object on which this interface is aggregated.
	*/
	WLBCmpPenObserver(IPMUnknown *boss);

	/**
		Destructor.
	*/	
	~WLBCmpPenObserver();

	/**
		AutoAttach is only called for registered observers
		of widgets.  This method is called by the application
		core when the widget is shown.
	
	*/	
	virtual void AutoAttach();

	/**
		AutoDetach is only called for registered observers
		of widgets. Called when widget hidden.
	*/	
	virtual void AutoDetach();

	/**
		Update when there's been a change on the pen widget.
	
		@param theChange this is specified by the agent of change; it can be the class ID of the agent,
		or it may be some specialised message ID.
		@param theSubject this provides a reference to the object which has changed; in this case, the button
		widget boss object that is being observed.
		@param protocol the protocol along which the change occurred.
		@param changedBy this can be used to provide additional information about the change or a reference
		to the boss object that caused the change.
	*/	
	virtual void Update(const ClassID& theChange, ISubject* theSubject, const PMIID &protocol, void* changedBy);


	
};

CREATE_PMINTERFACE(WLBCmpPenObserver, kWLBCmpPenObserverImpl)


WLBCmpPenObserver::WLBCmpPenObserver(IPMUnknown* boss)
: CObserver(boss)
{
	
}


WLBCmpPenObserver::~WLBCmpPenObserver()
{
	
}


void WLBCmpPenObserver::AutoAttach()
{
	InterfacePtr<ISubject> subject(this, UseDefaultIID());
	if (subject != nil)
	{
		subject->AttachObserver(this, IID_ITRISTATECONTROLDATA);
	}
	
}


void WLBCmpPenObserver::AutoDetach()
{
		InterfacePtr<ISubject> subject(this, UseDefaultIID());
	if (subject != nil)
	{
		subject->DetachObserver(this,IID_ITRISTATECONTROLDATA);
	}
}


void WLBCmpPenObserver::Update
(
	const ClassID& theChange, 
	ISubject* theSubject, 
	const PMIID &protocol, 
	void* changedBy
)
{
	if(theChange == kTrueStateMessage) {
		// Then the button has been activated.
		do {
				PMString dbgInfoString("WLBCmpPenObserver::Update() ");
				dbgInfoString.SetTranslatable(kFalse);	// only for debug- not real code
				CAlert::InformationAlert(dbgInfoString);
		
		} while(0);
	}
}




