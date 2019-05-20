//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IHTTPLinkResourceConnection.h $
//  
//  Owner: Arvinder Singh
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
#ifndef __IHTTPLinkResourceConnection__
#define __IHTTPLinkResourceConnection__

#include "IPMUnknown.h"
#include "IPMStream.h"

#include "LinksID.h"
#include "PMString.h"

/*
 AdobePatentID="P7137-US"
 AdobePatentID="P7225-US"
 AdobePatentID="P7609-US"
*/

/**
Experimental interface - will be modified/documented in future.
*/
class IHTTPLinkResourceConnection : public IPMUnknown
{
public:

	//[TODO] decide on type
	typedef PMString ConnectionId;

	enum { kDefaultIID = IID_IHTTPLINKRESOURCECONNECTION };

	/**
	Shuts down the current connection
	@return kTrue if the Http Connection is shutdown else kFalse
	*/
	virtual bool16 Shutdown() = 0;

	/**
	Checks if the current connection is connected
	@return kTrue if the Http Connection is connected else kFalse
	*/
	virtual bool16 IsConnected() const = 0;

	/**
	Checks if the current connection is authorized
	@return kTrue if the Http Connection is authorized else kFalse. 
	*/
	virtual bool16 IsAuthorized() const = 0;

	/**
	Creates/Logs-in the current connection
	@return kTrue if connection is created/logged-in successfully else kFalse.
	*/
	virtual bool16 Connect() = 0;

	/**
	Reconnects the current connection
	@return kTrue if re-connection is successful else kFalse
	*/
	virtual bool16 Reconnect() = 0;

	/**
	Disconnects the current connection
	@return kTrue if the connection is diconnected else kFalse
	*/
	virtual bool16 Disconnect() = 0;

	/**
	Fetches the connection ID for the current connection
	@return ConnectionId for the current connection
	*/
	virtual ConnectionId GetConnectionId() = 0;

    /**
    Sets the connection to logout. Empties session token.
    */
    virtual void SetLogout() = 0;

	/**
	Gets the login credentials for the given connection
	@param loginInformation		[OUT]  The login information that requires to be set for the given connection
	@return kFalse if credentials could not be encoded, else kTrue
	*/
    virtual bool16 GetLoginCredentials(std::stringstream& loginInformation) const = 0;

    /**
	Sets the login credentials for the given connection
	@param loginInformation		[IN]  The login information that requires to be set for the given connection
	@return kTrue if credentials are set
	*/
    virtual bool16 SetLoginCredentials(const std::stringstream& loginInformation) = 0;

	/**
	** For internal purpose only
	*/
	virtual void ReadWriteSnapshotForBackgroundThread(IPMStream* s) = 0;
};

#endif  // __IHTTPLinkResourceConnection__
