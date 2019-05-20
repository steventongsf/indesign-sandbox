//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/IStrandPastePiece.h $
//  
//  Owner: dwaterfa
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
#ifndef __ISTRANDPASTEPIECE__
#define __ISTRANDPASTEPIECE__

#include "IPMUnknown.h"
#include "TextID.h"
#include "K2Vector.h"

class VOSallSavedData;
class PasteDataXRefContext;
class ICommand;


/** 
	@ingroup text_strand
*/
class IStrandPastePiece : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_ISTRANDPASTEPIECE };

		virtual ClassID		GetStrandClassID() const = 0;

		virtual ErrorCode		OnCopyRange() = 0;

		virtual ErrorCode		PreTransferTo(PasteDataXRefContext* xRefCntxt) = 0;
		virtual ErrorCode		TransferTo(PasteDataXRefContext* xRefCntxt) = 0;
		//
		// Called during TextModel::DoPaste().
		//
		//
		virtual ErrorCode		OnPaste() = 0;

};

#endif	// __ISTRANDPASTEPIECE__

