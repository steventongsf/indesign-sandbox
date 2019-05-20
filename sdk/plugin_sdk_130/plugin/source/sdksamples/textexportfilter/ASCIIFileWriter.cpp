//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/sdksamples/textexportfilter/ASCIIFileWriter.cpp $
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

// General includes
#include "CTxtExpFileWriter.h"

// Project includes
#include "TxtExpID.h"


/** ASCIIFileWriter
	Implements ITxtExpFileWriter for ASCII encoded files. 

	@ingroup textexportfilter
	
*/
class ASCIIFileWriter: public CTxtExpFileWriter
{
public:
	/** Constructor
	*/
	ASCIIFileWriter(IPMUnknown* boss);

	/** Destructor
	*/
	virtual ~ASCIIFileWriter(void);

	/** Writes the textchar data to the given file stream.
		@param stream Stream to write to.
		@param tcbuf Pointer to a buffer of textchars to write. 
		@param bufSize Number of textchars to write.
		@return Number of textchars (not bytes) written to stream.
	*/
	virtual int32 WriteTextCharBuffer(IPMStream* stream, const textchar* tcbuf, const int32 bufSize);

};


/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its 
 ImplementationID making the C++ code callable by the 
 application.
*/
CREATE_PMINTERFACE(ASCIIFileWriter, kASCIIFileWriterImpl);


/* Constructor
   NOTE: 0 means "Roman" for the CTUnicodeTranslator
*/
ASCIIFileWriter::ASCIIFileWriter(IPMUnknown* boss)
 : CTxtExpFileWriter(boss, 0) {}


/* Destructor
*/
ASCIIFileWriter::~ASCIIFileWriter(void)
{
}


/* WriteTextCharBuffer
*/
int32 ASCIIFileWriter::WriteTextCharBuffer(IPMStream* stream, const textchar* tcbuf, const int32 bufSize)
{
	// call the parent class' method
	int32 written = CTxtExpFileWriter::WriteTextCharBuffer(stream, tcbuf, bufSize);
	
	// if there is any extra processing, place code here.
	
	return written;
}

// End, ASCIIFileWriter.cpp



