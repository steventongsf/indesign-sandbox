//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFPreviewWarningIconTip.cpp $
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

#include "IStringData.h"
#include "AbstractTip.h"

// ----- Includes -----

#include "PMString.h"

// ----- Utils -----

#include "IMenuUtils.h"

// ----- ID.h files -----

#include "DynamicDocumentsUIID.h"

class SWFPreviewWarningIconTip : public AbstractTip
{			
	public:
		SWFPreviewWarningIconTip( IPMUnknown *boss );
		virtual ~SWFPreviewWarningIconTip();

		virtual PMString  GetTipText(const PMPoint& mouseLocation);
};

CREATE_PMINTERFACE(SWFPreviewWarningIconTip, kSWFPreviewWarningIconTipImpl)

SWFPreviewWarningIconTip::SWFPreviewWarningIconTip(IPMUnknown *boss) :
	AbstractTip( boss )
{
}

SWFPreviewWarningIconTip::~SWFPreviewWarningIconTip()
{
}

PMString SWFPreviewWarningIconTip::GetTipText(const PMPoint& mouseLocation)
{
	PMString tipString("");
	InterfacePtr<IStringData> iData(this, UseDefaultIID()); // string data is set in SWFPreviewPanelObserver when update the current page widget
	if (iData)
	{
		tipString = iData->GetString();  
	}

	return tipString;
} 

