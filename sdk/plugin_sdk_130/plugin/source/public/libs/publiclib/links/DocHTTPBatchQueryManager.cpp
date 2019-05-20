//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/libs/publiclib/links/DocHTTPBatchQueryManager.cpp $
//  
//  Owner: Ramnik Singh
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
#include "DocHTTPBatchQueryManager.h"
#include "utf8_iterators.h"


class DocHTTPBatchQueryHandler
{
private:
	typedef std::set<UID> UIDSet;
	typedef std::map<HTTPLinkSubsystemTypes::BatchRequestObjectType, UIDSet> UIDSetPerType;
	typedef std::map<URI, UIDSetPerType> ConnectionURIToUIDSetPerTypeMap;
	typedef UIDSetPerType::iterator UIDSetPerType_iter;
	typedef ConnectionURIToUIDSetPerTypeMap::iterator ConnectionURIToUIDSetPerTypeMap_iter;
	ConnectionURIToUIDSetPerTypeMap fConnectionURIToUIDSetPerTypeMap;
public:
	bool AddUIDForGuidAndConnectionURI(URI uri, UID uid, HTTPLinkSubsystemTypes::BatchRequestObjectType type);
	bool RemoveUIDForGuidAndConnectionURI(URI uri, UID uid, HTTPLinkSubsystemTypes::BatchRequestObjectType type);
	size_t GetNumberOfUIDsForGuidAndConnectionURI(URI uri, HTTPLinkSubsystemTypes::BatchRequestObjectType type);
	bool GetUIDsForGuidAndConnectionURI(URI uri, UIDSet& uidSet, HTTPLinkSubsystemTypes::BatchRequestObjectType type);
};

bool DocHTTPBatchQueryHandler::AddUIDForGuidAndConnectionURI(URI uri, UID uid, HTTPLinkSubsystemTypes::BatchRequestObjectType type)
{
	ConnectionURIToUIDSetPerTypeMap_iter outerMap_iter = fConnectionURIToUIDSetPerTypeMap.find(uri);
	if (outerMap_iter != fConnectionURIToUIDSetPerTypeMap.end())
	{
		UIDSetPerType_iter innerMap_iter = outerMap_iter->second.find(type);
		if (innerMap_iter != outerMap_iter->second.end())
			return innerMap_iter->second.insert(uid).second;
		else
		{
			UIDSet uidSet;
			uidSet.insert(uid);
			outerMap_iter->second.insert(std::make_pair(type, uidSet));
		}
	}
	else
	{
		UIDSet uidSet;
		uidSet.insert(uid);
		UIDSetPerType uidSetPerType;
		uidSetPerType.insert(std::make_pair(type, uidSet));
		fConnectionURIToUIDSetPerTypeMap.insert(std::make_pair(uri, uidSetPerType));
	}

	return true;
}

bool DocHTTPBatchQueryHandler::RemoveUIDForGuidAndConnectionURI(URI uri, UID uid, HTTPLinkSubsystemTypes::BatchRequestObjectType type)
{
	ConnectionURIToUIDSetPerTypeMap_iter outerMap_iter = fConnectionURIToUIDSetPerTypeMap.find(uri);
	if (outerMap_iter != fConnectionURIToUIDSetPerTypeMap.end())
	{
		UIDSetPerType_iter innerMap_iter = outerMap_iter->second.find(type);
		if (innerMap_iter != outerMap_iter->second.end())
		{
			innerMap_iter->second.erase(uid);
			return true;
		}
	}
	return false;
}

size_t DocHTTPBatchQueryHandler::GetNumberOfUIDsForGuidAndConnectionURI(URI uri, HTTPLinkSubsystemTypes::BatchRequestObjectType type)
{
	ConnectionURIToUIDSetPerTypeMap_iter outerMap_iter = fConnectionURIToUIDSetPerTypeMap.find(uri);
	if (outerMap_iter != fConnectionURIToUIDSetPerTypeMap.end())
	{
		UIDSetPerType_iter innerMap_iter = outerMap_iter->second.find(type);
		if (innerMap_iter != outerMap_iter->second.end())
			return innerMap_iter->second.size();
	}
	return 0;
}

bool DocHTTPBatchQueryHandler::GetUIDsForGuidAndConnectionURI(URI uri, UIDSet& uidSet, HTTPLinkSubsystemTypes::BatchRequestObjectType type)
{
	ConnectionURIToUIDSetPerTypeMap_iter outerMap_iter = fConnectionURIToUIDSetPerTypeMap.find(uri);
	if (outerMap_iter != fConnectionURIToUIDSetPerTypeMap.end())
	{
		UIDSetPerType_iter innerMap_iter = outerMap_iter->second.find(type);
		if (innerMap_iter != outerMap_iter->second.end())
		{
			uidSet = innerMap_iter->second;
			return true;
		}
	}
	return false;
}

