//========================================================================================
//  
//  $File: //depot/devtech/14.0/plugin/source/private/toolkit/diagnosticlog/FileBytesOutStream.h $
//  
//  Owner: gxiao 
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2018/09/10 00:46:19 $
//  
//  $Revision: #2 $
//  
//  $Change: 1031899 $
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

#pragma once
#ifndef __FileBytesOutStream_h__
#define __FileBytesOutStream_h__

// write-only file byte output stream
class FileBytesOutStream
{
public:
	FileBytesOutStream(int32 bufferSize);
	virtual ~FileBytesOutStream();

	bool16 Open(IDFile& sysFile);	
	uint32 Write(void *buffer, uint32 length);
	void Flush();
	void Close();

private:
	// write-only file byte output stream
	bool16 FlushBuffer(uint32 length);
	uint32 WriteBytes(void* buffer, uint32 length);

#ifdef WINDOWS
	HANDLE	fHandle;
#else
	int	fHandle;
#endif
	
	char *	fWriteBuffer;
	int32	fUsedBufferBytes;
	int32	fBufferSize;
};

#endif
