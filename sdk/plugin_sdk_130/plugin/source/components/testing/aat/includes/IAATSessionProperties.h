//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/components/testing/aat/includes/IAATSessionProperties.h $
//  
//  Owner: Kristina Roberts
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
#ifndef _IAATSessionProperties_
#define _IAATSessionProperties_
//________________________________________________________________________________________________
//	INCLUDES
//________________________________________________________________________________________________

#include "AATArchID.h"
#include "IPMUnknown.h"
#include "ProductTypeDefs.h"

class LogObject;
class QAFile;
class AATIdleTask;
//================================================================================================

//________________________________________________________________________________________________
//	CLASS DECLARATION
//________________________________________________________________________________________________
class IAATSessionProperties : public IPMUnknown
	{
	//____________________________________________________________________________________________
	//	Data Types
	//____________________________________________________________________________________________
	public:
		enum { kDefaultIID = IID_IAATSESSIONPROPERTIES };
		

	//____________________________________________________________________________________________
	//	Member functions
	//____________________________________________________________________________________________
	
		// Log methods
		// do not delete the pointer you get back!
		virtual LogObject* 	GetAATSessionLog() = 0;
		virtual void 		CloseAATSessionLog() = 0;	
		virtual void		CreateAATSessionLog(IDFile log, ProdBool overwriteLog=kTrue) = 0;

		
		// associated file methods
		virtual void 		SetSessionListFile(QAFile& file) = 0;
		virtual void 		ClearSessionListFile() = 0;
		virtual QAFile		GetSessionListFile() = 0;
			
		virtual void		SetIdleTask(AATIdleTask *idleTask) = 0;
		virtual AATIdleTask*	GetIdleTask(void) = 0;
		
	};

#endif // _IAATSessionProperties_