//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/framelabel/IFrmLblDataSuite.h $
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
//========================================================================================

#pragma once
#ifndef __IFrmLblDataSuite_h__
#define __IFrmLblDataSuite_h__

#include "IPMUnknown.h"
#include "FrmLblID.h"

struct FrmLblInfo;

/** IFrmLblDataSuite defines the interface for this plug-ins selection suite.

    
    @ingroup framelabel
*/
class IFrmLblDataSuite : public IPMUnknown
{
public:
	enum {kDefaultIID = IID_IFRMLBLDATASUITE };

	/**	Get properties of the frame label on the selected item(s).
	 * 	@param frmLblInfo OUT The properties of frame label.
	 * 	@return ErrorCode kSuccess if success, specific error code otherwise.
	 */
	virtual ErrorCode GetFrameLabelProperties(FrmLblInfo& labelInfo) = 0;

	/**	Set the frame label properties on the selected item(s).
	 * 	@param frmLblInfo IN The frame label properties.
	 * 	@return ErrorCode kSuccess if success, specific error code otherwise.
	 */
	virtual ErrorCode UpdateFrameLabelProperties(const FrmLblInfo& labelInfo) = 0;

};

#endif // __IFrmLblDataSuite_h__
