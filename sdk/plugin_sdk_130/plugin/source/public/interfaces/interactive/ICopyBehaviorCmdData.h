//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/interactive/ICopyBehaviorCmdData.h $
//  
//  Owner: Michael Burbidge
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

#pragma once
#ifndef __ICopyBehaviorCmdData_h__
#define __ICopyBehaviorCmdData_h__

#include "IPMUnknown.h"
#include "BehaviorID.h"

/** Parameters for a CopyBehaviorCmd
*/

class ICopyBehaviorCmdData : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_ICOPYBEHAVIORCMDDATA };
	
	/** Set database and uid of owner of behavior to copy */
	virtual void Set(IDataBase* dstDb, const UID& dstOwner) = 0;

	/** @return database of owner of behavior to copy */
	virtual IDataBase* GetDstDataBase() const = 0;

	/** @return uid of owner of behavior to copy */
	virtual UID GetDstOwner() const = 0;
};

#endif // __ICopyBehaviorCmdData_h__
