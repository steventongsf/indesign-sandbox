//========================================================================================
//  
//  ADOBE CONFIDENTIAL
//   
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/graphics/IEditColorGroupOptionsCmdData.h $
// 
//  Owner: Harjot Singh
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  Copyright 2014 Adobe Systems Incorporated
//  All Rights Reserved.
//  
//  NOTICE:  All information contained herein is, and remains
//  the property of Adobe Systems Incorporated and its suppliers,
//  if any.  The intellectual and technical concepts contained
//  herein are proprietary to Adobe Systems Incorporated and its
//  suppliers and are protected by trade secret or copyright law.
//  Dissemination of this information or reproduction of this material
//  is strictly forbidden unless prior written permission is obtained
//  from Adobe Systems Incorporated.
//  
//========================================================================================

#pragma once
#ifndef __IEDITCOLORGROUPOPTIONSCMDDATA__
#define __IEDITCOLORGROUPOPTIONSCMDDATA__

#include "IPMUnknown.h"
#include "ColorSystemID.h"


/** Allows you to edit the color groups in a document
*/

class IEditColorGroupOptionsCmdData : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IEDITCOLORGROUPOPTIONSCMDDATA };
	
	/** Set the name of the color group.
		@param colorGroupName IN the string to be set as the name for the color group.
	*/
	virtual void SetColorGroupName(const PMString& colorGroupName) = 0 ;

	/** Get the color group name string.
		@return color group name string
	*/
	virtual PMString GetColorGroupName() = 0 ;
};

#endif // __IEDITCOLORGROUPOPTIONSCMDDATA__
