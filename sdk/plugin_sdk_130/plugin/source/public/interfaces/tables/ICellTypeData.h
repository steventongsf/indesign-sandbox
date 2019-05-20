//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/tables/ICellTypeData.h $
//  
//  Owner: Rahul Jain
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change $
//  ___________________
//  
//  ADOBE CONFIDENTIAL
//  
//  Copyright 2014 Adobe Systems Incorporated
//  All Rights Reserved.
//  
//  NOTICE:  All information contained herein is, and remains
//  the property of Adobe Systems Incorporated and its suppliers,
//  if any.  The intellectual and technical concepts contained
//  herein are proprietary to Adobe Systems Incorporated and its
//  suppliers and are protected by all applicable intellectual property
//  laws, including trade secret and copyright laws.
//  Dissemination of this information or reproduction of this material
//  is strictly forbidden unless prior written permission is obtained
//  from Adobe Systems Incorporated.
//  
//========================================================================================


#ifndef __ICellTypeData__
#define __ICellTypeData__

#include "ITableModel.h"


/**
 * 	Represents the type of table cell (text, graphic etc.)
 *  refer to ITableModel, for all possible types of cell
 *  Note: CellType is effectively alias of ClassID.
 */

class ICellTypeData : public IPMUnknown {

public:
	// ----- Types and Constants -----
	enum { kDefaultIID = IID_ICELLTYPEDATA };

	// ----- Accessors -----
	virtual void 		Set(CellType cellType) = 0;
	virtual CellType 	Get() const = 0;
};

#endif // __ICellTypeData__
