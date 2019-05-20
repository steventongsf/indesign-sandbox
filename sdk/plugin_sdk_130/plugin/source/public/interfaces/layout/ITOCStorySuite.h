//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/layout/ITOCStorySuite.h $
//  
//  Owner: Shengliu Dai
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
//  
//  Note:
//  
//========================================================================================

#pragma once
	#ifndef _ITOCStorySuite_
	#define _ITOCStorySuite_

	#include "IPMUnknown.h"
	#include "TOCID.h"

/**
	@ingroup layout_suite
*/
class ITOCStorySuite : public IPMUnknown
{

	public:
		enum { kDefaultIID = IID_ITOCSTORYSUITE };

	public:
		/**	Can pdateSelectedTOC?
			@param none
			@return bool16 
		 */
		virtual bool16	CanUpdateSelectedTOC (void) const = 0;

		/**	Update Selected TOC story
			@param void 
			@return Success or Failure 
		 */
		virtual ErrorCode	UpdateSelectedTOC (void) = 0;

};

#endif // _ITOCStorySuite_