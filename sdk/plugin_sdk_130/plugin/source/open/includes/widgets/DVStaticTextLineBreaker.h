//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/includes/widgets/DVStaticTextLineBreaker.h $
//  
//  Owner: Kevin Van Wiel
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  Copyright 1997-2002 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#pragma once
#ifndef __DVStaticTextLineBreaker__
#define __DVStaticTextLineBreaker__

#include "IStaticTextLineBreaker.h"
#include "HelperInterface.h"
#include "InterfaceFontInfo.h"
#include "PMRect.h"
#include "PMReal.h"
#include "PMPoint.h"
#include "K2Vector.h"

#ifdef DV_WIDGET_BUILD
#pragma export on
#endif

//class InterfaceFontInfo;
class IGraphicsContext;
class IControlView;
class IScrollBarPanoramaSync;

class DV_WIDGET_DECL DVStaticTextLineBreaker : public IStaticTextLineBreaker
{
public:
						DVStaticTextLineBreaker(IPMUnknown *boss);
	virtual 			~DVStaticTextLineBreaker();

	virtual void CreateLineBreaks(const PMString& stringToBreak, const PMReal maxLineWidth, const InterfaceFontInfo& fontInfo);
	virtual PMString GetNthLine(int32 lineIndex) const;
	virtual PMPoint GetNthLineSize(int32 lineIndex) const;
	virtual int32 GetNumLines() const;
protected:
	K2Vector<PMString>	fLines;
	K2Vector<PMPoint>	fLineSizes;
	
DECLARE_HELPER_METHODS()
};

#pragma export off

#endif //__DVStaticTextLineBreaker__
