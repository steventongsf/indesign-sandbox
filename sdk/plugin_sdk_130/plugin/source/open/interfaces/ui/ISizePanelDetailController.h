//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/interfaces/ui/ISizePanelDetailController.h $
//  
//  Owner: Lin Xia
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
#ifndef __ISizePanelDetailController__h_
#define __ISizePanelDetailController__h_

#include "IPanelDetailController.h"

//========================================================================================
// CLASS IPanelDetailController
//========================================================================================

// This interface exists to allow user to change the default panel size in the detail controller.
// Normally a panel's original size is specified in its resource file but some panels may have 
// different layouts and one of them will be used to set the original size at run time. 
// For example Tab panel shows horizontal layout in Roman feature set and vertical laout in J feature set.

class ISizePanelDetailController : public IPanelDetailController
{
public:
	virtual void	SetDefaultSize(const PMPoint& size) = 0;
					// Set the default size.
};

#endif // __ISizePanelDetailControllerr__h_
