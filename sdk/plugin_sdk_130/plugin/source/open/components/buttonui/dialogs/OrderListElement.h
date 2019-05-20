//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/dialogs/OrderListElement.h $
//  
//  Owner: Tim Wright
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
#ifndef __OrderListElement_h__
#define __OrderListElement_h__

#include "IDocumentFieldOrder.h"

//========================================================================================

class OrderListElement
{
public:
	typedef object_type data_type;

	OrderListElement(const IDocumentFieldOrder::ItemInstance& inItem, const PMString& inName) :
		fItem(inItem),
		fName(inName)
	{
	}
	
	OrderListElement(const OrderListElement& inItem) :
		fItem(inItem.fItem),
		fName(inItem.fName)
	{
	}
	
	OrderListElement& operator=(const OrderListElement& inItem)
	{
		if (this != &inItem)
		{
			fItem = inItem.fItem;
			fName = inItem.fName;
		}
		return *this;
	}

	IDocumentFieldOrder::ItemInstance GetItem() const
	{
		return fItem;
	}


	PMString GetName() const
	{
		return fName;
	}
	
private:
	IDocumentFieldOrder::ItemInstance fItem; //UIDs identifying item...
	PMString fName; //name of item in list..
};

#endif // __OrderListElement_h__
