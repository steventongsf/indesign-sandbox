//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/CPathShape.h $
//  
//  Owner: Jeff Argast
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
#ifndef __CPathShape__
#define __CPathShape__

#include "CShape.h"

class IViewPort;
class IPathPageItem;

#pragma export on

class PUBLIC_DECL CPathShape : public CShape
{
	public:

		CPathShape(IPMUnknown *boss);
		virtual ~CPathShape();
		
	protected:
		virtual void DrawShape(GraphicsData* gd, int32 flags);

		// CPathShape overrides GetPaintedBBox to compute the bbox for
		// path objects  
		virtual PMRect GetPaintedBBox(const PMMatrix& theMatrix, const Transform::CoordinateSpace& coordinateSpace);
	
	protected:
		IPathPageItem*	fPathPageItem;
		
	private:
		PMRect			fPaintedBounds;
};

#pragma export off

#endif