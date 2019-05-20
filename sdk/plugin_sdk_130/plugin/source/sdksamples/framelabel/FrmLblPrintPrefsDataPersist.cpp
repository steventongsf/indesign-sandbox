//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/framelabel/FrmLblPrintPrefsDataPersist.cpp $
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
#include "IBoolData.h"
#include "IPMStream.h"

// General includes
#include "CPMUnknown.h"

// Project includes:
#include "FrmLblID.h"

/** Stores persistent data to control the print preference of
the frame label adornment; implements IBoolData.

@ingroup framelabel

*/

class FrmLblPrintPrefsDataPersist : public CPMUnknown<IBoolData>
{
public:
	FrmLblPrintPrefsDataPersist(IPMUnknown* boss);  

	void Set(ValueType b);

    bool16 GetBool() const;

	/** Persistence related method; reads from or writes to given stream
	@param s IN the persistent in and out stream.
	@param prop IN the implementation ID
	*/
	void ReadWrite(IPMStream* s, ImplementationID prop);

private:
	ValueType fValue;
};

CREATE_PERSIST_PMINTERFACE(FrmLblPrintPrefsDataPersist, kFrmLblPrintPrefsDataPersistImpl)

FrmLblPrintPrefsDataPersist::FrmLblPrintPrefsDataPersist(IPMUnknown* boss) :
	CPMUnknown<IBoolData>(boss),
	fValue(kFalse)
{
}

void FrmLblPrintPrefsDataPersist::Set(ValueType b)
{
	PreDirty();
	fValue = b;
}

bool16 FrmLblPrintPrefsDataPersist::GetBool() const
{
	return fValue;
}


/** Persistence related method; reads from or writes to given stream
@param s IN the persistent in and out stream.
@param prop IN the implementation ID
*/
void FrmLblPrintPrefsDataPersist::ReadWrite(IPMStream* s, ImplementationID prop)
{
	s->XferBool(fValue);
}