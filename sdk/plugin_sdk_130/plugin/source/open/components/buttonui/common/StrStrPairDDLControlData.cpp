//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/common/StrStrPairDDLControlData.cpp $
//  
//  $Owner: Tim Wright $
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

#include "IPMStream.h"

// ----- Implementation Includes -----

#include "BehaviorUIID.h"
#include "DropDownListControlDataOf.tpp"
#include "K2Vector.tpp"
#include "K2Pair.h"
#include "PMString.h"

typedef K2Pair<PMString, PMString> StrStrContainerData;

CREATE_PMINTERFACE(DropDownListControlDataOf<StrStrContainerData>, kStrStrPairDDLControlDataImpl);

template <>
PMString DropDownListControlDataOf<StrStrContainerData>::GetString(const StrStrContainerData& item) const
{
	return item.first;
}
