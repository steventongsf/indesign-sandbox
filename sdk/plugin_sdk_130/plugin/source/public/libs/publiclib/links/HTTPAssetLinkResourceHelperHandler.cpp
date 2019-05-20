//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/public/libs/publiclib/links/HTTPAssetLinkResourceHelperHandler.cpp $
//
//  Owner: Sachin Singhal
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
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  All information contained herein is, and remains
//  the property of Adobe Systems Incorporated and its suppliers,
//  if any.  The intellectual and technical concepts contained
//  herein are proprietary to Adobe Systems Incorporated and its
//  suppliers and may be covered by U.S. and Foreign Patents,
//  patents in process, and are protected by trade secret or copyright law.
//  Dissemination of this information or reproduction of this material
//  is strictly forbidden unless prior written permission is obtained
//  from Adobe Systems Incorporated.
//  
//========================================================================================

#include "VCPublicHeaders.h"
#include "HTTPAssetLinkResourceHelperHandler.h"
#include "ITextFragmentLinkFacade.h"
// =============================================================================
// *** HTTPAssetLinkResourceHelperHandler implementation ***
// -----------------------------------------------------------------------------



//========================================================================================
// Constructor
//========================================================================================
HTTPAssetLinkResourceHelperHandler::HTTPAssetLinkResourceHelperHandler(IPMUnknown* boss)
	: inherited(boss)
{
}

//========================================================================================
// Destructor
//========================================================================================
HTTPAssetLinkResourceHelperHandler::~HTTPAssetLinkResourceHelperHandler()
{
}



ILinkResourceHelper::IconStatus HTTPAssetLinkResourceHelperHandler::GetIcon(const UIDRef& ref, const URI& uri, const ILink* link) const
{
	PMRsrcID iconRsrc(kInvalidRsrcID, kLinksPluginID);
	ILinkResourceHelper::IconStatus iconStatus(iconRsrc, ILinkResourceHelper::kIconOk, kHTTPLinkIconPriority);

	InterfacePtr<ILinkResource> linkResource(ref, UseDefaultIID());
	if (linkResource)
	{
		bool16 isMetadata = false;
		bool16 isFPO = linkResource->IsFPO();
		if (link)
		{
			InterfacePtr<const ILinkObject> linkObj(::GetDataBase(link), link->GetObject(), UseDefaultIID());
			if (linkObj)
			{
				isMetadata = Utils<Facade::ITextFragmentLinkFacade>()->IsTextFragmentLinkObject(::GetUIDRef(linkObj));
			}
		}
		
		if (linkResource->GetState() == ILinkResource::kUnknown)
		{
			iconRsrc.fId = kLinksUnknownStatusIconResID;
			iconStatus.fState = ILinkResourceHelper::kIconUnknown;
		}
		else if (linkResource->GetState() == ILinkResource::kMissing)
		{
			iconRsrc.fId = isFPO ? kHTTPFPOLinkMissingIconResID : (isMetadata ? kHTTPMetadataLinkMissingIconResID : kHTTPLinkMissingIconResID);
			iconStatus.fState = ILinkResourceHelper::kIconMissing;
		}
		else if (linkResource->GetState() == ILinkResource::kInaccessible)
		{
			iconRsrc.fId = isFPO ? kHTTPFPOLinkInaccessibleIconResID : (isMetadata ? kHTTPMetadataLinkInaccessibleIconResID : kHTTPLinkInaccessibleIconResID);
			iconStatus.fState = ILinkResourceHelper::kIconInaccessible;
		}
		else if (linkResource->GetState() == ILinkResource::kPending)
			iconRsrc.fId = kLinksPendingStatusIconResID;
		else if (link && link->GetResourceModificationState() == ILink::kResourceModified)
		{
			iconRsrc.fId = isFPO ? kHTTPFPOLinkModifiedIconResID : (isMetadata ? kHTTPMetadataLinkModifiedIconResID : kHTTPLinkModifiedIconResID);
			iconStatus.fState = ILinkResourceHelper::kIconModified;
		}
		else if (linkResource->GetStoreState() == ILinkResource::kCached)
			iconRsrc.fId = kLinksCachedStatusIconResID;
		else if (linkResource->GetStoreState() == ILinkResource::kEmbedded)
			iconRsrc.fId = kLinksEmbeddedStatusIconResID;
		else
		{
			if (isFPO)
			{
				ILinkResource::ResourceDownloadState resourceDownloadState;
				PMReal progress;
				resourceDownloadState = linkResource->GetDownloadProgress(progress);
				switch (resourceDownloadState)
				{
					//TODO: State should come correctly from download manager
				case ILinkResource::kComplete:
					iconRsrc.fId = (linkResource->CanReplaceFPOWithOriginal()) ? kHTTPOriginalAssetAvailableIconResID : kHTTPFPOLinkedResID;
					break;
				case ILinkResource::kInProgress:
					iconRsrc.fId = kHTTPAssetDownloadingIconResID;
					break;
				default:
					iconRsrc.fId = kHTTPFPOLinkedResID;
					break;
				}
			}
			else
				iconRsrc.fId = isMetadata ? kHTTPMetadataLinkedResID : kHTTPLinkedResID;

		}
	}
	iconStatus.fIcon = iconRsrc;
	return iconStatus;
}

