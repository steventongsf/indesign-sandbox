//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/SequenceCmd.h $
//  
//  Owner: jargast
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
#ifndef __SequenceCmd__
#define __SequenceCmd__

#include "Command.h"

class ICommandSequence;

#pragma export on

class PUBLIC_DECL SequenceCmd : public Command
{
	public:
		SequenceCmd(IPMUnknown *boss);
		virtual ~SequenceCmd();
		
		virtual void Do() = 0;
		
	protected:
		// Begins a sequence and gives it the name of the wrapping command.
		// Also sets the undoability of the sequence to the undoabiity of
		// wrapping command.  
		virtual	void BeginSequence();
		
		// Ends the sequence.  Will abort the sequence on error.
		virtual void EndSequence();
		
		// Return the command sequence itself.
		ICommandSequence* GetSequence()	{ return (fCmdSequence); }
		
	private:
		ICommandSequence*	fCmdSequence;		
};

#pragma export off

#endif		// __SequenceCmd__
