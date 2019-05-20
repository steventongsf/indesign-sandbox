//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/layerpanel/ProxyWidgetTip.cpp $
//  
//  Owner: Paul Sorrick
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
//  Contains the main implementation of the ITip interface for widgets
//  
//========================================================================================

#include "VCPlugInHeaders.h"

//interfaces
#include "AbstractTip.h"
#include "ISelectionProxyDrawData.h"
#include "IDocument.h"

//includes
#include "LayerPanelID.h"
#include "PMString.h"
#include "HelperInterface.h"

class ProxyWidgetTip : public AbstractTip
{			
public:
	ProxyWidgetTip( IPMUnknown *boss );
	virtual ~ProxyWidgetTip();

	virtual PMString  GetTipText(const PMPoint& mouseLocation);
	
};

CREATE_PMINTERFACE( ProxyWidgetTip, kProxyWidgetTipImpl )


ProxyWidgetTip::ProxyWidgetTip(IPMUnknown *boss) :
	AbstractTip( boss )
{
}

ProxyWidgetTip::~ProxyWidgetTip()
{
}

PMString ProxyWidgetTip::GetTipText(const PMPoint&)
{
	PMString proxyTip = "UnselectedProxyTip";

	// Only make a string for the tip if the proxy is visible for this layer.
	InterfacePtr<const ISelectionProxyDrawData> drawData(this, UseDefaultIID());
	if(drawData->GetDrawingMode() == ISelectionProxyDrawData::kSelected)
	{
		proxyTip = "ProxyTip";
	} 
	else if(drawData->GetDrawingMode() == ISelectionProxyDrawData::kChildSelected)
	{
		proxyTip = "ProxyChildSelectedTip";
	} 
	
	return proxyTip;
} 

