//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/includes/DynamicDocumentsUIDefs.h $
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
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#ifndef __DynamicDocumentsUIDefs__
#define __DynamicDocumentsUIDefs__

#include "StdHeightWidthConstants.h"

#define kPanelList_PageTransitionPanelRsrcID		128
#define kPanelList_SWFPreviewPanelRsrcID			129
#define kPanelList_AnimationUIPanelRsrcID			130
#define kPanelList_TimingPanelRsrcID				131

#define kMenuDef_PageTransitionPanelRsrcID			132
#define kMenuDef_SWFPreviewPanelRsrcID				133
#define kMenuDef_AnimationUIPanelRsrcID				134
#define kMenuDef_TimingPanelRsrcID					135
#define kMenuDef_LiquidLayoutPanelRsrcID			136

#define kPanelList_LiquidLayoutPanelRsrcID			160

#define kDynamicDocumentsUIStringsRsrcID			200
#define kDynamicDocumentsUIStringsNoTransRsrcID		300

// Icons
#define kConvertToMotionPath						500

// Cursor
// This is defined in CursorDefs.h, kCrsrButtonTrigger

#define kSWFExportDialogRsrcID						1000	// Resource ID of SWFExport Dialog
#define kSWFExportDialogOrderingRsrcID				1100
#define kSWFExportGeneralPanelCreatorRsrcID			1200
#define kSWFExportGeneralPanelRsrcID				1300
#define kSWFExportAdvancedPanelCreatorRsrcID		1400
#define kSWFExportAdvancedPanelRsrcID				1500

#define kXFLExportDialogRsrcID						2000	// Resource ID of XFLExport Dialog

#define kPageTransitionsPaletteRsrcID				3000	// Resource ID of PageTransitions Panel
#define kPageTransitionsPaletteIconRsrcID			4000	// Resource ID of PageTransitions Panel's icon
#define kPageTransitionsPanelActionsRsrcID          5000	// Resource ID of popup menu on PageTransitions Panel

#define kPageTransitionsIconRsrcID					7000	// Page transition icon

// Liquid Layout panel resource definition
#define kLiquidLayoutPaletteRsrcID					7100
#define kLiquidLayoutPaletteIconRsrcID				6101
#define kLiquidLayoutPanelActionsRsrcID				7102

//	SWF Preview panel resource definition
#define kSWFPreviewPaletteRsrcID					8000	// Resource ID of SWF Preview Panel
#define	kSWFPreviewPaletteIconObsoleteRsrcID		8001	// Resource ID of SWF Preview Panel's icon
#define kSWFPreviewPanelActionsRsrcID				8002	// Resource ID of popup menu on SWF Preview Panel
#define kSWFPreviewDocumentIconRsrcID				8003	// Preview icon
#define kSWFPreviewWarningIconRsrcID				8004
#define kSWFPreviewSelectionIconRsrcID				8005
#define kSWFPreviewSpreadIconRsrcID					8006
#define kSWFPreviewPlayIconRsrcID					8007
#define kSWFPreviewStopIconRsrcID					8008
// Keeping old kSWFPreviewPaletteIconRsrcID for now, as we can't delete resources in a patch update. This would
// otherwise result in the plugin signature getting invalidated on user machines.
#define	kSWFPreviewPaletteIconRsrcID				8009	// Resource ID of SWF Preview Panel's new icon
#define kSWFPreviousIconRsrcID						8010
#define kSWFNextIconRsrcID							8011
#define kMinSWFPreviewPanelWidth					kCC2016PanelStandardWidth			
#define kMinSWFPreviewPanelHeight					161

// Timing panel resource definition
#define kTimingPaletteRsrcID						9000
#define kTimingPaletteIconRsrcID					9001
#define kTimingPanelPlayTogetherIconRsrcID			9002
#define kTimingPanelPlaySeparatelyIconRsrcID		9003
#define kTimingPanelShowPreviewIconRsrcID			9004
#define kTimingPanelTreeNodeRsrcID					17000	// tree element in the timing panel
#define kTimingPanelActionsRsrcID					18000
const int kMinTimingPanelWidth = kCC2016PanelStandardWidth;
const int kMinTimingPanelWidth_DE = kCC2016PanelStandardWidth+10;
const int kMaxTimingPanelWidth = 10000;
const int kMinTimingPanelHeight = 185 + kCC2016PanelIconHeight;
const int kMaxTimingPanelHeight = 10000;
const int kGroupWidgetHorzizontalLineSlop = 4;
const int kGroupWidgetHorzizontalLineLength = 6;
const int kTimingPanelGroupWidgetWidth = 18;
const int kTimingPanelRowHeight = 22;

// HTML preview panel
#define kHTMLFXLPreviewPanelActionsRsrcID           10000

//	Animation panel resource definition
//	Occupies 20000 to 30000
#define kAnimationUIPanelRsrcID						20000
#define kAnimationUIActionsRsrcID					20100
#define kAnimationUISavePresetRsrcID				20200
#define	kAnimationUIPanelIconRsrcID					20300
#define kAnimationUITriggerEventCheckedIcon			20400
#define kAnimationUITriggerEventBlankIcon			20500
#define kAnimationUIEventSelectorIconRsrcID			20600
#define kAnimationUIShowProxyIcon					20700
#define kAnimationUIShowPreviewIcon					20800
#define kAnimationUIButtonTriggerIcon				20900
#define kAnimationUIScaleLockIcon					21000
#define kAnimationUIScaleUnlockIcon					21100
#define kAnimationUIShowTimingIcon					21200
#define kAnimationUIClearAnimationIcon				21300
#define kAnimationUIManagePresetsDialogRsrcID		21400
#define kAnimationUIPresetPopupMenuIconRsrcID		21500
#define kAnimationUIManagePresetsDialogListNodeRsrcID	21600

#define kAnimationUIAnimationAdornmentIcon			30000

#define kAnimationUIPanelMinWidth					270	//ID standard is 207
#define kAnimationUIPanelMinWidth_JP					295	//ID standard is 207

#define kAnimationUIPanelMinHeight					537
#define kAnimationPaletteWidth						270 // ID standard is 207
#define kAnimationPaletteWidth_JP					295 // ID standard is 207
#define kAnimationPaletteWidth_CZ					290 // ID standard is 207
#define kAnimationPaletteWidth_FR					270 // ID standard is 207
#define kAnimationPaletteHeight						527

#define kAnimationUIPropertySubPanelHeight          177 
#define kAnimationUIPreviewPanelHeight				135
#define kAnimationUIMainPanelHeight					177 
#define kAnimationUIControlStripHeight				23 
#define kAnimationUISubPanelControlHeight			22

//	Animation panel widget geometry
#define kAnimationUIPresetProxyWidth				201	// Preset proxy now span the panel width
#define kXFProxyWidgetWidth							30
#define kAMUITextWidth								70
#define kAMUITextWidth_DE								80
#define kAMUITextWidth_FR								90
#define kAMUITextWidth_CZ								100
#define kAMUITextWidth_JP								90
#define kAMUIEventInfoWidth							150
#define kAMUIEditWidth1								35
#define kAMUIEditWidth2								53
#define kAMUIEditWidth2_DE							52
#define kAMUIEditWidth2_CZ							52
#define kAMUIScaleWidth								20
#define kAMUIScaleWidth_FR								15

#ifdef MACINTOSH 
#undef kAnimationPaletteWidth_FR 
#define kAnimationPaletteWidth_FR						280 // ID standard is 207
#undef kAMUITextWidth_FR
#define kAMUITextWidth_FR							100
#endif 

#endif // __DynamicDocumentsUIDefs__
