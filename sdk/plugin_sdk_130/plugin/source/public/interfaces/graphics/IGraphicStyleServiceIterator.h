//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/graphics/IGraphicStyleServiceIterator.h $
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
//  
//  NOTE:	This interface is obsolete.
//  There's no associated IID, the implementation is not part of the project.
//  There's no usage anywhere in the code.
//  
//========================================================================================

#pragma once
	#ifndef _IGraphicStyle_ServiceIterator_
	#define _IGraphicStyle_ServiceIterator_
//===================================================================================
//___________________________________________________________________________________
//	INCLUDES
//___________________________________________________________________________________
	#include "IPMUnknown.h"
	#include "IGraphicStyleAttrBossList.h"
//===================================================================================
//___________________________________________________________________________________
//	CLASS DECLARATIONS
//___________________________________________________________________________________

	/**	This interface is obsolete .
	*/
	class IGraphicStyleServiceIterator : public IPMUnknown
		{
		public:
			virtual void			Initialize					(IGraphicStyleAttributeBossList*) = 0;
		//___________________________________________________________________________
		//	Attribute and Service Management
		//___________________________________________________________________________
		public:
			virtual uint32			GetServiceCount				(void) const = 0;
			virtual void			Reset						(void) = 0;

			virtual ErrorCode		GetNextService				(ServiceID*, ClassID*) = 0;
		};

#endif // _IGraphicStyle_ServiceIterator_
