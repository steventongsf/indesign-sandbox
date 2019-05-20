//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/customdatalinkui/CusDtLnkUIFileNodeID.h $
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
//  
//  Each C++ implementation class in the plug-in and its corresponding ImplementationID
//  should be registered in this file.
//  
//========================================================================================

#ifndef __CusDtLnkUIFileNodeID__
#define __CusDtLnkUIFileNodeID__

#include "NodeID.h"
#include "IPMStream.h"
#include "CusDtLnkUIID.h"

/** Represents a node in the treeview for an asset-file or database-file
	@ingroup customdatalinkui
*/
class CusDtLnkUIFileNodeID : public NodeIDClass
{
public:
	enum { kNodeType = kCusDtLnkUITreeViewWidgetBoss }; 


	/**	Factory method to create 
	new object of this class
		@return   new instance of this class 
		*/
	static	NodeID_rv Create() { return new CusDtLnkUIFileNodeID(); }

	/**	Factory method to create new object of this class
		@param path [IN] specifies initial path
		@return  new instance of this class
		*/
	static	NodeID_rv Create(const PMString& p)  
		{ return new CusDtLnkUIFileNodeID(p); }

	/**	Destructor
		*/
	virtual ~CusDtLnkUIFileNodeID() {}
	

	/**	@return type of this node
		*/
	virtual	NodeType GetNodeType() const { return kNodeType; } 

	/**	Comparator function
		@param NodeID [IN] specifies the node that we should compare against
		@return  Comparison results
		*/
	virtual int32 Compare(const NodeIDClass* NodeID) const;

	/**	Create a copy of this
		@return  
		*/
	virtual NodeIDClass* Clone() const;

	/**	Read this from the given stream
		@param stream [IN] specified stream
		@return  
		*/
	virtual void Read(IPMStream* stream);

	/**	Write this to the given stream
		@param [OUT] stream 
		@return  
		*/
	virtual void Write(IPMStream* stream) const;

	/** @return const PMString& 
		*/
	const PMString& GetUniqueKey() const { return this->fUniqueKey; }

private:
	// Note we're keeping the destructor private to force use of the factory methods
	CusDtLnkUIFileNodeID() {}

	CusDtLnkUIFileNodeID(PMString p):fUniqueKey(p) { }

	PMString	fUniqueKey;
};

#endif // __CusDtLnkUIFileNodeID__


