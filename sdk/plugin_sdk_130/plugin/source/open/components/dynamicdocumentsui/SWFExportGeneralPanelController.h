//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFExportGeneralPanelController.h $
//  
//  Owner: DBerggren
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

#include "CDialogController.h"

class IPageRange;
class ISWFExportPreferences;

//========================================================================================
// CLASS SWFExportGeneralPanelController
//========================================================================================

class SWFExportGeneralPanelController : public CDialogController
{
	typedef	CDialogController Inherited;

	public:
		enum {
			// Fit To
			k1280x800Index				= 0,
			k1240x620Index,
			k1024x768Index,
			k984x588Index,
			k800x600Index,
			k760x420Index,
			k640x480Index,
			k600x300Index,

			// Scale
			k250Index					= 0,
			k200Index,
			k150Index,
			k100Index,
			k75Index,
			k50Index,
			k25Index,

			// Page Transition
			kPageTransitionFromDocumentIndex = 0,
			kPageTransitionNoneIndex,
			kPageTransitionSeparatorIndex,
		};

		// ----- Initialization -----
		SWFExportGeneralPanelController(IPMUnknown *boss);
		virtual	~SWFExportGeneralPanelController();
	
		// ----- Dialog protocol -----
		virtual void InitializeDialogFields( IActiveContext* ac);
		virtual void ResetDialogFields(IActiveContext* ac);
		virtual WidgetID ValidateDialogFields(IActiveContext* ac);
		virtual void ApplyDialogFields(IActiveContext* myContext, const WidgetID& widgetId);

	private:
		// ----- Private methods -----
		void InitializePageRange(IActiveContext* ac, IPageRange* iPageRange);
		void InitializeScale(ISWFExportPreferences* iPrefsData, IPageRange* iPageRange);
		void InitializePageTransitions(ISWFExportPreferences* iData, IPageRange* iPageRange);
		void InitializeOKButton();
};


// End, SWFExportGeneralPanelController.h.
