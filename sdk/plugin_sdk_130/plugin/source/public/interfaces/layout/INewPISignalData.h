//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/layout/INewPISignalData.h $
//  
//  Owner: Roey Horns
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
//  
//  Purpose:	Data send with the newdoc signal
//  
//========================================================================================

#pragma once
#ifndef __INEWPAGEITEMSIGNALDATA__
#define __INEWPAGEITEMSIGNALDATA__

#include "IPMUnknown.h"
#include "GenericID.h"

class ICommand;

class INewPISignalData : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_INEWPAGEITEMSIGNALDATA };
	
	virtual void Set(ICommand *newPICmd, const UIDRef &pageItem) = 0;
	
	virtual ICommand *GetNewPICmd() = 0; // may be nil
	virtual const UIDRef &GetPageItem() const = 0;
};

#endif // __INEWPAGEITEMSIGNALDATA__

