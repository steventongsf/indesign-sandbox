//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/singlelinecomposer/SLCDiagnostics.h $
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

#ifndef __SLCDiagnostics_h__
#define __SLCDiagnostics_h__

class IWaxLine;
class IWaxRun;

/** Routines to dump diagnostic trace of the wax.
 * 	@ingroup singlelinecomposer
 * 	
*/
class SLCDiagnostics
{
public:
	/**
	*/
	void DumpWaxLine(const char* category, const IWaxLine* line) const;

	/**
	*/
	void DumpWaxLineAndRuns(const char* category, const IWaxLine* line, int32 index = -1) const;

	/**
	*/
	void DumpWaxRun(const char* category, const IWaxRun* run, int32 index = -1) const;
};

#endif // __SLCDiagnostics_h__

// End, SLCDiagnostics.h

