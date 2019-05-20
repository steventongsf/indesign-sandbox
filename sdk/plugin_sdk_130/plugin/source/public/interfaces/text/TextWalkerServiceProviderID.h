//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/text/TextWalkerServiceProviderID.h $
//  
//  Owner:
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

#ifndef __TextWalkerServiceProviderID__
#define __TextWalkerServiceProviderID__

#include "CrossPlatformTypes.h"
#include "IDFactory.h"

#define kTextWalkerServiceProviderPrefix	 RezLong(0x8400)

//---------------------------------------------------------------
//	Format Numbers
//---------------------------------------------------------------

// K2
#define	kTWSLastK2MinorFormat			kLastK2MinorVersionNumber

// Hotaka
#define	kTWSLastHotakaMinorFormat		kHotakaInitialMinorFormatNumber

// Anna
#define	kTWSAnnaFCOptionsChange			kAnnaInitialMinorFormatNumber
#define	kTWSLastAnnaMinorFormat			kTWSAnnaFCOptionsChange

// Cobalt
#define kTWSCobaltFCOptionsChange		kCobaltInitialMinorFormatNumber + 1
#define kTWSLastCobaltMinorFormat		kTWSCobaltFCOptionsChange
// Overall
#define kTWSLastMajorFormatNumber		kSiriusMajorFormatNumber
#define kTWSLastMinorFormatNumber		kSiriusInitialMinorFormatNumber

// <Start IDC>
// PluginID
#define kTextWalkerServicePluginName 		"Text Walker"
DECLARE_PMID(kPlugInIDSpace, kTextWalkerServicePluginID, kTextWalkerServiceProviderPrefix + 1)

// String resource ids
#define kTextWalkerServiceProviderStringsRsrcID			1000
#define kTextWalkerServiceProviderStringsNoTransRsrcID	1100
#define kTextWalkerErrorStringTableRsrcID				2000

