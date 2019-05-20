//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/includes/widgets/CTextDataValidation.h $
//  
//  Owner: Lance Bushore
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
#ifndef __CTextDataValidation__
#define __CTextDataValidation__

#include "ITextDataValidation.h"
#include "HelperInterface.h"

#ifdef WIDGET_BUILD
#pragma export on
#endif

class WIDGET_DECL CTextDataValidation : public ITextDataValidation
{
public:
	CTextDataValidation(IPMUnknown *boss);
	~CTextDataValidation();

	virtual void 		ReadWrite(IPMStream *s, ImplementationID prop);
	
	// used to turn off range checking(for margins, etc.)
	virtual void EnableRangeChecking(const bool16& checkingOn);
	virtual bool16 RangeCheckingEnabled() const;
	
	virtual bool16 IsBlankEntryAllowed() const;
	virtual void	AllowBlankEntry(const bool16& blankAllowed);

	virtual bool16 IsEntryLegal();	
	// if entry is not legal, calling GetErrorString will return an explanatory string.
	virtual PMString GetErrorString();
		
	virtual PMReal GetUpperLimit() const;
	virtual void	SetUpperLimit(const PMReal& limit);

	virtual PMReal GetLowerLimit() const;
	virtual void	SetLowerLimit(const PMReal& limit);

	virtual bool16 GetRestoreLastValueOnError() const;
	virtual void	SetRestoreLastValueOnError(const bool16& restoreValue);

protected:
	// child classes probably only need to override this one.
	virtual PMString GetOutOfRangeString();
	virtual bool16 ValueWithinLimits(const PMReal& value) const;

	bool16		fRangeCheckingEnabled;
	bool16		fBlankAllowed;
	RangeError	fErrorState;
	PMReal		fUpperLimit;
	PMReal		fLowerLimit;
	bool16		fRestoreValueOnError;

DECLARE_HELPER_METHODS()
};

#pragma export off

#endif // __CTextDataValidation__