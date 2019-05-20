//========================================================================================
//  
//  $File: //depot/devtech/14.0/devtools/idmltools/src/com/adobe/idml/PackageException.java $
//  
//  Owner: Joe Stinson
//  
//  $Author: praverma $
//  
//  $DateTime: 2018/09/07 11:54:17 $
//  
//  $Revision: #1 $
//  
//  $Change: 1031661 $
//  
//  ADOBE CONFIDENTIAL
//  
//  Copyright 2008 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

package com.adobe.idml;

/** 
 * A simple Exception subclass thrown by several IDMLTools methods.
 */
public class PackageException extends Exception {
	
	/**
	 * @param errMessage The message to be displayed with the Exception.
	 */
	public PackageException(String errMessage)
	{
		super(errMessage);
	}

}
