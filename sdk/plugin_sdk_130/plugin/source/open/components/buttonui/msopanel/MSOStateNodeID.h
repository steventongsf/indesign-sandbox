//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/msopanel/MSOStateNodeID.h $
//  
//  Owner: Michele Stutzman
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  ADOBE CONFIDENTIAL
//  
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#ifndef __MSOStateNodeID__
#define __MSOStateNodeID__

#include "IAppearanceList.h"
#include "FormFieldTypes.h"
#include "FormFieldUIID.h"
#include "NodeID.h"

#pragma export on

class MSOStateNodeID  : public NodeIDClass
{
public:
	enum { kNodeType = kMSOStateNodeID }; 

	virtual ~MSOStateNodeID() {}
    virtual NodeType GetNodeType() const { return kNodeType; }
    virtual int32 Compare(const NodeIDClass* NodeID) const;
    virtual NodeIDClass* Clone() const;
    virtual void Read(IPMStream* stream);
    virtual void Write(IPMStream* stream) const;
	virtual NodeID_rv GetGenericNodeID() const;
	virtual PMString GetDescription() const;

	static	NodeID_rv Create(const Form::AppearanceState& appearanceState) { return new MSOStateNodeID(appearanceState); }

public:
	Form::AppearanceState GetAppearance() const { return fAppearanceState; }
	IDataBase*	GetDataBase() const;

private:
	MSOStateNodeID(const Form::AppearanceState& appearanceState) : fAppearanceState(appearanceState) {}

	Form::AppearanceState	fAppearanceState;
};

#endif
