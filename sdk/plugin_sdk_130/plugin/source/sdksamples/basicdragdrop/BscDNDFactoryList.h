//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/basicdragdrop/BscDNDFactoryList.h $
//  
//  Owner: Adobe Developer Technologies
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

REGISTER_PMINTERFACE(BscDNDActionComponent, kBscDNDActionComponentImpl)
// for drag and drop target
REGISTER_PMINTERFACE(BscDNDDropTarget, kBscDNDDropTargetImpl)
// for drag and drop source
REGISTER_PMINTERFACE(BscDNDDragSource, kBscDNDDragSourceImpl)
// for custom flavor target helper
REGISTER_PMINTERFACE(BscDNDCustomDragSource, kBscDNDCustomDragSourceImpl)
REGISTER_PMINTERFACE(BscDNDCustomDEHandler, kBscDNDCustomDEHandlerImpl)
REGISTER_PMINTERFACE(BscDNDCustomFlavorHelper, kBscDNDCustomFlavorHelperImpl)

//  Code generated by DollyXS code generator
