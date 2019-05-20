//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/interfaces/interactive/IFormFieldLabelDrawer.h $
//  
//  Owner: Heath Lynn
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
#ifndef __IFormFieldLabelDrawer__
#define __IFormFieldLabelDrawer__

#include "IPMUnknown.h"
#include "IAdornmentShape.h"
#include "FormFieldID.h"

class IShape;
class GraphicsData;

class IFormFieldLabelDrawer : public IPMUnknown
{

public:

	enum { kDefaultIID = IID_IFORMFIELDLABELDRAWER };

	virtual void Draw
		(
			IShape* 							iShape,		// owning page item
			IAdornmentShape::AdornmentDrawOrder	drawOrder,	// for items that registered for more than one order
			GraphicsData*						gd,
			int32								flags
		) = 0;
};

#endif
