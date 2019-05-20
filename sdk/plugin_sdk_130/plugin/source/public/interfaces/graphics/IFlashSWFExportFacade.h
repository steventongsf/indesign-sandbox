//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/graphics/IFlashSWFExportFacade.h $
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
#ifndef __IFlashSWF_ExportFacade__
#define __IFlashSWF_ExportFacade__

// ----- Interface files -----

#include "IPageRange.h"
#include "IPMUnknown.h"
#include "ISWFExportPreferences.h"
#include "IXFLExportPreferences.h"

// ----- Include files -----

#include "DynamicDocumentsTypes.h"

// ----- ID files -----

#include "DynamicDocumentsID.h"

// ===================================================================================
//	class IFlashSWF_ExportFacade 
// ===================================================================================
namespace Facade
{
	/** This facade provides services for obtaining and modifying the preference settings for  
		SWF export that is new to InDesign CS4. The preference is on the application workspace 
		boss and the main interfaces in the preference are:
			@see ISWFExportPreferences
			@see IPageRange
	*/

	class IFlashSWF_ExportFacade : public IPMUnknown 
	{
		public:
			// ----- Constants -----
			enum {kDefaultIID = IID_IFLASHSWFEXPORTFACADE};

			/**
			 Gets the size selection setting for the export file.
			 	 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return SizeSelection: the size selection.
			 */
			virtual flash_export::SizeSelection GetSizeSelection(IWorkspace* ws) const = 0;

			/**
			 Gets the fit to selection setting for the exported file.
			 	 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return FitToSelection: the fit to selection.
			 */
			virtual flash_export::FitToSelection GetFitToSelection(IWorkspace* ws) const = 0;

			/**
			 Gets the width and height for the file to be exported.
			 	 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @param settings [OUT]: the width and height for the export file.
			 */
			virtual void GetWidthHeight(IWorkspace* ws, uint32& width, uint32& height) const = 0;

			/**
			 Gets the scale amount for the file to be exported.
			 	 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return PMReal: the scale amount for the xport file.
			 */
			virtual PMReal GetScale(IWorkspace* ws) const = 0;

			/**
			 Gets the page range information from the session preferences.
			 	 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @param pageRange [OUT]: contains string of page range.
			 @param pageRangeFormat [OUT]: contains enum value of page range format.
			 */
			virtual void GetPageRangeInfo(IWorkspace* ws, PMString &pageRange, IPageRange::RangeFormat &pageRangeFormat) const = 0;

			/**
			 Gets the transparency handling policy.
			 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return One of the TransparencyHandling (kIgnoreTransparency, kFlattenTransparency, kNativeTransparency).
			 */
			virtual flash_export::TransparencyHandling GetTransparencyHandling(IWorkspace* ws) const = 0;

			/**
			 Gets whether to rasterize each page/spread
			 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return kTrue if pages/spreads are to be rasterized.
			 */
			virtual bool RasterizePages(IWorkspace* ws) const = 0;

			/**
			 Gets whether to generate an HTML file that wraps the generated SWF.
			 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return kTrue if an HTML wrapper file should be generated.
			 */
			virtual bool GenerateHTML(IWorkspace* ws) const = 0;
	
			/**
			 Gets whether to view generated SWF after export.
			 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return kTrue if view after export.
			 */		
			virtual bool ViewAfterExport(IWorkspace* ws) const = 0;

			/**
			 Gets the frame rate for the SWF export.
			 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return number of frames per second.
			 */		
			virtual uint32 GetFrameRate(IWorkspace* ws) const = 0;

			/**
			 Gets the text export policy for all text frames dictating how text is to be represented in the exported file.
			 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return One of the TextExportPolicy (kLive, kRasterize, kVectorize).
			 */
			virtual flash_export::TextExportPolicy GetTextExportPolicy(IWorkspace* ws) const = 0;

			/**
			 Gets the dynamic media handling policy.
			 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return One of the DynamicMediaHandling (kIncludeAll, kAppearanceOnly).
			 */
			virtual flash_export::DynamicMediaHandling GetDynamicMediaHandling(IWorkspace* ws) const = 0;

			/**
			 Returns the ClassID of an IPageTransition, if one is selected as an override. If 
			 this returns kPageTransitionFromDocument the page transitions will honor the page
			 transition that is set on the spread. kInvalidClass means no page transition.
			 
			 @return ClassID the page transition, kInvalidClass if none selected, kPageTransitionFromDocument if not overridden.
			 @see IPageTransition 
			 @see IPageTransitionFacade
			 */		
			virtual ClassID GetPageTransitionOverride(IWorkspace* ws) const = 0;

			/**
			 Gets whether to include interactive page curl in generated SWF.
			 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return kTrue if interactive page curl is to be included in SWF output.
			 */
			virtual bool IncludeInteractivePageCurl(IWorkspace* ws) const = 0;

			/**
			 Gets whether the page in the SWF should have a transparent background,
			 or a paper color background (if false).
			 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return kTrue the background is transparent, false if background is paper color.
			 */
			virtual bool HasTransparentBackground(IWorkspace* ws) const = 0;

			/**
			 Gets the preferred raster compression to be used for the SWF export.

			 @param ws [IN]: The workspace where we get export preferences from.
			 @return One of the RasterCompression enum specifying the preferred raster compression.
			 */
			virtual flash_export::RasterCompression GetRasterCompression(IWorkspace* ws) const = 0;

			/**
			 Gets the quality to be used for JPEG compressed images during the SWF export.
			 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @return One of the JPEGQuality enum.
			 */
			virtual flash_export::JPEGQuality GetJPEGQuality(IWorkspace* ws) const = 0;

			/**
			 Gets the preferred raster resolution for the export.
			 
			 @return The preferred resolution, in ppi, for raster images.
			 */
			virtual uint32 GetRasterResolution(IWorkspace* ws) const = 0;	

			/**
			 Gets the SWF session workspace preferences.
			 	 
			 @param ws [IN]: The workspace where we get SWF export preferences from.
			 @param iPrefsData [OUT]: the ISWFExportPreferences interface contains SWF export preferences.
			 */
			virtual void GetWorkspacePreferences(IWorkspace* ws, ISWFExportPreferences* iPrefsData) const = 0;

			/**
			 Set the SWF export preferences for the session workspace.
			 	 
			 @param iPrefsData [IN]: The SWF general preference data where we use for setting export preferences.
			 @param iPageRangeData [IN]: The page preference data where we use for setting export preferences.
			 */
			virtual ErrorCode SetWorkspacePreferences(ISWFExportPreferences* iPrefsData, IPageRange* iPageRangeData) = 0;
	};
}
#endif // define