// Initilialize instance pointer with 0 
DocHTTPBatchQueryManager* DocHTTPBatchQueryManager::_pInstance = 0;


// Description: 
//    Get a pointer to this singleton's instance. 
// 
// Parameters: 
//    None 
// 
// Returns: 
//    Pointer to the one-and-only DocHTTPBatchQueryManager instance. 
// 
DocHTTPBatchQueryManager* DocHTTPBatchQueryManager::Instance()
{
	// Incase of IDML/PDF background thread export - following gets called from LinksCloseDocResponder causing the assert.
	//ASSERT_MSG(IDThreading::IsMainThreadDomain(), "DocHTTPBatchQueryManager::Instance should be called on main thread only");
	if (!IDThreading::IsMainThreadDomain())
		return nil;

	if (!_pInstance)
		_pInstance = new DocHTTPBatchQueryManager();

	return _pInstance;
}

void DocHTTPBatchQueryManager::TerminateInstance()
{
	ASSERT(IDThreading::IsMainThreadDomain());

	if (IDThreading::IsMainThreadDomain())
	{
		delete _pInstance;
		_pInstance = nil;
	}
}

HTTPLinkSubsystemTypes::GUID DocHTTPBatchQueryManager::GetGuid(IDataBase* db) const
{
	ASSERT_MSG(IDThreading::IsMainThreadDomain(), "DocHTTPBatchQueryManager::GetGuid should be called on main thread only");
	if (!IDThreading::IsMainThreadDomain())
		return HTTPLinkSubsystemTypes::GUID();

	DbGuidBimap_left_const_iterator iter = fDbToGuidMap.left.find(db);
	if (iter != fDbToGuidMap.left.end())
		return iter->second;
	return HTTPLinkSubsystemTypes::GUID();
}

IDataBase* DocHTTPBatchQueryManager::GetDatabase(const HTTPLinkSubsystemTypes::GUID& guid) const
{
	ASSERT_MSG(IDThreading::IsMainThreadDomain(), "DocHTTPBatchQueryManager::GetDatabase should be called on main thread only");
	if (!IDThreading::IsMainThreadDomain())
		return nil;

	DbGuidBimap_right_const_iterator iter = fDbToGuidMap.right.find(guid);
	if (iter != fDbToGuidMap.right.end())
		return iter->second;
	return nil;
}

static WideString UTF8StringToWideString(const dvacore::UTF8String& utf8String)
{
	return WideString(unicode::utf8::make_input_iter_adapter(utf8String.begin()), unicode::utf8::make_input_iter_adapter(utf8String.end()));
}

HTTPLinkSubsystemTypes::GUID DocHTTPBatchQueryManager::GenerateGuidAndCreateMapping(IDataBase* db)
{
	ASSERT_MSG(IDThreading::IsMainThreadDomain(), "DocHTTPBatchQueryManager::GenerateGuidAndCreateMapping should be called on main thread only");
	if (!IDThreading::IsMainThreadDomain())
		return HTTPLinkSubsystemTypes::GUID();

	HTTPLinkSubsystemTypes::GUID guid = GetGuid(db);
	if (guid.empty())
	{
		dvacore::utility::Guid dvaGuid = dvacore::utility::Guid::CreateUnique();
		guid = UTF8StringToWideString(dvaGuid.AsUTF8String());
		if (guid.empty() || fDbToGuidMap.right.find(guid) != fDbToGuidMap.right.end())
		{
			ASSERT("Duplicate or empty HTTPLinkSubsystemTypes::GUID generated");
			return HTTPLinkSubsystemTypes::GUID();
		}
		fDbToGuidMap.insert(value_type(db, guid));
	}	
	return guid;
}

