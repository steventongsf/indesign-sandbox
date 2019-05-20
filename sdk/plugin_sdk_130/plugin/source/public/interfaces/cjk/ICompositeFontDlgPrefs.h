//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/cjk/ICompositeFontDlgPrefs.h $
//  
//  Owner: Kuniko Nagayama
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
#ifndef __ICompositeFontDlgPrefs__
#define __ICompositeFontDlgPrefs__

#include "IPMUnknown.h"
#include "IPMFont.h"
#include "IWorkspace.h"
#include "ICompositeFont.h"
#include "IDocFontMgr.h"

class PMString;

/** Stores composite font dialog preferences on the application workspace.

	This dialog is available in the J version of the product under the type menu. The user may specify
	the default sample text that is used for the composite font editor.
*/
class ICompositeFontDlgPrefs	:	public IPMUnknown
{
	public:
		
		/**
			Get sample text used in Composite Font Editor
		
			@return	PMString 	text in sample
		*/
		virtual PMString GetSampleText(int32 script = kDontKnowScript) = 0;
		/**
			Set sample text used in Composite Font Editor
		
			@param	str		string to set sample to
		*/
		virtual void SetSampleText(const PMString& str, int32 script = kDontKnowScript) = 0;

};

#endif

//__ICompositeFontDlgPrefs__



