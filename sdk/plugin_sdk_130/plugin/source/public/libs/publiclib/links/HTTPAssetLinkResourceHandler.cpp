//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/libs/publiclib/links/HTTPAssetLinkResourceHandler.cpp $
//  
//  Owner: Arvinder Singh
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
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
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

#include "VCPublicHeaders.h"
#include "HTTPAssetLinkResourceHandler.h"
#include "IPrivateLinkUtils.h"

#include "boost/bind.hpp" 

// =============================================================================
// *** HTTPAssetLinkResourceHandler implementation ***
// -----------------------------------------------------------------------------


// see  .../source/components/utilities/plugin/PublicImpl.cpp
//CREATE_PMINTERFACE(HTTPAssetLinkResourceHandler, kHTTPAssetLinkResourceHandlerImpl)

//========================================================================================
// Constructor
//========================================================================================
HTTPAssetLinkResourceHandler::HTTPAssetLinkResourceHandler(IPMUnknown* boss)
: inherited(boss),
fbInited(false)
{
}

//========================================================================================
// Destructor
//========================================================================================
HTTPAssetLinkResourceHandler::~HTTPAssetLinkResourceHandler()
{
}

// -----------------------------------------------------------------------------
bool HTTPAssetLinkResourceHandler::Init(const UIDRef& ref, const URI& uri)
{
	IHTTPLinkUtils* httpLinkUtils = Utils<IHTTPLinkUtils>();
	if (!httpLinkUtils)
	{
		fbInited = false;
		return false;
	}

	if (!httpLinkUtils->IsHTTPLinksSupportedURI(uri))
	{
		fbInited = false;
		return false;
	}

	if (ref.GetDataBase() == nil || !ref.GetDataBase()->IsValidUID(ref.GetUID()))
	{
		fbInited = false;
		return false;
	}

	if (!httpLinkUtils)
	{
		fbInited = false;
		return false;
	}

	//get connection for the http uri
	fConnection = httpLinkUtils->GetHTTPLinkResourceConnection(uri);
	fCache = httpLinkUtils->GetHTTPLinkResourceServerCache(uri);
	if (!fCache || !fConnection)
	{
		fbInited = false;
		return false;
	}

	fbInited = true;
	fShortNameCache.Clear();
	fShortUINameCache.Clear();
	fLongNameCache.Clear();
	fLongUINameCache.Clear();

	return fbInited;
}

// -----------------------------------------------------------------------------

bool HTTPAssetLinkResourceHandler::AreResourceIdsEquivalent(const ILinkResource::ResourceId& id1, const ILinkResource::ResourceId& id2) const
{
	return (id1 == id2);
}


bool HTTPAssetLinkResourceHandler::AreStampsEquivalent(const WideString& stamp1, const WideString& stamp2) const
{
	return (stamp1 == stamp2);
}

bool HTTPAssetLinkResourceHandler::CanCreateResourceStream(const UIDRef& ref, const URI& uri, ILinkResource::AccessMode mode) const
{
	if (!fbInited || mode != ILinkResource::kRead)
	{
		return false;
	}

	return true;
}

bool HTTPAssetLinkResourceHandler::CanEditResource(const UIDRef& ref, const URI& uri) const
{
	return false;
}

bool HTTPAssetLinkResourceHandler::CanReadResource(const UIDRef& ref, const URI& uri) const
{
	IHTTPLinkCachedAssetEntry* cachedAssetEntry = GetCachedAssetEntry(ref, HTTPLinkSubsystemTypes::kAssetDownloadMode_ASync, kFalse /*shouldDownload*/);
	return fbInited && (cachedAssetEntry != nil) && cachedAssetEntry->CanRead();
}

bool HTTPAssetLinkResourceHandler::CanWriteResource(const UIDRef& ref, const URI& uri) const
{
	return false;
}

bool HTTPAssetLinkResourceHandler::CanReadWriteResource(const UIDRef& ref, const URI& uri) const
{
	return false;
}

IPMStream* HTTPAssetLinkResourceHandler::CreateResourceReadStream(const UIDRef& ref, const URI& inUri) const
{
	if (!fbInited)
	{
		return nil;
	}

	IHTTPLinkCachedAssetEntry* cachedAssetEntry = GetCachedAssetEntry(ref, HTTPLinkSubsystemTypes::kAssetDownloadMode_Sync, kTrue /*shouldDownload*/);

	if (cachedAssetEntry == nil || !cachedAssetEntry->CanRead())
	{
		return nil;
	}

	return cachedAssetEntry->CreateReadStream();
}

