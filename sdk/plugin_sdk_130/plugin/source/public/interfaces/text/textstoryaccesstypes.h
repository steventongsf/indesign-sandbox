//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/textstoryaccesstypes.h $
//  
//  Owner: HabibK
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
#ifndef __TEXTSTORYACCESSTYPES__
#define __TEXTSTORYACCESSTYPES__

/** 
	User accessibility identifies if a story was created by the user or whether
	it was created for internal use. Internal stories are not subject to search
	through find change, spell checking, and other activities that make sense
	only for user created stories.

	@ingroup text_datatype 
*/
enum TextStory_StoryAccess				
{
	kInvalid = 0,
	kUserAccessible,
	kNotUserAccessible
};



#endif // __TEXTSTORYACCESSTYPES__

