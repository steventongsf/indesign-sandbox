//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/layout/IAnnotationUtils.h $
//  
//  Owner: Mudit Rastogi
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
#ifndef __IAnnotationUtils__
#define __IAnnotationUtils__

#include "PDFID.h"

#include "UIDList.h"

#include "AnnotationItem.h"
#include "itextRangeNode.h"
#include "ITextRangeList.h"

#include "IDocument.h"
#include <list>
class ITextModel;

class IAnnotationUtils : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IANNOTATIONUTILS };

	/** Given a uidList of page/pageitems return UID list of all annotation linked to these page/pageitems.

	@param uidList - list of page/pageitems
	@return UIDList  - uidList of all annotations linked to page/pageitems list
    @param bIsSortByTimeStamp - true means sort the annotation list by time stamp
    @return includeTextRanges - false means do not get all the text ranges on the pageitem if it is a text frame
	*/
	virtual UIDList GetListOfAnnotUIDOnPageOrPageItems(const UIDList &uidList, bool bIsSortByTimeStamp = false, bool includeTextRanges = true) = 0;

	/** Given a text range return UID list of all annotation linked to this text range
	@param *model - The text model to look at
	@param start - The start of the range
	@param end - The end of the range 
	@param bIsSortByTimeStamp - true means sort the annotation list by time stamp
	@return UIDList  - uidList of all annotations linked to given text range
	*/
	virtual UIDList GetListOfAnnotUIDOnTextRange(ITextModel *model, TextIndex start, TextIndex end, bool bIsSortByTimeStamp = false) = 0;
    
    /** Given a document return UID list of all annotations that are orphan and hence have been mapped to this document
     @param doc - The UIDRef of the document
     */
    virtual UIDList GetListOfAnnotUIDMappedToDoc(const UIDRef &doc) = 0;

	/**	Deletes annotation. This method deletes the specified annotation object and disassociate the annotation with corresponding annotation destination.
	We delete the associated destination as well because there can only be one annotation referencing a destination.
	@param annotUIDRef - UIDRef of annotation to be deleted.
	@return ErrorCode - result of the operation.
	*/
	virtual ErrorCode DeleteAnnotation(const UIDRef &annotUIDRef) = 0;

	/**	Deletes annotation list. 
	@param annotList - annotation list to be deleted.
	*/
	virtual ErrorCode DeleteAnnotationList(const UIDList &annotList) = 0;

	/**	Change the  annotation status.

	@param annotation - annotation to be changed.
	@param newStatus - new Status for the annotation.

	@return ErrorCode - result of the operation.
	*/
	virtual ErrorCode ChangeAnnotationStatus(const UIDRef &annotation, const AnnotationStatus &newStatus) = 0;

	/** Given the annotation UID it fills the structure AnnotationItem with complete data of annotation.

	@param annotation - annotation to be read.
	@param annotData - structure AnnotationItem which will be filled by annotation Data
	*/
	virtual void ReadAnnotationData(const UIDRef &annotUIDRef, AnnotationItem &annotData) = 0;
};

#endif // __IAnnotationUtils__
