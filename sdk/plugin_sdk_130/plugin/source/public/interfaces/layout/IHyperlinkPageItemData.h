//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/layout/IHyperlinkPageItemData.h $
//  
//  Owner: Brendan O'Shea
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
#ifndef __IHyperlinkPageItemData__
#define __IHyperlinkPageItemData__

#include "IPMUnknown.h"
#include "HyperlinkID.h"

/**
	@ingroup layout_hyper
*/
class IHyperlinkPageItemData : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IHYPERLINKPAGEITEMDATA };

	/**	Setup this data structure
		@param &hyperLinkSource - UIDRef of the hyperlink source that "owns" this page item
	 */
	virtual void Initialize( const UIDRef &hyperLinkSource ) = 0;

	/**	Get the UID of the source that "owns" this page item
		@param none
		@return UID - UID of the appropriate source
	 */
	virtual UID GetSource() const = 0;

};


#endif // __IHyperlinkPageItemData__

