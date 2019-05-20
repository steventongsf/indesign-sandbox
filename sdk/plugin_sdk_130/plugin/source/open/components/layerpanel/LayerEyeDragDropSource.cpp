//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/layerpanel/LayerEyeDragDropSource.cpp $
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
//  
//  Drag source for layer panel eye widget.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// ----- Interfaces -----

#include "IBoolData.h"
#include "IDocument.h"
#include "IDocumentLayer.h"
#include "IUIDData.h"
#include "IWidgetParent.h"
#include "ITreeNodeIDData.h"
#include "LayerTreeUIDNodeID.h"
#include "IPageItemVisibilityFacade.h"

// ----- Includes -----

#include "CDragDropSource.h"
#include "LocaleSetting.h"
#include "HelperInterface.h"
#include "LayerPanelDefs.h"
#include "Utils.h"

// ----- Utility files -----

#include "CmdUtils.h"
#include "LayerPanelUtils.h"

// ----- ID.h files -----

#include "AppUIID.h"
#include "LayerPanelID.h"
#include "widgetid.h"



class LayerEyeDragDropSource : public CDragDropSource
{
public:
	LayerEyeDragDropSource(IPMUnknown *boss);
	virtual ~LayerEyeDragDropSource();

	virtual SysWireframe		DoMakeDragOutlineRegion() const	{ return nil; }
		// No drag outline region needed for eye

	virtual bool16		DoAddDragContent(IDragDropController*);
	virtual CursorSpec 	GetDragCursor(DragDrop::eTargetResponse, bool16 isDragLocal) const;

		DECLARE_HELPER_METHODS()
};


CREATE_PMINTERFACE(LayerEyeDragDropSource, kLayerEyeDragDropSourceImpl)
DEFINE_HELPER_METHODS(LayerEyeDragDropSource)

LayerEyeDragDropSource::LayerEyeDragDropSource(IPMUnknown *boss)  :
	CDragDropSource(boss),
	HELPER_METHODS_INIT(boss)
{
}


LayerEyeDragDropSource::~LayerEyeDragDropSource()
{
}

//--------------------------------------------------------------------------------------
// DoAddDragContent
//--------------------------------------------------------------------------------------
bool16 LayerEyeDragDropSource::DoAddDragContent(IDragDropController* controller)
{
//	if (LocaleSetting::GetLocale().IsProductFS(kInCopyProductFS))
//		return kFalse;

	// Obtain a handler for our internal data flavor
	InterfacePtr<IDataExchangeHandler> ourHandler(controller->QueryHandler(kPMLayerEyeFlavor));
	
	// Don't promise anything if we couldn't get a handler
	if (!ourHandler)
		return kFalse;
	
	// Place the appropriate data or data reference into the handler
	InterfacePtr<IUIDData> data(ourHandler, IID_IUIDDATA);
	if (data)
	{
		// Get the layer UID ref for this item/layer, store it
		NodeID treeNode(LayerPanelUtils::GetLayerTreeNodeFromSubwidget(this)); // this looks like it could be combined with the next line, but doing so creates a memory leak.
		TreeNodePtr<const LayerTreeUIDNodeID>	uidNode(treeNode);

		UIDRef itemUIDRef = UIDRef(LayerPanelUtils::GetCurrentLayerPanelDB(this),uidNode->GetUID());
		
		InterfacePtr<const IDocumentLayer> docLayer(itemUIDRef,UseDefaultIID());
		bool isVisible = false;
		if(docLayer)
			isVisible = docLayer->IsVisible();
		else
		{
			isVisible = Utils<Facade::IPageItemVisibilityFacade>()->GetVisibleState(itemUIDRef);
		}
		data->Set(itemUIDRef);	

		// Place the appropriate data or data reference into the handler
		InterfacePtr<IBoolData> boolData(ourHandler, IID_IBOOLDATA);
		if (boolData)
		{
			// Get the current state of the layer, store it
			boolData->Set(isVisible);
		}
	}
	
	// Install our handler so we can fulfill promises we make below
	controller->SetSourceHandler(ourHandler) ;
	
	// Add a data item and promise the appropriate data flavors
	//	Note that in this case we promise only one since the internal flavor and external flavor are the same.
	InterfacePtr<IPMDataObject> item(controller->AddDragItem(1));
	PMFlavorFlags flavorFlags = 0;
	item->PromiseFlavor(kPMLayerEyeFlavor, flavorFlags);

	return kTrue;
}

//--------------------------------------------------------------------------------------
// GetDragCursor
//--------------------------------------------------------------------------------------
CursorSpec 	LayerEyeDragDropSource::GetDragCursor(DragDrop::eTargetResponse, bool16 /*isDragLocal*/) const
{
	return CursorSpec(kAppUIPluginID,kCrsrPointyHand);
}

