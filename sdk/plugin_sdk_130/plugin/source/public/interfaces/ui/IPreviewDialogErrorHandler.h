//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/ui/IPreviewDialogErrorHandler.h $
//  
//  $Owner: Michael Burbidge $
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
#ifndef __IPreviewDialogErrorHandler_h__
#define __IPreviewDialogErrorHandler_h__

class IDialog;

#include "IPMUnknown.h"
#include "widgetid.h"

//========================================================================================
// CLASS IPreviewDialogErrorHandler
//========================================================================================

class IPreviewDialogErrorHandler : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IPREVIEWDIALOGERRORHANDLER };
	
	virtual void	ReportError(const ErrorCode& error) = 0;
	virtual void	CleanupDialog(IDialog *) = 0;
};

#endif // __IPreviewDialogErrorHandler_h__
