//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IHTTPLinkResourceServerAPIWrapper.h $
//  
//  Owner: Sanyam Jain
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  ADOBE CONFIDENTIAL
//  
//  ADOBE CONFIDENTIAL
//  
//  Copyright 2016 Adobe 
//  All Rights Reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in 
//  accordance with the terms of the Adobe license agreement accompanying 
//  it. If you have received this file from a source other than Adobe, 
//  then your use, modification, or distribution of it requires the prior 
//  written permission of Adobe.
//  
//========================================================================================
#pragma once
#ifndef __IHTTPLinkResourceServerAPIWrapper__
#define __IHTTPLinkResourceServerAPIWrapper__

#include "IPMUnknown.h"
#include "LinksID.h"
#include "IHTTPLinkResourceConnection.h"


#include "HTTPLinkSubsystemTypes.h"
#include "IDTime.h"
#include "URI.h"

#include "boost/config.hpp" 
#include "boost/shared_ptr.hpp" 
#include "boost/function.hpp" 

/*
 AdobePatentID="P7137-US"
 AdobePatentID="P7225-US"
 AdobePatentID="P7609-US"
 */

/**
Experimental interface - will be modified/documented in future.
*/
class IHTTPLinkResourceServerAPIWrapper : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IHTTPLINKRESOURCESERVERAPIWRAPPER };

	/*
	Asset Metadata structure format
	*/
	struct AssetMetadata
	{
		std::string fMimeType;			// mime- type of the asset
		uint64		fSize;				// size of the asset
		IDTime		fModifiedDate;		// modified Date for the asset
		std::string	fUniqueID;			// UniqueID which can used to determine the asset state(uptodate/modified)
		std::string	fVersionData;		// Version of the asset
		std::string fPath;				// Path of the asset on the server
		std::string fGuid;				// Unique identifier of the asset. Should come from the server
		std::string	fFullDataString;	// Full Data String for the asset
	};

	/*
	Asset Metadata along with its status(missing/inaccessible/available) structure format
	*/
	struct AssetStatusWithMetadata
	{
		enum AssetStatus
		{
			kMissing,
			kInaccessible,
			kUnknown,
			kAvailable
		};

		typedef boost::shared_ptr<AssetMetadata> AssetMetadataPtr;
		AssetStatus		    fAssetStatus;
		AssetMetadataPtr	fAssetMetadataPtr;
		AssetStatusWithMetadata()
		{
			fAssetStatus = AssetStatus::kUnknown;
		}
	};

	typedef boost::shared_ptr<AssetStatusWithMetadata>          AssetStatusWithMetadataPtr;
	typedef boost::shared_ptr<AssetMetadata>					AssetMetadataPtr;
	typedef std::vector<AssetStatusWithMetadataPtr>             AssetStatusWithMetadataPtrVector;
	typedef std::vector<URI>									URIVector;
	typedef boost::shared_ptr<std::string>                      AssetMetadataContentPtr;

	typedef boost::shared_ptr<AssetStatusWithMetadataPtrVector> AssetStatusWithMetadataPtrVectorPtr;
	typedef std::map<std::string, AssetStatusWithMetadataPtr>	AssetPathToMetadataMap;
	typedef AssetPathToMetadataMap::iterator					AssetPathToMetadataMap_iter;
	typedef std::vector<WideString>								AssetPathVector;
	
	/**
	Request the status of the Metadata asset specified by the assetURI on copnnection. e.g missing, modified etc
	@param connection [IN] HTTP Link Resource connection
	@param assetURIVector [IN] vector of asset URIs status check
	@return status of the metadata of the asset
	*/
	virtual AssetStatusWithMetadataPtr RequestAssetStatusWithMetadata(IHTTPLinkResourceConnection* connection, const URI& assetURI) = 0;

	/*
	Asset Status Completion Function
	*/
	typedef boost::function<void(AssetStatusWithMetadataPtr assetStatusWithMetadataPtr)> RequestAssetStatusCompletionFunction;

	/*
	Batch Asset Status Completion Function
	*/
	typedef boost::function<void(AssetStatusWithMetadataPtrVectorPtr assetStatusWithMetadataPtrVectorPtr)> RequestBatchAssetStatusCompletionFunction;

	/**
	Async mode request for the status of metadata asset for given asset URI.
	@param connection			[IN] HTTP Link Resource connection
	@param assetURI				[IN] asset URI for status check
	@param completionFunction	[IN] Asset Status Completion function
	@return kTrue on success else kFalse.
	*/
	virtual bool16 AsyncRequestAssetStatusWithMetadata(IHTTPLinkResourceConnection* connection, 
														const URI& assetURI, 
														RequestAssetStatusCompletionFunction completionFunction) = 0;

	/**
	Async mode for batch request for the status of metadata for passed vector of asset URIs.
	@param connection			[IN] HTTP Link Resource connection
	@param assetURIVector		[IN] vector of asset URIs for batch status check
	@param completionFunction	[IN] Asset Status Completion Function
	@return kTrue on success else kFalse.
	*/
	virtual bool16 AsyncRequestBatchAssetStatusWithMetadata(IHTTPLinkResourceConnection* connection,
															const URIVector &assetURIVector,
															RequestBatchAssetStatusCompletionFunction completionFunction) = 0;
	/**
	Fetches the metadata content for the metadata asset specified by the given input URI.
	@param connection [IN] HTTP Link Resource connection
	@param inURI	  [IN] input URI for text fragment content
	@param err		  [IN] errorCode
	@return pointer(handle) to Asset Metadata Content(Asset Text Fragment Link content)
	*/
	virtual AssetMetadataContentPtr RequestAssetTextFragmentContent(IHTTPLinkResourceConnection* connection, const URI& inURI, ErrorCode err = kCantPlaceTextFragmentLinkError) = 0;

	/*
	Generates the session token for the given connection
	@param connection [IN] HTTP Link Resource connection
	@param token [OUT] session token for the given HTTP Link resource connection
	@return kTrue if the session token is generated and set else kFalse
	*/
	virtual bool16 GenerateSessionToken(IHTTPLinkResourceConnection* connection, std::string& token) = 0;

	/*
	Configures the batch size limit for the batch request for given connection.
	@param connection [IN] HTTP Link Resource connection
	@param batchLimit [OUT] limit for the number of assets that can be part of batch update invocation
	@return kTrue if the configured batch limit is set else kFalse
	*/
	virtual bool16 GetConfiguredBatchLimit(IHTTPLinkResourceConnection* connection, int32& batchLimit) = 0;

	/*
	Checks if the server for given HTTP link resource connection is accessible
	@param connection [IN] HTTP Link Resource connection 
	@param serverAccessible [OUT] flag to check if server if accessible
	@return kTrue if the server is accessible else kFalse
	*/
	virtual bool16 IsServerAccessible(IHTTPLinkResourceConnection* connection, bool16& serverAccessible) = 0;

	/*
	Fetches the headers from the connection and resolves the uri to a correct server for the download to happen.
	@param connection		[IN]	HTTP Link Resource connection
	@param inURI			[IN]	input URI
	@param assetURI			[OUT]	adjusted asset URI with the actual server resolved URI
	@param headers			[OUT]	headers for the given connection
	@return kTrue if the server is accessible else kFalse
	*/
	virtual bool16 FetchAssetPathAndRequestHeadersForDownload(IHTTPLinkResourceConnection* connection, const URI& inURI, URI& assetURI, HTTPLinkSubsystemTypes::Headers& headers) const = 0;

	/*
	Fetches the rendition URI of the input asset.
	@param inOrgAssetURI [IN] original asset URI.
	@return URI for the rendition corresponding to passed asset URI
	*/
	virtual URI GetRenditionURI(const URI& inOrgAssetURI) const = 0;

	/*
	Checks if batch update is supported for uri or not
	@param uri [IN] uri of the asset.
	@return kTrue if uri is supported for batch update else kFalse.
	*/
	virtual bool16 SupportsHTTPResourceStateBatchUpdater(const URI& uri) const = 0;

	/*
	Gets the ObjectType for Batch Request.
	@param uri		[IN] uri of the asset.
	@param objType	[OUT] output object type(asset/asset text fragment link).
	@return kTrue if uri is supported for batch update for either asset/asset text fragment else kFalse.
	*/
	virtual bool16 GetHTTPBatchRequestObjectType(const URI& uri, HTTPLinkSubsystemTypes::BatchRequestObjectType& objType) const = 0;

	/*
	Helper API to adjust inUri according to some conditions
	@param inUri		[IN]	input uri of the asset.
	@param outUri		[OUT]	adjusted URI
	return kTrue if outUri is adjusted else kFalse
	*/
	virtual bool16 AdjustURI(const URI& inUri, URI &outUri) = 0;

	/**
	Fetches the original URI for the rendition URI
	@param inRenditionURI [IN] rendition uri of the asset.
	@return original asset URI
	*/
	virtual URI GetOriginalURI(const URI& inRenditionURI) const = 0;

	/**
	Checks if the passed URI is a rendition URI or not
	@return true if inURI is a rendition URI else return false
	*/
	virtual bool IsRenditionURI(const URI& inURI) const = 0;

};

#endif	// __IHTTPLinkResourceServerAPIWrapper__
