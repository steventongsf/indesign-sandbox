//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/layerpanel/SelectionProxyDrawData.cpp $
//  
//  Owner: lance bushore
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

#include "VCPlugInHeaders.h"

// ----- Interfaces -----

#include "ISelectionProxyDrawData.h"

// ----- ID.h files -----

#include "LayerPanelID.h"


class SelectionProxyDrawData : public CPMUnknown<ISelectionProxyDrawData>
{
	public:
		SelectionProxyDrawData(IPMUnknown *boss);
		virtual ~SelectionProxyDrawData() {}
		virtual void SetDrawingMode(ProxyDrawType type){ fDrawType = type; }
		virtual ProxyDrawType GetDrawingMode() const {return fDrawType; }

	private:
	ProxyDrawType fDrawType;
};



CREATE_PMINTERFACE(SelectionProxyDrawData, kSelectionProxyDrawDataImpl)

SelectionProxyDrawData::SelectionProxyDrawData(IPMUnknown *boss) :
	CPMUnknown<ISelectionProxyDrawData>(boss),fDrawType(kUnselected)
{
}


