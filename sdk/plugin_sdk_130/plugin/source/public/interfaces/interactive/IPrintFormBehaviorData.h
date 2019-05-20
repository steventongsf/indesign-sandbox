//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/interactive/IPrintFormBehaviorData.h $
//  
//  Owner: Michael Brubidge
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

#pragma once
#ifndef __IPrintFormBehaviorData_h__
#define __IPrintFormBehaviorData_h__

#include "IBehaviorData.h"
#include "BehaviorID.h"
#include "K2Vector.h"
#include "K2Pair.h"

//========================================================================================
// CLASS IPrintFormBehaviorData
//========================================================================================

/** Data interface for Print Form Behavior
	@see INamedPageItemList (for a way of getting candidates for SetFields()
*/
class IPrintFormBehaviorData : public IBehaviorData
{
};

#endif // __IPrintFormBehaviorData_h__
