//******************************************************************************
//***
//*** BasicPanelTriState.sdk
//*** File.h
//***
//*** Copyright (c) 2013, vjoon GmbH
//*** Alle Rechte vorbehalten. / All rights reserved.
//***
//******************************************************************************

#pragma once

#include "CEventHandler.h"

class TestWidgetEventHandler : public CEventHandler
{
public:
	TestWidgetEventHandler(IPMUnknown* iBossP)
	 : CEventHandler(iBossP){}
	
	virtual bool16 LButtonDn(IEvent* iEventP);
};