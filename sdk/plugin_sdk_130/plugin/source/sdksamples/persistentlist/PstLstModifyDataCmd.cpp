//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/persistentlist/PstLstModifyDataCmd.cpp $
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

#include "VCPlugInHeaders.h"

// Interface includes
#include "IUIDData.h"
#include "IDocument.h"
#include "ISubject.h"

// API includes
#include "ErrorUtils.h"
#include "IPageItemUtils.h"	 
#include "Command.h"

// Project includes
#include "PstLstID.h"
#include "IPstLstData.h"
#include "IPstLstUIDList.h"

/** 
	PstLstModifyDataCmd will modify the string data of the current selected IPstLstData
	in the IPstLstUIDList of the page item that is of interest to the user.  Note this 
	implementation actually handles more than just one page item. 

	PstLstModifyDataCmd implements ICommand based on the partial implementation Command. 
	
	@ingroup persistentlist
	
*/
class PstLstModifyDataCmd : public Command
{
	public:
		/**
			Constructor, we initialize all the private members and pass the boss pointer to 
			the parent class (Command).
		*/
		PstLstModifyDataCmd(IPMUnknown* boss);

		/**
			Destructor
		*/
		virtual ~PstLstModifyDataCmd();

		/**
			Don't execute this command if the memory is low.
		*/
		bool16 LowMemIsOK() const { return kFalse; }

	protected:
		/**
			The Do method is where we access the IPstLstData data objects, and modify them
			with the string specified in the IPstLstData interface aggregated by the command boss.  Since 
			there may be multiple items selected, we have to repeat this process thru all the passed in ItemList.
		*/
		void Do();

		/**
			Notify all the document observers that a change to the page item's IPstLstData
			has happened.
		*/
		void DoNotify();

		/**
			Gives the name that shows up under the Edit menu and allows the user to undo or redo the command.

			@return pointer to a PMString allocated using the new operator. Deleted by caller.
		*/
		PMString* CreateName();
};

/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its
 ImplementationID making the C++ code callable by the
 application.
*/
CREATE_PMINTERFACE(PstLstModifyDataCmd, kPstLstModifyDataCmdImpl)

/* PstLstModifyDataCmd Constructor
*/
PstLstModifyDataCmd::PstLstModifyDataCmd(IPMUnknown* boss) :
	Command(boss)
{
}

/* PstLstModifyDataCmd Destructor
*/
PstLstModifyDataCmd::~PstLstModifyDataCmd()
{
}

/*	PstLstModifyDataCmd::Do
*/
void PstLstModifyDataCmd::Do()
{
	ErrorCode err = kSuccess;
	
	do
	{
		// Acquire command argument
		InterfacePtr<IPstLstData> iNewPstLstCmdData(this, UseDefaultIID());
		if (iNewPstLstCmdData == nil)
		{
			ASSERT_FAIL("IPstLstData ptr nil, failed in Do");
			err = kFailure;
			break;
		}

		int32	items = fItemList.Length();

		// We have to loop thru all selected persistent list data items to modify its IPstLstData.
		for (int32 i = 0; i < items; i++)
		{
			// get the uid ref of the selected data object and then get to its ptr	
			InterfacePtr<IPstLstData>	iPstLstData(fItemList.GetRef(i), UseDefaultIID());
			if (iPstLstData != nil)
			{
				iPstLstData->SetName(iNewPstLstCmdData->GetName());
			}
			else
				err = kFailure;
		}
	} while (kFalse);
	//Handle errors
	if (err != kSuccess)
	{
		ErrorUtils::PMSetGlobalErrorCode(err);
	}
}

/* PstLstModifyDataCmd DoNotify
*/
void PstLstModifyDataCmd::DoNotify()
{
	// For notfication we'll let IPageItemUtils->NotifyDocumentObservers do the work.
	// Since this is the changed on the PstLstData, we use its interface ID and the 
	// this command boss'd id as parameter to go into the Change() 
	Utils<IPageItemUtils>()->NotifyDocumentObservers
	(
		fItemList.GetDataBase(), 
		kPstLstModifyDataCmdBoss, 
		IPstLstData::kDefaultIID, 
		this
	);
}

/* PstLstModifyDataCmd CreateName
*/
PMString* PstLstModifyDataCmd::CreateName()
{
	PMString* str = new PMString(kPstLstModifyStringKey);
	return str;
}
	
// End, PstLstModifyDataCmd.cpp.


