//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/customdatalinkui/CusDtLnkUIFileNodeID.cpp $
//  
//  Owner: Adobe Developer Technologies
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

#include "VCPlugInHeaders.h"

// Interface includes:
#include "IPMStream.h"

// Project includes:
#include "CusDtLnkUIFileNodeID.h"

/**
	@ingroup customdatalinkui
*/

/* Compare
*/
int32 CusDtLnkUIFileNodeID::Compare(const NodeIDClass* nodeID) const
{
	const CusDtLnkUIFileNodeID* fileNode = static_cast<const CusDtLnkUIFileNodeID*>(nodeID);
	ASSERT(nodeID);
	return (const_cast<CusDtLnkUIFileNodeID*>
		(this)->fUniqueKey.Compare(kFalse, fileNode->GetUniqueKey()));
}


/* Clone
*/
NodeIDClass* CusDtLnkUIFileNodeID::Clone() const
{
	return new CusDtLnkUIFileNodeID(this->GetUniqueKey());
}


/* Read
*/
void CusDtLnkUIFileNodeID::Read(IPMStream* stream)
{
	this->fUniqueKey .ReadWrite(stream);
}


/* Write
*/
void CusDtLnkUIFileNodeID::Write(IPMStream* stream) const
{
	(const_cast<CusDtLnkUIFileNodeID*>(this)->fUniqueKey).ReadWrite(stream);
}

//	end, File:	CusDtLnkUITreeDataNode.cpp
