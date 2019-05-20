//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/conditionaltextui/ConditionalTextVisitorHelper.cpp $
//  
//  Owner: wcheuk
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

#include "VCPlugInHeaders.h"
#include "IVisitorHelper.h"

#include "IOwnedItem.h"
#include "ConditionalTextUIID.h"

class ConditionalTextVisitorHelper : public IVisitorHelper
{
public:
	ConditionalTextVisitorHelper(IPMUnknown* boss);

	virtual bool16 Accept(IBaseVisitor* theVisitor);
	virtual int32 CollectChildren(IBaseHandler *theHandler) { return 0; }
	virtual IVisitorHelper* QueryChild(int32 index) { return nil; }

	DECLARE_HELPER_METHODS()

private:
	VisitorHelperList	fChildList;

};


CREATE_PMINTERFACE(ConditionalTextVisitorHelper, kConditionalTextVisitorHelperImpl)
DEFINE_HELPER_METHODS(ConditionalTextVisitorHelper)


//---------------------------------------------------------------
//
// ConditionalTextVisitorHelper::constructor
//
//---------------------------------------------------------------
ConditionalTextVisitorHelper::ConditionalTextVisitorHelper(IPMUnknown* boss) :
	HELPER_METHODS_INIT(boss)
{
}

//---------------------------------------------------------------
//
// ConditionalTextVisitorHelper::Accept
//
// This allows the note data to be visitable for hittest
//
//---------------------------------------------------------------
bool16 ConditionalTextVisitorHelper::Accept(IBaseVisitor* theVisitor)
{
	bool16 bDone = kFalse;

	// Call the Visitor without knowing anything about what its handler is
	// going to do
	if (theVisitor)
		bDone = theVisitor->VisitOwnedItem(this);
	return bDone;
}
