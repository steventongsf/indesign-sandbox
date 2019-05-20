//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/IFindChangeSelectionSuite.h $
//  
//  Owner: Bryce Morsello
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
//  Note:
//  
//========================================================================================

#pragma once
	#ifndef _IFindChangeSelectionSuite_
	#define _IFindChangeSelectionSuite_
//________________________________________________________________________________________________
//	INCLUDES
//________________________________________________________________________________________________
	#include "IPMUnknown.h"

	#include "FindChangeID.h"
	
//================================================================================================
//________________________________________________________________________________________________
//	CLASS DECLARATION
//________________________________________________________________________________________________

/** 
	Stub interface for find change selection suite. 
	It currently does not contain any method.
	
	@ingroup text_suite
*/
class IFindChangeSelectionSuite : public IPMUnknown
	{
	//____________________________________________________________________________________________
	//	Data Types
	//____________________________________________________________________________________________
	public:
		enum { kDefaultIID = IID_IFINDCHANGESELECTIONSUITE };

	//____________________________________________________________________________________________
	//	Member functions
	//____________________________________________________________________________________________
	public:
	};

#endif // _ITextMiscellanySuite_


