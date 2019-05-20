//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/actiondatapanels/movie/MovieDDLControlData.cpp $
//  
//  Owner: Michael Burbidge
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
#include "MovieListElement.h"
#include "DropDownListControlDataOf.tpp"
#include "K2Vector.tpp"

CREATE_PMINTERFACE(DropDownListControlDataOf<MovieListElement>, kMovieDDLControlDataImpl);

template <>
PMString DropDownListControlDataOf<MovieListElement>::GetString(const MovieListElement& item) const
{
	if (item.GetMovieRef() != UIDRef::gNull)
	{
		PMString title = Utils<Facade::IDynamicTargetsFacade>()->GetTargetName(item.GetMovieRef());
		
		if (title.IsEmpty())
		{
			title = Utils<Facade::IPageItemNameFacade>()->GetDefaultPageItemName(item.GetMovieRef());
			title.Translate();
			title.Insert("<");
			title.Append(">");
		}
		return title;
	}
	return PMString("$$$/Dialog/Behaviors/Movie/NoVideo");
}
