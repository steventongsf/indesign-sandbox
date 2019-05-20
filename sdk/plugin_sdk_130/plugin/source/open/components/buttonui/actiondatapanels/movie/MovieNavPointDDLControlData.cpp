//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/actiondatapanels/movie/MovieNavPointDDLControlData.cpp $
//  
//  Owner: Michele Stutzman
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

#include "INavigationPoints.h"

// ----- Implementation Includes -----

#include "BehaviorUIID.h"
#include "MovieListElement.h"
#include "DropDownListControlDataOf.tpp"
#include "K2Vector.tpp"

CREATE_PMINTERFACE(DropDownListControlDataOf<MovieNavPointListElement>, kMovieNavPointDDLControlDataImpl);

template <>
PMString DropDownListControlDataOf<MovieNavPointListElement>::GetString(const MovieNavPointListElement& item) const
{
	if (item.first == UIDRef::gNull && item.second == INavigationPoints::kInvalidNavigationPointId)
		return PMString("$$$/Dialog/Behaviors/Movie/NoVideoNavPoint");

	InterfacePtr<INavigationPoints> navPoints(item.first, UseDefaultIID());
	PMString title("");
	if ( navPoints )
	{
		navPoints->GetDisplayName( item.second, title );
		title.SetTranslatable(kFalse);
	}
	return title;
}
