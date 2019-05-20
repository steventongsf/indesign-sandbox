//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/IInlineGraphic.h $
//  
//  Owner: Zak_Williamson
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
#ifndef __IInlineGraphic__
#define __IInlineGraphic__

#include "IPMUnknown.h"
#include "TextID.h"
#include "UIDRef.h"

/** This interface allows a boss to store and retrieve an inline graphic UIDRef
	@ingroup text_owned
*/
class IInlineGraphic : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IINLINEGRAPHIC };
	
	/** Set the UIDRef of the graphic that is an inline
	@param &u - The UIDRef to use as an inline
	*/
	virtual void SetGraphic(const UIDRef& u) = 0;

	/** Get the UIDRef of the graphic that is an inline
	@return - UIDRef of the current inline
	*/
	virtual UIDRef GetGraphic() const = 0;
	
};

#endif
