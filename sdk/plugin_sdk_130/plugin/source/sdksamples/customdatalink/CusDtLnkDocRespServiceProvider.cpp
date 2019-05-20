//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/customdatalink/CusDtLnkDocRespServiceProvider.cpp $
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

// Implementation includes:
#include "CServiceProvider.h"
#include "DocumentID.h"
#include "CusDtLnkID.h"


/** Implements IK2ServiceProvider based on
	the partial implementation CServiceProvider.


	@ingroup customdatalink
	
*/
class CusDtLnkDocRespServiceProvider : public CServiceProvider
{
	public:

		/** Constructor 
			@param boss interface ptr from boss object on which interface is aggregated.
		*/
		CusDtLnkDocRespServiceProvider(IPMUnknown* boss);
		
		/**
			Destructor.  
		*/
		virtual	~CusDtLnkDocRespServiceProvider();

		/** See IK2ServiceProvider::GetName
		*/
		virtual void GetName(PMString* pName);

		/** See IK2ServiceProvider::GetServiceID
		*/
		virtual ServiceID GetServiceID();

		/** See IK2ServiceProvider::IsDefaultServiceProvider
		*/
		virtual bool16 IsDefaultServiceProvider();
		
		/** See IK2ServiceProvider::GetInstantiationPolicy
		*/
		virtual InstancePerX GetInstantiationPolicy();

		/** See IK2ServiceProvider::HasMultipleIDs
		*/
		virtual bool16 HasMultipleIDs() const;

		/** See IK2ServiceProvider::GetServiceIDs
		*/
		virtual void GetServiceIDs(K2Vector<ServiceID>& serviceIDs);

	private:

		K2Vector<ServiceID> fServices;
};


/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its ImplementationID 
 making the C++ code callable by the application.
*/
CREATE_PMINTERFACE(CusDtLnkDocRespServiceProvider, kCusDtLnkDocRespServiceProviderImpl)


/* CusDtLnkActionComponent Constructor
*/
CusDtLnkDocRespServiceProvider::CusDtLnkDocRespServiceProvider(IPMUnknown* boss)
	: CServiceProvider(boss)
{
	
	//	NewDoc
	fServices.push_back(kBeforeNewDocSignalResponderService);
	fServices.push_back(kDuringNewDocSignalResponderService);
	fServices.push_back(kAfterNewDocSignalResponderService);

	//	OpenDoc
	fServices.push_back(kBeforeOpenDocSignalResponderService);
	fServices.push_back(kDuringOpenDocSignalResponderService);
	fServices.push_back(kAfterOpenDocSignalResponderService);

	//	SaveDoc
	fServices.push_back(kBeforeSaveDocSignalResponderService);
	fServices.push_back(kAfterSaveDocSignalResponderService);

	//	SaveAsDoc
	fServices.push_back(kBeforeSaveAsDocSignalResponderService);
	fServices.push_back(kAfterSaveAsDocSignalResponderService);

	//	SaveACopyDoc
	fServices.push_back(kBeforeSaveACopyDocSignalResponderService);
	fServices.push_back(kDuringSaveACopyDocSignalResponderService);
	fServices.push_back(kAfterSaveACopyDocSignalResponderService);

	//	RevertDoc
	fServices.push_back(kBeforeRevertDocSignalResponderService);
	fServices.push_back(kAfterRevertDocSignalResponderService);

	//	CloseDoc
	fServices.push_back(kBeforeCloseDocSignalResponderService);
	fServices.push_back(kAfterCloseDocSignalResponderService);
}

/* CusDtLnkActionComponent Dtor
*/
CusDtLnkDocRespServiceProvider::~CusDtLnkDocRespServiceProvider()
{
}

/* GetName
*/
void CusDtLnkDocRespServiceProvider::GetName(PMString* pName)
{
	ASSERT_UNIMPLEMENTED();
}

/* GetServiceID
*/
ServiceID CusDtLnkDocRespServiceProvider::GetServiceID() 
{
	return fServices.size() > 0 ? fServices[0] : kInvalidService;
}

/* IsDefaultServiceProvider
*/
bool16 CusDtLnkDocRespServiceProvider::IsDefaultServiceProvider()
{
	return kFalse;
}

/* GetInstantiationPolicy
*/
IK2ServiceProvider::InstancePerX CusDtLnkDocRespServiceProvider::GetInstantiationPolicy()
{
	return IK2ServiceProvider::kInstancePerSession;
}

/* HasMultipleIDs
*/
bool16 CusDtLnkDocRespServiceProvider::HasMultipleIDs() const
{
	return kTrue;
}

/* GetServiceIDs
*/
void CusDtLnkDocRespServiceProvider::GetServiceIDs(K2Vector<ServiceID>& serviceIDs)
{
	std::copy(this->fServices.begin(), this->fServices.end(), std::back_inserter(serviceIDs));
}


//  Code generated by DollyXS code generator
