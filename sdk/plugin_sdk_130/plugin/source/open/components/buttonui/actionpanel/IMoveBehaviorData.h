//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/actionpanel/IMoveBehaviorData.h $
//  
//  Owner: Michael Brubidge
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
#ifndef __IMoveBehaviorData_h__
#define __IMoveBehaviorData_h__

#include "IPMUnknown.h"
#include "BehaviorID.h"
#include "BehaviorTypes.h"

#include <vector>

class IMoveBehaviorData : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IMOVEBEHAVIORDATA };
	
	virtual void Set(IDataBase* db,
					 const std::vector< std::pair<ActionEvent, UID> >& behaviors,
					 const ActionEvent& event,
					 const int32& position) = 0;
	virtual void Clear() = 0;

	virtual IDataBase* GetDataBase() const = 0;
	virtual std::vector< std::pair<ActionEvent, UID> > GetBehaviors() const = 0;
	virtual ActionEvent GetEvent() const = 0;
	virtual int32 GetPosition() const = 0;
};

#endif // __IMoveBehaviorData_h__
