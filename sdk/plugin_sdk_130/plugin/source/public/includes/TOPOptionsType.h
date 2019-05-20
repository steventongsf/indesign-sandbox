//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/TOPOptionsType.h $
//  
//  Owner: Yves Carbonneaux
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
//  This interface contains declarations used both by the ITOPOptionsCmdData
//  interface and by the TOPOptionsDatas class.
//  
//========================================================================================

#pragma once
#ifndef TOPOPTIONSTYPE_h
#define TOPOPTIONSTYPE_h


	//
	typedef enum {
		kUndefinedType = 0,  // Don't use this value. If used, it will be replaced by default value
		kRainbowType,		// Default
		kSkewType,
		k3DRibbonType,
		kStairStepType,
		kGravityType
	} EffectType;

	//
	typedef enum {
		kUndefinedTextAlign = 0,  // Don't use this value. If used, it will be replaced by default value
		kTextAlignAscender,
		kTextAlignDescender,
		kTextAlignCenter,
		kTextAlignBaseline,						// Default
		kTextAlignAboveRightEmbox,		// Above OR Right of the em box, depending on vertical or horizontal text
		kTextAlignBelowLeftEmbox,
		kTextAlignAboveRightICFBox,
		kTextAlignBelowLeftICFBox
	} TextAlignType;

	//
	typedef enum {
		kUndefinedPathAlign = 0,  // Don't use this value. If used, it will be replaced by default value
		kPathAlignTop,
		kPathAlignBottom,
		kPathAlignCenter	//Default
	} PathAlignType;



#endif /* TOPOPTIONSTYPE_h */
