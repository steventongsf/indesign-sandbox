//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/CImageWriteFormat.h $
//  
//  Owner: jargast
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
#ifndef __CIMAGEWRITEFORMAT__
#define __CIMAGEWRITEFORMAT__

#include "IImageWriteFormat.h"

class IPMStream;
class IImageAttributes;
class IImageStream;

class CImageWriteFormat : public IImageWriteFormat
{
	public:
		virtual bool16 SetImageAttributes (IImageAttributes* iImageAttributes) { return kFalse; }

		virtual bool16 Open(IPMStream* iPMStream) { return kFalse; }

		virtual bool16 Close() { return kFalse; }

		virtual bool16 SetFormatOption (uint32 formatOption, uint32 formatData) { return kFalse; }

		virtual bool16 WriteData (IImageStream* iImageStream) { return kFalse; }
};

#endif
