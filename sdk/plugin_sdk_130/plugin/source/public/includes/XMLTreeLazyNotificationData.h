//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/XMLTreeLazyNotificationData.h $
//  
//  Owner: Ryan Gano
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
#ifndef __XMLLazyTreeMsgCookie__
#define __XMLLazyTreeMsgCookie__

#include "TreeLazyNotificationData.h"
#include "IIDXMLElement.h"

/** Used by the Tree Widget to dirty (and clean) particular elements
in the tree. 
*/

class XMLTreeLazyNotificationData : public TreeLazyNotificationData<XMLReference>
{
public:
	XMLTreeLazyNotificationData() : TreeLazyNotificationData<XMLReference>()
	{
	}

	virtual ~XMLTreeLazyNotificationData()
	{
	}

private:
	virtual TreeLazyNotificationData<XMLReference> *CreateNewCookie() const
	{ return new XMLTreeLazyNotificationData; }

	virtual bool16 GetParent(const XMLReference &xmlRef, XMLReference &parentXMLRef) const
	{
		bool16 bFoundParent(kFalse);

		if (xmlRef != kInvalidXMLReference)
		{
			InterfacePtr<IIDXMLElement> element(xmlRef.Instantiate());
			if (element)
			{
				parentXMLRef = element->GetParent();

				if (parentXMLRef != kInvalidXMLReference)
					bFoundParent = kTrue;
			}
		}
		else
		{
			parentXMLRef = xmlRef;
			ASSERT_FAIL("Why am I getting passed an invalid reference? This will probably hang in release.");
		}

		return bFoundParent;
	}

#ifdef DEBUG
	virtual PMString GetNodeName(const XMLReference &xmlRef) const
	{
		PMString retVal;

		InterfacePtr<IIDXMLElement> element(xmlRef.Instantiate());
		if (element)
		{
			retVal = element->GetTagString();
			retVal.Append(" - ");
		}

		retVal.Append("[");
		retVal.AppendNumber(xmlRef.GetUID().Get());
		retVal.Append(",");
		retVal.AppendNumber(xmlRef.GetLogicalID());
		retVal.Append("]");

		return retVal;
	}
#endif
};

#endif