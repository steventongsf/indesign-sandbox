//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/gotolasttextedit/GTTxtEdtControlStripRegister.cpp $
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

// ----- Interfaces -----

#include "IControlStripRegister.h"

// ----- Includes -----

#include "GTTxtEdtResDefs.h"

// ----- ID.h files -----

#include "GTTxtEdtID.h"


/** Registers our control strip suite with the application.

@ingroup gotolasttextedit
*/
class GTTxtEdtControlStripRegister: public CPMUnknown<IControlStripRegister>
{
public:
	/** constructor
	*/
	GTTxtEdtControlStripRegister(IPMUnknown* boss);
	/** provides the IID of the control strips we are registering.
	@param IIDList OUT list of IIDs relating to the control strip entity
	*/
	virtual void GetRegisteredControlStripWidgetSuites(K2Vector<PMIID>& IIDList, K2Vector<ControlStripWidgetInfo>& controlSetList) const;
};

/*
*/
CREATE_PMINTERFACE(GTTxtEdtControlStripRegister, kGTTxtEdtControlStripRegisterImpl)

/*
*/
GTTxtEdtControlStripRegister::GTTxtEdtControlStripRegister(IPMUnknown* boss):
CPMUnknown<IControlStripRegister>(boss)
{
}

/*
*/
void GTTxtEdtControlStripRegister::GetRegisteredControlStripWidgetSuites(K2Vector<PMIID>& IIDList, K2Vector<ControlStripWidgetInfo>& controlSetList) const
{
	// IID for our selection suite
	IIDList.push_back(IID_IGTTXTEDTCONTROLSTRIPSUITE);

	// The widget this suite adds
	controlSetList.push_back(kGTTxtEditControlStripSet);
}
