//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/graphics/IGraphicAttrClassID.h $
//  
//  Owner: Michael_Martz
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

	#ifndef _IGraphicAttribute_ClassID_
	#define _IGraphicAttribute_ClassID_
//===================================================================================
//___________________________________________________________________________________
//	INCLUDES
//___________________________________________________________________________________
	#include "GraphicStylesID.h"
	#include "IPMUnknown.h"
//===================================================================================
//___________________________________________________________________________________
//	CLASS DECLARATION
//___________________________________________________________________________________
	
	/**	A graphic attribute data interface for the ClassID data.
	*/
	class IGraphicAttrClassID : public IPMUnknown
		{
		public:
			enum { kDefaultIID = IID_IGRAPHICATTR_CLASSID };

		//___________________________________________________________________________
		//	Accessor memeber functions
		//___________________________________________________________________________
		public:

			/**	Set the ClassID data.
				@param classID specifies the class ID to set.
			*/
			virtual void		SetClassID				(const ClassID& classID) = 0;

			/**	Returns the class ID value.
			*/
			virtual ClassID		GetClassID				(void) const = 0;
		};
		
#endif // _IGraphicAttribute_ClassID_
