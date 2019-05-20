//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/graphics/ISWFExportPreferences.h $
//  
//  Owner: Greg St. Pierre
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

#include "DynamicDocumentsID.h"
#include "DynamicDocumentsTypes.h"
#include "IPMStream.h"

/**
 Export preferences for SWF exports.
 
 ISWFExportPreferences is used to configure the parameters for an export to the
 SWF format supported by the Flash Player.
 
 In order to export InDesign content to SWF, you will typically create an instance
 of the SWF export command (kSWFExportCommandBoss), set its item list to refer to 
 the pages to be exported, and set up the stream and UI flags to be used. You can
 then use the ISWFExportPreferences aggregated on the command boss to set up
 various parameters for the export, including how to treat raster images, text,
 etc.
 
 ISWFExportPreferences is also aggregated on the app workspace, where it is used
 to ensure that default export settings are preserved from export to export. You
 might consider using this instance as the base for your export settings. You 
 might also consider using kSetSWFSessionPrefsCmdBoss to update the default export
 settings for subsequent exports.
 */
class ISWFExportPreferences : public IPMUnknown
{
public:
	enum { kDefaultIID = IID_ISWFEXPORTPREFERENCES };
	
	/**
	 Copies one set of prefs into another

	 @param other			IN The preferences to copy
	 */
	virtual void Copy(ISWFExportPreferences const *other) = 0;

	/**
	 Sets the preferred raster compression to be used for the export. Note that some 
	 compression types will be required in certain scenarios and that those will take 
	 precedence over the setting specified here. This will be used when no particular 
	 compression type is required.
	 
	 @param format		One of the RasterCompression enum specifying the preferred raster compression
	 */
	virtual void SetRasterCompression(flash_export::RasterCompression compression) = 0;
	
	/**
	 Gets the preferred raster compression to be used for the export.
	 
	 @return One of the RasterCompression enum specifying the preferred raster compression
	 */
	virtual flash_export::RasterCompression GetRasterCompression() const = 0;
	
	/**
	 Sets the quality to be used for JPEG compressed images during the export.
	 
	 @param quality		One of the JPEGQuality enum
	 */
	virtual void SetJPEGQuality(flash_export::JPEGQuality quality) = 0;
	
	/**
	 Gets the quality to be used for JPEG compressed images during the export.
	 
	 @return One of the JPEGQuality enum
	 */
	virtual flash_export::JPEGQuality GetJPEGQuality() const = 0;
	
	/**
	 Sets the preferred raster resolution for the export. This controls two related
	 items: the resolution at which content will be rasterized and the resolution to
	 which raster images will be resampled when resampling is enabled.
	 
	 @param ppi			The preferred resolution, in ppi, for raster images
	 */
	virtual void SetRasterResolution(uint32 ppi) = 0;
	
	/**
	 Gets the preferred raster resolution for the export.
	 
	 @return The preferred resolution, in ppi, for raster images.
	 */
	virtual uint32 GetRasterResolution() const = 0;
	
	/**
	 Sets the algorithm to be used for resampling raster images that exceed the 
	 specified resolution threshold. Setting to kNoResampling disables resampling.
	 
	 @type		One of the ResamplingType enum specifying the resampling algorithm to use.
	 */
	virtual void SetResamplingType(flash_export::ResamplingType type) = 0;
	
	/**
	 Gets the algorithm to be used for resampling raster images.
	 
	 @return One of the ResamplingType enum specifying the resampling algorithm to use.
	 */
	virtual flash_export::ResamplingType GetResamplingType() const = 0;

	/**
	 Sets the raster resolution threshold. Raster images whose rendered resolutions 
	 exceed this value will be resampled using the resampling algorithm specified by
	 SetResamplingType.
	 
	 @param ppi		The resolution threshold, in ppi
	 */
	virtual void SetResampleThresholdResolution(uint32 ppi) = 0;
	
	/**
	 Gets the raster resolution threshold.
	 
	 @return The raster resolution threshold, in ppi
	 */
	virtual uint32 GetResampleThresholdResolution() const = 0;
	
