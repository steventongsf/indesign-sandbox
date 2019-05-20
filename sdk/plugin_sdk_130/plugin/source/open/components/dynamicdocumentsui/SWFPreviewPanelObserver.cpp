//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/open/components/dynamicdocumentsui/SWFPreviewPanelObserver.cpp $
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

// ----- Interfaces -----

#include "IActiveContext.h"
#include "IAnimationAttributeSuite.h"
#include "IBoolData.h"
#include "IControlView.h"
#include "IDocument.h"
#include "IHierarchy.h"
#include "ILayoutControlData.h"
#include "IFlashPlayerController.h"
#include "IPanelControlData.h"
#include "ISubject.h"
#include "IWorkspace.h"
#include "ISWFExportPreferences.h"
#include "IFlashSWFExportFacade.h"
#include "IWidgetParent.h"
#include "ISpread.h"
#include "ISWFPreviewPreferences.h"
#include "IPageList.h"
#include "IUIDData.h"
#include "IControlViewCmdData.h"
#include "ISpreadList.h"
#include "ITextControlData.h"
#include "IStringData.h"
#include "ITriStateControlData.h"
#include "ISysFileData.h"
#include "IMasterSpread.h"
#include "IURIUtils.h"

// ----- Includes -----

#include "KeyStates.h"
#include "SelectionObserver.h"
#include "UIDList.h"
#include "K2Vector.h"

// ----- Utility files -----

#include "CoreFileUtils.h"
#include "IDynDocsPublicUtils.h"
#include "FileUtils.h"
#include "Utils.h"
#include "ISelectionUtils.h"
#include "FileUtility.h"
#include "PlatformFolderTraverser.h"
#include "DynamicDocumentsUIUtils.h"

// ----- ID.h files -----

#include "DynamicDocumentsUIID.h"
#include "GenericID.h"

static const int32 kFrameToSpreadAdjustment = 1;
static char const * const kPreviewSWFDefaultName = "IDSWFPreview.swf";

//========================================================================================
// class SWFPreviewPanelObserver
//========================================================================================
class SWFPreviewPanelObserver : public ActiveSelectionObserver 
{
		typedef ActiveSelectionObserver inherited;

		IControlView* fCurrentLayoutView;
		int32 fCurrentPreviewFrameIndex;
		UIDList fPreviewSpreadList;
		bool fIsLoaded;
		IDFile fExistingPreviewFile;	// Caching the preview file for reload

		void AttachDetachButtonWidget(WidgetID const &widgetID, bool const &bAttach);
		void AttachDetachPanelPreviewModeChangeMessage(bool const &bAttach);
		void EnableDisableNavigatorButtons(bool const &bEnablePrevious, bool const &bEnableNext);
										   
		void SelectDeselectPreviewModeButtons(bool const &bSelectPreviewDocument, bool const &bSelectPreviewSpread, bool const &bSelectPreviewSelection);

		void UpdatePreviewButton();
		void UpdatePreviewModeWidgets();
		void UpdateNavigationWidgets(int32 const &frameIndex = -1);
		void UpdateCurrentPageWidget(int32 const &frameIndex);
		void UpdatePreviewProxy(bool const &bReload);
		void UpdateSWFPreferences();
		void ClearTempPreviewFiles();
		bool ShowWarningIcon();
		int32 GetCurrentPreviewFrameIndex();
		void SetCurrentPreviewFrameIndex(int32 const &frameIndex);
		void CacheSpreadListInfo();
		
		// Set up/tear down the preview widget
		void InitializePreview();
		void TearDownPreview();
		
		void UpdateWidget(WidgetID const &widgetID, bool const &bEnable);

		// The following functions are used for hooking up with Flash.
		void LoadPreviewSWF(IDFile const &file);
		void UnloadPreviewSWF();

		static PMString PreviewSWFCallback(const PMString& request, void* refPtr);

		void ParseXMLRequest(const PMString& request, PMString& methodName, int32& spreadIndex, PMString& messageStr) const;
		void SendSpreadIndexToSWF();

		inline InterfacePtr<IFlashPlayerController> GetFlashPlayer() const
		{
			InterfacePtr<IPanelControlData const> panelControlData(this, UseDefaultIID());

			return InterfacePtr<IFlashPlayerController>(panelControlData->FindWidget(kSWFPreviewProxyWidgetID), UseDefaultIID());
		}
	
	public:
		SWFPreviewPanelObserver(IPMUnknown *boss);
		virtual ~SWFPreviewPanelObserver();

	protected:
		virtual void	AutoAttach();
		virtual void	AutoDetach();

		virtual void	Update(const ClassID& theChange, ISubject* theSubject, const PMIID& protocol, void* changedBy);	
		virtual void    HandleSelectionChanged(const ISelectionMessage*); 
};

CREATE_PMINTERFACE(SWFPreviewPanelObserver, kSWFPreviewPanelObserverImpl)

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::SWFPreviewPanelObserver
//----------------------------------------------------------------------------------------

