//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/private/toolkit/diagnosticlog/DiagnosticLog.cpp $
//  
//  Owner:
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

#include "VCPlugInHeaders.h" 

#include "IDiagnosticLog.h"

#include "IDiagLogConfigManager.h"
#include "IDiagLoggerManager.h"

#include "DiagnosticLogID.h"


class DiagnosticLog: public CPMUnknown<IDiagnosticLog>
{
public:		
	DiagnosticLog(IPMUnknown *boss);
	~DiagnosticLog();

	virtual IDiagLogConfigManager * QueryDiagLogConfigManager();
	virtual IDiagLoggerManager * QueryDiagLoggerManager();

private:
	IDiagLogConfigManager * fConfigManager;
	IDiagLoggerManager * fLoggerManager;
};

CREATE_PMINTERFACE(DiagnosticLog, kDiagnosticLogImpl)

DiagnosticLog::DiagnosticLog(IPMUnknown *boss) : 
	CPMUnknown<IDiagnosticLog>(boss),
	fConfigManager(nil),
	fLoggerManager(nil)
{
}

DiagnosticLog::~DiagnosticLog()
{
	if (fConfigManager)
		fConfigManager->Release();

	if (fLoggerManager)
		fLoggerManager->Release();
}


IDiagLogConfigManager * DiagnosticLog::QueryDiagLogConfigManager()
{		
	if (fConfigManager == nil)
	{
		fConfigManager = (IDiagLogConfigManager*)::CreateObject(kDiagLogConfigManagerBoss, IID_IDIAGLOGCONFIGMANAGER);
		ASSERT(fConfigManager != nil);
	}
	
	fConfigManager->AddRef();

	return fConfigManager;
}


IDiagLoggerManager * DiagnosticLog::QueryDiagLoggerManager()
{		
	if (fLoggerManager == nil)
	{
		fLoggerManager = (IDiagLoggerManager*)::CreateObject(kDiagLoggerManagerBoss, IID_IDIAGLOGGERMANAGER);
		ASSERT(fLoggerManager != nil);
	}
	
	fLoggerManager->AddRef();

	return fLoggerManager;
}
