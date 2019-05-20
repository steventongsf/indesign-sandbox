//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IPMUnknownIterator.h $
//  
//  Owner: Paul Messmer
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
#ifndef __IPMUnknownIterator__
#define __IPMUnknownIterator__

#include "IPMUnknown.h"
#include "GenericSettingsID.h"

/** Iterate over a list of IPMUnknowns */
class IPMUnknownIterator INHERITFROM
{
public:
	virtual ~IPMUnknownIterator() {}
	
	/** Returns kTrue if there another element to process */
	virtual bool16 HasNext() = 0;

	/** Move to the next element */
	virtual IPMUnknown* Next() = 0;
};

#endif 
