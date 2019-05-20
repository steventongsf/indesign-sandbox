//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/interfaces/ui/IColumnHeaderAttributes.h $
//  
//  Owner: SusanCL
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
#ifndef __IColumnHeaderAttributes__
#define __IColumnHeaderAttributes__

#include "IPMUnknown.h"
#include "widgetid.h"
#include "TreeViewDefs.h"

const int32 kMinimumColumnWidth = 16;

/** A data interface used in conjunction with the column header widget (kColumnHeaderWidgetBoss).
*/
class IColumnHeaderAttributes : public IPMUnknown
{
public:
	// ----- Query -----
	enum { kDefaultIID = IID_ICOLUMNHEADERATTRIBUTES };
	
	/**	Set the auto resize option for the column header.
		This determine how the column header should be resized when the parent panel resizes.
		@param resize is the resize option to set for the column header.
	*/
	virtual void	SetAutoResizeOption (const int16& resize) = 0;
	
	/** Get auto resize option for the columns.
		@see TreeViewDefs.h
		@return the auto resize option.
	*/
	virtual int16	GetAutoResizeOption () const = 0;

	/**	Set minimum column size for the column header.
		When resizing, the column size should not go below this minimum width.
		@param minWidth is the minimun width to set.
	*/
	virtual void	SetMinimumColumnWidth (const int32& minWidth) = 0;
	
	/** Get minimum width for the columns.
		@see TreeViewDefs.h
		@return the auto resize option.
	*/
	virtual int32	GetMinimumColumnWidth () const = 0;
};

#endif