	/**
	 Sets whether to export as reader's spreads.
	 
	 @param spreads		Boolean. If kTrue, export as reader's spread; if kFalse, export as pages
	 */
	virtual void SetReadersSpreads(bool16 spreads) = 0;
	
	/**
	 Gets whether to export as reader's spreads.
	 
	 @return kTrue if exporting as reader's spreads; otherwise kFalse
	 */
	virtual bool16 GetReadersSpreads() const = 0;

	/**
	 Sets whether to rasterize each page/spread
	 
	 @param rasterize	Boolean. If kTrue, pages/spreads are rasterized
	 */
	virtual void SetRasterizePages(bool16 rasterize) = 0;
	
	/**
	 Gets whether to rasterize each page/spread
	 
	 @return kTrue if pages/spreads are to be rasterized
	 */
	virtual bool16 GetRasterizePages() const = 0;

	/**
	 Sets the text export policy for all text frame dictating how text is to be represented in the exported file.
	 
	 @param policy	One of the TextExportPolicy enum
	 */
	virtual void SetTextExportPolicy(flash_export::TextExportPolicy policy) = 0;
	
	/**
	 Gets the text export policy for all text frame dictating how text is to be represented in the exported file.
	 
	 @return One of the TextExportPolicy
	 */
	virtual flash_export::TextExportPolicy GetTextExportPolicy() const = 0;
		
	/**
	 Book control (page curl) settings are used to determine how the page curl behavior
	 works in SWF files exported from InDesign.
	 
	 fUseBookControl may be used to enable or disable the page curl behavior.
	 
	 fShowPageSlopeAtRest may be used to control whether the 'page spine' gradient will 
	 be shown even when no page curl transition is in effect. By default, the gradient 
	 is only shown while a page curl transition is in progress or while a user is 
	 performing a manual page turn by clicking a corner and dragging.
	 
	 fShowCornerTease may be used to control whether a 'tease' animation is used when
	 a user mouses over the corners of the page. The tease is meant to highlight that
	 a given corner is interactive.
	 */
	class BookControlSettings
	{
	public:
		typedef object_type data_type;

		/**
		 Boolean. If kTrue, page curl is enabled.
		 */
		bool16 fUseBookControl;
		
		/**
		 Boolean. If kTrue, 'page spine' gradient is shown even when no page curl is in progress.
		 */
		bool16 fShowPageSlopeAtRest;
		
		/**
		 Boolean. If kTrue, a teaser animation is shown if user mouses over a corner.
		 */
		bool16 fShowCornerTease;
		
		/**
		 Real value indicating percentage of width/height for grabber area size. Pinned to [0..100]
		 */
		PMReal fEdgeAndCornerSizePercent;		// [0..100]
		
		/**
		 Default constructor. Sets BookControlSettings instance to default values.
		 */
		BookControlSettings() :
			fUseBookControl(kTrue),
			fShowPageSlopeAtRest(kFalse),
			fShowCornerTease(kTrue),
			fEdgeAndCornerSizePercent(10)
		{
		}

		/**
		 Constructor. Can be used to initialize values in a BookControlSettings instance.
		 
		 @param useBookControl				Boolean. If kTrue, page curl is enabled.
		 @param showPageSlopeAtRest			Boolean. If kTrue, 'page spine' gradient is shown even when no page curl is in progress.
		 @param showCornerTease				Boolean. If kTrue, a teaser animation is shown if user mouses over a corner.
		 @param edgeAndCornerSizePercent	Real value indicating percentage of width/height for grabber area size. Pinned to [0..100]
		 */
		BookControlSettings(
			bool16 const &useBookControl,
			bool16 const &showPageSlopeAtRest,
			bool16 const &showCornerTease,
			PMReal const &edgeAndCornerSizePercent
		) :
			fUseBookControl(useBookControl),
			fShowPageSlopeAtRest(showPageSlopeAtRest),
			fShowCornerTease(showCornerTease),
			fEdgeAndCornerSizePercent(edgeAndCornerSizePercent)
		{
		}

