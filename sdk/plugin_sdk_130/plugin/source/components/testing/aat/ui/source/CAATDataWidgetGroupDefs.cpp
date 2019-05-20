//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/components/testing/aat/ui/source/CAATDataWidgetGroupDefs.cpp $
//  
//  Owner: Gregor Kaplan
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
//  NOTICE:  All information contained herein is, and remains
//  the property of Adobe Systems Incorporated and its suppliers,
//  if any.  The intellectual and technical concepts contained
//  herein are proprietary to Adobe Systems Incorporated and its
//  suppliers and may be covered by U.S. and Foreign Patents,
//  patents in process, and are protected by trade secret or copyright law.
//  Dissemination of this information or reproduction of this material
//  is strictly forbidden unless prior written permission is obtained
//  from Adobe Systems Incorporated.
//  
//========================================================================================

#include "VCAATLibHeaders.h"
#include "AATArchUIDlgDefines.h"
#include "CAATDataWidgetGroupDefs.h"
#include "PMRect.h"

extern const 	PMRect k_valEditRect(kDataStringsRight + kDlgMargin, 
							kValueStringTop, 
							kDataEntryRight -15, 
							kValueStringBottom);


extern const 	PMRect k_valTreeRect(kDataStringsRight - kDlgMargin, 
							kValueStringTop, 
							kDataEntryRight -15, 
							kValueTreeBottom);
							
extern const	PMRect k_varEditRect(kDataStringsRight + kDlgMargin, 
							kVarStringTop,
							kDataEntryRight -15, 
							kVarStringBottom);
							
extern const	PMRect k_varIterRect(kDataStringsRight + kDlgMargin, 
							kIterStringTop,
							kDataEntryRight -15, 
							kIterStringBottom);

extern const 	PMRect k_typeDDRect(kDataStringsRight + kDlgMargin, 
							(kVarStringTop - 10) - kStdWidgetHeight,
							kDataEntryRight -15,
							kVarStringTop - 10);
