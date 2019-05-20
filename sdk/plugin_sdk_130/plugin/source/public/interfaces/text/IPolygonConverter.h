//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/IPolygonConverter.h $
//  
//  Owner: Bernd Paradies
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
#ifndef __IPolygonConverter__
#define __IPolygonConverter__

#include "IPMUnknown.h"
#include "StandOffID.h"

class IPathGeometry;

/** The IPolygonConverter is used by the PageItemStandOff for rotated TextFrames, 
	rotated StandOffs and contour StandOffs. 
	The implementations are named as *ToPolygon:
	<pre>
	Generic PageItem: kPageItemToPolygonBoss
	Rectangle:	 kRectToPolygonBoss
	Oval: kPageItemToPolygonBoss
	Line: kLineToPolygonBoss
	Polygon: kPolyToPolygonBoss
	FrameItem: kRectToPolygonBoss
	QD3DItem: kRectToPolygonBoss
	</pre>
	@ingroup text_wrap
*/
class IPolygonConverter : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IPOLYGONCONVERTER };

	// usually called by the ITextTiler:
	virtual IPathGeometry *		CreatePolygon() const = 0;
	virtual bool16				InitPolygon( IPathGeometry *pNew ) const = 0;
	virtual bool16				IsRectangle(bool16 checkCornerRadius= kFalse) const = 0;
};

#endif
