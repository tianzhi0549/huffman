#pragma once
#include <stdio.h>
#include "Bit.h"
class CFileStream
{
public:
	CFileStream(void);
	virtual ~CFileStream(void);
	bool openOutStream(const char* outFileName);
	int closeOutStream(void);
private:
	FILE* fout;
	FILE* fin;
	char buffer;
	int usedBuffer;
	int writedLen;
public:
	void skip(int size)
	{
		fseek(fin,size,SEEK_SET);
	}
	bool pushABit(bool theBit);
	void pushBits(CBit& bits);
	bool openInStream(const char* inFileName);
	bool getCurrentBit(void);
	void closeInStream(void);
};
