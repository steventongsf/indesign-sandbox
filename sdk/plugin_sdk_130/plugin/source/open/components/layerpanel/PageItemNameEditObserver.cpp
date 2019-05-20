//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/layerpanel/PageItemNameEditObserver.cpp $
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

#include "InLineEditObserver.h"
#include "ISubject.h"
#include "ITextControlData.h"
#include "IPageItemNameFacade.h"
#include "IDocument.h"

#include "LayerPanelID.h"
#include "LayerTreeUIDNodeID.h"
#include "LayerPanelUtils.h"
#include "Utils.h"

class PageItemNameEditObserver : public InLineEditObserver
{
	public:
		PageItemNameEditObserver(IPMUnknown *boss);
		virtual ~PageItemNameEditObserver();
		
		virtual void Update(const ClassID& theChange, ISubject* theSubject, const PMIID& protocol, void* changedBy);
		
		virtual void AutoAttach();			
		virtual void AutoDetach();
	
};


CREATE_PMINTERFACE(PageItemNameEditObserver, kPageItemNameEditObserverImpl)

PageItemNameEditObserver::PageItemNameEditObserver(IPMUnknown *boss) :
	InLineEditObserver(boss)
{
}

PageItemNameEditObserver::~PageItemNameEditObserver()
{
}

void PageItemNameEditObserver::AutoAttach()
{
	InLineEditObserver::AutoAttach();

	InterfacePtr<ISubject> subjectList( this, UseDefaultIID() );
	if (subjectList)
		subjectList->AttachObserver(this, ITextControlData::kDefaultIID); 
}

void PageItemNameEditObserver::AutoDetach()
{
	InterfacePtr<ISubject> subjectList( this, UseDefaultIID() );
	if (subjectList)
		subjectList->DetachObserver(this, ITextControlData::kDefaultIID);

	InLineEditObserver::AutoDetach();
}

void PageItemNameEditObserver::Update(const ClassID& theChange, ISubject* theSubject, const PMIID& protocol, void* changedBy)
{
	if (protocol == ITextControlData::kDefaultIID && theChange == kTextChangeStateMessage)
	{
		NodeID treeNode(LayerPanelUtils::GetLayerTreeNodeFromSubwidget(this)); // this looks like it could be combined with the next line, but doing so creates a memory leak.
		TreeNodePtr<const LayerTreeUIDNodeID>	layerTreeNode(treeNode);

		InterfacePtr<const ITextControlData>	textData(theSubject, UseDefaultIID());
		UIDRef piRef(LayerPanelUtils::GetCurrentLayerPanelDB(this),layerTreeNode->GetUID());
		PMString newString(textData->GetString());
		newString.SetTranslatable(kFalse);
		Utils<Facade::IPageItemNameFacade>()->SetUserAssignedPageItemName(piRef,newString);	
	}

	InLineEditObserver::Update(theChange, theSubject, protocol, changedBy);
}

