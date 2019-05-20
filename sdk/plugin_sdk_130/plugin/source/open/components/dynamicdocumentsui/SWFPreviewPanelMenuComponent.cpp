//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFPreviewPanelMenuComponent.cpp $
//  
//  Owner: Yeming Liu
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

#include "VCPlugInHeaders.h"

// ----- Interface files -----

#include "IActionStateList.h"
#include "IActiveContext.h"
#include "IApplication.h"
#include "IBoolData.h"
#include "IDialog.h"
#include "IDialogMgr.h"
#include "IDocument.h"
#include "IPanelControlData.h"
#include "ISelectableDialogSwitcher.h"
#include "IFlashSWFExportFacade.h"
#include "ISWFExportPreferences.h"
#include "ISWFPreviewPreferences.h"
#include "ISubject.h"
#include "IUIDData.h"
#include "IUIDListData.h"
#include "IWorkspace.h"

// ----- Include files -----

#include "CActionComponent.h"
#include "CoreResTypes.h"
#include "DynamicDocumentsUIDefs.h"
#include "LocaleSetting.h"
#include "RsrcSpec.h"

// ----- Utility files -----

#include "DynamicDocumentsUIUtils.h"
#include "IPalettePanelUtils.h"
#include "ISelectionUtils.h"
#include "PreferenceUtils.h"

// ----- ID files -----

#include "DynamicDocumentsUIID.h"
#include "GenericID.h"

//========================================================================================
// CLASS SWFPreviewPanelMenuComponent
//========================================================================================
class SWFPreviewPanelMenuComponent : public CActionComponent
{
	public:
		SWFPreviewPanelMenuComponent(IPMUnknown *boss);
		
		virtual void	UpdateActionStates(IActiveContext* ac, IActionStateList *listToUpdate, GSysPoint mousePoint, IPMUnknown* widget);
		virtual void	DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget);
};

CREATE_PMINTERFACE(SWFPreviewPanelMenuComponent, kSWFPreviewPanelMenuComponentImpl)

//---------------------------------------------------------------
// Constructor
//---------------------------------------------------------------
SWFPreviewPanelMenuComponent::SWFPreviewPanelMenuComponent(IPMUnknown *boss) :
	CActionComponent(boss)
{
}

//---------------------------------------------------------------
// SWFPreviewPanelMenuComponent::UpdateActionStates()
//---------------------------------------------------------------
void SWFPreviewPanelMenuComponent::UpdateActionStates(IActiveContext* ac, IActionStateList *updateList, GSysPoint mousePoint, IPMUnknown* widget)
{		
	int32 count = updateList->Length();

	for (int32 i = 0; i < count; ++i)
	{
		ActionID nthActionID = updateList->GetNthAction(i);
		switch (nthActionID.Get())
		{
			case kSWFPreviewSelectionActionID:
			{	
				InterfacePtr<ISelectionManager> iSelectMgr(Utils<ISelectionUtils>()->QueryViewSelectionManager(ac->GetContextView()));
				if (!iSelectMgr || !(iSelectMgr->SelectionExists (kNewLayoutSelectionBoss, ISelectionManager::kUniqueSelection))) 
					updateList->SetNthActionState(i, kDisabled_Unselected);
				else
					updateList->SetNthActionState(i, kEnabledAction);
				
				break;
			}
			case kSWFPreviewSaveSettingsActionID:
			{				
				updateList->SetNthActionState(i, kEnabledAction);
				break;
			}

			case kSWFTestInBrowserActionID:
			{
				updateList->SetNthActionState(i, kEnabledAction);
				break;
			}

			default:
			{
				ASSERT("Unknown action!");
				break;
			}
		}
	}
}

