//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/includes/MInterfaceFontInfo.h $
//  
//  Owner: Michael Burbidge
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
#ifndef __MInterfaceFontInfo_h__
#define __MInterfaceFontInfo_h__

#include "CInterfaceFontInfo.h"
#include "PMString.h"

class IGraphicsContext;

/**	Macintosh platform specific implementation of UI font structure. Note that this can only be used with fonts that are installed
	in the system. Fonts in Adobe fonts folders can't be used to draw UI elements.

	@see IUIFontSpec for the interface which allows widgets to override their default UI font.
	@see IInterfaceFonts for the main interface to get InterfaceFontInfo from an interface font IDs
	@see DrawStringUtils.h for the main routines that use InterfaceFontInfo
*/
class DV_WIDGET_DECL InterfaceFontInfo : public CInterfaceFontInfo
{
public:
	InterfaceFontInfo();
	InterfaceFontInfo(const InterfaceFontInfo& other);
	InterfaceFontInfo(const PMString& fontName, const int16& pts, const int16& attrs);
	~InterfaceFontInfo();
	
	InterfaceFontInfo& operator=(const InterfaceFontInfo& other);
	
	/** Get the font size, in points */
	int16					GetFontSize() const;

	/** Get the font attributes. Should be one of {kInterfaceFontPlain, kInterfaceFontBold, kInterfaceFontItalic} */
	int16					GetFontAttributes() const;
	
    /** OBSOLETE: Get the MacOS font number. Can be passed to the QuickDraw call TextFont() 
        Return value is always kInvalidFontFamily. */
	int16					GetFontNumber() const;
    
	/** Get some metrics about the font 
		@param gc the graphics context to use to set up drawing environment to get font information.
		@param ascent OUT the ascent value of the font, as reported by the OS.
		@param descent OUT the descent value of the font, as reported by the OS.
		@param leading OUT the leading value of the font, as reported by the OS.
	*/
	void					GetMetrics(IGraphicsContext* gc, int16& ascent, int16& descent, int16& leading) const;

private:
	int16					fFontSize;
	int16					fFontAttributes;
	bool16				    fIsSystemFont;
};

#endif
