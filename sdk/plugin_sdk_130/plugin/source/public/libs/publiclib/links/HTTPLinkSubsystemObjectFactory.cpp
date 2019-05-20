//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/libs/publiclib/links/HTTPLinkSubsystemObjectFactory.cpp $
//  
//  Owner: Sanyam Jain
//  
//  $Author: praverma $
//  
//  $DateTime: 2018/09/07 11:54:17 $
//  
//  $Revision: #1 $
//  
//  $Change: 1031661 $
//  
//  ADOBE CONFIDENTIAL
//  
//  Copyright 2015 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  All information contained herein is, and remains
//  the property of Adobe Systems Incorporated and its suppliers,
//  if any.  The intellectual and technical concepts contained
//  herein are proprietary to Adobe Systems Incorporated and its
//  suppliers and may be covered by U.S. and Foreign Patents,
//  patents in process, and are protected by trade secret or copyright law.
//  Dissemination of this information or reproduction of this material
//  is strictly forbidden unless prior written permission is obtained
//  from Adobe Systems Incorporated.
//  
//========================================================================================

//#include "VCPlugInHeaders.h"

#include "VCPublicHeaders.h"

#include "HTTPLinkSubsystemObjectFactory.h"

//CREATE_PMINTERFACE(HTTPLinkSubsystemObjectFactory, kHTTPLinkSubsystemObjectFactoryImpl)

//========================================================================================
//
// HTTPLinkSubsystemObjectFactory Public Implementation
//
//========================================================================================

//========================================================================================
// Constructor
//========================================================================================
HTTPLinkSubsystemObjectFactory::HTTPLinkSubsystemObjectFactory(IPMUnknown* boss)
: inherited(boss)
{
}

//========================================================================================
// Destructor
//========================================================================================
HTTPLinkSubsystemObjectFactory::~HTTPLinkSubsystemObjectFactory()
{
}

//========================================================================================
// HTTPLinkSubsystemObjectFactory::GetSchemes
//========================================================================================
void HTTPLinkSubsystemObjectFactory::GetSchemes(K2Vector<WideString>& schemes) const
{
	schemes.push_back(kHTTPAssetURIScheme);
	schemes.push_back(kHTTPSAssetURIScheme);
	return;
}

//========================================================================================
// HTTPLinkSubsystemObjectFactory::QueryHandler
//========================================================================================
ILinkResourceHandler* HTTPLinkSubsystemObjectFactory::QueryHandler(const URI& uri, IDataBase* db) const
{
	if (IsURISchemeSupported(uri))
		return ::CreateObject2<ILinkResourceHandler>(kHTTPAssetLinkResourceHandlerBoss);
	return nil;
}

//========================================================================================
// HTTPLinkSubsystemObjectFactory::QueryStateUpdater
//========================================================================================
ILinkResourceStateUpdater* HTTPLinkSubsystemObjectFactory::QueryStateUpdater(const URI& uri, IDataBase* db) const
{
	if (IsURISchemeSupported(uri))
		return ::CreateObject2<ILinkResourceStateUpdater>(kHTTPAssetLinkResourceStateUpdaterBoss);
	return nil;
}

//========================================================================================
// HTTPLinkSubsystemObjectFactory::QueryHTTPLinkResourceConnection
//========================================================================================
IHTTPLinkResourceConnection* HTTPLinkSubsystemObjectFactory::QueryHTTPLinkResourceConnection(const URI& uri, IDataBase* db) const
{
	if (IsURISchemeSupported(uri))
		return ::CreateObject2<IHTTPLinkResourceConnection>(kHTTPAssetLinkResourceHelperBoss);
	return nil;
}

//========================================================================================
// HTTPLinkSubsystemObjectFactory::QueryHTTPLinkResourceServerAPIWrapper
//========================================================================================
IHTTPLinkResourceServerAPIWrapper* HTTPLinkSubsystemObjectFactory::QueryHTTPLinkResourceServerAPIWrapper(const URI& uriScheme, IDataBase* db) const
{
	if (IsURISchemeSupported(uriScheme))
		return ::CreateObject2<IHTTPLinkResourceServerAPIWrapper>(kHTTPAssetLinkResourceServerHelperBoss);
	return nil;
}

//========================================================================================
// HTTPLinkSubsystemObjectFactory::IsURISchemeSupported
//========================================================================================
bool16 HTTPLinkSubsystemObjectFactory::IsURISchemeSupported(const URI& uri) const
{
	K2Vector<WideString> schemes;
	GetSchemes(schemes);
	bool16 isURISchemeSupportedB = kFalse;
	for (uint32 i = 0; (size_t)i < schemes.size(); ++i)
	{
		if (uri.GetComponent(URI::kScheme) == schemes[i])
		{
			isURISchemeSupportedB = kTrue;
			break;
		}
	}
	ASSERT(isURISchemeSupportedB);
	return isURISchemeSupportedB;
}