// <Class ID>
//******CLASS IDs
DECLARE_PMID(kClassIDSpace, kTextWalkerServiceProviderBoss, kTextWalkerServiceProviderPrefix + 1)
DECLARE_PMID(kClassIDSpace, kFindTextCmdBoss, kTextWalkerServiceProviderPrefix + 2)
DECLARE_PMID(kClassIDSpace, kTWReplaceTextCmdBoss, kTextWalkerServiceProviderPrefix + 3)
DECLARE_PMID(kClassIDSpace, kReplaceFindTextCmdBoss, kTextWalkerServiceProviderPrefix + 4)
DECLARE_PMID(kClassIDSpace, kReplaceAllTextCmdBoss, kTextWalkerServiceProviderPrefix + 5)
DECLARE_PMID(kClassIDSpace, kEntireWordCmdBoss, kTextWalkerServiceProviderPrefix + 6)
DECLARE_PMID(kClassIDSpace, kCaseSensitiveCmdBoss, kTextWalkerServiceProviderPrefix + 7)
DECLARE_PMID(kClassIDSpace, kOversetCmdBoss, kTextWalkerServiceProviderPrefix + 8)
DECLARE_PMID(kClassIDSpace, kScopeCmdBoss, kTextWalkerServiceProviderPrefix + 9)
DECLARE_PMID(kClassIDSpace, kFindStringCmdBoss, kTextWalkerServiceProviderPrefix + 10)
DECLARE_PMID(kClassIDSpace, kReplaceStringCmdBoss, kTextWalkerServiceProviderPrefix + 11)
DECLARE_PMID(kClassIDSpace, kGrepCmdBoss, kTextWalkerServiceProviderPrefix + 12)
DECLARE_PMID(kClassIDSpace, kFindChangeServiceBoss, kTextWalkerServiceProviderPrefix + 13)
DECLARE_PMID(kClassIDSpace, kFindGlyphCmdBoss, kTextWalkerServiceProviderPrefix + 14)
DECLARE_PMID(kClassIDSpace, kReplaceGlyphCmdBoss, kTextWalkerServiceProviderPrefix + 15)
DECLARE_PMID(kClassIDSpace, kFindObjectCmdBoss, kTextWalkerServiceProviderPrefix + 16)
DECLARE_PMID(kClassIDSpace, kReplaceObjectCmdBoss, kTextWalkerServiceProviderPrefix + 17)
DECLARE_PMID(kClassIDSpace, kReplaceFindObjectCmdBoss, kTextWalkerServiceProviderPrefix + 18)
DECLARE_PMID(kClassIDSpace, kReplaceAllObjectCmdBoss, kTextWalkerServiceProviderPrefix + 19)
DECLARE_PMID(kClassIDSpace, kFindChangeFormatCmdBoss, kTextWalkerServiceProviderPrefix + 20)
DECLARE_PMID(kClassIDSpace, kReplaceAllApplyFormatCmdBoss, kTextWalkerServiceProviderPrefix + 21)
DECLARE_PMID(kClassIDSpace, kDocTextWalkerScopeBoss, kTextWalkerServiceProviderPrefix + 22)
DECLARE_PMID(kClassIDSpace, kClearFindFormatCmdBoss, kTextWalkerServiceProviderPrefix + 23)
DECLARE_PMID(kClassIDSpace, kClearChangeFormatCmdBoss, kTextWalkerServiceProviderPrefix + 24)
DECLARE_PMID(kClassIDSpace, kFindSearchModeCmdBoss, kTextWalkerServiceProviderPrefix + 25)
DECLARE_PMID(kClassIDSpace, kKanaSensitiveCmdBoss, kTextWalkerServiceProviderPrefix + 26)
DECLARE_PMID(kClassIDSpace, kWidthSensitiveCmdBoss, kTextWalkerServiceProviderPrefix + 27)
DECLARE_PMID(kClassIDSpace, kFindCharacterTypeCmdBoss, kTextWalkerServiceProviderPrefix + 28)
DECLARE_PMID(kClassIDSpace, kReplaceCharacterTypeCmdBoss, kTextWalkerServiceProviderPrefix + 29)
DECLARE_PMID(kClassIDSpace, kFindChangeModeCmdBoss, kTextWalkerServiceProviderPrefix + 30)
DECLARE_PMID(kClassIDSpace, kTextWalkerErrorStringServiceBoss, kTextWalkerServiceProviderPrefix + 31)
DECLARE_PMID(kClassIDSpace, kWalkerScopeBoss,kTextWalkerServiceProviderPrefix + 32)
DECLARE_PMID(kClassIDSpace, kTextWalkerBoss,kTextWalkerServiceProviderPrefix + 33)
DECLARE_PMID(kClassIDSpace, kWalkerStoryDeleteObserverBoss,kTextWalkerServiceProviderPrefix + 34)
DECLARE_PMID(kClassIDSpace, kTextWalkerPositionBoss, kTextWalkerServiceProviderPrefix + 35)
DECLARE_PMID(kClassIDSpace, kFindFontClientBoss, kTextWalkerServiceProviderPrefix + 36)
DECLARE_PMID(kClassIDSpace, kFindChangeClientBoss, kTextWalkerServiceProviderPrefix + 37)
DECLARE_PMID(kClassIDSpace, kBasicTextWalkerBoss, kTextWalkerServiceProviderPrefix + 38)
DECLARE_PMID(kClassIDSpace, kNonSession_FindChangeOptionsBoss,kTextWalkerServiceProviderPrefix + 39)
DECLARE_PMID(kClassIDSpace, kFindStringFunObjBoss,kTextWalkerServiceProviderPrefix + 40)
DECLARE_PMID(kClassIDSpace, kWalkerScopeCursorBoss,	kTextWalkerServiceProviderPrefix + 41)
DECLARE_PMID(kClassIDSpace, kFindChangeUniversalAttrUIDDBBoss,kTextWalkerServiceProviderPrefix + 42)
DECLARE_PMID(kClassIDSpace, kTextWalkerIteratorRegBoss, kTextWalkerServiceProviderPrefix + 43)
DECLARE_PMID(kClassIDSpace, kTextWalkerConversionBoss, kTextWalkerServiceProviderPrefix + 44)
DECLARE_PMID(kClassIDSpace, kClearFindChangeOptionsCmdBoss, kTextWalkerServiceProviderPrefix + 45)
DECLARE_PMID(kClassIDSpace, kFCStartupShutdownBoss, kTextWalkerServiceProviderPrefix + 46)
DECLARE_PMID(kClassIDSpace, kReplaceAllTextDataBoss, kTextWalkerServiceProviderPrefix + 47)
DECLARE_PMID(kClassIDSpace, kFCClient_ReturnsReplacementCount_Boss, kTextWalkerServiceProviderPrefix + 48)
//gap
DECLARE_PMID(kClassIDSpace, kFindChangePrefScriptProviderBoss, kTextWalkerServiceProviderPrefix + 50)
DECLARE_PMID(kClassIDSpace, kFindChangeScriptProviderBoss, kTextWalkerServiceProviderPrefix + 51)
DECLARE_PMID(kClassIDSpace, kSearchBackwardsCmdBoss, kTextWalkerServiceProviderPrefix + 52)
DECLARE_PMID(kClassIDSpace, kSearchBackwardsSilentCmdBoss, kTextWalkerServiceProviderPrefix + 53)
DECLARE_PMID(kClassIDSpace, kTWClientSelectionFocusBoss, kTextWalkerServiceProviderPrefix + 54)
DECLARE_PMID(kClassIDSpace, kTextWalkerScopeFocusBoss, kTextWalkerServiceProviderPrefix + 55)
DECLARE_PMID(kClassIDSpace, kIncludeLockedStoriesForFindCmdBoss, kTextWalkerServiceProviderPrefix + 56)
DECLARE_PMID(kClassIDSpace, kIncludeLockedLayersForFindCmdBoss, kTextWalkerServiceProviderPrefix + 57)
DECLARE_PMID(kClassIDSpace, kIncludeHiddenLayersCmdBoss, kTextWalkerServiceProviderPrefix + 58)
DECLARE_PMID(kClassIDSpace, kIncludeMasterPagesCmdBoss, kTextWalkerServiceProviderPrefix + 59)
DECLARE_PMID(kClassIDSpace, kIncludeFootnotesCmdBoss, kTextWalkerServiceProviderPrefix + 60)
DECLARE_PMID(kClassIDSpace, kObjectSearchTypeCmdBoss, kTextWalkerServiceProviderPrefix + 61)
DECLARE_PMID(kClassIDSpace, kObjectWalkerServiceProviderBoss, kTextWalkerServiceProviderPrefix + 62)
DECLARE_PMID(kClassIDSpace, kFindChangeGlyphIDCmdBoss, kTextWalkerServiceProviderPrefix + 63)
DECLARE_PMID(kClassIDSpace, kFindChangeGlyphFontCmdBoss, kTextWalkerServiceProviderPrefix + 64)
DECLARE_PMID(kClassIDSpace, kFindROSFontGroupCmdBoss, kTextWalkerServiceProviderPrefix + 65)
DECLARE_PMID(kClassIDSpace, kUseROSFontGroupCmdBoss, kTextWalkerServiceProviderPrefix + 66)
DECLARE_PMID(kClassIDSpace, kGlyphPanelQueryXMLWriterBoss, kTextWalkerServiceProviderPrefix + 67)
DECLARE_PMID(kClassIDSpace, kTextPanelQueryXMLWriterBoss, kTextWalkerServiceProviderPrefix + 68)
DECLARE_PMID(kClassIDSpace, kGrepPanelQueryXMLWriterBoss, kTextWalkerServiceProviderPrefix + 69)
DECLARE_PMID(kClassIDSpace, kObjectPanelQueryXMLWriterBoss, kTextWalkerServiceProviderPrefix + 70)
DECLARE_PMID(kClassIDSpace, kFCQueryXMLReaderCmdBoss, kTextWalkerServiceProviderPrefix + 71)
DECLARE_PMID(kClassIDSpace, kGlyphPanelQueryXMLReaderBoss, kTextWalkerServiceProviderPrefix + 72)
DECLARE_PMID(kClassIDSpace, kTextPanelQueryXMLReaderBoss, kTextWalkerServiceProviderPrefix + 73)
DECLARE_PMID(kClassIDSpace, kGrepPanelQueryXMLReaderBoss, kTextWalkerServiceProviderPrefix + 74)
//DECLARE_PMID(kClassIDSpace, kFindChangePrefScriptProvider50Boss, kTextWalkerServiceProviderPrefix + 75)
DECLARE_PMID(kClassIDSpace, kObjectWalkerBoss, kTextWalkerServiceProviderPrefix + 76)
DECLARE_PMID(kClassIDSpace, kFindChangeTextScriptProviderBoss, kTextWalkerServiceProviderPrefix + 77)
DECLARE_PMID(kClassIDSpace, kFindChangeGrepScriptProviderBoss, kTextWalkerServiceProviderPrefix + 78)
DECLARE_PMID(kClassIDSpace, kFindChangeGlyphScriptProviderBoss, kTextWalkerServiceProviderPrefix + 79)
DECLARE_PMID(kClassIDSpace, kFindChangeObjectScriptProviderBoss, kTextWalkerServiceProviderPrefix + 80)
DECLARE_PMID(kClassIDSpace, kFindChangeTransliterateScriptProviderBoss,kTextWalkerServiceProviderPrefix + 81)
DECLARE_PMID(kClassIDSpace, kFindChangeTextOptionsScriptProviderBoss, kTextWalkerServiceProviderPrefix + 82)
DECLARE_PMID(kClassIDSpace, kFindChangeGrepOptionsScriptProviderBoss, kTextWalkerServiceProviderPrefix + 83)
DECLARE_PMID(kClassIDSpace, kFindChangeGlyphOptionsScriptProviderBoss, kTextWalkerServiceProviderPrefix + 84)
DECLARE_PMID(kClassIDSpace, kFindChangeObjectOptionsScriptProviderBoss, kTextWalkerServiceProviderPrefix + 85)
DECLARE_PMID(kClassIDSpace, kFindChangeTransliterateOptionsScriptProviderBoss, kTextWalkerServiceProviderPrefix + 86)
DECLARE_PMID(kClassIDSpace, kFindTextPreferencesScriptProviderBoss, kTextWalkerServiceProviderPrefix + 87)
DECLARE_PMID(kClassIDSpace, kChangeTextPreferencesScriptProviderBoss, kTextWalkerServiceProviderPrefix + 88)
DECLARE_PMID(kClassIDSpace, kFindGrepPreferencesScriptProviderBoss, kTextWalkerServiceProviderPrefix + 89)
DECLARE_PMID(kClassIDSpace, kChangeGrepPreferencesScriptProviderBoss, kTextWalkerServiceProviderPrefix + 90)
DECLARE_PMID(kClassIDSpace, kFindTransliteratePreferencesScriptProviderBoss, kTextWalkerServiceProviderPrefix + 91)
DECLARE_PMID(kClassIDSpace, kChangeTransliteratePreferencesScriptProviderBoss, kTextWalkerServiceProviderPrefix + 92)
DECLARE_PMID(kClassIDSpace, kFindGlyphPreferencesScriptProviderBoss, kTextWalkerServiceProviderPrefix + 93)
DECLARE_PMID(kClassIDSpace, kChangeGlyphPreferencesScriptProviderBoss, kTextWalkerServiceProviderPrefix + 94)
DECLARE_PMID(kClassIDSpace, kFindObjectPreferencesScriptProviderBoss, kTextWalkerServiceProviderPrefix + 95)
DECLARE_PMID(kClassIDSpace, kChangeObjectPreferencesScriptProviderBoss, kTextWalkerServiceProviderPrefix + 96)
DECLARE_PMID(kClassIDSpace, kObjectPanelQueryXMLReaderBoss, kTextWalkerServiceProviderPrefix + 97)
DECLARE_PMID(kClassIDSpace, kTransliteratePanelQueryXMLWriterBoss, kTextWalkerServiceProviderPrefix + 98)
DECLARE_PMID(kClassIDSpace, kTransliteratePanelQueryXMLReaderBoss, kTextWalkerServiceProviderPrefix + 99)
DECLARE_PMID(kClassIDSpace, kFCLoadSaveQueryScriptProviderBoss, kTextWalkerServiceProviderPrefix + 100)
DECLARE_PMID(kClassIDSpace, kReplaceAllOTFAttributesCmdBoss, kTextWalkerServiceProviderPrefix + 101)
DECLARE_PMID(kClassIDSpace, kFCQuerySettingsMigrationServiceProviderBoss, kTextWalkerServiceProviderPrefix + 102)
DECLARE_PMID(kClassIDSpace, kFontSearchWalkerServiceProviderBoss, kTextWalkerServiceProviderPrefix + 103)

// <Interface ID>
//******INTERFACE IDs
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDCHANGEOPTIONS, kTextWalkerServiceProviderPrefix + 1)
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDCHANGECMDDATA, kTextWalkerServiceProviderPrefix + 2)
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDCHANGSERVICE, kTextWalkerServiceProviderPrefix + 3)
DECLARE_PMID(kInterfaceIDSpace, IID_ITEXTWALKERCLIENT, kTextWalkerServiceProviderPrefix + 4)
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDCHANGEATTRIBUTECMDDATA, kTextWalkerServiceProviderPrefix + 5)
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDCHANGEFORMATCMDDATA, kTextWalkerServiceProviderPrefix + 6)
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDFONTCMDDATA, kTextWalkerServiceProviderPrefix + 7)
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDCHANGEFORMATDATA, kTextWalkerServiceProviderPrefix + 8)
DECLARE_PMID(kInterfaceIDSpace, IID_ITEXTWALKER, kTextWalkerServiceProviderPrefix + 9)

