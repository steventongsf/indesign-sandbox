//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/layout/IAutoLayoutPrefsCmdData.h $
//  
//  Owner: Rich Gartland
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
//  Data interface for auto layout preference command.
//  
//========================================================================================

#pragma once
#ifndef __IAutoLayoutPrefsCmdData__
#define __IAutoLayoutPrefsCmdData__

#include "IPMUnknown.h"
#include "AutoLayoutID.h"

/**	Interface for setting and getting data for the kSetAutoLayoutPrefsCmdBoss command.
*/
class IAutoLayoutPrefsCmdData : public IPMUnknown
{
public:
	/**	Set all the values at once.
		@param doc IN a reference to the document whose preferences are being set.
		@param bAutoLayoutOn IN kTrue to turn on, kFalse to turn off.
		@param bStretchGraphics IN kTrue to allow stretching of graphics or groups, kFalse to disallow
		@param bMoveGuides IN kTrue to allow moving ruler guides, kFalse to disallow
		@param bLoosenLocks IN kTrue to allow adjusting locked items, kFalse to disallow
		@param bStickyGuides IGNORED guide stickiness is always on; this setting is ignored
		@param bIgnoreGuides IN kTrue to ignore guides, kFalse to obey guides
		@param rAutoSnapZone IN distance in points from either side of an edge to consider aligned with guides, columns, etc. (range is 0 to 12 pts).
	*/
	virtual void Set(	const	UIDRef&	doc,
						bool16 bAutoLayoutOn,
						bool16 bStretchGraphics,
						bool16 bMoveGuides,
						bool16 bLoosenLocks,
						bool16 bStickyGuides,
						bool16 bIgnoreGuides,
						PMReal rAutoSnapZone) = 0;	
	
	/**	Enable the Layout Adjustment feature.
		@param val IN kTrue to turn on, kFalse to turn off.
	*/
	virtual void SetAutoLayoutOn(bool16 val) = 0;

	/**	Allow graphics and groups to be stretched (as opposed to moved only) by layout adjustment.
		@param val IN kTrue to allow stretching, kFalse to disallow
	*/
	virtual void SetStretchGraphics(bool16 val) = 0;

	/**	Allow guides to be moved by layout adjustment.
		@param val IN kTrue to allow moving, kFalse to disallow
	*/
	virtual void SetMoveGuides(bool16 val) = 0;

	/**	Allow locked items to be adjusted by layout adjustment.
		@param val IN kTrue to allow adjusting locked items, kFalse to disallow
	*/
	virtual void SetLoosenLocks(bool16 val) = 0;

	/**	Set whether ruler guides move with column edges if aligned.
		@param val IGNORED guide stickiness is always on; this setting is ignored
	*/
	virtual void SetStickyGuides(bool16 val) = 0;

	/**	Ignore alignment to ruler guides when performing layout adjustment.
		@param val IN kTrue to ignore guides, kFalse to obey guides
	*/
	virtual void SetIgnoreGuides(bool16 val) = 0;

	/**	Set the tolerance zone for layout adjustment's determination of pageitem edge alignment to guides, columns, etc.
		@param val IN distance in points from either side of an edge to consider aligned with guides, columns, etc. (range is 0 to 12 pts).
	*/
	virtual void SetAutoSnapZone(PMReal val) = 0;
	
	/**	Get a UIDRef for the document to apply the preferences to.
		@return a UIDRef for the document.
	*/
	virtual const UIDRef& GetDocument() const = 0;

	/**	Get the on/off state of layout adjustment.
		@return kTrue for on, kFalse for off
	*/
	virtual const bool16 GetAutoLayoutOn() const = 0;

	/**	Get whether graphics and groups may be stretched by layout adjustment.
		@return kTrue for allow stretching,  kFalse for disallow
	*/
	virtual const bool16 GetStretchGraphics() const = 0;

	/**	Get whether guides may be moved by layout adjustment.
		@return kTrue for allow moving,  kFalse for disallow
	*/
	virtual const bool16 GetMoveGuides() const = 0;

	/**	Get whether locked items can be adjusted by layout adjustment.
		@return kTrue for allow adjusting locked items,  kFalse for disallow
	*/
	virtual const bool16 GetLoosenLocks() const = 0;

	/**	Get whether ruler guides move with column guides when aligned. UNUSED; INTERNAL STATE IS ALWAYS kTrue.
		@return kTrue for allow stretching,  kFalse for disallow
	*/
	virtual const bool16 GetStickyGuides() const = 0;

	/**	Get whether guide alignments are ignored by layout adjustment.
		@return kTrue for ignore guides,  kFalse for don't ignore guides
	*/
	virtual const bool16 GetIgnoreGuides() const = 0;

	/**	Get the auto-snap zone.
		@return PMReal alignment tolerance zone in points (range 0-12 pts)
	*/
	virtual const PMReal GetAutoSnapZone() const = 0;

};




#endif // __IDocSetupCmdData__
