//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/TimingPanelDataExchangeHandler.cpp $
//  
//  Owner: Yeming Liu
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  ADOBE CONFIDENTIAL
//  
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//  
//  Comments: Implementation for object style z-order exchange handler
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// ----- Interface files -----

// ----- Include files -----

#include "CDataExchangeHandlerFor.h"

// ----- Utilitity files -----

// ----- ID files -----

#include "DynamicDocumentsUIID.h"

//========================================================================
// Class TimingPanelDataExchangeHandler
//========================================================================

class TimingPanelDataExchangeHandler : public CDataExchangeHandlerFor
{
	public:
				TimingPanelDataExchangeHandler(IPMUnknown *boss) : CDataExchangeHandlerFor(boss) {}
		virtual	~TimingPanelDataExchangeHandler() {}

		virtual	PMFlavor 	GetFlavor() const { return kPMTimingPanelDragDropFlavor; }
};

CREATE_PMINTERFACE(TimingPanelDataExchangeHandler, kTimingPanelDataExchangeHandlerImpl)