DECLARE_PMID(kInterfaceIDSpace, IID_IFINDGLYPHCMDDATA, kTextWalkerServiceProviderPrefix + 10)
DECLARE_PMID(kInterfaceIDSpace, IID_IOBJECTFINDCHANGECMDDATA, kTextWalkerServiceProviderPrefix + 11)
DECLARE_PMID(kInterfaceIDSpace, IID_ITEXTWALKERSCOPE, kTextWalkerServiceProviderPrefix + 12)
DECLARE_PMID(kInterfaceIDSpace, IID_IWALKERSCOPEFACTORYUTILS, kTextWalkerServiceProviderPrefix + 13)
DECLARE_PMID(kInterfaceIDSpace, IID_IWALKERSTORYDELETEOBSERVER, kTextWalkerServiceProviderPrefix + 14)
DECLARE_PMID(kInterfaceIDSpace, IID_IREPLACEALLTEXTDATA, kTextWalkerServiceProviderPrefix + 15)
DECLARE_PMID(kInterfaceIDSpace,IID_IWALKERSCOPECURSOR, kTextWalkerServiceProviderPrefix + 16)
//DECLARE_PMID(kInterfaceIDSpace, IID_IMYFANCYIID,kTextWalkerServiceProviderPrefix + 17)
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDCHANGEACTION,kTextWalkerServiceProviderPrefix + 18)
DECLARE_PMID(kInterfaceIDSpace, IID_ITEXTWALKERMSG, kTextWalkerServiceProviderPrefix + 19)

DECLARE_PMID(kInterfaceIDSpace,IID_ITEXTWALKERPROGRESSMONITOR, kTextWalkerServiceProviderPrefix + 20)
DECLARE_PMID(kInterfaceIDSpace, IID_ITEXTWALKERTERMINATOR, kTextWalkerServiceProviderPrefix + 21)
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDSTRINGFUNOBJ, kTextWalkerServiceProviderPrefix + 22)
DECLARE_PMID(kInterfaceIDSpace, IID_IDOCTEXTWALKERSCOPE, kTextWalkerServiceProviderPrefix + 23)
DECLARE_PMID(kInterfaceIDSpace, IID_IFCUNIVERSALATTRUIDDB, kTextWalkerServiceProviderPrefix + 24)
DECLARE_PMID(kInterfaceIDSpace, IID_IFCUNIVERSALATTRUIDTMPDB, kTextWalkerServiceProviderPrefix + 25)
DECLARE_PMID(kInterfaceIDSpace, IID_IREPLACEALLTEXTUTIL, kTextWalkerServiceProviderPrefix + 26)
//DECLARE_PMID(kInterfaceIDSpace, IID_IPATTERNMATCHINGUTILS_OBSOLETE, kTextWalkerServiceProviderPrefix + 27)
DECLARE_PMID(kInterfaceIDSpace,IID_IDATA_K2VECTOR_TEXTRANGE, kTextWalkerServiceProviderPrefix + 28)
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDCHANGEMODEDATA, kTextWalkerServiceProviderPrefix + 29)		// Just an IntData

DECLARE_PMID(kInterfaceIDSpace, IID_IIROSFONTGROUPSCACHE, kTextWalkerServiceProviderPrefix + 30)
DECLARE_PMID(kInterfaceIDSpace, IID_IOBJECTWALKER, kTextWalkerServiceProviderPrefix + 32)
DECLARE_PMID(kInterfaceIDSpace, IID_IFONTREGISTRY, kTextWalkerServiceProviderPrefix + 33)
DECLARE_PMID(kInterfaceIDSpace, IID_IFONTORDERING, kTextWalkerServiceProviderPrefix + 34)
DECLARE_PMID(kInterfaceIDSpace, IID_IFCQUERYXMLWRITER, kTextWalkerServiceProviderPrefix + 35)
DECLARE_PMID(kInterfaceIDSpace, IID_IXMLDOMDOCUMENTPTRHACK, kTextWalkerServiceProviderPrefix + 36)
DECLARE_PMID(kInterfaceIDSpace, IID_IFCQUERYXMLREADER, kTextWalkerServiceProviderPrefix + 37)
DECLARE_PMID(kInterfaceIDSpace, IID_IFCATTRIMPORTEXPORT, kTextWalkerServiceProviderPrefix + 38)
DECLARE_PMID(kInterfaceIDSpace, IID_IOBJECTWALKERMSG, kTextWalkerServiceProviderPrefix + 39)

DECLARE_PMID(kInterfaceIDSpace, IID_IOBJECTFINDCHANGESUITE, kTextWalkerServiceProviderPrefix + 40)
DECLARE_PMID(kInterfaceIDSpace, IID_IFINDCHANGEUTILS, kTextWalkerServiceProviderPrefix + 41)
DECLARE_PMID(kInterfaceIDSpace, IID_IFONTSEARCHWALKER, kTextWalkerServiceProviderPrefix + 42)

// <Service ID>
//******SERVICE IDs
DECLARE_PMID(kServiceIDSpace, kTextWalkerService, kTextWalkerServiceProviderPrefix + 1)
DECLARE_PMID(kServiceIDSpace, kObjectWalkerService, kTextWalkerServiceProviderPrefix + 2)
DECLARE_PMID(kServiceIDSpace, kFontSearchWalkerService, kTextWalkerServiceProviderPrefix + 3)

// <Implementation ID>
//******IMPLEMENTATION IDs
DECLARE_PMID(kImplementationIDSpace, kTextWalkerServiceProviderImpl, kTextWalkerServiceProviderPrefix + 1)
DECLARE_PMID(kImplementationIDSpace, kFindTextCmdImpl, kTextWalkerServiceProviderPrefix + 2)
DECLARE_PMID(kImplementationIDSpace, kTWReplaceTextCmdImpl, kTextWalkerServiceProviderPrefix + 3)
DECLARE_PMID(kImplementationIDSpace, kReplaceFindTextCmdImpl, kTextWalkerServiceProviderPrefix + 4)
DECLARE_PMID(kImplementationIDSpace, kReplaceAllTextCmdImpl, kTextWalkerServiceProviderPrefix + 5)
DECLARE_PMID(kImplementationIDSpace, kFindChangeOptionsImpl, kTextWalkerServiceProviderPrefix + 6)
DECLARE_PMID(kImplementationIDSpace, kEntireWordCmdImpl, kTextWalkerServiceProviderPrefix + 7)
DECLARE_PMID(kImplementationIDSpace, kCaseSensitiveCmdImpl, kTextWalkerServiceProviderPrefix + 8)
DECLARE_PMID(kImplementationIDSpace, kOversetCmdImpl, kTextWalkerServiceProviderPrefix + 9)

DECLARE_PMID(kImplementationIDSpace, kScopeCmdImpl, kTextWalkerServiceProviderPrefix + 10)
DECLARE_PMID(kImplementationIDSpace, kFindStringCmdImpl, kTextWalkerServiceProviderPrefix + 11)
DECLARE_PMID(kImplementationIDSpace, kReplaceStringCmdImpl, kTextWalkerServiceProviderPrefix + 12)
DECLARE_PMID(kImplementationIDSpace, kFindChangeUtilsImpl, kTextWalkerServiceProviderPrefix + 13)
DECLARE_PMID(kImplementationIDSpace, kFindChangeCmdDataImpl, kTextWalkerServiceProviderPrefix + 14)
DECLARE_PMID(kImplementationIDSpace, kFindChangeServiceImpl, kTextWalkerServiceProviderPrefix + 15)
DECLARE_PMID(kImplementationIDSpace, kFindChangeClientImpl, kTextWalkerServiceProviderPrefix + 16)
DECLARE_PMID(kImplementationIDSpace, kFindGlyphCmdImpl, kTextWalkerServiceProviderPrefix + 17)
DECLARE_PMID(kImplementationIDSpace, kReplaceGlyphCmdImpl, kTextWalkerServiceProviderPrefix + 18)
DECLARE_PMID(kImplementationIDSpace, kFindGlyphCmdDataImpl, kTextWalkerServiceProviderPrefix + 19)

DECLARE_PMID(kImplementationIDSpace, kDocTextWalkerScopeImpl, kTextWalkerServiceProviderPrefix + 20)
DECLARE_PMID(kImplementationIDSpace, kTextWalkerPositionImpl, kTextWalkerServiceProviderPrefix + 21)
DECLARE_PMID(kImplementationIDSpace, kSearchBackwardsCmdImpl, kTextWalkerServiceProviderPrefix + 22)
DECLARE_PMID(kImplementationIDSpace, kSearchBackwardsSilentCmdImpl, kTextWalkerServiceProviderPrefix + 23)
DECLARE_PMID(kImplementationIDSpace, kFindChangeFormatCmdImpl, kTextWalkerServiceProviderPrefix + 24)		// command for everything
DECLARE_PMID(kImplementationIDSpace, kFindChangeFormatCmdDataImpl, kTextWalkerServiceProviderPrefix + 25)		// command data for everything
DECLARE_PMID(kImplementationIDSpace, kFindChangeFormatDataImpl, kTextWalkerServiceProviderPrefix + 26)
DECLARE_PMID(kImplementationIDSpace, kTextWalkerErrorStringServiceImpl, kTextWalkerServiceProviderPrefix + 27)
DECLARE_PMID(kImplementationIDSpace, kClearFindFormatCmdImpl, kTextWalkerServiceProviderPrefix + 28)
DECLARE_PMID(kImplementationIDSpace, kClearChangeFormatCmdImpl, kTextWalkerServiceProviderPrefix + 29)

