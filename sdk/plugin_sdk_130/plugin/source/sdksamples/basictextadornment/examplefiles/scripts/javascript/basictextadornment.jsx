//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/basictextadornment/examplefiles/scripts/javascript/basictextadornment.jsx $
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
//  exercises each scriptable feature of the plug-in.
//  
//  The results of the script are logged in a file called 
//  basictextadornment.jsx-log.txt in the folder that contains
//  the script. Check the log file for the results.
//  
//  Close all open files.
//  
//========================================================================================

CloseAll();

//Get a reference to the folder containing the running script.
var myScriptFileName = app.activeScript;
var myScriptFile = File(myScriptFileName);
var myFolder = myScriptFile.parent + "/";

// Open log file alongside the script.
var myLogFile = myScriptFile + "-log.txt";
var sink;
sink = new File(myLogFile);
sink.open("w");

// Local variables used to track status.
var myError = false;
var myName = "";

// Create a document with a text frame containing text "Hello shaded world!".
app.documents.add();
app.documents[0].pages[0].textFrames.add();
app.documents[0].pages[0].textFrames[0].geometricBounds = ["0p0", "0p0", "36p0", "36p0"];
app.documents[0].pages[0].textFrames[0].contents = "Hello shaded world!";

// Apply shade.
myName = "Apply shade";
sink.writeln(myName);
app.documents[0].pages[0].textFrames[0].words[1].basictextadornmentShade = true;
if (app.documents[0].pages[0].textFrames[0].words[1].basictextadornmentShade != true) {
	sink.writeln(" error");
	myError = true;
}

// Remove shade.
myName = "Remove shade";
sink.writeln(myName);
app.documents[0].pages[0].textFrames[0].words[1].basictextadornmentShade = false;
if (app.documents[0].pages[0].textFrames[0].words[1].basictextadornmentShade != false) {
	sink.writeln(" error");
	myError = true;
}

// Re-apply shade.
myName = "Re-apply shade";
sink.writeln(myName);
app.documents[0].pages[0].textFrames[0].words[1].basictextadornmentShade = true;
if (app.documents[0].pages[0].textFrames[0].words[1].basictextadornmentShade != true) {
	sink.writeln(" error");
	myError = true;
}

// Report results of script.
if (myError) {
	alert("DONE WITH ERRORS");
	sink.writeln("DONE WITH ERRORS");
	alert("Check log file: "  + myLogFile);}
else {
	alert("DONE");
	sink.writeln("DONE");
}  

// Close the log.
sink.close();

/*
*/
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