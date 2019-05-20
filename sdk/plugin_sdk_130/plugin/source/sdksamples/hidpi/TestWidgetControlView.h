//******************************************************************************
//***
//*** BasicPanelTriState.sdk
//*** TestWidgetControlView.h
//***
//*** Copyright (c) 2013, vjoon GmbH
//*** Alle Rechte vorbehalten. / All rights reserved.
//***
//******************************************************************************

#include "DVControlView.h"

class TestWidgetControlView : public DVControlView
{
public:
	TestWidgetControlView(IPMUnknown* iBossP)
	 : DVControlView(iBossP) {}
	
	virtual void ReadWrite(IPMStream* iStreamP, ImplementationID iImpID);
	virtual void Draw(IViewPort* iViewPortP, SysRgn iUpdateRgn);
};
