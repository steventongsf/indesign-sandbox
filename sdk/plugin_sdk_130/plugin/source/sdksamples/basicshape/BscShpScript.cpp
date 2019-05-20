//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/basicshape/BscShpScript.cpp $
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
#include "IPageItemScriptUtils.h"
#include "Utils.h"

// Implementation includes:
#include "CScript.h"
#include "BscShpID.h"
#include "BscShpScriptingDefs.h"

/** From SDK sample; shows how to implement CScript for this plug-in's scriptable custom page item,
	kBscShpPageItemBoss.

	@see kBscShpPageItemBoss
	@see BscShpScriptProvider
	@ingroup basicshape
*/
class BscShpScript : public CScript
{
public:
	/**	Constructor 
		@param boss interface ptr from boss object on which this interface is aggregated.
	*/
	BscShpScript(IPMUnknown* boss);

	/** Destructor.  
	*/
	virtual ~BscShpScript(void);

	/** Return the object's type.
		@param context is the request context
		@return The object's ScriptID.
	 */
	virtual ScriptID	GetObjectType( const RequestContext& context ) const;

	/** Set the object's type.
		@param context is the request context
	*/
	virtual void		SetObjectType( const ScriptID& type, const RequestContext& context );

	/**	Return the parent of this object in the script DOM hierarchy.
		IDOMElement::QueryParent delegates to this method. 
		@param iid IN IID of interest on the parent DOM object.
		@param context is the request context
		@return An interface pointer to the IID of interest on the parent DOM object. 
	 */
	virtual IPMUnknown*	QueryParent( const PMIID& iid, const RequestContext& context ) const ;
};


/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its
 ImplementationID making the C++ code callable by the
 application.
*/
CREATE_PMINTERFACE(BscShpScript, kBscShpScriptImpl)


/* 
*/
BscShpScript::BscShpScript(IPMUnknown* boss)
: 	CScript(boss)
{
	// do nothing
}

/* 
*/
BscShpScript::~BscShpScript(void)	
{
	// do nothing
}

/*
*/
void BscShpScript::SetObjectType( const ScriptID& type, const RequestContext& context )
{
	ASSERT(type == c_BasicShape);
}

/* 
*/
ScriptID BscShpScript::GetObjectType( const RequestContext& context ) const
{
	return c_BasicShape;
}

/*  
*/
IPMUnknown* BscShpScript::QueryParent( const PMIID& iid, const RequestContext& context ) const
{
	IPMUnknown* parent = nil;

	InterfacePtr<IScript> parentScript ( Utils<IPageItemScriptUtils>()->QueryPageItemParent( this, context ) );
	if ( parentScript != nil )
		parent = parentScript->QueryInterface( iid ) ;

	return parent ;
}

// End, BscShpScript.cpp.


