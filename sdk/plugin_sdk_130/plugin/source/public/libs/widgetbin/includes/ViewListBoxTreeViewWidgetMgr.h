//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/libs/widgetbin/includes/ViewListBoxTreeViewWidgetMgr.h $
//  
//  Owner: Bob Freeman
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
#ifndef __ViewListBoxTreeViewWidgetMgr__
#define __ViewListBoxTreeViewWidgetMgr__

#include "CTreeViewWidgetMgr.h"
#include "ViewNodeID.h"


class WIDGET_DECL ViewListBoxTreeViewWidgetMgr : public CTreeViewWidgetMgr
{
public:
	ViewListBoxTreeViewWidgetMgr(IPMUnknown *boss);
	virtual ~ViewListBoxTreeViewWidgetMgr();
	virtual PMReal GetNodeWidgetHeight(const NodeID& node) const;
	virtual PMReal GetNodeWidgetWidth(const NodeID& node) const;
	virtual void	PreDeleteWidget( IControlView* widget );

protected:
	virtual bool16	ApplyDataToWidget( const NodeID& node, IPanelControlData* widgetList, int32 message = 0 ) const;
	virtual void	RegisterStyles();
	virtual IControlView* CreateWidgetForNode(const NodeID& node) const;

};


#pragma export off

#endif