DECLARE_PMID(kImplementationIDSpace, kReplaceAllApplyFormatCmdImpl, kTextWalkerServiceProviderPrefix + 30)
DECLARE_PMID(kImplementationIDSpace, kFindFontClientImpl, kTextWalkerServiceProviderPrefix + 31)
DECLARE_PMID(kImplementationIDSpace, kGrepCmdImpl, kTextWalkerServiceProviderPrefix + 32)
DECLARE_PMID(kImplementationIDSpace, kTextWalkerImpl, kTextWalkerServiceProviderPrefix + 33)
DECLARE_PMID(kImplementationIDSpace, kKanaSensitiveCmdImpl, kTextWalkerServiceProviderPrefix + 34)
DECLARE_PMID(kImplementationIDSpace, kWidthSensitiveCmdImpl, kTextWalkerServiceProviderPrefix + 35)
DECLARE_PMID(kImplementationIDSpace, kFindCharacterTypeCmdImpl, kTextWalkerServiceProviderPrefix + 36)
DECLARE_PMID(kImplementationIDSpace, kReplaceCharacterTypeCmdImpl, kTextWalkerServiceProviderPrefix + 37)
DECLARE_PMID(kImplementationIDSpace, kFindChangeModeCmdImpl, kTextWalkerServiceProviderPrefix + 38)

DECLARE_PMID(kImplementationIDSpace, kNonSession_FindChangeOptionsImpl, kTextWalkerServiceProviderPrefix + 41)
DECLARE_PMID(kImplementationIDSpace, kFindSearchModeCmdImpl, kTextWalkerServiceProviderPrefix + 42)
DECLARE_PMID(kImplementationIDSpace, kTextWalkerScopeImpl, kTextWalkerServiceProviderPrefix + 43)
DECLARE_PMID(kImplementationIDSpace, kWalkerScopeFactoryUtilsImpl, kTextWalkerServiceProviderPrefix + 44)
DECLARE_PMID(kImplementationIDSpace, kWalkerStoryDeleteObserverImpl, kTextWalkerServiceProviderPrefix + 45)
DECLARE_PMID(kImplementationIDSpace, kFindFontCmdDataImpl, kTextWalkerServiceProviderPrefix + 46)
DECLARE_PMID(kImplementationIDSpace, kWalkerScopeCursorImpl, kTextWalkerServiceProviderPrefix + 47)
//DECLARE_PMID(kImplementationIDSpace, kMyFancyImpl, kTextWalkerServiceProviderPrefix + 48)
DECLARE_PMID(kImplementationIDSpace, kReplaceAllTextUtilImpl, kTextWalkerServiceProviderPrefix + 49)

DECLARE_PMID(kImplementationIDSpace, kReplaceAllTextDataImpl, kTextWalkerServiceProviderPrefix + 50)
DECLARE_PMID(kImplementationIDSpace, kFindChangeActionImpl, kTextWalkerServiceProviderPrefix + 51)
DECLARE_PMID(kImplementationIDSpace, kTextWalkerProgressMonitorImpl,kTextWalkerServiceProviderPrefix + 52)
DECLARE_PMID(kImplementationIDSpace, kReplaceAllOTFAttributesCmdImpl,kTextWalkerServiceProviderPrefix + 53)
DECLARE_PMID(kImplementationIDSpace, kFindStringFunObjImpl, kTextWalkerServiceProviderPrefix + 54)
//gap

DECLARE_PMID(kImplementationIDSpace, kFCUniversalAttrUIDDBImpl, kTextWalkerServiceProviderPrefix + 61)
DECLARE_PMID(kImplementationIDSpace, kFCUniversalAttrUIDTmpDBImpl, kTextWalkerServiceProviderPrefix + 62)
DECLARE_PMID(kImplementationIDSpace, kTextWalkerIteratorRegImpl, kTextWalkerServiceProviderPrefix + 63)
DECLARE_PMID(kImplementationIDSpace, kClearFindChangeOptionsCmdImpl, kTextWalkerServiceProviderPrefix + 64)
DECLARE_PMID(kImplementationIDSpace, kFCStartupShutdownImpl, kTextWalkerServiceProviderPrefix + 65)
//DECLARE_PMID(kImplementationIDSpace, kPatternMatchingUtilsImpl_Obsolete, kTextWalkerServiceProviderPrefix + 66)
DECLARE_PMID(kImplementationIDSpace, kIData_K2Vector_TextRangeImpl, kTextWalkerServiceProviderPrefix + 67)
DECLARE_PMID(kImplementationIDSpace, kFindChangePrefScriptProviderImpl, kTextWalkerServiceProviderPrefix + 68)

//gap
DECLARE_PMID(kImplementationIDSpace, kFindChangeScriptProviderImpl, kTextWalkerServiceProviderPrefix + 72)
DECLARE_PMID(kImplementationIDSpace, kTWClientSelectionFocusImpl, kTextWalkerServiceProviderPrefix + 73)
DECLARE_PMID(kImplementationIDSpace, kTextWalkerScopeFocusImpl, kTextWalkerServiceProviderPrefix + 74)
DECLARE_PMID(kImplementationIDSpace, kIncludeLockedStoriesForFindCmdImpl, kTextWalkerServiceProviderPrefix + 75)
DECLARE_PMID(kImplementationIDSpace, kIncludeLockedLayersForFindCmdImpl, kTextWalkerServiceProviderPrefix + 76)
DECLARE_PMID(kImplementationIDSpace, kIncludeHiddenLayersCmdImpl, kTextWalkerServiceProviderPrefix + 77)
DECLARE_PMID(kImplementationIDSpace, kIncludeMasterPagesCmdImpl, kTextWalkerServiceProviderPrefix + 78)
DECLARE_PMID(kImplementationIDSpace, kIncludeFootnotesCmdImpl, kTextWalkerServiceProviderPrefix + 79)

DECLARE_PMID(kImplementationIDSpace, kObjectSearchTypeCmdImpl, kTextWalkerServiceProviderPrefix + 80)
DECLARE_PMID(kImplementationIDSpace, kROSFontGroupsCacheImpl, kTextWalkerServiceProviderPrefix + 81)
DECLARE_PMID(kImplementationIDSpace, kObjectWalkerFactoryUtilsImpl, kTextWalkerServiceProviderPrefix + 82)
DECLARE_PMID(kImplementationIDSpace, kObjectWalkerServiceProviderImpl, kTextWalkerServiceProviderPrefix + 83)
DECLARE_PMID(kImplementationIDSpace, kObjectWalkerImpl, kTextWalkerServiceProviderPrefix + 84)
DECLARE_PMID(kImplementationIDSpace, kFindChangeGlyphIDCmdImpl, kTextWalkerServiceProviderPrefix + 85)
DECLARE_PMID(kImplementationIDSpace, kFindChangeGlyphFontCmdImpl, kTextWalkerServiceProviderPrefix + 86)
DECLARE_PMID(kImplementationIDSpace, kFindROSFontGroupCmdImpl, kTextWalkerServiceProviderPrefix + 87)
DECLARE_PMID(kImplementationIDSpace, kUseROSFontGroupCmdImpl, kTextWalkerServiceProviderPrefix + 88)
DECLARE_PMID(kImplementationIDSpace, kRegistryStringDataImpl, kTextWalkerServiceProviderPrefix + 89)

DECLARE_PMID(kImplementationIDSpace, kFCGlyphPanelQueryXMLWriterImpl, kTextWalkerServiceProviderPrefix + 90)
DECLARE_PMID(kImplementationIDSpace, kFCTextPanelQueryXMLWriterImpl, kTextWalkerServiceProviderPrefix + 91)
DECLARE_PMID(kImplementationIDSpace, kFCGrepPanelQueryXMLWriterImpl, kTextWalkerServiceProviderPrefix + 92)
DECLARE_PMID(kImplementationIDSpace, kFCObjectPanelQueryXMLWriterImpl, kTextWalkerServiceProviderPrefix + 93)
DECLARE_PMID(kImplementationIDSpace, kXMLDOMDocumentPtrHackImpl, kTextWalkerServiceProviderPrefix + 94)
DECLARE_PMID(kImplementationIDSpace, kFCQueryXMLReaderCmdImpl, kTextWalkerServiceProviderPrefix + 95)
DECLARE_PMID(kImplementationIDSpace, kFCGlyphPanelQueryXMLReaderImpl, kTextWalkerServiceProviderPrefix + 96)
DECLARE_PMID(kImplementationIDSpace, kFCTextPanelQueryXMLReaderImpl, kTextWalkerServiceProviderPrefix + 97)
DECLARE_PMID(kImplementationIDSpace, kFCGrepPanelQueryXMLReaderImpl, kTextWalkerServiceProviderPrefix + 98)
//DECLARE_PMID(kImplementationIDSpace, kFindChangePrefScriptProvider50Impl, kTextWalkerServiceProviderPrefix + 99)

DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpBooleanImpl, kTextWalkerServiceProviderPrefix + 100)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpRealNumberImpl, kTextWalkerServiceProviderPrefix + 101)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpInt16Impl, kTextWalkerServiceProviderPrefix + 102)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpInt32Impl, kTextWalkerServiceProviderPrefix + 103)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpStringImpl, kTextWalkerServiceProviderPrefix + 104)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpAlignImpl, kTextWalkerServiceProviderPrefix + 105)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpBalanceStyleImpl, kTextWalkerServiceProviderPrefix + 106)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpBreakBeforeModeImpl, kTextWalkerServiceProviderPrefix + 107)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpCapitalModeImpl, kTextWalkerServiceProviderPrefix + 108)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpFigureStyleImpl, kTextWalkerServiceProviderPrefix + 109)

DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpListTypeImpl, kTextWalkerServiceProviderPrefix + 110)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpOTPosFormImpl, kTextWalkerServiceProviderPrefix + 111)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpPositionModeImpl, kTextWalkerServiceProviderPrefix + 112)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpUnderlineModeImpl, kTextWalkerServiceProviderPrefix + 113)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpClassIDImpl, kTextWalkerServiceProviderPrefix + 114)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpStrokeTypeImpl, kTextWalkerServiceProviderPrefix + 115)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpUIDImpl, kTextWalkerServiceProviderPrefix + 116)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpFontStyleImpl, kTextWalkerServiceProviderPrefix + 117)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpNumberingStyleImpl, kTextWalkerServiceProviderPrefix + 118)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpRestartPolicyImpl, kTextWalkerServiceProviderPrefix + 119)

DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpBulletCharImpl, kTextWalkerServiceProviderPrefix + 120)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpRubyAlignImpl, kTextWalkerServiceProviderPrefix + 121)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpRubyOverHangImpl, kTextWalkerServiceProviderPrefix + 122)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpKinsokuTypeImpl, kTextWalkerServiceProviderPrefix + 123)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpKinsokuHangTypeImpl, kTextWalkerServiceProviderPrefix + 124)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpLeadingModelImpl, kTextWalkerServiceProviderPrefix + 125)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpGridAlignmentImpl, kTextWalkerServiceProviderPrefix + 126)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpRubyAdjustParentImpl, kTextWalkerServiceProviderPrefix + 127)
DECLARE_PMID(kImplementationIDSpace, kFindObjectCmdImpl, kTextWalkerServiceProviderPrefix + 128)
DECLARE_PMID(kImplementationIDSpace, kReplaceObjectCmdImpl, kTextWalkerServiceProviderPrefix + 129)

DECLARE_PMID(kImplementationIDSpace, kReplaceFindObjectCmdImpl, kTextWalkerServiceProviderPrefix + 130)
DECLARE_PMID(kImplementationIDSpace, kReplaceAllObjectCmdImpl, kTextWalkerServiceProviderPrefix + 131)
DECLARE_PMID(kImplementationIDSpace, kObjectFindChangeCmdDataImpl, kTextWalkerServiceProviderPrefix + 132)
DECLARE_PMID(kImplementationIDSpace, kFindChangeTextScriptProviderImpl, kTextWalkerServiceProviderPrefix + 133)
DECLARE_PMID(kImplementationIDSpace, kFindChangeGrepScriptProviderImpl, kTextWalkerServiceProviderPrefix + 134)
DECLARE_PMID(kImplementationIDSpace, kFindChangeGlyphScriptProviderImpl, kTextWalkerServiceProviderPrefix + 135)
DECLARE_PMID(kImplementationIDSpace, kFindChangeObjectScriptProviderImpl, kTextWalkerServiceProviderPrefix + 136)
DECLARE_PMID(kImplementationIDSpace, kFindChangeTransliterateScriptProviderImpl, kTextWalkerServiceProviderPrefix + 137)
DECLARE_PMID(kImplementationIDSpace, kFindChangeTextOptionsScriptProviderImpl, kTextWalkerServiceProviderPrefix + 138)
DECLARE_PMID(kImplementationIDSpace, kFindChangeGrepOptionsScriptProviderImpl, kTextWalkerServiceProviderPrefix + 139)

DECLARE_PMID(kImplementationIDSpace, kFindChangeGlyphOptionsScriptProviderImpl, kTextWalkerServiceProviderPrefix + 140)
DECLARE_PMID(kImplementationIDSpace, kFindChangeObjectOptionsScriptProviderImpl, kTextWalkerServiceProviderPrefix + 141)
DECLARE_PMID(kImplementationIDSpace, kFindChangeTransliterateOptionsScriptProviderImpl, kTextWalkerServiceProviderPrefix + 142)
DECLARE_PMID(kImplementationIDSpace, kFindTextPreferencesScriptProviderImpl, kTextWalkerServiceProviderPrefix + 143)
DECLARE_PMID(kImplementationIDSpace, kChangeTextPreferencesScriptProviderImpl, kTextWalkerServiceProviderPrefix + 144)
DECLARE_PMID(kImplementationIDSpace, kFindGrepPreferencesScriptProviderImpl, kTextWalkerServiceProviderPrefix + 145)
DECLARE_PMID(kImplementationIDSpace, kChangeGrepPreferencesScriptProviderImpl, kTextWalkerServiceProviderPrefix + 146)
DECLARE_PMID(kImplementationIDSpace, kFindTransliteratePreferencesScriptProviderImpl, kTextWalkerServiceProviderPrefix + 147)
DECLARE_PMID(kImplementationIDSpace, kChangeTransliteratePreferencesScriptProviderImpl, kTextWalkerServiceProviderPrefix + 148)
DECLARE_PMID(kImplementationIDSpace, kFindGlyphPreferencesScriptProviderImpl, kTextWalkerServiceProviderPrefix + 149)

DECLARE_PMID(kImplementationIDSpace, kChangeGlyphPreferencesScriptProviderImpl, kTextWalkerServiceProviderPrefix + 150)
DECLARE_PMID(kImplementationIDSpace, kFindObjectPreferencesScriptProviderImpl, kTextWalkerServiceProviderPrefix + 151)
DECLARE_PMID(kImplementationIDSpace, kChangeObjectPreferencesScriptProviderImpl, kTextWalkerServiceProviderPrefix + 152)
DECLARE_PMID(kImplementationIDSpace, kFCObjectPanelQueryXMLReaderImpl, kTextWalkerServiceProviderPrefix + 153)
DECLARE_PMID(kImplementationIDSpace, kFCTransliteratePanelQueryXMLWriterImpl, kTextWalkerServiceProviderPrefix + 154)
DECLARE_PMID(kImplementationIDSpace, kFCTransliteratePanelQueryXMLReaderImpl, kTextWalkerServiceProviderPrefix + 155)
DECLARE_PMID(kImplementationIDSpace, kFCGraphicAttrImpExpBooleanImpl, kTextWalkerServiceProviderPrefix + 156)
DECLARE_PMID(kImplementationIDSpace, kFCGraphicAttrImpExpInt16Impl, kTextWalkerServiceProviderPrefix + 157)
DECLARE_PMID(kImplementationIDSpace, kFCGraphicAttrImpExpInt32Impl, kTextWalkerServiceProviderPrefix + 158)
DECLARE_PMID(kImplementationIDSpace, kFCGraphicAttrImpExpRealNumberImpl, kTextWalkerServiceProviderPrefix + 159)

DECLARE_PMID(kImplementationIDSpace, kFCGraphicAttrImpExpClassIDImpl, kTextWalkerServiceProviderPrefix + 160)
DECLARE_PMID(kImplementationIDSpace, kFCGraphicAttrImpExpPointImpl, kTextWalkerServiceProviderPrefix + 161)
DECLARE_PMID(kImplementationIDSpace, kFCGraphicAttrImpExpUIDImpl, kTextWalkerServiceProviderPrefix + 162)
DECLARE_PMID(kImplementationIDSpace, kFCLoadSaveQueryScriptProviderImpl, kTextWalkerServiceProviderPrefix + 163)
DECLARE_PMID(kImplementationIDSpace, kObjectFindChangeASBImpl, kTextWalkerServiceProviderPrefix + 164)
DECLARE_PMID(kImplementationIDSpace, kObjectFindChangeTextCSBImpl, kTextWalkerServiceProviderPrefix + 165)
DECLARE_PMID(kImplementationIDSpace, kObjectFindChangeTableCSBImpl, kTextWalkerServiceProviderPrefix + 166)
DECLARE_PMID(kImplementationIDSpace, kObjectFindChangeDefaultCSBImpl, kTextWalkerServiceProviderPrefix + 167)
DECLARE_PMID(kImplementationIDSpace, kObjectFindChangeLayoutCSBImpl, kTextWalkerServiceProviderPrefix + 168)
DECLARE_PMID(kImplementationIDSpace, kFCGraphicAttrImpExpOpacityStopsImpl, kTextWalkerServiceProviderPrefix + 169)
DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpUIDListImpl, kTextWalkerServiceProviderPrefix + 170)

DECLARE_PMID(kImplementationIDSpace, kFCAttrImpExpGlyphFormImpl, kTextWalkerServiceProviderPrefix + 171)
DECLARE_PMID(kImplementationIDSpace, kFCQuerySettingsMigrationImpl, kTextWalkerServiceProviderPrefix + 172)
DECLARE_PMID(kImplementationIDSpace, kFontSearchWalkerImpl, kTextWalkerServiceProviderPrefix + 173)
DECLARE_PMID(kImplementationIDSpace, kFontSearchWalkerServiceProviderImpl, kTextWalkerServiceProviderPrefix + 174)

