//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/DrawFilter.h $
//  
//  Owner: boshea
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
#ifndef __DrawFilter__
#define __DrawFilter__

class IGeometry;

#pragma export on
/** Obsolete - do not use 
*/
class PUBLIC_DECL DrawFilter
{
public:
	/** Constructor */
	DrawFilter();

	/** Destructor */
	virtual ~DrawFilter();
	
	/** @return kTrue if specified item should draw */
	virtual bool16 ShouldDraw(IGeometry *);
};

#pragma export off

#endif
