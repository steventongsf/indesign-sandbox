//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/IInsertTextData.h $
//  
//  Owner: EricK
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
#ifndef __IInsertTextData__
#define __IInsertTextData__

#include "IPMUnknown.h"
#include "TextID.h"
#include "K2SmartPtr.h"

class WideString;

/** Used to hold the string to insert into a text story with the InsertTextCmd
	@ingroup text_story
*/
class IInsertTextData : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_IINSERTTEXTDATA };
	
			// Set the string.
		virtual void Set(const boost::shared_ptr<WideString>& data) = 0;

			// grab the pointer to the string, don't edit or delete the string
		virtual const boost::shared_ptr<WideString>& GrabInsertData() const = 0 ;
#ifdef DEBUG
		virtual void DataCanNoLongerBeChanged() = 0;	
#endif
};

#endif
