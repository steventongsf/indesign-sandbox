//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/interfaces/architecture/SavebackServiceID.h $
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
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================


#ifndef __SavebackServiceID_h__
#define __SavebackServiceID_h__

// Plug-in:
#define kSavebackServicePluginName	"kSavebackService"			// Name of this plug-in.
#define kSavebackServicePrefix	RezLong(0x22C00) 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kSavebackServicePluginID, kSavebackServicePrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kSavebackDialogBoss, kSavebackServicePrefix + 3)
DECLARE_PMID(kClassIDSpace, kShowSavebackDialogCmdBoss, kSavebackServicePrefix + 4)
DECLARE_PMID(kClassIDSpace, kSavebackServiceStartupShutdownBoss, kSavebackServicePrefix + 5)

DECLARE_PMID(kClassIDSpace, kSavebackServiceConversionContextBoss, kSavebackServicePrefix + 7)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 8)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 9)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 10)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 11)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 12)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 13)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 14)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 15)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 16)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 17)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 18)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 19)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 20)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 21)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 22)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 23)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 24)
//DECLARE_PMID(kClassIDSpace, kSavebackServiceBoss, kSavebackServicePrefix + 25)

//MessageId share space with class ids. So just keeping them out of range here. 
//DECLARE_PMID(kMessageIDSpace, kSavebackServiceConnectionUpdateMessage, kSavebackServicePrefix + 100 ) //TODO kaustubh - See if we need to delete this
DECLARE_PMID(kMessageIDSpace, kSavebackConnectionUpdateMessage, kSavebackServicePrefix + 101 ) 



// InterfaceIDs:
DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEUTILS, kSavebackServicePrefix + 0)
DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICECONNECTIONCACHE, kSavebackServicePrefix + 1)
DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEUPDATETRIGGER, kSavebackServicePrefix + 2)
DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEDATA, kSavebackServicePrefix + 3)
DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEIDLETASK, kSavebackServicePrefix + 4)
DECLARE_PMID(kInterfaceIDSpace, IID_IALLOWSAVEBACKSERVICE, kSavebackServicePrefix + 5)
DECLARE_PMID(kInterfaceIDSpace, IID_IOPENEDVIASAVEBACKSERVICE, kSavebackServicePrefix + 6)

DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKCONVERSIONCONTEXT, kSavebackServicePrefix + 8)
DECLARE_PMID(kInterfaceIDSpace, IID_IDOSHOWSAVEASDIALOG, kSavebackServicePrefix + 9)
DECLARE_PMID(kInterfaceIDSpace, IID_IVERSIONSTRINGDATA, kSavebackServicePrefix + 10)
DECLARE_PMID(kInterfaceIDSpace, IID_ICOPYFILEVERSIONINFO, kSavebackServicePrefix + 11)
DECLARE_PMID(kInterfaceIDSpace, IID_IENABLESAVEBACKSERVICEFORALLDOCS, kSavebackServicePrefix + 12)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 13)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 14)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 15)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 16)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 17)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 18)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 19)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 20)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 21)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 22)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 23)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 24)
//DECLARE_PMID(kInterfaceIDSpace, IID_ISAVEBACKSERVICEINTERFACE, kSavebackServicePrefix + 25)


// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, kSavebackServiceUtilsImpl, kSavebackServicePrefix + 1)
DECLARE_PMID(kImplementationIDSpace, kSavebackDialogControllerImpl, kSavebackServicePrefix + 2)
DECLARE_PMID(kImplementationIDSpace, kSavebackServiceIdleTaskImpl, kSavebackServicePrefix + 3)
DECLARE_PMID(kImplementationIDSpace, kSavebackDialogObserverImpl, kSavebackServicePrefix + 4)
DECLARE_PMID(kImplementationIDSpace, kShowSavebackDialogCmdImpl, kSavebackServicePrefix + 5)
DECLARE_PMID(kImplementationIDSpace, kSavebackServiceStartupShutdownImpl, kSavebackServicePrefix + 6)
DECLARE_PMID(kImplementationIDSpace, kSavebackServiceConnectionCacheImpl, kSavebackServicePrefix + 7)
DECLARE_PMID(kImplementationIDSpace, kSavebackServiceDataImpl, kSavebackServicePrefix + 8)

DECLARE_PMID(kImplementationIDSpace, kSavebackConversionContextImpl, kSavebackServicePrefix + 12)
DECLARE_PMID(kImplementationIDSpace, kCopyFileVersionInfoImpl, kSavebackServicePrefix + 13)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 14)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 15)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 16)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 17)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 18)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 19)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 20)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 21)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 22)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 23)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 24)
//DECLARE_PMID(kImplementationIDSpace, kSavebackServiceImpl, kSavebackServicePrefix + 25)


// ActionIDs:
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 0)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 5)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 6)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 7)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 8)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 9)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 10)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 11)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 12)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 13)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 14)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 15)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 16)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 17)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 18)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 19)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 20)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 21)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 22)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 23)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 24)
//DECLARE_PMID(kActionIDSpace, kSavebackServiceActionID, kSavebackServicePrefix + 25)


// WidgetIDs:
DECLARE_PMID(kWidgetIDSpace, kSavebackDialogWidgetID, kSavebackServicePrefix + 2)
DECLARE_PMID(kWidgetIDSpace, kSavebackHeroImageWidgetID, kSavebackServicePrefix + 3)
DECLARE_PMID(kWidgetIDSpace, kConvertButtonWidgetId, kSavebackServicePrefix + 4)
DECLARE_PMID(kWidgetIDSpace, kReportSavebackServiceStatusId, kSavebackServicePrefix + 5)
DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWarningIconId, kSavebackServicePrefix + 6)
//DECLARE_PMID(kWidgetIDSpace, kSavebackConversionWarningWidgetId, kSavebackServicePrefix + 7)
DECLARE_PMID(kWidgetIDSpace, kSavebackServiceSpinningIconWidgetID, kSavebackServicePrefix + 8)
DECLARE_PMID(kWidgetIDSpace, kSavebackSuccessIconWidgetID, kSavebackServicePrefix + 9)
//DECLARE_PMID(kWidgetIDSpace, kConnectionWarningMessageId, kSavebackServicePrefix + 10)
DECLARE_PMID(kWidgetIDSpace, kRetryButtonWidgetId, kSavebackServicePrefix + 11)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 12)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 13)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 14)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 15)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 16)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 17)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 18)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 19)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 20)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 21)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 22)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 23)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 24)
//DECLARE_PMID(kWidgetIDSpace, kSavebackServiceWidgetID, kSavebackServicePrefix + 25)


// Initial data format version numbers
#define kSavebackServiceFirstMajorFormatNumber  RezLong(1)
#define kSavebackServiceFirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kSavebackServiceCurrentMajorFormatNumber kSavebackServiceFirstMajorFormatNumber
#define kSavebackServiceCurrentMinorFormatNumber kSavebackServiceFirstMinorFormatNumber

#define kSavebackServiceStringResourceId 2000

#endif // __SavebackServiceID_h__
