//========================================================================================
//  
//  ADOBE CONFIDENTIAL
//   
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/layout/IArticleMemberList.h $
// 
//  Owner: Paresh Goel
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  Copyright 2010 Adobe Systems Incorporated
//  All Rights Reserved.
//  
//  NOTICE:  All information contained herein is, and remains
//  the property of Adobe Systems Incorporated and its suppliers,
//  if any.  The intellectual and technical concepts contained
//  herein are proprietary to Adobe Systems Incorporated and its
//  suppliers and are protected by trade secret or copyright law.
//  Dissemination of this information or reproduction of this material
//  is strictly forbidden unless prior written permission is obtained
//  from Adobe Systems Incorporated.
//  
//========================================================================================

#pragma once
#ifndef __IARTICLEMEMBERLIST__
#define __IARTICLEMEMBERLIST__

#include "IPMUnknown.h"
#include "ArticleID.h"

/** Provides access to the members of an Article.
*/
class IArticleMemberList : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_IARTICLEMEMBERLIST };

	/** Get the number of members in the Article.
		@return the number of members in the Article.
	*/
	virtual int32 CountMembers() const = 0 ;

	/** Add a member at the specified position in the Article.
		@param memberUID IN the UID of the member that needs to be added.
		@param pos IN 0 based position at which to add the member. Specify -1 to add to the end.
	*/
	virtual void AddMember(UID memberUID, int32 pos = -1) = 0 ;

	/** Remove a member from the Article
		@param memberUID IN the UID of the member that needs to be removed.
	*/
	virtual void RemoveMember(UID memberUID) = 0 ;
	
	/** Remove a member from the Article.
		@param pos IN the position of the member in the Article.
	*/
	virtual void RemoveNthMember(int32 pos) = 0 ;
	
	/** Remove all members from the Article.
	*/
	virtual void RemoveAllMembers() = 0 ;

	/** Get the Nth member UID from the Article.
		@param pos IN the 0 based index of the member in the Article.
		@return the UID of the member.
	*/
	virtual UID GetNthMemberUID(int32 pos) const = 0 ;
	
	/** Get the position of the member in the Article.
		@param memberUID IN the UID of the member in the Article.
		@return the position of the member.
	*/
	virtual int32 GetMemberPosition(UID memberUID) const = 0 ;
};

#endif // __IARTICLEMEMBERLIST__