IPMStream* HTTPAssetLinkResourceHandler::CreateResourceWriteStream(const UIDRef& ref, const URI& uri) const
{
	return nil;
}

IPMStream* HTTPAssetLinkResourceHandler::CreateResourceReadWriteStream(const UIDRef& ref, const URI& uri) const
{
	return nil;
}

FileTypeInfo HTTPAssetLinkResourceHandler::GetResourceDataType(const UIDRef& ref, const URI& uri) const
{
	if (!fbInited)
	{
		return FileTypeInfo();
	}

	IHTTPLinkCachedAssetEntry* cachedAssetEntry = GetCachedAssetEntry(ref, HTTPLinkSubsystemTypes::kAssetDownloadMode_Sync, kFalse /*shouldDownload*/);

	if (cachedAssetEntry == nil)
		return FileTypeInfo();

	return cachedAssetEntry->GetFileTypeInfo();
}

WideString HTTPAssetLinkResourceHandler::GetShortResourceName(const UIDRef& ref, const URI& uri, bool bUIName) const
{
	if (bUIName && !fShortUINameCache.empty())
	{
		return fShortUINameCache;
	}

	if (!fShortNameCache.empty())
		return fShortNameCache;

	if (Utils<IHTTPLinkUtils>()->IsHTTPLinksSupportedURI(uri))
	{
		PMString assetShortName;
		Utils<IPrivateLinkUtils>()->URIToAssetName(uri, assetShortName);
		fShortNameCache.clear();
		fShortNameCache.BuildFromSystemString(assetShortName);
		fShortUINameCache = fShortNameCache;
	}

	return bUIName ? fShortUINameCache : fShortNameCache;
}

bool HTTPAssetLinkResourceHandler::IsHTTPSSupportedURI(const URI& uri) const
{
	return (uri.GetComponent(URI::kScheme) == kHTTPSAssetURIScheme) ? true : false;
}
WideString HTTPAssetLinkResourceHandler::GetLongResourceName(const UIDRef& ref, const URI& uri, bool bUIName) const
{
	if (bUIName && !fLongUINameCache.empty())
	{
		return fLongUINameCache;
	}

	if (!fLongNameCache.empty())
		return fLongNameCache;

	if (Utils<IHTTPLinkUtils>()->IsHTTPLinksSupportedURI(uri))
	{
		URI assetURI(uri);
		if (IsHTTPSSupportedURI(uri))
		{
			assetURI.SetComponent(URI::kScheme, kHTTPSAssetURIScheme);
		}
		else 
		{
			assetURI.SetComponent(URI::kScheme, kHTTPAssetURIScheme);
		}

		WideString wUri;
		URICommonUtils::URIEncodingToWideString(assetURI.GetURI(), wUri);

		fLongNameCache = wUri;
		fLongUINameCache = fLongNameCache;
	}

	return bUIName ? fLongUINameCache : fLongNameCache;
}

ErrorCode HTTPAssetLinkResourceHandler::EditResource(const UIDRef& ref, const URI& uri, const AppInfo& appInfo, PMString* errorString) const
{
	//edit resource not allowed
	return kFailure;
}

bool HTTPAssetLinkResourceHandler::IsResourceURIValid(const UIDRef& ref, const URI& uri) const
{
	bool isValid(false);

	if (Utils<IHTTPLinkUtils>()->IsHTTPLinksSupportedURI(uri))
	{
		WideString path(uri.GetComponent(URI::kPath));
		isValid = !path.IsNull();
	}

	return isValid;
}

bool HTTPAssetLinkResourceHandler::CanCopyToFile(const UIDRef& ref, const URI& uri) const
{
	if (!fbInited)
		return false;
	return true;
}

ErrorCode HTTPAssetLinkResourceHandler::CopyToFile(const UIDRef& ref, const URI& uri, IDFile& file) const
{
	IHTTPLinkCachedAssetEntry* cachedAssetEntry = GetCachedAssetEntry(ref, HTTPLinkSubsystemTypes::kAssetDownloadMode_Sync, kTrue /*shouldDownload*/, kTrue /*forceOriginal*/);
	if (!fbInited || cachedAssetEntry == nil || !cachedAssetEntry->CanCopyToFile())
		return kFailure;

	return cachedAssetEntry->CopyToFile(file);
}

bool HTTPAssetLinkResourceHandler::CanRevealResource(const UIDRef& ref, const URI& uri) const
{
	return false;
}

