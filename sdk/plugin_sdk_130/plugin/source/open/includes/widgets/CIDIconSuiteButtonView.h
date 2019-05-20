//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/includes/widgets/CIDIconSuiteButtonView.h $
//  
//  Owner: Vadim Tkachev	
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
#ifndef __CIDIconSuiteButtonView__
#define __CIDIconSuiteButtonView__

/** class CIDIconSuiteButtonView

		Concrete implementation of the IControlView interface for icon buttons.  
		
		This is the default implementation used in InDesign icon buttons, kIconSuiteButtonViewImpl
		Clients seeking to modify default icon buttons behaviors should derive from this class.
		
		This file replaces PlatformIconSuiteButtonView.h, which is now obsolete.
*/

#include "DVIconSuiteButtonView.h"

class WIDGET_DECL CIDIconSuiteButtonView : public DVIconSuiteButtonView
{
	typedef DVIconSuiteButtonView inherited;

public:
	CIDIconSuiteButtonView(IPMUnknown *boss);
	virtual ~CIDIconSuiteButtonView();
};

#endif //__CIDIconSuiteButtonView__