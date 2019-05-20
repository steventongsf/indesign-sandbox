//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/preflight/IDeletePreflightProfileCmdData.h $
//  
//  Owner: Matt Phillips
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

#include "IPMUnknown.h"
#include "PackageAndPreflightID.h"

/**	This interface provides the settings to accompany a DeletePreflightProfile command.
	Note that it may be easier to use IPreflightFacade::DeleteProfile(), although that
	only deletes one profile at a time.
*/
class IDeletePreflightProfileCmdData : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IDELETEPREFLIGHTPROFILECMDDATA };

public:
	/** Set the profile(s) to delete.
		@param profiles IN The profiles you wish to delete.
	*/
	virtual void SetProfiles(const UIDList& profiles) = 0;

	/** @return the profile(s) to delete.
	*/
	virtual UIDList GetProfiles() const = 0;
};
