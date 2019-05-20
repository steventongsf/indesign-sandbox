//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/IStandOffMarginCmdData.h $
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
#ifndef __IStandOffMarginCmdData__
#define __IStandOffMarginCmdData__

#include "IPMUnknown.h"
#include "PMRect.h"
#include "StandOffID.h"

/** INTERNAL USE ONLY */
class IStandOffMarginCmdData : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_ISTANDOFFMARGINCMDDATA };

	enum { kUnchanged = 0xFFFF };

	/* Set one or more margins for a text wrap standoff. Use kUnchanged to leave a value unchanged.
	If item's IStandoffData HasOnlyOneDistance, use only the nTopMargin value, set others to kUnchanged
	@see IStandoffData
	*/
	virtual	void				SetMargins( PMReal nTopMargin,
											PMReal nLeftMargin,
											PMReal nBottomMargin,
											PMReal nRightMargin ) = 0;

	/* @return These may return kUnchanged. */
	virtual	PMReal			GetTopMargin() const = 0;
	virtual	PMReal			GetLeftMargin() const = 0;
	virtual	PMReal			GetBottomMargin() const = 0;
	virtual	PMReal			GetRightMargin() const = 0;
};

#endif
