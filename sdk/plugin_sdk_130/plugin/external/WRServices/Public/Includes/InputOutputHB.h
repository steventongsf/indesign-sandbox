//========================================================================================
//  
//  File: InputOutputHB.h
//  
//  Author: Shubhi Mohta
//  
//  Copyright 2018 Adobe Inc.
//  Usage rights licenced to Adobe Inc.
//  
//========================================================================================
#pragma once
#ifndef _InputOutputHB_
#define _InputOutputHB_


#include "WRConfig.h"

#include "WRDefines.h"
#include "WRClass.h"
#include "WRVector.h"
#include <map>

typedef WRInt32			HBIndex;
typedef WRInt32 HBInnerPosition;
/*
InputOutputHB is the Input-Output Interface when Harfbuzz Shaping is used.

Each output glyph has a cluster value assigned to it with the possiblity of many glyphs forming a cluster and hence having the same cluster value in case of complex scripts;

HBClusters 
-clusterValue: cluster value (with 0 being the first cluster). Cluster value of a cluster is the smallest index of the input characters which form that cluster. Hence cluster values might not be continuous values .
-glyphStart/glyphEnd: tells us the start and end of the glyphs forming a cluster
-unicodeStart/UnicodeEnd: tells us the start and end of the input unicodes forming a cluster

All Hit-Test, Selection, cursor movement workflows should be cluster based.


*/
class HBClusters
{
public:
	HBClusters() {};
	HBClusters(WRInt32 a, WRInt32 b, WRInt32 c, WRInt32 d, WRInt32 e) : clusterValue(a), glyphStart(b), glyphEnd(c), unicodeStart(d), unicodeEnd(e) {};
	WRInt32 clusterValue;
	WRInt32 glyphStart; 
	WRInt32 glyphEnd;
	WRInt32 unicodeStart;
	WRInt32 unicodeEnd;
};

class HBRun
{
public:
	HBRun() { }
	HBRun(HBIndex c, WRInt32 d) { count = c; data = d; }
	HBIndex count; // no of characters/glyphs
	WRInt32	data;// start index
};

class HBRunList : public WRVector<HBRun>
{
public:
	HBIndex	GetLength() const { WRInt32 res = 0; for (WRInt32  i = 0; i < fSize; i++) res += fData[i].count; return res; }
};

class WRSERVICES_DECL InputOutputHB : public WRClass
{
private:
	WRInt32				fInputCount; ///< number of input slots (characters) 
	WRInt32				fOutputCount; ///< number of output slots (glyphs) 
	HBRunList			fInputRuns;///track of input runs
	HBRunList			fOutputRuns;///track of output runs
	WRVector<WRInt32> fInputClusters;// keep track of cluster values of input characters before shaping
	WRVector<WRInt32> fUpdatedInputClusters;// keep track of cluster values of input characters after shaping
	WRVector<WRInt32> fOutputClusters;// keep track of cluster values of output glyphs
	WRVector<WRInt32> glyphXPos;//keep track of cummulative x-advances of glyphs; for a glyph its xpos is glyphXpos of previous glyph ; for 0th glyph its xPos to be assumed 0 
	std::map<int, HBClusters*> clusterInfo;
	void fillClusterInfo();
public:
	enum {
		kInputOutputHB_NoErr ,kInputOutputHB_AllocErr, kInputOutputHB_OutOfRangeErr
	};
	InputOutputHB();
	~InputOutputHB();
	
	void Reset();
	WRInt32 getInputCount() { return fInputCount; };
	WRInt32 getOutputCount() { return fOutputCount; };
	void MergeClusters(WRVector<WRInt32> inputClusters, WRVector<WRInt32> outputClusters, WRInt32 charCount, WRInt32 glyphCount, WRVector<WRInt32> advances);//TODO:decide if public or private
	WRInt32 getGlyphClusterValue(WRInt32 glyphIndex);//return the cluster value of the glyph
	WRInt32 getUnicodeClusterValue(WRInt32 unicodeIndex);//returns the cluster value of input character
	HBClusters getClusterFromGlyph(WRInt32 glyphIndex);// returns HBCluster of the glyph 
	HBClusters getClusterFromUnicode(WRInt32 unicodeIndex);// returns HBCluster corresponding to the input character
	HBClusters getCluster(WRInt32 clusterValue); //returns HBCluster corresponding to the output clusters
	WRInt32 Extract(InputOutputHB& extractedLog, WRInt32 start, WRInt32 count);
	WRInt32 Copy(const InputOutputHB& b);
	WRInt32 Catenate(const InputOutputHB& b);
	InputOutputHB & operator = (const InputOutputHB &t);
	/*
	takes input runs and updates the count to reflect the number of output glyphs of the run
	*/
	void Replay(HBRunList& runs, WRInt32 startPos);

	/*
	void OutputToInput(HBIndex glyphIndex, HBInnerPosition &inner, HBIndex &characterIndex);
	
	-glyphIndex : 0-based index of the output glyph sequence
	-inner: As input it contains the portion(0-100) of the glyph
			As output it return 0 or 100 as described below
	-charcaterIndex: the start or end unicodeIndex of the range of unicodes forming the output cluster which contains the output glyph(glyphIndex)
	1. if the glyph is part of the first half of the cluster ; it returns the start unicode and inner=0
	2. if the glyph is part of the secont half od the cluster; it returns the end unicode and inner=100
	*/
	void OutputToInput(HBIndex glyphIndex, HBInnerPosition &inner, HBIndex &characterIndex);
	/*
	void InputToOutput(HBIndex characterIndex, HBInnerPosition &inner, HBIndex &glyphIndex);

	-characterIndex : 0-based index of the input unicode sequence
	-inner: As input it contains the portion(0-100) of the unicode character
			As output it returns 0 or 100 as described below
	-glyphIndex: the start or end glyphIndex of the range of glyphs forming the output cluster which is formed by the input unicode(characterIndex)

	1. if the unicode character is part of the first half of the cluster ; it returns the start glyph and inner=0
	2. if the unicode character is part of the secont half od the cluster; it returns the end glyph and inner=100
	*/

	void InputToOutput(HBIndex characterIndex, HBInnerPosition &inner, HBIndex &glyphIndex);
};



#endif // ! _InputOutputHB_