ILinkResourceHelper::IconStatus  HTTPAssetLinkResourceHelperHandler::GetPageItemAdornmentIcon(const UIDRef& ref, const URI& uri, const ILink* link) const
{
	PMRsrcID iconRsrc(kInvalidRsrcID, kLinksPluginID);
	ILinkResourceHelper::IconStatus iconStatus(iconRsrc, ILinkResourceHelper::kIconOk, kHTTPLinkIconPriority);

	InterfacePtr<ILinkResource> linkResource(ref, UseDefaultIID());
	if (linkResource)
	{
		bool16 isFPO = linkResource->IsFPO();
		iconStatus.fPriority = (isFPO) ? kHTTPFPOLinkIconPriority : kHTTPLinkIconPriority;

		if (linkResource->GetState() == ILinkResource::kMissing)
		{
			iconRsrc.fId = isFPO ? kPageItemAdornmentHTTPFPOLinkMissingStatusIconRsrcID : kPageItemAdornmentHTTPLinkMissingStatusIconRsrcID;
			iconStatus.fState = ILinkResourceHelper::kIconMissing;
		}

		else if (linkResource->GetState() == ILinkResource::kInaccessible)
		{
			iconRsrc.fId = isFPO ? kPageItemAdornmentHTTPFPOLinkInaccessibleStatusIconRsrcID : kPageItemAdornmentHTTPLinkInaccessibleStatusIconRsrcID;
			iconStatus.fState = ILinkResourceHelper::kIconInaccessible;
		}

		else if (link && link->GetResourceModificationState() == ILink::kResourceModified)
		{
			iconRsrc.fId = isFPO ? kPageItemAdornmentHTTPFPOLinkModifiedIconRsrcID : kPageItemAdornmentHTTPLinkModifiedIconRsrcID;
			iconStatus.fState = ILinkResourceHelper::kIconModified;
		}

		else
		{
			if (isFPO)
			{
				iconRsrc.fId = (linkResource->CanReplaceFPOWithOriginal()) ? kPageItemAdornmentHTTPOriginalAssetAvailableIconRsrcID : kPageItemAdornmentHTTPFPOLinkedIconRsrcID;
			}
			else
				iconRsrc.fId = kPageItemAdornmentHTTPLinkedIconRsrcID;

		}
	}
	iconStatus.fIcon = iconRsrc;
	return iconStatus;
}

bool HTTPAssetLinkResourceHelperHandler::CanDoDoubleClickInaccessibleAction() const
{
	return false;
}
void HTTPAssetLinkResourceHelperHandler::DoubleClickInaccessibleAction() const
{
	return;
}

bool HTTPAssetLinkResourceHelperHandler::IsInaccessibleActionSupportedURIScheme() const
{
	return false;
}

void HTTPAssetLinkResourceHelperHandler::InaccessibleActionOnOpenDoc() const
{ 
	return; 
}

PMString  HTTPAssetLinkResourceHelperHandler::InaccessibleLinksWarningMessage(int32 count) const
{
	return ""; 
}

void HTTPAssetLinkResourceHelperHandler::ReplaceWithOriginalAsset() const
{ 
	return; 
}