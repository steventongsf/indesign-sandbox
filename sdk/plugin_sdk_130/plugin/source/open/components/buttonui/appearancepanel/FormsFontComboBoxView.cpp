//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/buttonui/appearancepanel/FormsFontComboBoxView.cpp $
//  
//  Owner: Reena Agrawal
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

#include "VCPlugInHeaders.h"

// ----- Interfaces -----
#include "CIDComboBoxView.h"
// ----- Includes -----
#include "FormFieldUIID.h"
#include "ISubject.h"
#include "IFontMgr.h"
#include "FontMgrID.h"
#include "IFontGroup.h"
#include "IPMFont.h"
#include "IStringListControlData.h"
#include"IDropDownListController.h"


bool ArrayComparator(const std::vector<PMString>& a, const std::vector<PMString>& b)
{
	return a[0] < b[0];
}


class FormsFontComboBoxView : public CIDComboBoxView
{
	typedef CIDComboBoxView Inherited;
public:
	FormsFontComboBoxView(IPMUnknown* boss);
	virtual ~FormsFontComboBoxView();

	virtual void DoPostCreate()
	{
		Inherited::DoPostCreate();
	}
private:
	void FillOutFontInList();
};

CREATE_PERSIST_PMINTERFACE(FormsFontComboBoxView, kFormsFontComboboxViewImpl)

FormsFontComboBoxView::FormsFontComboBoxView(IPMUnknown* boss) :Inherited(boss)
{}

FormsFontComboBoxView::~FormsFontComboBoxView()
{}

void  FormsFontComboBoxView::FillOutFontInList()
{
}
