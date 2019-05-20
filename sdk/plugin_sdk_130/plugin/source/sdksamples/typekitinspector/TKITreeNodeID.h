//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/typekitinspector/TKITreeNodeID.h $
//  
//  Owner: Timothy Brand-Spencer
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  Copyright 1997-2015 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#ifndef __TKITreeNodeID__
#define __TKITreeNodeID__

#include "NodeID.h"
#include "IPMStream.h"
#include "TKIID.h"
#include "TextRange.h"

class TKITreeNodeID : public NodeIDClass
{
	public:
		enum { kNodeType = kTKITextListWidgetBoss }; 

		static	NodeID_rv			Create() { return new TKITreeNodeID(); }
		static	NodeID_rv			Create(const PMString& pathListString, InDesign::TextRange& textRange) { return new TKITreeNodeID(pathListString, textRange); }

		virtual ~TKITreeNodeID() {}
		
		virtual	NodeType			GetNodeType() const { return kNodeType; } 
		virtual int32				Compare(const NodeIDClass* NodeID) const;
		virtual NodeIDClass*		Clone() const;
		virtual void				Read(IPMStream*	stream);
		virtual void				Write(IPMStream* stream) const;
		virtual PMString			GetDescription() const;
		virtual InDesign::TextRange GetTextRange() const;
		
		const PMString& GetString() const { return fString; }
	private:
		TKITreeNodeID() {}
		TKITreeNodeID(PMString theString, InDesign::TextRange textRange):fString(theString),fTextRange(textRange) {}

		PMString			fString;
		InDesign::TextRange fTextRange;
};

#endif //__TKITreeNodeID__