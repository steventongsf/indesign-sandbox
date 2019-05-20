//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFExportAdvancedPanelEvents.cpp $
//  
//  Owner: DBerggren
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
//  
//  ADOBE CONFIDENTIAL
//  
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

#include "IDialogController.h"
#include "IPanelControlData.h"
#include "ISWFExportPreferences.h"
#include "IWidgetParent.h"

#include "DynamicDocumentsUIID.h"
#include "CIdleMouseWatcher.h"

enum
{
	dtUninitialized,
	dtNothing,
	dtFrameRate,
	dtFlashText,
	dtConvertOutlines,
	dtConvertPixels,
	dtFlattenXP,
	dtRasterizePages,
	dtJPEG,
	dtPNG,
	dtAuto,
	dtQuality,
	dtResolution,
	dtRasterizeAlert,
	dtFlattenAlert
};
	
//========================================================================================
// CLASS SWFExportAdvancedPanelEvents
//========================================================================================

class SWFExportAdvancedPanelEvents : public CIdleMouseWatcher
{
	typedef CIdleMouseWatcher inherited;
	
public:
	SWFExportAdvancedPanelEvents(IPMUnknown *boss);
	
	virtual uint32 MouseMoved(GSysPoint);
	
	virtual void StopWatching();
	
protected:
	SysPoint	fLocalPoint;
	int32		fDescriptionID;
};

CREATE_PMINTERFACE(SWFExportAdvancedPanelEvents, kSWFExportAdvancedPanelEventsImpl)

//========================================================================================
// SWFExportAdvancedPanelEvents::SWFExportAdvancedPanelEvents
//========================================================================================
SWFExportAdvancedPanelEvents::SWFExportAdvancedPanelEvents(IPMUnknown *boss)
	:inherited(boss)
{
	SysPointH(fLocalPoint)	= 0;
	SysPointV(fLocalPoint)	= 0;

	fDescriptionID	= dtUninitialized;
}

//========================================================================================
// SWFExportAdvancedPanelEvents::MouseMoved
//========================================================================================

uint32 SWFExportAdvancedPanelEvents::MouseMoved(GSysPoint newMouse)
{
	InterfacePtr<IControlView> myControlView(this, IID_ICONTROLVIEW);
	
	SysPoint localPoint = ::ToSys(myControlView->GlobalToWindow(newMouse));
	if ( localPoint != fLocalPoint )
	{
		InterfacePtr<IPanelControlData> myPanelControlData(this, IID_IPANELCONTROLDATA);
		
		WidgetID widgetID = 0;
		
		IControlView *view = myPanelControlData->FindWidget(localPoint);
		if ( (view != nil) && view->IsEnabled() )
		{
			widgetID = view->GetWidgetID();
		}
		
		int32 descriptionID = dtNothing;

		switch ( widgetID.Get() )
		{
			case kFrameRateStrWidgetID:
			case kFrameSecStrWidgetID:
			case kFramesPerSecEditWidgetID:
			{
				descriptionID = dtFrameRate;
				break;
			}
			case kTextStrWidgetID:
			case kTextPopupWID:
			{
				InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
				InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
				if (!iData) break;

				flash_export::TextExportPolicy textPolicy(iData->GetTextExportPolicy());
				if (textPolicy == flash_export::kLiveText)
					descriptionID = dtFlashText;
				else if (textPolicy == flash_export::kVectorizeText)
					descriptionID = dtConvertOutlines;
				else if (textPolicy == flash_export::kRasterizeText)
					descriptionID = dtConvertPixels;
				break;
			}
			case kFlattenXPCheckboxWID:
			{
				descriptionID = dtFlattenXP;
				break;
			}
			case kRastorizeCheckboxWID:
			{
				descriptionID = dtRasterizePages;
				break;
			}
			case kCompressionStrWidgetID:
			case kCompressionPopupWID:
			{
				InterfacePtr<IWidgetParent> iWidgetParent(this, UseDefaultIID());
				InterfacePtr<ISWFExportPreferences> iData((ISWFExportPreferences*)iWidgetParent->QueryParentFor(IID_ISWFEXPORTPREFERENCES));
				if (!iData) break;

				flash_export::RasterCompression compression(iData->GetRasterCompression());
				if (compression == flash_export::kJPEGCompression)
					descriptionID = dtJPEG;
				else if (compression == flash_export::kLosslessCompression)
					descriptionID = dtPNG;
				else if (compression == flash_export::kAutomaticCompression)
					descriptionID = dtAuto;
				break;
			}
			case kJPEGQualityStrWidgetID:
			case kJPEGQualityPopupWID:
			{
				descriptionID = dtQuality;
				break;
			}
			case kResolutionStrWidgetID:
			case kComboDropDownWidgetID:
			case kResolutionComboWID:
			{
				descriptionID = dtResolution;
				break;
			}
			case kFlattenWarningIconWidgetId:
			{
				descriptionID = dtFlattenAlert;
				break;
			}
			case kRastorizeWarningIconWidgetId:
			{
				descriptionID = dtRasterizeAlert;
				break;
			}
			default:
			{
				break;
			}
		}
		
		if ( descriptionID != fDescriptionID )
		{
			PMString descriptionText = "dtNothing";
			
			InterfacePtr<IDialogController> myDialogController(this, IID_IDIALOGCONTROLLER);
			
			switch ( descriptionID )
			{
				case dtNothing:
				{
					break;
				}
				case dtFrameRate:
				{
					descriptionText = "dtFrameRateMsg";
					break;
				}
				case dtFlashText:
				{
					descriptionText = "dtFlashTextMsg";
					break;
				}
				case dtConvertOutlines:
				{
					descriptionText = "dtConvertOutlinesMsg";
					break;
				}
				case dtConvertPixels:
				{
					descriptionText = "dtConvertPixelsMsg";
					break;
				}
				case dtFlattenXP:
				{
					descriptionText = "dtFlattenXPMsg";
					break;
				}
				case dtRasterizePages:
				{
					descriptionText = "dtRasterizePagesMsg";
					break;
				}
				case dtJPEG:
				{
					descriptionText = "dtJPEGMsg";
					break;
				}
				case dtPNG:
				{
					descriptionText = "dtPNGMsg";
					break;
				}
				case dtAuto:
				{
					descriptionText = "dtAutoMsg";
					break;
				}
				case dtQuality:
				{
					descriptionText = "dtQualityMsg";
					break;
				}
				case dtResolution:
				{
					descriptionText = "dtResolutionMsg";
					break;
				}
				case dtRasterizeAlert:
				{
					descriptionText = "dtRasterizeAlertMsg";
					break;
				}
				case dtFlattenAlert:
				{
					descriptionText = "dtFlattenAlertMsg";
					break;
				}
				default:
				{
					break;
				}
			}
			
			myDialogController->SetTextControlData(kSWFExportDescriptionTextWidgetID, descriptionText);
			
			fDescriptionID = descriptionID;
		}
		
		fLocalPoint = localPoint;
	}
	return 1000/7; //call me 7 times/second
}

//========================================================================================
// SWFExportAdvancedPanelEvents::StopWatching
//========================================================================================
void SWFExportAdvancedPanelEvents::StopWatching()
{
	inherited::StopWatching();
	
	fDescriptionID = dtUninitialized;
}

// End, SWFExportAdvancedPanelEvents.cpp.
