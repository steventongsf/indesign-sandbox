//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/common/IFieldSelectionTreeViewAdptr.h $
//  
//  Owner: Michael Brubidge
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

#pragma once
#ifndef __IFieldSelectionTreeViewAdapter_h__
#define __IFieldSelectionTreeViewAdapter_h__

#include "ITreeViewHierarchyAdapter.h"
#include "BehaviorTypes.h"
#include "K2Vector.h"
#include "K2Pair.h"

//========================================================================================
// CLASS IFieldSelectionTreeViewAdapter
//========================================================================================

class IFieldSelectionTreeViewAdapter : public ITreeViewHierarchyAdapter
{
public:
	virtual void		Set(IDataBase* db, const K2Vector< K2Pair<UID, bool16> >& fields) = 0;
	virtual K2Vector< K2Pair<UID, bool16> > Get() const = 0;
	
	virtual IDataBase* 	GetDataBase() const = 0;
	
	virtual PMString 	GetFieldName(const NodeID& node) const = 0;
	
	virtual void		SetSelected(const NodeID& node, const bool16& selected) = 0;
	virtual bool16 		GetSelected(const NodeID& node) const = 0;
};

#endif // __IFieldSelectionTreeViewAdapter_h__
