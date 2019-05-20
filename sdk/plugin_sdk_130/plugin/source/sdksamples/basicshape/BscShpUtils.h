//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/basicshape/BscShpUtils.h $
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

#ifndef __BscShpUtils__
#define __BscShpUtils__

class UIDRef;
class PMRect;

/** From SDK sample; Utility methods for the BasicShape plug-in.

	@ingroup basicshape
*/
class BscShpUtils
{
public:
	/** Create a kBscShpPageItemBoss.
		@param parent - the boss that owns the created kBscShpPageItemBoss.
		@param bbox - the desired bounds in pasteboard co-ordinates
		@return reference to the created kBscShpPageItemBoss.
	*/
	UIDRef CreateBasicShape(const UIDRef& parent, PBPMRect bbox);
};

#endif // __BscShpUtils__

// End, BscShpUtils.h


