//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/ITextPreferencesFacade.h $
//  
//  Owner: nmccully
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
#ifndef __ITextPreferencesFacade__
#define __ITextPreferencesFacade__

// ----- Interfaces -----

#include "IPMUnknown.h"

// ----- Includes -----

#include "TextEditorModelID.h"

class IDataBase;

/**   A high level API for dealing with text options/prefs.  Please use the ITextPreferencesFacade 
	directly via the UtilsBoss if possible, see Utils.h:
	i.e. Utils<Facade::ITextPreferencesFacade>()->SetTextToolConvertsFrames( ... ) ;
	  @author Dave Stephens
   */
namespace Facade
{
	enum DynamicAutoFlowKind {
		kAtEndOfStory = 0,	/** auto-add pages at end of story */
		kAtEndOfSection,	/** auto-add pages at end of section. */
		kAtEndOfDocument	/** auto-add pages at end of document. */
	};

	class ITextPreferencesFacade : public IPMUnknown
	{
	public:
		enum { kDefaultIID = IID_ITEXTPREFERENCESFACADE };


		//------------------------------------------------------
		//	Type Options
		//------------------------------------------------------
		/**     Return whether or not the text tool converts empty frames to text frames.
			@return true if the text tool converts empty frames to text frames. false otherwise.
		*/
		virtual bool GetTextToolConvertsFrames() const = 0;

		/**     Set whether or not the text tool converts empty frames to text frames.
			@param bConvertToText The new boolean to store
			@return kSuccess if successful.  Otherwise, an error code.
		*/
		virtual ErrorCode SetTextToolConvertsFrames(bool bConvertToText) const = 0;

		/**		Set Dynamic Autoflow Options
			@param enabled [IN]: Set whether or not to enable auto-page insertion
			@param kind [IN]: New auto-insert page setting to specify where to add pages.
			@param requireMaster [IN]: Restrict auto-insertion of pages to overridden master 
				text frames whose associated master text frame is empty.
			@param preserveRectoVerso [IN]: When auto-adding or auto-deleting pages during dynamic autoflow,
				preserve recto-verso orientation of pages. This option is only applicable when inserting/deleting
				pages in the middle of a document.
			@param allowAutoDelete [IN]: Enable the auto-deleting of pages with empty threaded text frames.
			@param db [IN]: IDataBase of doc holding the setting. If nil, then the option will be set
				in the application workspace.
			@return kSuccess if successful.  Otherwise, an error code.
		*/
		virtual ErrorCode SetDynamicAutoFlowOptions(bool enabled, DynamicAutoFlowKind kind, bool requireMaster, 
				bool preserveRectoVerso, bool allowAutoDelete, IDataBase *db) const = 0;

		/** Get the GetDynamicAutoFlowOptions
			@param db [IN]: IDataBase of the document containing the setting, or nil to get the setting
				from the application workspace.
			@param kind [OUT]: the current dynamic autoflow kind for the given workspace (application or document)
			@param requireMaster [OUT]: Restrict auto-insertion of pages to overridden master 
				text frames whose associated master text frame is empty.
			@param preserveRectoVerso [OUT]: When auto-adding or auto-deleting pages during dynamic autoflow,
				preserve recto-verso orientation of pages. This option is only applicable when inserting/deleting
				pages in the middle of a document.
			@param allowAutoDelete [OUT]: Enable the auto-deleting of pages with empty threaded text frames.
			@return whether or not dynamic autoflow is enabled
		*/
		virtual bool GetDynamicAutoFlowOptions( DynamicAutoFlowKind& kind, bool& requireMaster, 
			bool& preserveRectoVerso, bool& allowAutoDelete, IDataBase *db) const = 0;

		//------------------------------------------------------
		//	Drag & Drop Text Editing
		//------------------------------------------------------

		//------------------------------------------------------
		//	Links
		//------------------------------------------------------
	};
}
#endif	// __ITextPreferencesFacade__
