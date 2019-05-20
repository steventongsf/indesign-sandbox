//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/IRecoverDocumentCmdData.h $
//  
//  Owner: Roey Horns
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
#ifndef __IRecoverDocumentCmdData__
#define __IRecoverDocumentCmdData__

#include "IPMUnknown.h"

#ifndef __IDATABASE__
#include "IDataBase.h"
#endif
#include "PMString.h"
#include "IDocument.h"
#include "DocumentID.h"


class IRecoverDocumentCmdData : public IPMUnknown
{
public:
	enum {kDefaultIID = IID_IRECOVERDOCUMENTCMDDATA}; 
	virtual void SetPubFilePath(const PMString &path) = 0;
	virtual void SetMiniSaveFilePath(const PMString &path) = 0;
	virtual void SetProtectionLevel(IDataBase::ProtectionLevel level) = 0;
	virtual void SetOpenUIFlag(const bool16& bOpen) = 0;
	virtual void SetIsFauxUserFile(bool bIsFauxUserFile) = 0;

	/**
		Set the undo support option @see IDocument.
		@param IDocument::UndoSupport.  
	*/
	virtual void SetUndoSupport(IDocument::UndoSupport undoSupport) = 0;

	
	virtual const PMString& PubFilePath() const = 0;
	virtual const PMString& MiniSaveFilePath() const = 0;
	virtual IDataBase::ProtectionLevel ProtectionLevel() const = 0;
	virtual const bool16& GetOpenUIFlag() const = 0;
	virtual bool16 GetIsFauxUserFile() const = 0;
	/**
		Get the undo support option @see IDocument.
		@return IDocument::UndoSupport.  
	*/
	virtual IDocument::UndoSupport GetUndoSupport() const = 0;
};


#endif // __IDocProtectionPrefsCmdData__
