//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/snapshot/SnapResources.r $
//  
//  Owner: Adobe Developer Technologies
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
//  This is the resource file that provides the platform-specific resource information.
//  
//  too many nested include in .r seems to cause Xcode rez to puke, so bring the content of SnapRezDef.h in to this level
//  
//========================================================================================

//===========================
//  #include "SnapRezDefs.h"
//===========================

#include "SDKDef.h"

#define kIconInfoResourceID				kSDKIconInfoResourceID
#define kIconSnapResource				135
#define kCursorSnapResource				145

#ifdef MACINTOSH
// Macintosh specific resources: ---------------------------------------------------------

	#include <CoreServices/CoreServices.r>

	
	data 'icl4' (kIconSnapResource, "snap_icon") 
{
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 FFFF FFFF FFFF FFF0 0000 0000"            /* ....’’’’’’’š.... */
	$"0000 0000 F000 0000 0000 00FF 0000 0000"            /* ....š......’.... */
	$"0000 0000 F000 DDD0 00DD D0FF 0000 0000"            /* ....š.ŻŠ.ŻŠ’.... */
	$"0000 0000 F00D CCCD 00DD D0FF 0000 0000"            /* ....šĀĢĶ.ŻŠ’.... */
	$"0000 0000 F0DC CCCC D000 00FF 0000 0000"            /* ....šÜĢĢŠ..’.... */
	$"0000 0000 F0DC CCCC D000 00FF 0000 0000"            /* ....šÜĢĢŠ..’.... */
	$"0000 0000 F0DC CCCC D000 00FF 0000 0000"            /* ....šÜĢĢŠ..’.... */
	$"0000 0000 F00D CCCD 0000 00FF 0000 0000"            /* ....šĀĢĶ...’.... */
	$"0000 0000 F000 DDD0 0000 00FF 0000 0000"            /* ....š.ŻŠ...’.... */
	$"0000 0000 F000 0000 0000 00FF 0000 0000"            /* ....š......’.... */
	$"0000 0000 FFFF FFFF FFFF FFFF 0000 0000"            /* ....’’’’’’’’.... */
	$"0000 0000 00FF FFFF FFFF FFFF 0000 0000"            /* .....’’’’’’’.... */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
};

	data 'icl8' (kIconSnapResource, "snap_icon") 
{
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 FFFF FFFF FFFF FFFF"            /* ........’’’’’’’’ */
	$"FFFF FFFF FFFF FF00 0000 0000 0000 0000"            /* ’’’’’’’......... */
	$"0000 0000 0000 0000 FF00 0000 0000 0000"            /* ........’....... */
	$"0000 0000 0000 FFFF 0000 0000 0000 0000"            /* ......’’........ */
	$"0000 0000 0000 0000 FF00 0000 8181 8100"            /* ........’.... */
	$"0000 8181 8100 FFFF 0000 0000 0000 0000"            /* ...’’........ */
	$"0000 0000 0000 0000 FF00 0081 F7F7 F781"            /* ........’..÷÷÷ */
	$"0000 8181 8100 FFFF 0000 0000 0000 0000"            /* ...’’........ */
	$"0000 0000 0000 0000 FF00 81F7 F7F7 F7F7"            /* ........’.÷÷÷÷÷ */
	$"8100 0000 0000 FFFF 0000 0000 0000 0000"            /* .....’’........ */
	$"0000 0000 0000 0000 FF00 81F7 F7F7 F7F7"            /* ........’.÷÷÷÷÷ */
	$"8100 0000 0000 FFFF 0000 0000 0000 0000"            /* .....’’........ */
	$"0000 0000 0000 0000 FF00 81F7 F7F7 F7F7"            /* ........’.÷÷÷÷÷ */
	$"8100 0000 0000 FFFF 0000 0000 0000 0000"            /* .....’’........ */
	$"0000 0000 0000 0000 FF00 0081 F7F7 F781"            /* ........’..÷÷÷ */
	$"0000 0000 0000 FFFF 0000 0000 0000 0000"            /* ......’’........ */
	$"0000 0000 0000 0000 FF00 0000 8181 8100"            /* ........’.... */
	$"0000 0000 0000 FFFF 0000 0000 0000 0000"            /* ......’’........ */
	$"0000 0000 0000 0000 FF00 0000 0000 0000"            /* ........’....... */
	$"0000 0000 0000 FFFF 0000 0000 0000 0000"            /* ......’’........ */
	$"0000 0000 0000 0000 FFFF FFFF FFFF FFFF"            /* ........’’’’’’’’ */
	$"FFFF FFFF FFFF FFFF 0000 0000 0000 0000"            /* ’’’’’’’’........ */
	$"0000 0000 0000 0000 0000 FFFF FFFF FFFF"            /* ..........’’’’’’ */
	$"FFFF FFFF FFFF FFFF 0000 0000 0000 0000"            /* ’’’’’’’’........ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
};

	data 'ICN#' (kIconSnapResource, "snap_icon") 
{
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 00FF FE00 0080 0300"            /* .........’ž.... */
	$"008E 3B00 0091 3B00 00A0 8300 00A0 8300"            /* .;..;.. .. . */
	$"00A0 8300 0091 0300 008E 0300 0080 0300"            /* . .......... */
	$"00FF FF00 003F FF00 0000 0000 0000 0000"            /* .’’..?’......... */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 00FF FE00 0080 0300"            /* .........’ž.... */
	$"008E 3B00 0091 3B00 00A0 8300 00A0 8300"            /* .;..;.. .. . */
	$"00A0 8300 0091 0300 008E 0300 0080 0300"            /* . .......... */
	$"00FF FF00 003F FF00 0000 0000 0000 0000"            /* .’’..?’......... */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
};

	data 'CURS' (kCursorSnapResource, "snap_cursor", preload) 
{
	$"FFFE 8003 8E3B 913B A083 A083 A083 9103"            /* ’ž.;;   . */
	$"8E03 8003 FFFF 3FFF 0000 0000 0000 0000"            /* ..’’?’........ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000"                                          /* .... */
};

#else
// Windows specific resources: ---------------------------------------------------------

#endif // else MACINTOSH

// End, SnapshotResources.r.


