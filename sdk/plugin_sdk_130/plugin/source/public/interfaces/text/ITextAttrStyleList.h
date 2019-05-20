//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/ITextAttrStyleList.h $
//  
//  Owner: Eric_Menninga
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
#ifndef __ITextAttrStyleList__
#define __ITextAttrStyleList__

#include "IPMUnknown.h"
#include "RunInStyleList.h"
#include "TextAttrID.h"


/** Simple data interface for holding the list of run-in styles applied to the paragraph
	@ingroup text_attr
*/
class ITextAttrStyleList : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_ITEXTATTRSTYLELIST };
		enum { kMaximumNumberOfRuninStyleRules = 100 };

		typedef RunInStyleList		ValueType;

			/** assign the RunInStyleList associated with this interface (usually as a text attribute)
				@param ValueType = standardized alias to RunInStyleList
			*/
		void Set(const ValueType& list)
			{ SetStyleList(list); }

			/** @return the RunInStyleList associated with this interface, more standardized naming */
		ValueType Get() const
			{ return GetStyleList(); }

			/** assign the RunInStyleList associated with this interface (usually as a text attribute)
				@param RunInStyleList
			*/
		virtual void SetStyleList(const RunInStyleList& list) = 0;

			/** @return the RunInStyleList associated with this interface */
		virtual RunInStyleList GetStyleList() const = 0;
};

#endif
		// __ITextAttrStyleList__
