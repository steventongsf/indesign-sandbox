//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/actiondatapanels/sound/SoundDDLControlData.cpp $
//  
//  Owner: Tim Wright
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

// ----- Interface Includes -----

#include "IDynamicTargetsFacade.h"
#include "IPageItemNameFacade.h"

// ----- Implementation Includes -----

#include "BehaviorUIID.h"
#include "SoundListElement.h"
#include "DropDownListControlDataOf.tpp"
#include "K2Vector.tpp"

CREATE_PMINTERFACE(DropDownListControlDataOf<SoundListElement>, kSoundDDLControlDataImpl);

template <>
PMString DropDownListControlDataOf<SoundListElement>::GetString(const SoundListElement& item) const
{
	if (item.GetSoundRef() != UIDRef::gNull)
	{
		PMString title = Utils<Facade::IDynamicTargetsFacade>()->GetTargetName(item.GetSoundRef());
		
		if (title.IsEmpty())
		{
			title = Utils<Facade::IPageItemNameFacade>()->GetDefaultPageItemName(item.GetSoundRef());
			title.Translate();
			title.Insert("<");
			title.Append(">");
		}
		
		return title;
	}
	return PMString("$$$/Dialog/Behaviors/Sound/NoSound");
}