		/** Equal operator for comparison.
	    @param other IN the object to compare with.
		@return bool16 kTrue means equal, otherwise kFalse.
		*/
		bool16 operator==(BookControlSettings const &other) const
		{
			return ( (fUseBookControl == other.fUseBookControl) &&
					 (fShowPageSlopeAtRest == other.fShowPageSlopeAtRest) && 
					 (fShowCornerTease == other.fShowCornerTease) && 
					 (fEdgeAndCornerSizePercent == other.fEdgeAndCornerSizePercent));
		}

		/** Not equal operator for comparison.
	    @param other IN the object to compare with.
		@return bool16 kTrue means NOT equal, otherwise kFalse.
		*/
		bool16 operator!=(BookControlSettings const &other) const
		{
			return ( (fUseBookControl != other.fUseBookControl) ||
					 (fShowPageSlopeAtRest != other.fShowPageSlopeAtRest) || 
					 (fShowCornerTease != other.fShowCornerTease) || 
					 (fEdgeAndCornerSizePercent != other.fEdgeAndCornerSizePercent));
		}

		/** Persist SizeAndFitSettings
	    @param s IN stream where we read/write object of SizeAndFitSettings.
		*/
		void ReadWrite(IPMStream *s)
		{
			s->XferBool(fUseBookControl);
			s->XferBool(fShowPageSlopeAtRest);
			s->XferBool(fShowCornerTease);
			s->XferRealNumber(fEdgeAndCornerSizePercent);
		}
	};
	
	/**
	 Sets the settings for the book control (page curl) in the exported file.
	 
	 @param settings		The BookControlSettings to use for the export
	 */
	virtual void SetBookControlSettings(BookControlSettings settings) = 0;
	
	/**
	 Gets the settings for the book control (page curl) in the exported file.
	 
	 @param settings		A BookControlSettings structure to be filled with current settings
	 */
	virtual void GetBookControlSettings(BookControlSettings &settings) const = 0;

	/**
	 Sets the curve quality for the export.
	 
	 @param quality		The quality for converting cubic curves to quadratic curves
	 */
	virtual void SetCurveQuality(uint32 precision) = 0;
	
	/**
	 Sets the curve quality for the export.
	 
	 @return The quality for converting cubic curves to quadratic curves
	 */
	virtual uint32 GetCurveQuality() const = 0;
	
	/**
	 Sets the UID for the flattener style to be used when exporting pages or spreads
	 with transparency and SetTransparencyHandling is set to kFlattenTransparency.
	 
	 @param style	The UID of the flattener style to be used
	 */
	virtual void SetFlattenerStyle(UID const &style) = 0;
	
	/**
	 Gets the UID for the flattener style to be used when exporting pages or spreads
	 with transparency and SetTransparencyHandling is set to kFlattenTransparency.
	 
	 @return The UID of the flattener style to be used
	 */
	virtual UID GetFlattenerStyle() const = 0;
	
	/**
	 Sets the preferred method for handling dynamic media page items.
	 
	 @param the method to be used for dynamic media page items
	 */
	virtual void SetDynamicMediaHandling(flash_export::DynamicMediaHandling dmh) = 0;
	
	/**
	 Gets the preferred method for handling dynamic media page items.
	 
	 @return The method to be used dynamic media page items
	 */
	virtual flash_export::DynamicMediaHandling GetDynamicMediaHandling() const = 0;

	/**
	 Sets whether to generate an HTML file that wraps the generated SWF.
	 
	 @param generateHTML		Boolean. If kTrue, an HTML wrapper file will be generated
	 */
	virtual void SetGenerateHTML(bool16 generateHTML) = 0;
	
	/**
	 Gets whether to generate an HTML file that wraps the generated SWF.
	 
	 @return kTrue if an HTML wrapper file should be generated
	 */
	virtual bool16 GetGenerateHTML() const = 0;

