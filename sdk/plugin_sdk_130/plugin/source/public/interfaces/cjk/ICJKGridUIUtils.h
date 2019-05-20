//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/cjk/ICJKGridUIUtils.h $
//  
//  Owner: Heath Lynn, (Bernd Paradies: generalized from BookUtils.h).
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
#ifndef __ICJKGRIDUIUTILS__
#define __ICJKGRIDUITILS__

#include "CJKGridPrefsDialogID.h"
#include "IPMUnknown.h"
#include "Utils.h"

class ICJKGridData;


/** ICJKGridUIUtils is the interface for utilities related to the UI of CJK grid.
*/
class ICJKGridUIUtils : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_ICJKGRIDUIUTILS };

	/** Returns ICJKGridData for currently selected LayoutGrid.  This
		is taken from the page that is currently selected in the page's palette.
		
		@return ICJKGridData pointer for currently selected page.
	*/
	virtual ICJKGridData * QuerySelectedLayoutGrid() = 0;

};


#endif	// __ICJKGridUIUtils__