//---------------------------------------------------------------
// SWFPreviewPanelMenuComponent::DoAction()
//---------------------------------------------------------------
void SWFPreviewPanelMenuComponent::DoAction(IActiveContext* ac, ActionID id, GSysPoint mousePoint, IPMUnknown* widget)
{
	switch (id.Get()) 
	{
		case kSWFPreviewDocumentActionID:
		{
			ddui_utils::DoPreview(ISWFPreviewPreferences::kPreviewWholeDocument);
			break;
		}
		case kSWFPreviewSpreadActionID:
		{
			ddui_utils::DoPreview(ISWFPreviewPreferences::kPreviewCurrentSpread);
			break;
		}
		case kSWFPreviewSelectionActionID:
		{
			ddui_utils::DoPreview(ISWFPreviewPreferences::kPreviewCurrentSelection);
			break;
		}
		case kSWFPreviewSaveSettingsActionID:
		{	
			// Bring up export SWF dialog.
			InterfacePtr<IApplication> iApp(GetExecutionContextSession()->QueryApplication());
			InterfacePtr<IDialogMgr> iDialogMgr(iApp, IID_IDIALOGMGR);
			IDialog* iDialog = iDialogMgr->CreateNewDialog(RsrcSpec(LocaleSetting::GetLocale(), kDynamicDocumentsUIPluginID, kViewRsrcType, kSWFExportDialogRsrcID),
								IDialog::kMovableModal);

			if (iDialog)
			{
				InterfacePtr<IWindow> iWindow(iDialog, UseDefaultIID()); 

				IControlView *dialogPanel = iDialog->GetDialogPanel();

				// initialize the dialog preferences from the application workspace
				InterfacePtr<IWorkspace> ws(GetExecutionContextSession()->QueryWorkspace());
				InterfacePtr<ISWFExportPreferences> iSWFPrefs(dialogPanel, UseDefaultIID());
				InterfacePtr<IPageRange> iSWFPageRange(dialogPanel, IID_ISWFEXPORTPAGERANGE);
				if (ws && iSWFPrefs && iSWFPageRange)
				{
					// copy the application SWF export preferences to the dialog
					Utils<Facade::IFlashSWF_ExportFacade>()->GetWorkspacePreferences(ws, iSWFPrefs);

					// copy the application Page Range info to the dialog
					PMString pageRange;
					IPageRange::RangeFormat pageRangeFormat(IPageRange::kAllPages);
					Utils<Facade::IFlashSWF_ExportFacade>()->GetPageRangeInfo(ws, pageRange, pageRangeFormat);
					iSWFPageRange->SetPageRange(pageRange);
					iSWFPageRange->SetPageRangeFormat(pageRangeFormat);
				}

				PMString windowTitle("kPreviewSettings", PMString::kTranslateDuringCall);
				iWindow->SetTitle(windowTitle);

				// Set data notifying dialog that we are saving preview settings, therefore don't need to fire export command. 
				InterfacePtr<IBoolData> iSavePreviewSettings(dialogPanel, IID_ISAVEPREVIEWSETTINGS); 
				iSavePreviewSettings->Set(kTrue);

				// clear out any selection data that may be left by a previous SWF export selection
				InterfacePtr<IUIDListData> iUIDListData(dialogPanel, UseDefaultIID());
				if (iUIDListData)
				{
					UIDList *noSelectedItems = new UIDList();
					iUIDListData->Set(noSelectedItems);
				}

				// switch to the General panel
				InterfacePtr<ISelectableDialogSwitcher> iDialogSwitcher(dialogPanel, UseDefaultIID());
				if (iDialogSwitcher)
				{
					iDialogSwitcher->SetDialogServiceID(kSWFExportSelectableDialogService);
					iDialogSwitcher->SwitchDialogPanelByID(kSWFExportGeneralParentWidgetId);
				}

				iDialog->Open();
				iDialog->WaitForDialog();
			}
			break;
		}
		case kSWFTestInBrowserActionID:
		{	
			ddui_utils::PreviewSWFInBrowser(ac);
			break;
		}
		default:
			ASSERT_FAIL("Asked to do unknown action");
			break;
	}
}