// <Error ID>
//******ERROR CODE IDs
DECLARE_PMID(kErrorIDSpace, kInvalidReplaceMetaCharError, kTextWalkerServiceProviderPrefix + 1)
DECLARE_PMID(kErrorIDSpace, kCantSearchOnEmptyTextError, kTextWalkerServiceProviderPrefix + 2)
//DECLARE_PMID(kErrorIDSpace, kMyFancyError, kTextWalkerServiceProviderPrefix + 3)
DECLARE_PMID(kErrorIDSpace, kInvalidSearchModeError, kTextWalkerServiceProviderPrefix + 4)
DECLARE_PMID(kErrorIDSpace, kInvalidObjectTypeError, kTextWalkerServiceProviderPrefix + 5)
DECLARE_PMID(kErrorIDSpace, kFCInvalidQueryNameError, kTextWalkerServiceProviderPrefix + 6)
DECLARE_PMID(kErrorIDSpace, kFCReadOnlyQueryFileError, kTextWalkerServiceProviderPrefix + 7)
DECLARE_PMID(kErrorIDSpace, kFCQueryFileNotFoundError, kTextWalkerServiceProviderPrefix + 8)
DECLARE_PMID(kErrorIDSpace, kInvalidFindFontError,		kTextWalkerServiceProviderPrefix + 9)
DECLARE_PMID(kErrorIDSpace, kInvalidFindGlyphIDError,	kTextWalkerServiceProviderPrefix + 10)
DECLARE_PMID(kErrorIDSpace, kInvalidReplaceFontError,	kTextWalkerServiceProviderPrefix + 11)
DECLARE_PMID(kErrorIDSpace, kInvalidReplaceGlyphIDError,kTextWalkerServiceProviderPrefix + 12)
DECLARE_PMID(kErrorIDSpace, kFCPrefAttributeNotPresentError, kTextWalkerServiceProviderPrefix + 13)
DECLARE_PMID(kErrorIDSpace, kInvalidFindCharacterTypeError, kTextWalkerServiceProviderPrefix + 14)
DECLARE_PMID(kErrorIDSpace, kInvalidReplaceCharacterTypeError, kTextWalkerServiceProviderPrefix + 15)

///////////////////////////////////////////////

DECLARE_PMID(kMessageIDSpace, kTextWalkerOnStartMessage, kTextWalkerServiceProviderPrefix + 1)
	// Received by observer that observe kTextWalkerServiceProviderBoss.
	// Sent by TextWalker::WalkRange() direct after calling ITextWalkerClient::OnStart().
	// ChangeBy: ITextWalkerClient *.
DECLARE_PMID(kMessageIDSpace, kTextWalkerOnEndMessage, kTextWalkerServiceProviderPrefix + 2)
	// Received by observer that observe kTextWalkerServiceProviderBoss.
	// Sent by TextWalker::WalkRange() direct after calling ITextWalkerClient::OnEnd().
	// ChangeBy: ITextWalkerClient *.
DECLARE_PMID(kMessageIDSpace, kTextWalkerOnHaltMessage, kTextWalkerServiceProviderPrefix + 3)
	// Received by observer that observe kTextWalkerServiceProviderBoss.
	// ChangeBy: ITextWalkerClient *.
DECLARE_PMID(kMessageIDSpace, kTextWalkerOnSuspendMessage, kTextWalkerServiceProviderPrefix + 4)
	// Received by observer that observe kTextWalkerServiceProviderBoss.
	// Sent by TextWalker::Suspend().
	// ChangeBy: ITextWalkerClient *.
DECLARE_PMID(kMessageIDSpace, kTextWalkerOnResumeMessage, kTextWalkerServiceProviderPrefix + 5)
	// Received by observer that observe kTextWalkerServiceProviderBoss.
	// Sent by TextWalker::Resume().
	// ChangeBy: ITextWalkerClient *.

DECLARE_PMID(kMessageIDSpace, kTextWalkerOnStoryStartMessage, kTextWalkerServiceProviderPrefix + 6)
	// Received by observer that observe kTextWalkerServiceProviderBoss.
	// Sent by TextWalker::WalkStory() and WalkStoryList() direct after calling ITextWalkerClient::OnStoryStart().
	// ChangeBy: ITextWalkerClient *.
DECLARE_PMID(kMessageIDSpace, kTextWalkerOnStoryEndMessage, kTextWalkerServiceProviderPrefix + 7)
	// Received by observer that observe kTextWalkerServiceProviderBoss.
	// Sent by TextWalker::WalkStory() and WalkStoryList() direct after calling ITextWalkerClient::OnStoryEnd().
	// ChangeBy: ITextWalkerClient *.

DECLARE_PMID(kMessageIDSpace, kTextWalkerWordHasChangedMessage, kTextWalkerServiceProviderPrefix + 8)
	// Received by TextWalkerObserver, calls ITextWalker::MoveTo() in order to synchronize the walker with the word change.
	// Example: sent by SpellWordEventHandler after changing the word in the editbox.
	// ChangeBy: const PMString *pNewWord.

DECLARE_PMID(kMessageIDSpace, kTextWalkerDoHaltMessage, kTextWalkerServiceProviderPrefix + 9)
	// Sent by TextWalkerObserver shortly before calling ITextWalker::Halt().
	// Example: received by SpellScopeObserver so it could resume after interactive spelling mode.
	// ChangeBy: this TextWalkerObserver.
DECLARE_PMID(kMessageIDSpace, kTextWalkerScopeHasChangedMessage, kTextWalkerServiceProviderPrefix + 10)
	// Received by TextWalkerObserver, sets the new scope.
	// Example: sent by SpellScopeObserver.
	// ChangeBy: const ITextWalker::WalkScope *pNewScope.
DECLARE_PMID(kMessageIDSpace, kTextWalkerOversetHasChangedMessage, kTextWalkerServiceProviderPrefix + 11)
	// Received by TextWalkerObserver, sets the new overset flag.
	// Example: sent by SpellOversetObserver.
	// ChangeBy: const bool16 *pNewOverset.
DECLARE_PMID(kMessageIDSpace, kTextWalkerWrapHasChangedMessage, kTextWalkerServiceProviderPrefix + 12)
	// Received by TextWalkerObserver, sets the new wrap flag.
	// Example: sent by SpellWrapObserver.
	// ChangeBy: const bool16 *pNewWrap.

DECLARE_PMID(kMessageIDSpace, kWalkOverSetText, kTextWalkerServiceProviderPrefix + 13)
DECLARE_PMID(kMessageIDSpace, kWalkText, kTextWalkerServiceProviderPrefix + 14)
DECLARE_PMID(kMessageIDSpace, kWalkTextInTable, kTextWalkerServiceProviderPrefix + 15)
DECLARE_PMID(kMessageIDSpace, kWalkMasterPageText, kTextWalkerServiceProviderPrefix + 16)
DECLARE_PMID(kMessageIDSpace, kWalkMasterPageTextInTable, kTextWalkerServiceProviderPrefix + 17)
DECLARE_PMID(kMessageIDSpace, kWalkMasterPageOverSetText, kTextWalkerServiceProviderPrefix + 18)
DECLARE_PMID(kMessageIDSpace, kObjectWalkerFoundObjectMsg, kTextWalkerServiceProviderPrefix + 19)
DECLARE_PMID(kMessageIDSpace, kObjectWalkerReplacedObjectMsg, kTextWalkerServiceProviderPrefix + 20)
DECLARE_PMID(kMessageIDSpace, kObjectWalkerReplacedButCouldNotFindNextObjectMsg, kTextWalkerServiceProviderPrefix + 21)
DECLARE_PMID(kMessageIDSpace, kObjectWalkerReplacedAndFoundNextObjectMsg, kTextWalkerServiceProviderPrefix + 22)
DECLARE_PMID(kMessageIDSpace, kObjectWalkerReplacedAllObjectsMsg, kTextWalkerServiceProviderPrefix + 23)
DECLARE_PMID(kMessageIDSpace, kObjectWalkCompletedMsg, kTextWalkerServiceProviderPrefix + 24)
DECLARE_PMID(kMessageIDSpace, kObjectFoundOnLockedLayerMsg, kTextWalkerServiceProviderPrefix + 25)
DECLARE_PMID(kMessageIDSpace, kObjectFoundOnHiddenLayerMsg, kTextWalkerServiceProviderPrefix + 26)
DECLARE_PMID(kMessageIDSpace, kObjectFoundOnLockedStoryMsg, kTextWalkerServiceProviderPrefix + 27)
DECLARE_PMID(kMessageIDSpace, kObjectFoundMsg, kTextWalkerServiceProviderPrefix + 28)
DECLARE_PMID(kMessageIDSpace, kObjectWalkHaltMsg, kTextWalkerServiceProviderPrefix + 29)
DECLARE_PMID(kMessageIDSpace, kFindGlyphHasChangedMsg, kTextWalkerServiceProviderPrefix + 30)
DECLARE_PMID(kMessageIDSpace, kReplaceGlyphHasChangedMsg, kTextWalkerServiceProviderPrefix + 31)
DECLARE_PMID(kMessageIDSpace, kWalkHiddenLayerText, kTextWalkerServiceProviderPrefix + 32)
DECLARE_PMID(kMessageIDSpace, kWalkMasterPageHiddenLayerText, kTextWalkerServiceProviderPrefix + 33)

//
//Script Element IDs
//

