//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IApplyMasterSignalData.h $
//  
//  Owner: Patrick Lau
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
//  Purpose:	Data send with the ApplyMaster signal
//  
//========================================================================================

#pragma once
#ifndef __IAPPLYMASTERSIGNALDATA__
#define __IAPPLYMASTERSIGNALDATA__

#include "IPMUnknown.h"
#include "MasterPageID.h"
#include "UIDList.h"

class ICommand;

class IApplyMasterSignalData : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IAPPLYMASTERSIGNALDATA };
	
	virtual void SetApplyMasterSignalData(ICommand *ApplyMasterCmd, 
					 UIDList *oldMasters, 
					 K2Vector<int32> *oldMasterIndex) = 0;
	virtual ICommand *GetApplyMasterCmd() = 0; // may be nil
	virtual UIDList *GetOldMasters() = 0;
	virtual K2Vector<int32> *GetOldMasterIndex() = 0;
};

#endif // __IAPPLYMASTERSIGNALDATA__

