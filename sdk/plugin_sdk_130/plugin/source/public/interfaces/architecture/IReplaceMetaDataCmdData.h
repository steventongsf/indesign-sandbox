//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IReplaceMetaDataCmdData.h $
//  
//  Owner: Michael Burbidge
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
#ifndef __IReplaceMetaDataCmdData_h__
#define __IReplaceMetaDataCmdData_h__

#include "IPMUnknown.h"
#include "MetaDataID.h"

/**
	A data interface used by ReplaceMetaDataCmd.
*/

//========================================================================================
// INTERFACE IReplaceMetaDataCmdData
//========================================================================================

class IReplaceMetaDataCmdData : public IPMUnknown
{
public:	
	enum { kDefaultIID = IID_IREPLACEMETADATACMDDATA };
	
	/**
		Set the command data.
		@param	targetObject	IN	The target object of the command. It must have a IID_IMETADATA interface.
		@param	file			IN	The file that contains external metadata.
		@param  treatAllAsExternal	IN  Whether to treat all properties as external.
	*/
	virtual void 				Set(IPMUnknown* targetObject, const IDFile& file, bool16 treatAllAsExternal = kFalse) = 0;
	
	/**
		Query an interface on the target object.
		@param	iid	IN	The ID of the interface to query.
	*/
	virtual IPMUnknown*			QueryTargetObject(const PMIID& iid) const = 0;
	/**
		Return the file that contains external metadata.
		@return	The file that contains external metadata.
	*/
	virtual IDFile				GetFile() const = 0;
	/**
		Return whether to treat all properties as external
		@return	kTure if all properties are treated as extrenal. kFalse otherwise.
	*/
	virtual bool16				TreatAllAsExternal() const = 0;

};

#endif // __IReplaceMetaDataCmdData_h__