//gap
DECLARE_PMID(kScriptInfoIDSpace, kFindPreferenceObjectScriptElement,				kTextWalkerServiceProviderPrefix + 5)
DECLARE_PMID(kScriptInfoIDSpace, kChangePreferenceObjectScriptElement,				kTextWalkerServiceProviderPrefix + 6)
DECLARE_PMID(kScriptInfoIDSpace, kFindTextPreferenceObjectScriptElement,			kTextWalkerServiceProviderPrefix + 7)
DECLARE_PMID(kScriptInfoIDSpace, kChangeTextPreferenceObjectScriptElement,			kTextWalkerServiceProviderPrefix + 8)
//gap
DECLARE_PMID(kScriptInfoIDSpace, kSearchMethodScriptElement,							kTextWalkerServiceProviderPrefix + 10)
DECLARE_PMID(kScriptInfoIDSpace, kFindTextMethodScriptElement,						kTextWalkerServiceProviderPrefix + 11)
DECLARE_PMID(kScriptInfoIDSpace, kChangeTextMethodScriptElement,						kTextWalkerServiceProviderPrefix + 12)
DECLARE_PMID(kScriptInfoIDSpace, kFindGrepMethodScriptElement,						kTextWalkerServiceProviderPrefix + 13)
DECLARE_PMID(kScriptInfoIDSpace, kChangeGrepMethodScriptElement,						kTextWalkerServiceProviderPrefix + 14)
DECLARE_PMID(kScriptInfoIDSpace, kFindGlyphMethodScriptElement,						kTextWalkerServiceProviderPrefix + 15)
DECLARE_PMID(kScriptInfoIDSpace, kChangeGlyphMethodScriptElement,					kTextWalkerServiceProviderPrefix + 16)
DECLARE_PMID(kScriptInfoIDSpace, kFindObjectMethodScriptElement,						kTextWalkerServiceProviderPrefix + 17)
DECLARE_PMID(kScriptInfoIDSpace, kChangeObjectMethodScriptElement,					kTextWalkerServiceProviderPrefix + 18)
DECLARE_PMID(kScriptInfoIDSpace, kFindTransliterateMethodScriptElement,				kTextWalkerServiceProviderPrefix + 19)
DECLARE_PMID(kScriptInfoIDSpace, kFindTextPropertyScriptElement,					kTextWalkerServiceProviderPrefix + 20)
DECLARE_PMID(kScriptInfoIDSpace, kWholeWordPropertyScriptElement,					kTextWalkerServiceProviderPrefix + 21)
DECLARE_PMID(kScriptInfoIDSpace, kCaseSensitivePropertyScriptElement,				kTextWalkerServiceProviderPrefix + 22)
DECLARE_PMID(kScriptInfoIDSpace, kChangeTextPropertyScriptElement,					kTextWalkerServiceProviderPrefix + 23)
DECLARE_PMID(kScriptInfoIDSpace, kFindPreferencePropertyScriptElement,				kTextWalkerServiceProviderPrefix + 24)
DECLARE_PMID(kScriptInfoIDSpace, kChangePreferencePropertyScriptElement,			kTextWalkerServiceProviderPrefix + 25)
DECLARE_PMID(kScriptInfoIDSpace, kPrefsParagraphStylePropertyScriptElement,			kTextWalkerServiceProviderPrefix + 26)
DECLARE_PMID(kScriptInfoIDSpace, kPrefsCharacterStylePropertyScriptElement,			kTextWalkerServiceProviderPrefix + 27)
DECLARE_PMID(kScriptInfoIDSpace, kPrefsFillColorPropertyScriptElement,				kTextWalkerServiceProviderPrefix + 28)
DECLARE_PMID(kScriptInfoIDSpace, kPrefsStrokeColorPropertyScriptElement,			kTextWalkerServiceProviderPrefix + 29)
DECLARE_PMID(kScriptInfoIDSpace, kPrefsLanguagePropertyScriptElement,				kTextWalkerServiceProviderPrefix + 30)
DECLARE_PMID(kScriptInfoIDSpace, kKanaSensitivePropertyScriptElement,				kTextWalkerServiceProviderPrefix + 31)
DECLARE_PMID(kScriptInfoIDSpace, kWidthSensitivePropertyScriptElement,				kTextWalkerServiceProviderPrefix + 32)
DECLARE_PMID(kScriptInfoIDSpace, kGrepPropertyScriptElement,						kTextWalkerServiceProviderPrefix + 33)
DECLARE_PMID(kScriptInfoIDSpace, kIncludeLockedStoriesForFindPropertyScriptElement,	kTextWalkerServiceProviderPrefix + 34)
DECLARE_PMID(kScriptInfoIDSpace, kIncludeLockedLayersForFindPropertyScriptElement,	kTextWalkerServiceProviderPrefix + 35)
DECLARE_PMID(kScriptInfoIDSpace, kIncludeHiddenLayersPropertyScriptElement,			kTextWalkerServiceProviderPrefix + 36)
DECLARE_PMID(kScriptInfoIDSpace, kIncludeMasterPagesPropertyScriptElement,			kTextWalkerServiceProviderPrefix + 37)
DECLARE_PMID(kScriptInfoIDSpace, kIncludeFootnotesPropertyScriptElement,			kTextWalkerServiceProviderPrefix + 38)
DECLARE_PMID(kScriptInfoIDSpace, kSearchBackwardsPropertyScriptElement,				kTextWalkerServiceProviderPrefix + 39)
DECLARE_PMID(kScriptInfoIDSpace, kGlyphPropertyScriptElement,						kTextWalkerServiceProviderPrefix + 40)
DECLARE_PMID(kScriptInfoIDSpace, kFindGlyphROSFontGroupPropertyScriptElement,		kTextWalkerServiceProviderPrefix + 41)
DECLARE_PMID(kScriptInfoIDSpace, kChangeTransliterateMethodScriptElement,			kTextWalkerServiceProviderPrefix + 42)
//gap
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeTextOptionsObjectScriptElement,			kTextWalkerServiceProviderPrefix + 51)
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeGrepOptionsObjectScriptElement,			kTextWalkerServiceProviderPrefix + 52)
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeGlyphOptionsObjectScriptElement,		kTextWalkerServiceProviderPrefix + 53)
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeObjectOptionsObjectScriptElement,		kTextWalkerServiceProviderPrefix + 54)
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeTransliterateOptionsObjectScriptElement,kTextWalkerServiceProviderPrefix + 55)
//gap
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeTextPreferencePropertyScriptElement,	kTextWalkerServiceProviderPrefix + 57)
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeGrepPreferencePropertyScriptElement,	kTextWalkerServiceProviderPrefix + 58)
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeGlyphPreferencePropertyScriptElement,	kTextWalkerServiceProviderPrefix + 59)
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeObjectPreferencePropertyScriptElement,	kTextWalkerServiceProviderPrefix + 60)
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeTransliteratePreferencePropertyScriptElement, kTextWalkerServiceProviderPrefix + 61)
DECLARE_PMID(kScriptInfoIDSpace, kFindTextPreferencesObjectScriptElement,			kTextWalkerServiceProviderPrefix + 62)
DECLARE_PMID(kScriptInfoIDSpace, kFindGrepPreferencesObjectScriptElement,			kTextWalkerServiceProviderPrefix + 63)
DECLARE_PMID(kScriptInfoIDSpace, kFindGlyphPreferencesObjectScriptElement,			kTextWalkerServiceProviderPrefix + 64)
DECLARE_PMID(kScriptInfoIDSpace, kFindObjectPreferencesObjectScriptElement,			kTextWalkerServiceProviderPrefix + 65)
DECLARE_PMID(kScriptInfoIDSpace, kFindTransliteratePreferencesObjectScriptElement,	kTextWalkerServiceProviderPrefix + 66)
DECLARE_PMID(kScriptInfoIDSpace, kChangeTextPreferencesObjectScriptElement,			kTextWalkerServiceProviderPrefix + 67)
DECLARE_PMID(kScriptInfoIDSpace, kChangeGrepPreferencesObjectScriptElement,			kTextWalkerServiceProviderPrefix + 68)
DECLARE_PMID(kScriptInfoIDSpace, kChangeGlyphPreferencesObjectScriptElement,		kTextWalkerServiceProviderPrefix + 69)
DECLARE_PMID(kScriptInfoIDSpace, kChangeObjectPreferencesObjectScriptElement,		kTextWalkerServiceProviderPrefix + 70)
DECLARE_PMID(kScriptInfoIDSpace, kChangeTransliteratePreferencesObjectScriptElement,kTextWalkerServiceProviderPrefix + 71)
DECLARE_PMID(kScriptInfoIDSpace, kFindTextPreferencesPropertyScriptElement,			kTextWalkerServiceProviderPrefix + 72)
DECLARE_PMID(kScriptInfoIDSpace, kFindGrepPreferencesPropertyScriptElement,			kTextWalkerServiceProviderPrefix + 73)
DECLARE_PMID(kScriptInfoIDSpace, kFindGlyphPreferencesPropertyScriptElement,		kTextWalkerServiceProviderPrefix + 74)
DECLARE_PMID(kScriptInfoIDSpace, kFindObjectPreferencesPropertyScriptElement,		kTextWalkerServiceProviderPrefix + 75)
DECLARE_PMID(kScriptInfoIDSpace, kFindTransliteratePreferencesPropertyScriptElement,kTextWalkerServiceProviderPrefix + 76)
DECLARE_PMID(kScriptInfoIDSpace, kChangeTextPreferencesPropertyScriptElement,		kTextWalkerServiceProviderPrefix + 77)
DECLARE_PMID(kScriptInfoIDSpace, kChangeGrepPreferencesPropertyScriptElement,		kTextWalkerServiceProviderPrefix + 78)
DECLARE_PMID(kScriptInfoIDSpace, kChangeGlyphPreferencesPropertyScriptElement,		kTextWalkerServiceProviderPrefix + 79)
DECLARE_PMID(kScriptInfoIDSpace, kChangeObjectPreferencesPropertyScriptElement,		kTextWalkerServiceProviderPrefix + 80)
DECLARE_PMID(kScriptInfoIDSpace, kChangeTransliteratePreferencesPropertyScriptElement, kTextWalkerServiceProviderPrefix + 81)
DECLARE_PMID(kScriptInfoIDSpace, kObjectTypePropertyScriptElement,					kTextWalkerServiceProviderPrefix + 82)
DECLARE_PMID(kScriptInfoIDSpace, kPrefsObjectStylePropertyScriptElement,			kTextWalkerServiceProviderPrefix + 83)
DECLARE_PMID(kScriptInfoIDSpace, kSaveFindChangeQueryMethodScriptElement,			kTextWalkerServiceProviderPrefix + 84)
DECLARE_PMID(kScriptInfoIDSpace, kLoadFindChangeQueryMethodScriptElement,			kTextWalkerServiceProviderPrefix + 85)
DECLARE_PMID(kScriptInfoIDSpace, kDeleteFindChangeQueryMethodScriptElement,			kTextWalkerServiceProviderPrefix + 86)
DECLARE_PMID(kScriptInfoIDSpace, kFindWhatPropertyScriptElement,					kTextWalkerServiceProviderPrefix + 87)
DECLARE_PMID(kScriptInfoIDSpace, kChangeToPropertyScriptElement,					kTextWalkerServiceProviderPrefix + 88)
DECLARE_PMID(kScriptInfoIDSpace, kFindCharacterTypePropertyScriptElement,			kTextWalkerServiceProviderPrefix + 89)
DECLARE_PMID(kScriptInfoIDSpace, kChangeCharacterTypePropertyScriptElement,			kTextWalkerServiceProviderPrefix + 90)
DECLARE_PMID(kScriptInfoIDSpace, kPrefsXMLTagPropertyScriptElement,					kTextWalkerServiceProviderPrefix + 91)
DECLARE_PMID(kScriptInfoIDSpace, kAddNothingEnumToFCPropsMetadataScriptElement,		kTextWalkerServiceProviderPrefix + 92)
DECLARE_PMID(kScriptInfoIDSpace, kAddNothingEnumToFCTextPropsMetadataScriptElement,	kTextWalkerServiceProviderPrefix + 93)
DECLARE_PMID(kScriptInfoIDSpace, kAddNothingEnumToFCObjectPropsMetadataScriptElement,kTextWalkerServiceProviderPrefix + 94)
DECLARE_PMID(kScriptInfoIDSpace, kAddNothingEnumToFCTransPropsMetadataScriptElement,kTextWalkerServiceProviderPrefix + 95)
DECLARE_PMID(kScriptInfoIDSpace, kPrefsChangeConditionsModePropertyScriptElement,	kTextWalkerServiceProviderPrefix + 96)
DECLARE_PMID(kScriptInfoIDSpace, kChangeConditionsModeEnumScriptElement,			kTextWalkerServiceProviderPrefix + 97)
DECLARE_PMID(kScriptInfoIDSpace, kPrefsConditionsPropertyScriptElement,				kTextWalkerServiceProviderPrefix + 98)
//gap
DECLARE_PMID(kScriptInfoIDSpace, kSearchModeTypeEnumScriptElement,					kTextWalkerServiceProviderPrefix + 100)
DECLARE_PMID(kScriptInfoIDSpace, kObjectTypeEnumScriptElement,						kTextWalkerServiceProviderPrefix + 101)
DECLARE_PMID(kScriptInfoIDSpace, kFindChangeTransliterateCharacterTypeEnumScriptElement, kTextWalkerServiceProviderPrefix + 102)


