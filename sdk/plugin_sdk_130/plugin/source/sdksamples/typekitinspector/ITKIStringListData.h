//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/typekitinspector/ITKIStringListData.h $
//  
//  Owner: Timothy Brand-Spencer
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  Copyright 1997-2015 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#ifndef __ITKISTRINGLISTDATA__
#define __ITKISTRINGLISTDATA__

#include "TKIID.h"
#include "IPMUnknown.h"
#include "K2Vector.tpp"
#include "NodeID.h"

/**  
  * Data interface for storing list data of TKITreeNodeID type.
  */
class ITKIStringListData : public IPMUnknown
{
	public:
		enum { kDefaultIID = IID_ITKISTRINGLISTDATA };

		/** Set the value of the list of strings.
			@param newList - the list of strings that will be the new value
		*/
		virtual void SetStringList(const K2Vector<NodeID>& newList) = 0;

		/** Return the value of the list.
			@return the list of strings 
		*/
		virtual const K2Vector<NodeID>& GetStringList() = 0;
};

#endif // __ITKISTRINGLISTDATA__