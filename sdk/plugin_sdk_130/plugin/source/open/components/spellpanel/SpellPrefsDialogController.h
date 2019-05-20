//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/spellpanel/SpellPrefsDialogController.h $
//  
//  Owner: Heath Horton
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
//  Proj:	
//  
//========================================================================================

#pragma once
#ifndef _H_SpellPrefsDialogController
#define _H_SpellPrefsDialogController

#include "CDialogController.h"

class ICommand;

class SpellPrefsDialogController : public CDialogController
{
public:
	// ----- Initialization -----
	
						SpellPrefsDialogController(IPMUnknown *boss);
	virtual				~SpellPrefsDialogController();
	
	// ----- Dialog protocol -----

	virtual void		InitializeDialogFields(IActiveContext* context);
	virtual WidgetID	ValidateDialogFields(IActiveContext* myContext);
	virtual void		ApplyDialogFields(IActiveContext* myContext, const WidgetID& widgetId);
};


#endif
