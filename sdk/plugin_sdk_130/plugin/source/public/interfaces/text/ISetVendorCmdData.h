//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/ISetVendorCmdData.h $
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
#ifndef __ISetVendorCmdData__
#define __ISetVendorCmdData__

#include "IPMUnknown.h"



//----------------------------------------------------------------------------------------
// Interface ISetVendorCmdData
//----------------------------------------------------------------------------------------

/** Currently only used internaly in the linguistic project...
	@ingroup text_ling
*/
class ISetVendorCmdData : public IPMUnknown
{
public:
	virtual	ClassID				GetDefaultVendor() const = 0;
	virtual	void					SetDefaultVendor( ClassID nVendorBoss ) = 0;

	
	virtual	PMIID				GetVendorID() const = 0;
	virtual	void					SetVendorID( PMIID nID ) = 0;
	
};

#endif
