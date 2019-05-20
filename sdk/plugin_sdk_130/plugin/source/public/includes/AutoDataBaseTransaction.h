//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/AutoDataBaseTransaction.h $
//  
//  Owner: Paul Messmer
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
#ifndef __AutoDataBaseTransaction__
#define __AutoDataBaseTransaction__

#include "IDataBase.h"

/**
	A stack-based approach to enabling a database transaction.
*/
class AutoDataBaseTransaction
{
public:
	/**
		Begin transaction on a database
		@param db is the database
	*/
	AutoDataBaseTransaction(IDataBase* db) : fDB(db)
		{ if (fDB) fDB->BeginTransaction(); }
	/**
		End transaction on the database
	*/
	~AutoDataBaseTransaction()
		{ if (fDB) fDB->EndTransaction(); }
	/**
		Get the database
	*/
	IDataBase* GetDataBase()
		{ return fDB; }

private:
	IDataBase* fDB;
};

#endif //__AutoDataBaseTransaction__
