//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/ITinDocumentData.h $
//  
//  Owner: daan Strebe
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

#ifndef __ITinDocumentData__
#define __ITinDocumentData__

#include "FontMgrID.h"

/**
	@class	ITinDocumentData
	
	An interface on the document boss to identify whether the document holds any glyphlets or not
*/
class ITinDocumentData: public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_TINDOCUMENTDATA };

		/**	
			Returns whether or not there are glyphlets in the document. 

			@return	bool16	kTrue if there are glyphlets in the document, vice versa.
		 */
		virtual bool16 HasGlyphlets() = 0;

};

#endif
