//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFPreviewPanelView.cpp $
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
//========================================================================================

#include "VCPlugInHeaders.h"

#include "DVPalettePanelView.h"
#include "DynamicDocumentsUIDefs.h"

#include "DynamicDocumentsUIID.h"

class SWFPreviewPanelView : public DVPalettePanelView
{
	public:
		typedef DVPalettePanelView inherited;


		SWFPreviewPanelView(IPMUnknown *boss);
		~SWFPreviewPanelView();

	protected:
		virtual PMPoint ConstrainDimensions(const PMPoint& dimensions) const;
};

CREATE_PERSIST_PMINTERFACE(SWFPreviewPanelView, kSWFPreviewPanelViewImpl)


//----------------------------------------------------------------------------------------
// SWFPreviewPanelView::SWFPreviewPanelView
//----------------------------------------------------------------------------------------

SWFPreviewPanelView::SWFPreviewPanelView(IPMUnknown *boss) :
	inherited(boss)
{
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelView::~SWFPreviewPanelView
//----------------------------------------------------------------------------------------

SWFPreviewPanelView::~SWFPreviewPanelView()
{
}

PMPoint SWFPreviewPanelView::ConstrainDimensions(const PMPoint& dimensions) const
{
	PMPoint constrainedDim(dimensions);

	if(constrainedDim.X() < kMinSWFPreviewPanelWidth  )
		constrainedDim.X(kMinSWFPreviewPanelWidth);

	if (constrainedDim.Y() < kMinSWFPreviewPanelHeight)
		constrainedDim.Y(kMinSWFPreviewPanelHeight);

	return constrainedDim;
}

