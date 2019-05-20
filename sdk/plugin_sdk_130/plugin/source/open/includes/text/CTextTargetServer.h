//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/includes/text/CTextTargetServer.h $
//  
//  Owner: Bernd Paradies
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
#ifndef __CTextTargetServer__
#define __CTextTargetServer__

#include "CTargetServer.h"
#include "TextPanelID.h"
#include "ITextModel.h"

class ITextAttributes;

#ifdef TEXTPANELLIB_BUILD
#pragma export on
#endif

//----------------------------------------------------------------------------------------
// Class CTextTargetServer
//----------------------------------------------------------------------------------------

class TEXTPANELLIB_DECL CTextTargetServer : public CTargetServer
{
public:
					CTextTargetServer(IPMUnknown *boss, PMIID nServerIID = IID_ITEXTTARGETSERVER );
		virtual		~CTextTargetServer();
		// CTargetServer
		virtual void	TextAttributesChanged(ITextAttributeSuite* attributes);
		virtual void	HandleFrequentSelectionChanged (void);

		virtual void	Update(const ClassID& theChange, ISubject* theSubject, const PMIID& protocol, void* changedBy);


		// CTargetServer's pure virtual methods:
		virtual	ITextTargetAttributes *		CreateTarget( IPMUnknown *pModelTarget ) const;
		virtual	IPMUnknown *		QueryModelTarget();
		virtual	PMIID			GetTargetServerIID() const;		// IID_ITEXTTARGETSERVER
		virtual	PMIID			GetWorkspaceIID() const;			// IID_ITEXTATTRIBUTES
		virtual	PMIID			GetObserverIID() const;			// IID_ITEXTTARGETOBSERVER

protected:
		bool16					fTextSelectionChanged;			// optimization in TextSelectionChanged()

		ITextAttributes *			QueryTextDefaults();

		virtual void AttachToAbstractSelection ();
		virtual void DetachFromAbstractSelection();

private:
		ITextModel* QueryModel();
};

#ifdef TEXTPANELLIB_BUILD
#pragma export off
#endif

#endif