	/**
	 Sets whether to view the generated SWF file after exporting.
	 
	 @param viewAfterExport		Boolean. If kTrue, view the generated SWF file after exporting.
	 */
	virtual void SetViewAfterExport(bool16 viewAfterExport) = 0;
	
	/**
	 Gets whether to view the generated SWF file after exporting.
	 
	 @return kTrue if viewing the generated SWF file after exporting.
	 */
	virtual bool16 GetViewAfterExport() const = 0;

	/**
	 Sets the page transition to use for all pages, overriding any page tranition 
	 set on a spread. If the parameter passed is kInvalidClass then no page 
	 transition will be used. If the parameter passed is kPageTransitionFromDocument
	 then the spread's page transition will be honored.
	 
	 @param pageTransition ClassID: the ClassID of the page tranition to use.
	 @see IPageTransitionFacade
	 @see IPageTransition
	 */
	virtual void SetPageTransitionOverride(const ClassID& pageTransitionOverride) = 0;
	
	/**
	 Gets the page transition ClassID that will be used for all pages exported,
	 overriding any page transition on a spread. If the ClassID is kInvalidClass
	 then no page transition will be used. If the ClassID is kPageTransitionFromDocument,
	 the spread's page transition will be used.
	 
	 @return ClassID of the page transition.
	 @see IPageTransitionFacade
	 @see IPageTransition
	 */
	virtual ClassID GetPageTransitionOverride() const = 0;
	
	/**
	 Sets the scale and fit settings to be applied for the export.
	 	 
	 @param settings		A SizeAndFitSettings structure to be filled with current settings
	 */
	virtual void SetSizeAndFitSettings(flash_export::SizeAndFitSettings const &settings) = 0;
	
	/**
	 Gets the scale and fit settings for the exported file.
	 	 
	 @param settings		A SizeAndFitSettings structure to be filled with current settings
	 */
	virtual void GetSizeAndFitSettings(flash_export::SizeAndFitSettings &settings) const = 0;

	/**
	 Set whether to allow using network access in generated SWF.

	 @param useNetwork		Boolean. If kTrue, allows to use network access.
	 */
	virtual void SetUseNetwork(bool16 useNetwork) = 0;

	/**
	 Gets whether to allow using network access in generated SWF.
	 
	 @return kTrue if allow using network access in generated SWF.
	 */
	virtual bool16 GetUseNetwork() const = 0;
	
	/**
	 Get whether to include a preloader in the generated SWF.
	 
	 @return kTrue if include a preloader
	 */
	virtual bool16 GetIncludePreloader() const = 0;
	
	/**
	 Set whether to include a preloader in the generated SWF.
	 
	 @param includePreloader	Boolean. If kTrue, includes a preloader.
	 */
	virtual void SetIncludePreloader(bool16 includePreloader) = 0;
	
	/**
	 Get the frame rate for the generated SWF.
	 
	 @return the frame rate for the generated SWF
	 */
	virtual uint32 GetFrameRate() const = 0;
	
	/**
	 Set the frame rate for the generated SWF.
	 
	 @param rate		The frame rate for the generated SWF
	 */
	virtual void SetFrameRate(uint32 rate) = 0;
	
	/**
	 Get whether the generated SWF has a transparent background.
	 
	 @return kTrue if the generated SWF will have a transparent background
	 */
	virtual bool16 GetHasTransparentBackground() const = 0;
	
	/**
	 Set whether the generated SWF has a transparent background.
	 
	 @param useXPBackground		Boolean. If kTrue, SWF will use a transparent background
	 */
	virtual void SetHasTransparentBackground(bool16 useXPBackground) = 0;

	/**
	 Sets the preferred method for handling transparency on a page or spread, if it exists.
	 
	 @param th		The method to be used for pages or spreads with transparency
	 */
	virtual void SetTransparencyHandling(flash_export::TransparencyHandling th) = 0;
	
	/**
	 Gets the preferred method for handling transparency on a page or spread, if it exists.
	 
	 @return The method to be used for pages or spread with transparency
	 */
	virtual flash_export::TransparencyHandling GetTransparencyHandling() const = 0;
};
