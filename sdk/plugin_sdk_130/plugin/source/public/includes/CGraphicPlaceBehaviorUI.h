//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/CGraphicPlaceBehaviorUI.h $
//  
//  Owner: Lonnie Millett
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
#ifndef __CGraphicPlaceBehaviorUI__
#define __CGraphicPlaceBehaviorUI__

#include "CPMUnknown.h"
#include "IPlaceBehaviorUI.h"

class WIDGET_DECL CGraphicPlaceBehaviorUI : public CPMUnknown<IPlaceBehaviorUI>
{
public:	
	CGraphicPlaceBehaviorUI(IPMUnknown *boss);
	virtual ~CGraphicPlaceBehaviorUI();

	virtual CursorSpec GetCursor(SysPoint globalLocation, ICursorMgr::eCursorModifierState modifiers) const;
	virtual IPlaceBehavior* QueryPlaceBehaviorAt(const PMPoint& point) const;
	virtual CursorSpec	GetDropCursor(SysPoint globalLocation, ICursorMgr::eCursorModifierState modifiers) const;
protected:
/// helpers
	// override this for custom place into cursor.
	virtual CursorSpec GetPlaceIntoCursor() const;

	// override this for custom place cursor.
	virtual CursorSpec GetPlaceCursor() const;

private:
	CursorSpec CommonGetCursor(SysPoint globalLocation, ICursorMgr::eCursorModifierState modifiers, bool16 dropCursor = kFalse) const;
};

#endif