//GUIDS
// {96EA6552-0AF2-442f-AA5B-68950D578A8D}
#define kFindPref_CLSID { 0x96ea6552, 0xaf2, 0x442f, { 0xaa, 0x5b, 0x68, 0x95, 0xd, 0x57, 0x8a, 0x8d } }
// {C33267EA-E8B0-11d3-9D01-00C04F99131A}
#define kChangePref_CLSID { 0xc33267ea, 0xe8b0, 0x11d3, { 0x9d, 0x1, 0x0, 0xc0, 0x4f, 0x99, 0x13, 0x1a } }
// {1408EBD9-210E-4a56-8BCE-13D96DF65856}
#define kFindChangeTextOptions_CLSID { 0x1408ebd9, 0x210e, 0x4a56, { 0x8b, 0xce, 0x13, 0xd9, 0x6d, 0xf6, 0x58, 0x56 } }
// {4DDDBCE6-DE1F-49b7-B7FA-212112425A27}
#define kFindChangeGrepOptions_CLSID { 0x4dddbce6, 0xde1f, 0x49b7, { 0xb7, 0xfa, 0x21, 0x21, 0x12, 0x42, 0x5a, 0x27 } }
// {9DFFD927-708D-4afa-A14C-497D44B9BA89}
#define kFindChangeGlyphOptions_CLSID { 0x9dffd927, 0x708d, 0x4afa, { 0xa1, 0x4c, 0x49, 0x7d, 0x44, 0xb9, 0xba, 0x89 } }
// {3C01E0B1-88A2-4214-92D8-176BD17CA2F8}
#define kFindChangeObjectOptions_CLSID { 0x3c01e0b1, 0x88a2, 0x4214, { 0x92, 0xd8, 0x17, 0x6b, 0xd1, 0x7c, 0xa2, 0xf8 } }
// {590D370D-4E05-48b6-84DC-0410A309F04E}
#define kFindChangeTransliterateOptions_CLSID { 0x590d370d, 0x4e05, 0x48b6, { 0x84, 0xdc, 0x4, 0x10, 0xa3, 0x9, 0xf0, 0x4e } }
// {7A344CB5-B629-4046-AFA7-B92EA4047F75}
#define kFindTextPreferences_CLSID { 0x7a344cb5, 0xb629, 0x4046, { 0xaf, 0xa7, 0xb9, 0x2e, 0xa4, 0x4, 0x7f, 0x75 } }
// {D30435E3-522A-4630-BE1D-C29143B3519D}
#define kFindGrepPreferences_CLSID { 0xd30435e3, 0x522a, 0x4630, { 0xbe, 0x1d, 0xc2, 0x91, 0x43, 0xb3, 0x51, 0x9d } }
// {2C4C24E8-92D2-4fb2-AE06-D45292A38CA8}
#define kFindGlyphPreferences_CLSID { 0x2c4c24e8, 0x92d2, 0x4fb2, { 0xae, 0x6, 0xd4, 0x52, 0x92, 0xa3, 0x8c, 0xa8 } }
// {63C1AABA-1537-4f38-AE58-F8A61EB2BDFA}
#define kFindObjectPreferences_CLSID { 0x63c1aaba, 0x1537, 0x4f38, { 0xae, 0x58, 0xf8, 0xa6, 0x1e, 0xb2, 0xbd, 0xfa } }
// {54BBD585-3C47-4b59-90EE-E17AFD4B0EA6}
#define kFindTransliteratePreferences_CLSID { 0x54bbd585, 0x3c47, 0x4b59, { 0x90, 0xee, 0xe1, 0x7a, 0xfd, 0x4b, 0xe, 0xa6 } }
// {24E5C855-0317-4d1f-935E-2FE848CB6B76}
#define kChangeTextPreferences_CLSID { 0x24e5c855, 0x317, 0x4d1f, { 0x93, 0x5e, 0x2f, 0xe8, 0x48, 0xcb, 0x6b, 0x76 } }
// {F1F5E505-B99E-4f26-8152-A2F5962735DF}
#define kChangeGrepPreferences_CLSID { 0xf1f5e505, 0xb99e, 0x4f26, { 0x81, 0x52, 0xa2, 0xf5, 0x96, 0x27, 0x35, 0xdf } }
// {57B06035-7DBB-49f8-8CDB-4C6E293FD755}
#define kChangeGlyphPreferences_CLSID { 0x57b06035, 0x7dbb, 0x49f8, { 0x8c, 0xdb, 0x4c, 0x6e, 0x29, 0x3f, 0xd7, 0x55 } }
// {E4432D00-6797-460f-95D9-2318DFC8A37E}
#define kChangeObjectPreferences_CLSID { 0xe4432d00, 0x6797, 0x460f, { 0x95, 0xd9, 0x23, 0x18, 0xdf, 0xc8, 0xa3, 0x7e } }
// {37D5C1E7-DB19-4e12-9B61-DAEC754294BC}
#define kChangeTransliteratePreferences_CLSID { 0x37d5c1e7, 0xdb19, 0x4e12, { 0x9b, 0x61, 0xda, 0xec, 0x75, 0x42, 0x94, 0xbc } }

#endif // __TextWalkerServiceProviderID__
