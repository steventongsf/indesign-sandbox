//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/graphics/Icolorcontroldatarangemapper.h $
//  
//  Owner: SusanCL
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
#ifndef __IColorControlDataRangeMapper__
#define __IColorControlDataRangeMapper__

#include "ColorPickerID.h"
#include "IPMUnknown.h"
#include "IColorData.h"

/**	A data conversion interface which maps the data range from the persistent data
	format to the UI format.
*/
class IColorControlDataRangeMapper : public IPMUnknown
{
public:
		
	enum {kDefaultIID = IID_ICOLORCONTROLDATARANGEMAPPER};

		/**	Maps the specifies data value to value consistent with UI ranges.
			@param value is the data value.
			@return the converted value in the UI ranges.
		*/
		virtual PMReal	MapDataToUIRange( PMReal value ) = 0;

		/**	Maps the specifies UI value to data value.
			@param value is the UI value.
			@return the converted value in the data ranges.
		*/
		virtual PMReal	MapUIRangeToDataRange( PMReal value ) = 0;
};

#endif	// __IColorPickerDataRangeMapper__