ErrorCode HTTPAssetLinkResourceHandler::RevealResource(const UIDRef& ref, const URI& uri) const
{
	return false;
}

PMString HTTPAssetLinkResourceHandler::GetResourceStateInfo(const UIDRef& ref, const URI& uri, ILinkResource::ResourceState state, ILinkResource::ResourceStoreState storeState) const
{
	return PMString();
}

bool HTTPAssetLinkResourceHandler::CanEmbedResource(const UIDRef& ref, const URI& uri) const
{
	if (!fbInited)
	{
		return false;
	}
	return true;
}

bool HTTPAssetLinkResourceHandler::CanGetXMPPacketInfo(const UIDRef& ref, const URI& uri) const
{
	if (fbInited)
	{
		InterfacePtr<ILinkResource> iLinkResource(ref, UseDefaultIID());
		if (iLinkResource && iLinkResource->GetState() == ILinkResource::kAvailable)
			return true;
	}
	return false;
}

bool HTTPAssetLinkResourceHandler::GetXMPPacketInfo(const UIDRef& resourceRef, const URI& uri, std::string& packet) const
{
	if (CanGetXMPPacketInfo(resourceRef, uri))
	{
		IHTTPLinkCachedAssetEntry* cachedAssetEntry = GetCachedAssetEntry(resourceRef, HTTPLinkSubsystemTypes::kAssetDownloadMode_Sync, kTrue /*shouldDownload*/);
		if (cachedAssetEntry != nil)
			return cachedAssetEntry->GetXMPPacketInfo(packet);
	}
	return false;
}

bool HTTPAssetLinkResourceHandler::CanDownloadOriginalResource(const UIDRef& ref, const URI& uri) const
{
	if (!fbInited)
		return false;

	//check if the valid connection to server exists
	bool isConnectionValid = false;
	InterfacePtr<IHTTPLinkConnectionManager> connectionMgr(GetExecutionContextSession(), UseDefaultIID());
	ASSERT(connectionMgr);
	if (connectionMgr)
	{
		InterfacePtr<IHTTPLinkResourceConnection> connection(connectionMgr->GetHTTPConnection(uri), UseDefaultIID());
		ASSERT(connection);
		if (connection)
			isConnectionValid = connection->IsConnected();
	}
	if (!isConnectionValid)
		return false;

	if (CanReplaceFPOWithOriginalResource(ref, uri))
		return false;

	PMReal progress;
	ILinkResource::ResourceDownloadState downloadState = GetResourceDownloadProgress(ref, uri, progress);

	if (downloadState == ILinkResource::kInProgress)
		return false;
	return true;
}

ErrorCode HTTPAssetLinkResourceHandler::DownloadOriginalResource(const UIDRef& ref, const URI& uri) const
{
	IHTTPLinkCachedAssetEntry* cachedAssetEntry = GetCachedAssetEntry(ref, HTTPLinkSubsystemTypes::kAssetDownloadMode_Sync, kTrue /*shouldDownload*/, kTrue /*forceOriginalURI*/);
	if (cachedAssetEntry == nil)
		return kFailure;
	return kSuccess;
}

ErrorCode HTTPAssetLinkResourceHandler::AsyncDownloadOriginalResource(const UIDRef& ref, const URI& uri, ILinkResource::DownloadCompletionFunction completionFunction) const
{
	IHTTPLinkResourceServerCache::AssetDownloadCompletionCallback inDownloadCompletionCallback = NULL;
	if (completionFunction != NULL)
	{
		inDownloadCompletionCallback = boost::bind<void>(&HTTPAssetLinkResourceHandler::DownloadCompletionCallback, _1, _2, _3, completionFunction);
	}

	GetCachedAssetEntry(ref, HTTPLinkSubsystemTypes::kAssetDownloadMode_ASync, kTrue /*shouldDownload*/, kTrue /*forceOriginalURI*/, inDownloadCompletionCallback);
	return kSuccess;
}

bool HTTPAssetLinkResourceHandler::CanReplaceFPOWithOriginalResource(const UIDRef& ref, const URI& uri) const
{
	if (!fbInited)
		return false;

	IHTTPLinkCachedAssetEntry* cachedAssetEntry = GetCachedAssetEntry(ref, HTTPLinkSubsystemTypes::kAssetDownloadMode_ASync, kFalse /*shouldDownload*/, kTrue /*forceOriginalURI*/);
	return (cachedAssetEntry != nil) && cachedAssetEntry->CanCreateReadStream();
}