SWFPreviewPanelObserver::SWFPreviewPanelObserver(IPMUnknown *boss) :
	inherited (boss), 
	fCurrentLayoutView(nil),
	fCurrentPreviewFrameIndex(-1),
	fPreviewSpreadList(),
	fIsLoaded(false),
	fExistingPreviewFile()
{
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::~SWFPreviewPanelObserver
//----------------------------------------------------------------------------------------

SWFPreviewPanelObserver::~SWFPreviewPanelObserver()
{
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::AutoAttach()
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::AutoAttach()
{
	inherited::AutoAttach();
	
	//
	// Attach to all the widgets on this panel
	//
	this->AttachDetachButtonWidget(kSWFPreviewButtonWidgetID, true/*attach*/);
	this->AttachDetachButtonWidget(kSWFStopButtonWidgetID, true/*detach*/);

	this->AttachDetachButtonWidget(kSWFPreviewPreviousButtonWidgetID, true/*attach*/);
	this->AttachDetachButtonWidget(kSWFPreviewNextButtonWidgetID, true/*attach*/);

	this->AttachDetachButtonWidget(kSWFPreviewSelectionButtonWidgetID, true/*attach*/);
	this->AttachDetachButtonWidget(kSWFPreviewSpreadButtonWidgetID, true/*attach*/);
	this->AttachDetachButtonWidget(kSWFPreviewDocumentButtonWidgetID, true/*attach*/);

	this->AttachDetachPanelPreviewModeChangeMessage(true/*attach*/);

	//
	// Update widgets
	//
	this->UpdateNavigationWidgets(-1);
	this->UpdateCurrentPageWidget(-1);

	//
	// Update preview mode widgets
	//
	this->UpdatePreviewModeWidgets();

	//
	// Update warning widget
	//
	InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());
	IControlView* iWarningIconView = iPanelControlData->FindWidget(kSWFPreviewWarningButtonWidgetID);
	iWarningIconView->HideView();

	// Delay the InitializePreview() until it's to be used the first time.
	//InitializePreview();

	//	Hide instead.
	IControlView* iPreivewPlayerWidget = iPanelControlData->FindWidget(kSWFPreviewProxyWidgetID);
	iPreivewPlayerWidget->HideView();
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::InitializePreview()
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::InitializePreview()
{
	InterfacePtr<IFlashPlayerController> player = GetFlashPlayer();
	
	if (player)
	{		
		IDFile flashExportFolder; 
		PMString subFolderName("kSWFPreviewFolderTextKey", PMString::kTranslateDuringCall);
		
		if (FileUtils::GetPresetsFolder(&flashExportFolder, subFolderName, PMLocaleId()))	
		{
			AString path = flashExportFolder.GetPath().GetPath();
            PMString componentDirectory(path.GrabWString(), path.UTF16Count());
			IFlashPlayerController::LoadContentParams loadContentParams;
			loadContentParams.fLoadSynchronously = kTrue;
			loadContentParams.fContentType = IFlashPlayerController::kComponentContentType;
			loadContentParams.fUrl = componentDirectory;
			if (player->LoadContent(loadContentParams) == kSuccess)
			{
				fIsLoaded = true;

				// Attach the app function callback to the Flash Player
				ErrorCode err1 = player->SetAppFunctionCallback(&PreviewSWFCallback, (void*)this);
				ASSERT_MSG( err1 == kSuccess, "SWFpreviewPanelObserver - SetAppFunctionCallback for PreviewSWFCallback() failed");
			}
		}
	}
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::AutoDetach()
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::AutoDetach()
{	
	//
	// Detach of all the widgets on this panel
	//
	this->AttachDetachButtonWidget(kSWFPreviewButtonWidgetID, false/*detach*/);
	this->AttachDetachButtonWidget(kSWFStopButtonWidgetID, false/*detach*/);

	this->AttachDetachButtonWidget(kSWFPreviewPreviousButtonWidgetID, false/*attach*/);
	this->AttachDetachButtonWidget(kSWFPreviewNextButtonWidgetID, false/*attach*/);

	this->AttachDetachButtonWidget(kSWFPreviewSelectionButtonWidgetID, false/*attach*/);
	this->AttachDetachButtonWidget(kSWFPreviewSpreadButtonWidgetID, false/*attach*/);
	this->AttachDetachButtonWidget(kSWFPreviewDocumentButtonWidgetID, false/*attach*/);

	this->AttachDetachPanelPreviewModeChangeMessage(false/*attach*/);

	//
	// Detach from flash callback.
	//
	TearDownPreview();
	
	fCurrentLayoutView = nil;

	inherited::AutoDetach();
	
	//
	// Clear temp files
	//
	this->ClearTempPreviewFiles();
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::TearDownPreview()
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::TearDownPreview()
{
	if (fIsLoaded)
	{
		InterfacePtr<IFlashPlayerController> player = GetFlashPlayer();

		if (player)
		{
			// Unload swf to stop movie/sound before close the panel. This is to address bug #2393417.
			UnloadPreviewSWF();

			player->SetAppFunctionCallback(nil, nil);	// don't point to me anymore is to unload

			fIsLoaded = false;
		}
	}
}

void SWFPreviewPanelObserver::UnloadPreviewSWF()
{
	if (fIsLoaded)
	{
		InterfacePtr<IFlashPlayerController> player = GetFlashPlayer();

		if (player)
		{
			PMString request, result;

			request.Append("<invoke name=\"unloadSWF\" returntype=\"xml\">");
			request.Append("<arguments/>");
			request.Append("</invoke>");
			
			player->CallMovieFunction(request, result);
		}
	}
	
	UpdateWidget(kSWFStopButtonWidgetID, false);
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::AttachDetachButtonWidget()
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::AttachDetachButtonWidget(WidgetID const &widgetID, bool const &bAttach)
{	
	InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());

	IControlView* buttonWidget = iPanelControlData->FindWidget(widgetID);
	InterfacePtr<ISubject> iButtonSubject(buttonWidget, IID_ISUBJECT);
	if (iButtonSubject)
	{
		if (bAttach && !iButtonSubject->IsAttached( this,  IID_ITRISTATECONTROLDATA, IID_IOBSERVER))
			iButtonSubject->AttachObserver( this,  IID_ITRISTATECONTROLDATA, IID_IOBSERVER);
		else if (!bAttach && iButtonSubject->IsAttached( this,  IID_ITRISTATECONTROLDATA, IID_IOBSERVER))
			iButtonSubject->DetachObserver( this,  IID_ITRISTATECONTROLDATA, IID_IOBSERVER);
		if (bAttach && !iButtonSubject->IsAttached( this,  IID_ISWFUPDATEPREVIEWMESSAGE, IID_IOBSERVER))
			iButtonSubject->AttachObserver( this,  IID_ISWFUPDATEPREVIEWMESSAGE, IID_IOBSERVER);
		else if (!bAttach && iButtonSubject->IsAttached( this,  IID_ISWFUPDATEPREVIEWMESSAGE, IID_IOBSERVER))
			iButtonSubject->DetachObserver( this,  IID_ISWFUPDATEPREVIEWMESSAGE, IID_IOBSERVER);
	}
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::AttachDetachPanelPreviewModeChangeMessage()
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::AttachDetachPanelPreviewModeChangeMessage(bool const &bAttach)
{
	//
	// Attach/Detach to the preview mode message that is sent from the flyout menu when preview mode is changed.
	//
	InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());
	InterfacePtr<ISubject> iPanelSubject(iPanelControlData, UseDefaultIID());

	if (iPanelSubject)
	{
		if (bAttach && !iPanelSubject->IsAttached( this,  IID_ISWFPREVIEWMODECHANGEMESSAGE, IID_IOBSERVER))
			iPanelSubject->AttachObserver( this,  IID_ISWFPREVIEWMODECHANGEMESSAGE, IID_IOBSERVER);
		else if (!bAttach && iPanelSubject->IsAttached( this,  IID_ISWFPREVIEWMODECHANGEMESSAGE, IID_IOBSERVER))
			iPanelSubject->DetachObserver( this,  IID_ISWFPREVIEWMODECHANGEMESSAGE, IID_IOBSERVER);
	}
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::HandleSelectionChanged
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::HandleSelectionChanged(const ISelectionMessage* inSelMsg)
{	
	UpdatePreviewButton();

	//
	// Clear navigate buttons and static text widget if there is no doc or 
	// current layout view is different from the context view.
	//
	IActiveContext *ac = GetExecutionContextSession()->GetActiveContext();
	if (!ac || (ac->GetContextDocument() == nil) || (ac->GetContextView() == nil) || (ac->GetContextView() != fCurrentLayoutView))
	{		
		this->UpdateNavigationWidgets(-1);
		this->UpdateCurrentPageWidget(-1);

		// Hide preview proxy in no-doc state or switch to different context.
		InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());
		IControlView* iProxyView = iPanelControlData->FindWidget(kSWFPreviewProxyWidgetID);
 		iProxyView->HideView();

		UnloadPreviewSWF();

		// Switch selection should clear the existing preview file and the associated spread list for the file.
		fExistingPreviewFile = IDFile();
		fPreviewSpreadList.Clear();

		// Hide warning icon if context is switched.
		IControlView* iWarningIconView = iPanelControlData->FindWidget(kSWFPreviewWarningButtonWidgetID);
		iWarningIconView->HideView();
	}
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::Update
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::Update(const ClassID& theChange, ISubject* theSubject, const PMIID& protocol, void* changedBy)
{
	switch (protocol.Get())
	{	
		case IID_ISWFPREVIEWMODECHANGEMESSAGE:
		{
			if (theChange.Get() == kSWFPreviewModeChangeMessage)
				this->UpdatePreviewModeWidgets();

			break;
		}
		case IID_ISWFUPDATEPREVIEWMESSAGE:
		case IID_ITRISTATECONTROLDATA:	// click the navigation buttons
		{
			// If this is not layout view (e.g., story edit mode or note edit mode or structure view), we bail out. 
			IActiveContext *ac = GetExecutionContextSession()->GetActiveContext();
			IControlView* activeView = ac ? ac->GetContextView() : nil;

			InterfacePtr<ILayoutControlData> iLayoutControlData(activeView, UseDefaultIID());
			if (iLayoutControlData && (!fCurrentLayoutView || (fCurrentLayoutView != activeView)))
				fCurrentLayoutView = activeView;

			InterfacePtr<IControlView> iPreviewButtonView(theSubject, UseDefaultIID());
			WidgetID widgetID = iPreviewButtonView->GetWidgetID();

			if (theChange.Get() == kTrueStateMessage)
			{		
				InterfacePtr<ISWFPreviewPreferences> iSWFPreviewPrefs(this, UseDefaultIID());

				if (widgetID == kSWFPreviewButtonWidgetID)	// Preview button
				{
					if (iLayoutControlData)
					{
						this->UpdateWidget( kSWFPreviewButtonWidgetID,false);
						if(protocol.Get() == IID_ISWFUPDATEPREVIEWMESSAGE)
							this->UpdatePreviewProxy(kFalse);
						else
							this->UpdatePreviewProxy(::IsOptionAltKeyPressed() && !::IsShiftKeyPressed() && !::IsCommandKeyPressed());

						if (fPreviewSpreadList.Length() > 0)	// only when there are spreads, we will update the navigate widgets and text widget.
						{
							this->UpdateNavigationWidgets(0);
  							this->UpdateCurrentPageWidget(0);
						}
					}
				}	
				else if (widgetID == kSWFStopButtonWidgetID)	// Stop button
				{
					// Disable stop button 
					this->UpdateWidget( kSWFStopButtonWidgetID,false);

					// Unload any loaded SWF
					UnloadPreviewSWF();

					// Enable play button
					this->UpdateWidget( kSWFPreviewButtonWidgetID,true);

					// Clear naviation button, page widget and warning icon
					this->UpdateNavigationWidgets(-1);
					this->UpdateCurrentPageWidget(-1);

					InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());
					IControlView* iWarningIconView = iPanelControlData->FindWidget(kSWFPreviewWarningButtonWidgetID);
					iWarningIconView->HideView();
				}
				else if (widgetID == kSWFPreviewDocumentButtonWidgetID)	// Change to preview document mode
				{
					iSWFPreviewPrefs->SetPreviewType(ISWFPreviewPreferences::kPreviewWholeDocument);
					this->UpdatePreviewModeWidgets();
				}
				else if (widgetID == kSWFPreviewSpreadButtonWidgetID)	// Change to preview spread mode
				{
					iSWFPreviewPrefs->SetPreviewType(ISWFPreviewPreferences::kPreviewCurrentSpread);
					this->UpdatePreviewModeWidgets();
				}
				else if (widgetID == kSWFPreviewSelectionButtonWidgetID)	// Change to preview selection mode
				{
					iSWFPreviewPrefs->SetPreviewType(ISWFPreviewPreferences::kPreviewCurrentSelection);
					this->UpdatePreviewModeWidgets();
					this->EnableDisableNavigatorButtons(false/*previous*/, false/*next*/);
				}
				else
				{
					ASSERT(iLayoutControlData != nil);
					ASSERT((widgetID == kSWFPreviewPreviousButtonWidgetID) || (widgetID == kSWFPreviewNextButtonWidgetID));

					int32 frameIndex = this->GetCurrentPreviewFrameIndex();

					// It's possible that frameIndex could be -1 if this is the first time to navigate 
					// since fCurrentPreviewFrameIndex is initialized -1. In this case, since the first spread 
					// has already been shown, we need to adjust the frame index to be 0 to reflect the current 
					// viewing spread. See bug #2511079.
					if (frameIndex < 0) 
						frameIndex = 0;

					int32 numFrames = fPreviewSpreadList.Length();

					if ((widgetID == kSWFPreviewPreviousButtonWidgetID) && (frameIndex > 0))
						frameIndex -= 1;
					else if ((widgetID == kSWFPreviewNextButtonWidgetID) && (frameIndex < numFrames-1))
						frameIndex += 1;	

					ASSERT((frameIndex >= 0) && (frameIndex < numFrames));
					if ((frameIndex >= 0) && frameIndex < numFrames)
					{
						this->SetCurrentPreviewFrameIndex(frameIndex);
						this->SendSpreadIndexToSWF();
					}

					this->UpdateNavigationWidgets(frameIndex);
					this->UpdateCurrentPageWidget(frameIndex);
				}
			}

			break;
		}
		default:
		{
			inherited::Update(theChange, theSubject, protocol, changedBy);

			break;
		}
	}
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::UpdatePreviewProxy
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::UpdatePreviewProxy(bool const &bReload)
{	
	if (!fCurrentLayoutView)
		return;

	// Make sure if user in in process of editing motion path that main item is updated to reflect current state of motion item
	InterfacePtr<ISelectionManager> iSelectionMgr(Utils<ISelectionUtils>()->QueryActiveSelection ()); 
	InterfacePtr<IAnimationAttributeSuite> iAttrSuite (iSelectionMgr, UseDefaultIID ());
	if (iAttrSuite && iAttrSuite->CanUpdateAnimationMotionPathFromSelection())
		iAttrSuite->UpdateAnimationMotionPathFromSelection();

	//	Hide player widget first; then determining if we should play. If we have valid SWF file, then show widget.
	//	This is an attempt in trying to avoid noises between SWF loads
	//	since APE claims that noises may be present for an invalid stage.
	//	We may get invalid stage during a call to load because APE delete existing stage and create a new one to load
	//	a new SWF.
	InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());
	IControlView* iProxyView = iPanelControlData->FindWidget(kSWFPreviewProxyWidgetID);
	iProxyView->HideView ();

	bool bShowWarning = false;
	IDFile file;

	// If Option/Alt is pressed, we want to do reload (without generating the swf file if it already exists)
	ErrorCode result = kFailure;
	if (bReload)
	{
		if (FileUtils::DoesFileExist(fExistingPreviewFile))
		{
			file = fExistingPreviewFile;
			result = kSuccess;
		}
	}
	
	// If 1) play button is pressed or 2) reload but file not exists, 
	// then we have to generate the file first.
	if (result != kSuccess)
	{
		this->ClearTempPreviewFiles();

		//
		// Build destination file that we export SWF to.
		//
		InterfacePtr<ILayoutControlData> iLayoutControlData(fCurrentLayoutView, UseDefaultIID());
		IDocument*	iCurrentDoc = iLayoutControlData->GetDocument();
		IDataBase* db = ::GetDataBase(iCurrentDoc);

		InterfacePtr<ISWFPreviewPreferences> iSWFPreviewPrefs(this, UseDefaultIID());

		InterfacePtr<ICommand> iSWFPreviewCmd(CmdUtils::CreateCommand(kSWFPreviewCmdBoss));

		if (iSWFPreviewCmd)
		{
			InterfacePtr<IUIDData> iPreviewDoc(iSWFPreviewCmd, UseDefaultIID());
			iPreviewDoc->Set(::GetUIDRef(iCurrentDoc));

			InterfacePtr<ISWFPreviewPreferences> iCmdPreviewType(iSWFPreviewCmd, UseDefaultIID());
			iCmdPreviewType->SetPreviewType(iSWFPreviewPrefs->GetPreviewType());

			InterfacePtr<IControlViewCmdData> iControlViewData(iSWFPreviewCmd, UseDefaultIID());
			iControlViewData->Set(fCurrentLayoutView);

			if (ddui_utils::GetTemporaryFileForExport(file))
			{
				file = IDFile(file.GetPath() + APath(kPreviewSWFDefaultName));
   				InterfacePtr<ISysFileData> fileData(iSWFPreviewCmd, UseDefaultIID());
	   
   				fileData->Set(file);
	   			
   				result = CmdUtils::ProcessCommand(iSWFPreviewCmd);
			}
			else
			{
				result = kFailure;
			}

			if (result == kSuccess)
			{
#ifdef DEBUG
				InterfacePtr<ISysFileData> iDestFile(iSWFPreviewCmd, UseDefaultIID());
				IDFile resultSWFFile = iDestFile->GetSysFile();
				ASSERT(resultSWFFile == file);
#endif
				InterfacePtr<IBoolData> iWarningCmdData(iSWFPreviewCmd, UseDefaultIID());
				bShowWarning = iWarningCmdData->GetBool();
			}
		}
	}

	//
	// Load the exported swf movie
	//
	if ((result == kSuccess) && FileUtils::DoesFileExist(file))
	{
		// Cache the preview file for reloading.
		fExistingPreviewFile = file;

		this->CacheSpreadListInfo();

		this->UpdateWidget(kSWFPreviewButtonWidgetID, false);

		fCurrentPreviewFrameIndex = -1;

		LoadPreviewSWF(file);

 		iProxyView->ShowView();

		this->UpdateWidget(kSWFStopButtonWidgetID, true);
	}
	else if (result == kCancel)
	{
		// If preview is cancelled, we should enable the play button, disable the stop button, clear all the widgets. See bug #2546612.
		this->UpdateWidget(kSWFPreviewButtonWidgetID, true);
		this->UpdateWidget(kSWFStopButtonWidgetID, false);
		this->UpdateNavigationWidgets(-1);
		this->UpdateCurrentPageWidget(-1);
	}

	//
	// Update warning icon. 
	// - We get one part of the warning info from command. 
	//   If either of the following three conditions is true, we show the warning icon;
	//		A media file is missing, return true
	//		A media clop is legacy only, return true;
	//		Transparency Flattener is used
	// - We get the other part of the warning info from preference setting.
	//   If Rasterize page or appearance only is on. 
	//
	if (bReload)	// Don't need to update the warning icon if we are doing reload. See bug #2547683.
		return;

	IControlView* iWarningIconView = iPanelControlData->FindWidget(kSWFPreviewWarningButtonWidgetID);
	if (bShowWarning || this->ShowWarningIcon())	
	{
		iWarningIconView->ShowView();

		InterfacePtr<IStringData> iTipString(iWarningIconView, UseDefaultIID());
		if (this->ShowWarningIcon())
			iTipString->Set("kSWFPreviewWarningTip1");
		else
			iTipString->Set("kSWFPreviewWarningTip2");
	}
	else
		iWarningIconView->HideView();
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::UpdateNavigationWidgets
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::UpdateNavigationWidgets(int32 const &frameIndex)
{		
	if ((frameIndex == -1) || !fCurrentLayoutView)
	{
		this->EnableDisableNavigatorButtons(false/*previous*/, false/*next*/);
		return;
	}
	
	InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());
	IControlView* iPreviousButtonView = iPanelControlData->FindWidget(kSWFPreviewPreviousButtonWidgetID);
	IControlView* iNextButtonView = iPanelControlData->FindWidget(kSWFPreviewNextButtonWidgetID);

	InterfacePtr<ISWFPreviewPreferences> iSWFPreviewPrefs(this, UseDefaultIID());
	ISWFPreviewPreferences::SWFPreviewType type = iSWFPreviewPrefs->GetPreviewType();

	if (type == ISWFPreviewPreferences::kPreviewWholeDocument)
	{	
		// Enable/Disable the buttons based on current preview frame index.
		int32 numFrames = fPreviewSpreadList.Length();

		if ((frameIndex == 0) && (numFrames == 1))
		{
			// Disable both buttons if there is only one frame in the document.
			ASSERT((frameIndex == 0) && (frameIndex == numFrames - 1));

			this->EnableDisableNavigatorButtons(false, false);
		}
		else
		{
			if ((frameIndex == 0) && (numFrames - 1 > frameIndex))
			{
				// Disable first and previous buttons if current spread is the first spread.
				this->EnableDisableNavigatorButtons(false/*previous*/, true/*next*/);
			}
			else if ((frameIndex > 0) && (frameIndex == numFrames - 1))
			{
				// Disable next and last buttons if current spread is the last spread.
				this->EnableDisableNavigatorButtons(true/*previous*/, false/*next*/);
			}
			else
			{
				// We are in the middle spreads, enable everything.
				this->EnableDisableNavigatorButtons(true/*previous*/, true/*next*/);
			}			
		}
	}
	else
	{		
		// Disable all buttons if type is either spread or objects.
		this->EnableDisableNavigatorButtons(false/*previous*/, false/*next*/);
	}
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::EnableDisableNavigatorButtons
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::EnableDisableNavigatorButtons(bool const &bEnablePrevious, bool const &bEnableNext)														
{		
	this->UpdateWidget(kSWFPreviewPreviousButtonWidgetID, bEnablePrevious);
	this->UpdateWidget(kSWFPreviewNextButtonWidgetID, bEnableNext);
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::UpdateWidget
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::UpdateWidget(WidgetID const &widgetID, bool const &bEnable)
{
	InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());
	IControlView* iWidgetView = iPanelControlData->FindWidget(widgetID);
	if (bEnable)
		iWidgetView->Enable();
	else
		iWidgetView->Disable();
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::UpdatePreviewModeWidgets
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::UpdatePreviewModeWidgets()
{
	InterfacePtr<ISWFPreviewPreferences> iSWFPreviewPrefs(this, UseDefaultIID());
	ISWFPreviewPreferences::SWFPreviewType previewType = iSWFPreviewPrefs->GetPreviewType();

	if (previewType == ISWFPreviewPreferences::kPreviewWholeDocument)
		this->SelectDeselectPreviewModeButtons(true, false, false);
	else if (previewType == ISWFPreviewPreferences::kPreviewCurrentSpread)
		this->SelectDeselectPreviewModeButtons(false, true, false);
	else if (previewType == ISWFPreviewPreferences::kPreviewCurrentSelection)
		this->SelectDeselectPreviewModeButtons(false, false, true);

	this->UpdatePreviewButton();
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::UpdatePreviewButton
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::UpdatePreviewButton()
{
	InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());
	IControlView* iPreviewButton = iPanelControlData->FindWidget(kSWFPreviewButtonWidgetID);

	IActiveContext *ac = GetExecutionContextSession()->GetActiveContext();
	if (!ac || (ac->GetContextView() == nil) || (ac->GetContextDocument() == nil))
	{
		iPreviewButton->Disable();
		return;
	}
	else 
	{
		InterfacePtr<ILayoutControlData> iLayoutControlData(ac->GetContextView(), UseDefaultIID());
		if (!iLayoutControlData)
		{
			iPreviewButton->Disable();
			return;
		}
		else
		{
			InterfacePtr<ISWFPreviewPreferences> iSWFPreviewPrefs(this, UseDefaultIID());
			ISWFPreviewPreferences::SWFPreviewType previewType = iSWFPreviewPrefs->GetPreviewType();

			if (previewType == ISWFPreviewPreferences::kPreviewCurrentSelection)
			{
				InterfacePtr<ISelectionManager> iSelectMgr(Utils<ISelectionUtils>()->QueryViewSelectionManager(ac->GetContextView()));
				if (!iSelectMgr || !(iSelectMgr->SelectionExists (kNewLayoutSelectionBoss, ISelectionManager::kUniqueSelection))) 
				{
					iPreviewButton->Disable();
					return;
				}
			}
		}
	}
	
	iPreviewButton->Enable();
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::SelectDeselectPreviewModeButtons
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::SelectDeselectPreviewModeButtons(bool const &bSelectPreviewDocument, bool const &bSelectPreviewSpread, bool const &bSelectPreviewSelection)
{
	InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());

	InterfacePtr<ITriStateControlData> iPreviewDocument(iPanelControlData->FindWidget(kSWFPreviewDocumentButtonWidgetID), UseDefaultIID());
	InterfacePtr<ITriStateControlData> iPreviewSpread(iPanelControlData->FindWidget(kSWFPreviewSpreadButtonWidgetID), UseDefaultIID());
	InterfacePtr<ITriStateControlData> iPreviewSelection(iPanelControlData->FindWidget(kSWFPreviewSelectionButtonWidgetID), UseDefaultIID());

	if (bSelectPreviewDocument)
		iPreviewDocument->Select(kTrue, kFalse);
	else
		iPreviewDocument->Deselect(kTrue, kFalse);

	if (bSelectPreviewSpread)
		iPreviewSpread->Select(kTrue, kFalse);
	else
		iPreviewSpread->Deselect(kTrue, kFalse);

	if (bSelectPreviewSelection)
		iPreviewSelection->Select(kTrue, kFalse);
	else
		iPreviewSelection->Deselect(kTrue, kFalse);
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::UpdateCurrentPageWidget
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::UpdateCurrentPageWidget(int32 const &frameIndex)
{	
	PMString pageRangeString(kNullString);

	InterfacePtr<IPanelControlData> iPanelControlData(this, UseDefaultIID());
  	IControlView* iCurrentPageWidgetView = iPanelControlData->FindWidget(kSWFPreviewCurrentPageWidgetID);
  	InterfacePtr<ITextControlData> iCurrentPageWidgetData(iCurrentPageWidgetView, UseDefaultIID());		
	InterfacePtr<IStringData> iTipData(iCurrentPageWidgetView, UseDefaultIID());

	if ((frameIndex == -1) || (fPreviewSpreadList.Length() == 0))
	{
		iCurrentPageWidgetData->SetString(pageRangeString, kTrue, kFalse);
		iTipData->Set(pageRangeString);
		return;
	}

	//
	// Get page range string.
	//			

	this->SetCurrentPreviewFrameIndex(frameIndex);
	UID spreadUID = fPreviewSpreadList[frameIndex];

	InterfacePtr<ILayoutControlData> iLayoutControlData(fCurrentLayoutView, UseDefaultIID());
	IDocument* iCurrentDoc = iLayoutControlData->GetDocument();
	IDataBase* db = ::GetDataBase(iCurrentDoc);

	InterfacePtr<ISWFPreviewPreferences> iSWFPreviewPrefs(this, UseDefaultIID());
	ISWFPreviewPreferences::SWFPreviewType previewType = iSWFPreviewPrefs->GetPreviewType();

	if (previewType != ISWFPreviewPreferences::kPreviewWholeDocument)
	{
		ASSERT((previewType == ISWFPreviewPreferences::kPreviewCurrentSpread) || (previewType == ISWFPreviewPreferences::kPreviewCurrentSelection));
		spreadUID = iLayoutControlData->GetSpreadRef().GetUID();
	}

	PMString masterSpreadName(kNullString);
	InterfacePtr<IMasterSpread> iMasterSpread(db, spreadUID, UseDefaultIID());
	if (iMasterSpread)
	{
		iMasterSpread->GetName(&pageRangeString);
	}
	else
	{	
		UIDList pageUIDList(db);
		InterfacePtr<ISpread> iCurrentSpread(db, spreadUID, UseDefaultIID());
		for (int32 i = 0, n = iCurrentSpread->GetNumPages(); i < n; ++i) 
			pageUIDList.push_back(iCurrentSpread->GetNthPageUID(i));

		InterfacePtr<IPageList> iPageList(iCurrentDoc, UseDefaultIID());
		iPageList->GetPageRangeString (pageUIDList, &pageRangeString); 
	}
	ASSERT(!pageRangeString.empty());
	iCurrentPageWidgetData->SetString(pageRangeString, kTrue, kFalse);

	//
	// Set the string for tool tip which is "docName + pageRange"
	//
	if (!pageRangeString.empty())
	{
		// Get doc name
		PMString tipString(kNullString);
		iCurrentDoc->GetName(tipString);	

		// Remove the extension
		CharCounter lastPeriodPosition = tipString.LastIndexOfWChar(kTextChar_Period);
		if (lastPeriodPosition > 1)
			tipString.Remove(lastPeriodPosition, kMaxInt32);

		// Append the page range string
		if (!pageRangeString.empty())
		{
			PMString separatorString("kStatusSeparatorStr", PMString::kTranslateDuringCall);
			tipString.Append(separatorString);
			
			if (iMasterSpread)
			{
				PMString masterPagePrefixString("kMasterPagePrefixString", PMString::kTranslateDuringCall);
				tipString.Append(masterPagePrefixString);
			}
			else
			{
				PMString pagePrefixString("kPagePrefixString", PMString::kTranslateDuringCall);
				tipString.Append(pagePrefixString);
			}				

			tipString.Append(pageRangeString);
		}

		iTipData->Set(tipString);
	}
	else
	{
		iTipData->Set(pageRangeString);
	}
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::ClearTempPreviewFiles
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::ClearTempPreviewFiles()
{
	const bool16 kDoReturnDirectoryPaths		= kTrue;
	const bool16 kDoNotSearchSubDirectories		= kFalse;
	const bool16 kDoNotResolveAliases			= kFalse;
	const bool16 kDoNotExcludeInvisibleFiles	= kFalse;

	IDFile tempSWFDirectory;
	
	if (ddui_utils::GetSWFPreviewDirectory(tempSWFDirectory))
	{
		PlatformFolderTraverser folderTraverser(
			tempSWFDirectory,
			kDoReturnDirectoryPaths, 
			kDoNotSearchSubDirectories, 
			kDoNotResolveAliases, 
			kDoNotExcludeInvisibleFiles
			);

		K2Vector<IDFile> filesToDelete;
		
		IDFile tempExportDirectory;
		bool16 isDirectory = kFalse;
		while(folderTraverser.Next(&tempExportDirectory, &isDirectory))
		{
			if(isDirectory)
				filesToDelete.push_back(tempExportDirectory);

			isDirectory = kFalse;
		}
		
		for(K2Vector<IDFile>::const_iterator itr = filesToDelete.begin();
			itr != filesToDelete.end();
			++itr)
		{
			ddui_utils::DeleteTempExportDirectory(*itr);
		}
	}

	// Clear the cached preview file and the associated spread list for the file.
	fExistingPreviewFile = IDFile();
	fPreviewSpreadList.Clear();
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::ShowWarningIcon
//----------------------------------------------------------------------------------------
bool SWFPreviewPanelObserver::ShowWarningIcon()
{
	InterfacePtr<IWorkspace> iWorkspace(GetExecutionContextSession()->QueryWorkspace());
	InterfacePtr<ISWFExportPreferences> iWSSWFExportPrefs(iWorkspace, UseDefaultIID());

	if (iWSSWFExportPrefs->GetRasterizePages())
		return true;

	if (iWSSWFExportPrefs->GetDynamicMediaHandling() == flash_export::kAppearanceOnly)
		return true;

	return false;
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::GetCurrentPreviewFrameIndex
//----------------------------------------------------------------------------------------
int32 SWFPreviewPanelObserver::GetCurrentPreviewFrameIndex() 
{		
	return fCurrentPreviewFrameIndex;
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::SetCurrentPreviewFrameIndex
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::SetCurrentPreviewFrameIndex(int32 const &frameIndex) 
{		
	fCurrentPreviewFrameIndex = frameIndex;
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::CacheSpreadListInfo
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::CacheSpreadListInfo()
{
	InterfacePtr<ILayoutControlData> iLayoutControlData(fCurrentLayoutView, UseDefaultIID());
	IDocument*	iCurrentDoc = iLayoutControlData->GetDocument();
	IDataBase* db = ::GetDataBase(iCurrentDoc);

	if (!fPreviewSpreadList.IsEmpty())
		fPreviewSpreadList.Clear();
	else
		fPreviewSpreadList = UIDList(db);

	InterfacePtr<ISpreadList> iSpreadList(iCurrentDoc, UseDefaultIID());

	InterfacePtr<IWorkspace> iWorkspace(GetExecutionContextSession()->QueryWorkspace());
	InterfacePtr<IPageRange> iWSSWFExportPageRange(iWorkspace, IID_ISWFEXPORTPAGERANGE);

	if (iWSSWFExportPageRange)
	{
		InterfacePtr<ISWFPreviewPreferences> iSWFPreviewPrefs(this, UseDefaultIID());

		if (iSWFPreviewPrefs->GetPreviewType() == ISWFPreviewPreferences::kPreviewWholeDocument)
		{
			if (iWSSWFExportPageRange->GetPageRangeFormat() == IPageRange::kAllPages)
			{
				int32 numSpreads = iSpreadList->GetSpreadCount();
				for (int32 i = 0; i < numSpreads; ++i)
					fPreviewSpreadList.push_back(iSpreadList->GetNthSpreadUID(i));
			}
			else if (iWSSWFExportPageRange->GetPageRangeFormat() == IPageRange::kUseRange)
			{
				PMString pageRangeString = iWSSWFExportPageRange->GetPageRange();

				UIDList items(db);
				InterfacePtr<IPageList> iPageList(iCurrentDoc, UseDefaultIID());
				ITextDataValidation::RangeError rangeError = iPageList->PageRangeStringToUIDList(pageRangeString, &items);
				
				// It's possible that the items could be empty when the current document and the preview settings are not in sync, 
				// then we push all pages to preview.
				if (items.IsEmpty() || (rangeError != ITextDataValidation::kNoError))
				{
					int32 numSpreads = iSpreadList->GetSpreadCount();
					for (int32 i = 0; i < numSpreads; ++i)
						fPreviewSpreadList.push_back(iSpreadList->GetNthSpreadUID(i));
				}
				else
				{
					int32 numItems = static_cast<int32>(items.size());
					for (int32 i = 0 ; i < numItems; ++i)
					{
						InterfacePtr<IHierarchy> iPageHier(db, items[i], UseDefaultIID());
						InterfacePtr<ISpread> iSpread(db, iPageHier->GetRootUID(), UseDefaultIID());
						UID spreadUID = ::GetUID(iSpread);
						if (fPreviewSpreadList.Location(spreadUID) < 0)
							fPreviewSpreadList.push_back(spreadUID);
					}
				}
			}
		}
		else
		{
			UIDRef spreadUIDRef = iLayoutControlData->GetSpreadRef();
			fPreviewSpreadList.push_back(spreadUIDRef.GetUID());
		}
	}
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::PreviewSWFCallback
// Comments:  This static method provides the connection point for a swf to call my plug-in
//				@return string containing the result XML packet
//				@param request IN the request XML string containing method name and arguments
//				@param refPtr IN the 'this' pointer which is established in playerController->SetAppFunctionCallback()
//----------------------------------------------------------------------------------------
PMString SWFPreviewPanelObserver::PreviewSWFCallback(const PMString& request, void* refPtr)
{
	PMString returnString;

	// refPtr is a void pointer - reinterpret the pointer to point to me
	SWFPreviewPanelObserver* thisPtr = reinterpret_cast<SWFPreviewPanelObserver*>(refPtr);

	if (thisPtr && thisPtr->fIsLoaded)
	{
		//
		// Get methodName and spreadIndex from Flash by parsing the XML request.
		//
		PMString methodName;
		int32 spreadIndex = -1;
		PMString messageStr;
		
		thisPtr->ParseXMLRequest(request, methodName, spreadIndex, messageStr);

		// perform an action based on the request's method name
		if (methodName == PMString("setSpreadIndex"))
		{
			if (
				thisPtr->fCurrentLayoutView && 
				(spreadIndex >= kFrameToSpreadAdjustment) && 
				((spreadIndex - kFrameToSpreadAdjustment) != thisPtr->fCurrentPreviewFrameIndex)
			   )
			{
				thisPtr->UpdateNavigationWidgets(spreadIndex - kFrameToSpreadAdjustment);
				thisPtr->UpdateCurrentPageWidget(spreadIndex - kFrameToSpreadAdjustment);
			}
		}
		else if (methodName == PMString("loadSWFDoneMessage"))
		{
			if (!messageStr.empty())
			{
				returnString = messageStr;

				// This callback is called when we use kbsc to bring up preview panel and generate the swf at the same time. See bug #2447783.
				// We should pass true for reload to avoid unnecessary regenerate the swf file if it's already generated through the play button. See bug #2541568.
				thisPtr->UpdatePreviewProxy(true /* reload*/);
			}
		}
	}
	
	return returnString;
}

void SWFPreviewPanelObserver::LoadPreviewSWF(IDFile const &file)
{
	if (!fIsLoaded)
		InitializePreview();

	if (fIsLoaded)
	{
		InterfacePtr<IFlashPlayerController> player = GetFlashPlayer();
		
		if (player)
		{
			ASSERT(FileUtils::DoesFileExist(file));
			URI uri;
			Utils<IURIUtils>()->IDFileToURI(file, uri);

			if (!uri.HasComponent(URI::kAuthority))
			{
				uri.SetComponent(URI::kAuthority, WideString());
			}

			PMString urlString(uri.GetURIW());
			PMString request, result;

			request.Append("<invoke name=\"loadSWF\" returntype=\"xml\">");
			request.Append("<arguments>");
			request.Append("<string>");
			request.Append(urlString);
			request.Append("</string>");
			request.Append("</arguments>");
			request.Append("</invoke>");
			
			ErrorCode error = player->CallMovieFunction(request, result);
			
			ASSERT_MSG(error == kSuccess, "SWFPreviewPanelObserver: Failed to load preview SWF");
			
			UpdateWidget(kSWFPreviewButtonWidgetID, true);
		}
	}
}

//----------------------------------------------------------------------------------------
// SWFPreviewPanelObserver::SendSpreadIndexToSWF
// Comments: This method provides the connection point for my plug-in to call my swf.
//				@return kSuccess if method was called successfully
//				@param request IN the request XML string containing method name and arguments
//				@param result OUT contains a result XML string if swf method returned a result.
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::SendSpreadIndexToSWF() 
{
	int32 spreadIndex = this->GetCurrentPreviewFrameIndex();
	if (fIsLoaded && (spreadIndex >= 0))
	{
		PMString request;

		request.Append("<invoke name=\"spreadIndexChanged\" returntype=\"xml\">");
		request.Append("<arguments>");
		request.Append("<number>");
		request.AppendNumber(spreadIndex + kFrameToSpreadAdjustment);	// +1 (frame is 1-based)
		request.Append("</number>");
		request.Append("</arguments>");
		request.Append("</invoke>");
		
		InterfacePtr<IFlashPlayerController> player = GetFlashPlayer();
		
		if (player)
		{
			PMString result;
			ErrorCode err = player->CallMovieFunction(request, result);
		}
	}
}

// ---------------------------------------------------------------------------------------
// 	SWFPreviewPanelObserver::ParseXMLRequest
//  Comments:
//	For this sample, we are specifically parsing the tags we know will exist in the request.  For a more general solution,
//	you will need to use an XML parser to handle a wider range of argument types, including:  number, true, false, etc.
//----------------------------------------------------------------------------------------
void SWFPreviewPanelObserver::ParseXMLRequest(const PMString& request, PMString& methodName, int32& spreadIndex, PMString& messageStr) const
{
	/*	The request is formatted as an xml string:
	
		<invoke name="functionName" returntype="xml">
			<arguments>
				<string>methodName</string>
				<number>spreadIndex</number>
			</arguments>
		</invoke>
	*/

	PMString requestStr = request;	

	//
	// Parse the <arguments> tag and grab arguments string
	//
	PMString argStart("<arguments>");
	PMString argEnd("</arguments>");
	CharCounter argStartPos = requestStr.IndexOfString(argStart);
	CharCounter argEndPos = requestStr.IndexOfString(argEnd);
	K2::scoped_ptr<PMString> argString(requestStr.Substring(argStartPos + argStart.CharCount(), argEndPos - argEnd.CharCount() - argStartPos + 1));
	if(argString == NULL)
	{
		return;
	}
	//
	// Parse the <string> tags for method name from arguments string
	//
	PMString strStart("<string>");
	PMString strEnd("</string>");
	CharCounter strStartPos = argString->IndexOfString(strStart);
	CharCounter strEndPos = argString->IndexOfString(strEnd);
	//Bug #2762990 Adding checks for the test case when the request has arguments but none of them is of type string
	if(strStartPos < 0 || strEndPos < 0)
	{
		return;
	}
	K2::scoped_ptr<PMString> methodString(argString->Substring(strStartPos + strStart.CharCount(), strEndPos - strEnd.CharCount() - strStartPos + 1));
	methodName = PMString(*methodString);
	argString->Remove(0, strEndPos+strEnd.CharCount());
	
	if (methodName == PMString("setSpreadIndex"))
	{
		//
		// Parse the <number> tag for spreadIndex
		//
		PMString numStart("<number>");
		PMString numEnd("</number>");
		CharCounter numStartPos = argString->IndexOfString(numStart);
		CharCounter numEndPos = argString->IndexOfString(numEnd);
		//Bug #2762990 Adding checks for the test case when the request setSpreadIndex method but no number type argument
		if(numStartPos < 0 || numEndPos < 0)
		{
			methodName.clear();
			return;
		}
		K2::scoped_ptr<PMString> numberString(argString->Substring(numStartPos + numStart.CharCount(), numEndPos - numEnd.CharCount() - numStartPos + 1));
		if(numberString == NULL)
		{
			methodName.clear();
			return;
		}
		PMString numStr = PMString(*numberString);
		spreadIndex = numStr.GetAsNumber();
	}
	else if (methodName == PMString("loadSWFDoneMessage"))
	{
		//
		// Parse the <string> tag for result message
		//
		PMString msgStart("<string>");
		PMString msgEnd("</string>");
		CharCounter msgStartPos = argString->IndexOfString(msgStart);
		CharCounter msgEndPos = argString->IndexOfString(msgEnd);
		//Bug #2762990 Adding checks for the test case when the request loadSWFDoneMessage method but no string type argument
		if(msgStartPos < 0 || msgEndPos < 0)
		{
			methodName.clear();
			return;
		}
		K2::scoped_ptr<PMString> msgString(argString->Substring(msgStartPos + msgStart.CharCount(), msgEndPos - msgEnd.CharCount() - msgStartPos + 1));
		if(msgString == NULL)
		{
			methodName.clear();
			return;
		}
		messageStr = PMString(*msgString);
	}
}
