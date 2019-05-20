//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/layout/ISetMasterDocCmdData.h $
//  
//  Owner: Yeming Liu
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
#ifndef __ISETMASTERDOCCMDDATA__
#define __ISETMASTERDOCCMDDATA__

class ISetMasterDocCmdData : public IPMUnknown
{
	public:

		virtual IDFile GetBookFile() = 0;

		virtual void SetBookFile(const IDFile& BookFile) = 0;

		virtual UID GetMasterDoc() = 0;

		virtual void SetMasterDoc(UID masterDoc) = 0;
};

#endif //__ISETMASTERDOCCMDDATA__