bool DocHTTPBatchQueryManager::InvalidateAndClearDBGuidMapping(IDataBase* db)
{
	ASSERT_MSG(IDThreading::IsMainThreadDomain(), "DocHTTPBatchQueryManager::InvalidateAndClearDBGuidMapping should be called on main thread only");
	if (!IDThreading::IsMainThreadDomain())
		return false;

	DbGuidBimap_left_const_iterator iter = fDbToGuidMap.left.find(db);
	if (iter != fDbToGuidMap.left.end())
	{
		HTTPLinkSubsystemTypes::GUID toRemove = iter->second;
		fDbToGuidMap.left.erase(db);

		GuidToDocHTTPBatchQueryHandlerMap_iter batchQueryHandler_iter = fGuidToDocHTTPBatchQueryHandlerMap.find(toRemove);
		if (batchQueryHandler_iter == fGuidToDocHTTPBatchQueryHandlerMap.end())
		{
			// its possible that the fGuidToDocHTTPBatchQueryHandlerMap may not have got any UID added in the list.
			// For example, a document having all inaccessible links( for which connection is not estabilished). 
			// There's no entry added corresponding to connection uri and link resource uid in the map.
			return true;
		}		
		fGuidToDocHTTPBatchQueryHandlerMap.erase(toRemove);
		return true;
	}
	return false;	
}

bool DocHTTPBatchQueryManager::AddUIDForGuidAndConnectionURI(const HTTPLinkSubsystemTypes::GUID& guid, const URI& uri, const UID& uid, HTTPLinkSubsystemTypes::BatchRequestObjectType type)
{
	ASSERT_MSG(IDThreading::IsMainThreadDomain(), "DocHTTPBatchQueryManager::AddUIDForGuidAndConnection should be called on main thread only");
	if (!IDThreading::IsMainThreadDomain())
		return false;

	GuidToDocHTTPBatchQueryHandlerMap_iter iter = fGuidToDocHTTPBatchQueryHandlerMap.find(guid);	
	if (iter != fGuidToDocHTTPBatchQueryHandlerMap.end())	
		return iter->second->AddUIDForGuidAndConnectionURI(uri, uid, type);
	
	else
	{
		boost::shared_ptr<DocHTTPBatchQueryHandler>	obj(new DocHTTPBatchQueryHandler);
		obj->AddUIDForGuidAndConnectionURI(uri, uid, type);
		fGuidToDocHTTPBatchQueryHandlerMap.insert(std::make_pair(guid, obj));
	}

	return true;
}

bool DocHTTPBatchQueryManager::RemoveUIDForGuidAndConnectionURI(const HTTPLinkSubsystemTypes::GUID& guid, const URI& uri, const UID& uid, HTTPLinkSubsystemTypes::BatchRequestObjectType type)
{
	ASSERT_MSG(IDThreading::IsMainThreadDomain(), "DocHTTPBatchQueryManager::RemoveUIDForGuidAndConnection should be called on main thread only");
	if (!IDThreading::IsMainThreadDomain())
		return false;

	GuidToDocHTTPBatchQueryHandlerMap_iter iter = fGuidToDocHTTPBatchQueryHandlerMap.find(guid);
	if (iter != fGuidToDocHTTPBatchQueryHandlerMap.end())
		return iter->second->RemoveUIDForGuidAndConnectionURI(uri, uid, type);
	
	return false;
}

size_t DocHTTPBatchQueryManager::GetNumberOfUIDsForGuidAndConnectionURI(const HTTPLinkSubsystemTypes::GUID& guid, const URI& uri, HTTPLinkSubsystemTypes::BatchRequestObjectType type)
{
	ASSERT_MSG(IDThreading::IsMainThreadDomain(), "DocHTTPBatchQueryManager::GetNumberOfUIDsForGuidAndConnection should be called on main thread only");
	if (!IDThreading::IsMainThreadDomain())
		return 0;	

	GuidToDocHTTPBatchQueryHandlerMap_iter iter = fGuidToDocHTTPBatchQueryHandlerMap.find(guid);
	if (iter != fGuidToDocHTTPBatchQueryHandlerMap.end())	
		return iter->second->GetNumberOfUIDsForGuidAndConnectionURI(uri, type);
	
	return 0;
}
bool DocHTTPBatchQueryManager::GetUIDsForGuidAndConnectionURI(const HTTPLinkSubsystemTypes::GUID& guid, const URI& uri, std::set<UID> &uidSet, HTTPLinkSubsystemTypes::BatchRequestObjectType type)
{
	ASSERT_MSG(IDThreading::IsMainThreadDomain(), "DocHTTPBatchQueryManager::GetUIDsForGuidAndConnection should be called on main thread only");
	if (!IDThreading::IsMainThreadDomain())
		return false;

	GuidToDocHTTPBatchQueryHandlerMap_iter iter = fGuidToDocHTTPBatchQueryHandlerMap.find(guid);
	if (iter != fGuidToDocHTTPBatchQueryHandlerMap.end())		
		return iter->second->GetUIDsForGuidAndConnectionURI(uri, uidSet, type);	
	
	return false;
}	