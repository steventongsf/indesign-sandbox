//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/graphics/IPMMatrixListData.h $
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

#pragma once
#ifndef __IPMMatrixListData__
#define __IPMMatrixListData__

#include "IPMUnknown.h"
#include "CommandID.h"
#include "PMMatrix.h"

/** 
 Data interface for storing a list of PMMatrixs.

 @see PMMatrix
 */
class IPMMatrixListData : public IPMUnknown 
{
public:
	/**
	 Sets the PMMatrixCollection stored by this interface
	 
	 @param thePMMatrix		IN The matrix collection to store
	 */
	virtual void Set(const PMMatrixCollection& thePMMatrix) = 0;
	
	/**
	 Returns the PMMatrixCollection stored by this interface
	 
	 @return The stored matrix collection
	 */
	virtual const PMMatrixCollection& GetPMMatrixList() const = 0;
};


#endif // __IPMMatrixListData__
