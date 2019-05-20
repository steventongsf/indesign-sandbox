//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/actionmenus/ActionMenuProvider.cpp $
//  
//  Owner: Tim Wright
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

// ----- Implementation Includes -----

#include "BehaviorUIID.h"
#include "CServiceProvider.h"	

//========================================================================================
// CLASS MenuOrderProvider
//========================================================================================

class ActionMenuProvider : public CServiceProvider
{
public:
	ActionMenuProvider(IPMUnknown *boss);
	
	virtual void			GetName(PMString * pName); 
	virtual ServiceID		GetServiceID(); 
	virtual bool16			IsDefaultServiceProvider(); 
	virtual InstancePerX	GetInstantiationPolicy(); 
};

//========================================================================================
// METHODS ActionMenuProvider
//========================================================================================

CREATE_PMINTERFACE(ActionMenuProvider, kActionMenuProviderImpl)

//----------------------------------------------------------------------------------------
// ActionMenuProvider::ActionMenuProvider
//----------------------------------------------------------------------------------------

ActionMenuProvider::ActionMenuProvider(IPMUnknown *boss) :
	CServiceProvider(boss) 
{
}

//----------------------------------------------------------------------------------------
// ActionMenuProvider::GetName
//----------------------------------------------------------------------------------------

void ActionMenuProvider::GetName(PMString * pName) 
{
	pName->SetCString("$$$/Service/Register/Action Menu");
}

//----------------------------------------------------------------------------------------
// ActionMenuProvider::GetServiceID
//----------------------------------------------------------------------------------------

ServiceID ActionMenuProvider::GetServiceID() 
{
	return kActionMenuService;
}

//----------------------------------------------------------------------------------------
// ActionMenuProvider::IsDefaultServiceProvider
//----------------------------------------------------------------------------------------

bool16 ActionMenuProvider::IsDefaultServiceProvider() 
{
	return kFalse;
}

//----------------------------------------------------------------------------------------
// ActionMenuProvider::GetInstantiationPolicy
//----------------------------------------------------------------------------------------

IK2ServiceProvider::InstancePerX ActionMenuProvider::GetInstantiationPolicy() 
{
	return IK2ServiceProvider::kInstancePerUse;
}
