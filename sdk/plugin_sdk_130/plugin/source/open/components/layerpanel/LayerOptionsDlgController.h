//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/layerpanel/LayerOptionsDlgController.h $
//  
//  Owner: psorrick
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
#ifndef __LayerOptionsDlgController__
#define __LayerOptionsDlgController__

#include "CDialogController.h"
#include "ICommand.h"
#include "LayerPanelUtils.h"

class ISubject;
class IWidgetParent;
class IDocumentLayer;

class LayerOptionsDlgController : public CDialogController
{
public:
	// ----- Initialization -----
	
						LayerOptionsDlgController(IPMUnknown *boss);
	virtual				~LayerOptionsDlgController();
	
	// ----- Dialog protocol -----

	virtual void		InitializeDialogFields( IActiveContext* dlgContext);
	virtual WidgetID	ValidateDialogFields( IActiveContext* dlgContext);
	virtual void		ApplyDialogFields( IActiveContext* dlgContext, const WidgetID& widgetId);
	virtual void		ClosingDialog(IActiveContext* lastChanceToUseMyContext);

private:
	virtual ICommand*	MakeBoolCommand(ClassID classID, IDocumentLayer* layer, ITriStateControlData::TriState value);

	WidgetID ValidateNameField(IActiveContext* dlgContext, PMString& nameString, PMString& errorString);

	LayerPanelUtils::LayerDialogType fDialogType;			// Layer Options mode Duplicate Layer mode or New Layer mode (kFalse)
	LayerPanelUtils::LayerLocation fLayerLocation;	// Layer location for New Layer mode (onTop, aboveActive, or belowActive )

};


#endif
