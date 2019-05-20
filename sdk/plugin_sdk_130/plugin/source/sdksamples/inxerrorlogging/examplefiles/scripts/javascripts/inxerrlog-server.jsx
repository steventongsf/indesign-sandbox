//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/inxerrorlogging/examplefiles/scripts/javascripts/inxerrlog-server.jsx $
//  
//  Owner: ???
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

CloseAll();

app.documents.add();
app.documents[0].pages[0].textFrames.add();

//Install for import
app.inxerrlogOn = true;
app.inxerrlogPath = "c:/inxerrlog_export.txt";
app.documents[0].exportFile(ExportFormat.INDESIGN_INTERCHANGE, File("c:/myinxerrlog.inx"));
CloseAll();
function CloseAll() 
{
	while	(app.documents.length >	0)  {
		app.documents[0].close(SaveOptions.NO);	
	}
	if (app.name !=	"Adobe InCopy")	{
		while (app.books.length	> 0) {
			app.books[0].close(SaveOptions.NO);	
		}
		while (app.libraries.length	> 0) {
			app.libraries[0].close(); 
		}
	}
}