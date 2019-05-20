//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/IStandOffItemCmdData.h $
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
#ifndef __IStandOffItemCmdData__
#define __IStandOffItemCmdData__

#include "IPMUnknown.h"
#include "IStandOff.h"
#include "StandOffID.h"

class IGeometry;
class UIDRef;

/** INTERNAL USE ONLY */
class IStandOffItemCmdData : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_ISTANDOFFITEMCMDDATA };

	virtual	void				SetMainItem( const UIDRef &rMainItemRef ) = 0;
	virtual	IGeometry *		QueryMainItem() = 0;

	virtual	void				SetMode( IStandOff::mode nMode ) = 0;
	virtual	IStandOff::mode	GetMode() const = 0;
};

#endif
