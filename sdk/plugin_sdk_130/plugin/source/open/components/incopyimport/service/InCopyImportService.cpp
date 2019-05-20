//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/incopyimport/service/InCopyImportService.cpp $
//  
//  Owner: ?
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
#include "CServiceProvider.h"
 
class InCopyImportService : public CServiceProvider
{
	public:
		InCopyImportService(IPMUnknown *boss) : CServiceProvider(boss) {}

		virtual void GetName(PMString * pName);
		virtual ServiceID GetServiceID();
		virtual bool16 IsDefaultServiceProvider();
		virtual InstancePerX GetInstantiationPolicy();		
		virtual IPlugIn::ThreadingPolicy GetThreadingPolicy() const 
			{ return IPlugIn::kMultipleThreads; }
};

#include "OpenPlaceID.h"		// for kImportProviderService
#include "InCopyImportID.h"

CREATE_PMINTERFACE(InCopyImportService, kInCopyImportServiceImpl)

//---------------------------------------------------------------
// InCopyImportService::GetName 
//---------------------------------------------------------------
void InCopyImportService::GetName(PMString *pName)
{
	ASSERT_UNIMPLEMENTED();
}

//---------------------------------------------------------------
// InCopyImportService::IsDefaultServiceProvider 
//---------------------------------------------------------------
bool16 InCopyImportService::IsDefaultServiceProvider()
{
	return kFalse;
}

//---------------------------------------------------------------
// InCopyImportService::GetServiceID 
//---------------------------------------------------------------
ServiceID InCopyImportService::GetServiceID()
{
	return kImportProviderService;
}

//---------------------------------------------------------------
// InCopyImportService::GetInstantiationPolicy 
//---------------------------------------------------------------
IK2ServiceProvider::InstancePerX InCopyImportService::GetInstantiationPolicy()
{
	return IK2ServiceProvider::kInstancePerSession;
}