ILinkResource::ResourceDownloadState HTTPAssetLinkResourceHandler::GetResourceDownloadProgress(const UIDRef& ref, const URI& uri, PMReal& progress) const
{
	if (!fbInited)
		return ILinkResource::kDownloadError;

	InterfacePtr<ILinkResource> iLinkResource(ref, UseDefaultIID());
	if (!iLinkResource)
		return ILinkResource::kDownloadError;

	URI origAssetURI;
	IHTTPLinkUtils* httpLinkUtils = Utils<IHTTPLinkUtils>();
	if (httpLinkUtils->GetOriginalURIForResource(iLinkResource, origAssetURI))
	{
		HTTPLinkSubsystemTypes::HTTPAssetDownloadState downloadState = fCache->GetDownloadState(origAssetURI);
		return DownloadStateConverter(downloadState);
	}


	return ILinkResource::kDownloadError;
}

bool HTTPAssetLinkResourceHandler::CanProvideFile(const UIDRef& ref, const URI& uri) const
{
	if (!fbInited)
		return false;

	IHTTPLinkCachedAssetEntry* cachedAssetEntry = GetCachedAssetEntry(ref, HTTPLinkSubsystemTypes::kAssetDownloadMode_ASync, kFalse /*shouldDownload*/);
	if (cachedAssetEntry == nil)
		return false;
	return cachedAssetEntry->CanGetFile();
}

ErrorCode HTTPAssetLinkResourceHandler::GetFile(const UIDRef& ref, const URI& uri, IDFile& idFile) const
{
	if (!CanProvideFile(ref, uri))
		return kFailure;
	IHTTPLinkCachedAssetEntry* cachedAssetEntry = GetCachedAssetEntry(ref, HTTPLinkSubsystemTypes::kAssetDownloadMode_ASync, kFalse /*shouldDownload*/);
	if (cachedAssetEntry && cachedAssetEntry->GetFile(idFile))
		return kSuccess;

	return kFailure;
}

IHTTPLinkCachedAssetEntry* HTTPAssetLinkResourceHandler::GetCachedAssetEntry(const UIDRef& ref,
	HTTPLinkSubsystemTypes::AssetDownloadMode downloadMode,
	bool16 shouldDownload,
	bool16 forceOriginalURI,
	IHTTPLinkResourceServerCache::AssetDownloadCompletionCallback downloadCompletionFunction) const
{
	InterfacePtr<ILinkResource> iLinkResource(ref, UseDefaultIID());

	if (!iLinkResource)
		return nil;

	URI assetUri;
	if (forceOriginalURI)
	{
		if (!Utils<IHTTPLinkUtils>()->GetOriginalURIForResource(iLinkResource, assetUri))
			return nil;
	}
	else
	{
		if (iLinkResource->IsFPO())
		{
			if (!Utils<IHTTPLinkUtils>()->GetRenditionURIForResource(iLinkResource, assetUri))
			{
				return nil;
			}
		}
		else if (!Utils<IHTTPLinkUtils>()->GetOriginalURIForResource(iLinkResource, assetUri))
			return nil;
	}

	return fCache->GetCachedAssetEntry(assetUri,
		shouldDownload /* inDownloadIfMissing */,
		downloadMode,
		NULL,
		downloadCompletionFunction);
}

ILinkResource::ResourceDownloadState HTTPAssetLinkResourceHandler::DownloadStateConverter(const HTTPLinkSubsystemTypes::HTTPAssetDownloadState downloadState)
{
	switch (downloadState)
	{
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_Start:
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_InProgress:
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_Paused:
		return ILinkResource::kInProgress;
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_Complete:
		return ILinkResource::kComplete;
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_NotStarted:
		return ILinkResource::kNotStarted;
		//Error states
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_Cancelled:
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_ConnectionError:
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_ServerError:
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_ClientError:
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_DownloadTimeout:
	case HTTPLinkSubsystemTypes::kHTTPAssetDownloadState_UnknownError:
	default:
		return ILinkResource::kDownloadError;

	}
	return ILinkResource::kDownloadError;
}

void HTTPAssetLinkResourceHandler::DownloadCompletionCallback(const URI& inUri,
	const HTTPLinkSubsystemTypes::HTTPAssetDownloadState& inState,
	IHTTPLinkCachedAssetEntry* cachedAssetEntry,
	ILinkResource::DownloadCompletionFunction completionFunction)
{
	if (completionFunction)
	{
		completionFunction(inUri, DownloadStateConverter(inState));
	}
}

