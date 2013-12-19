#pragma once
#include <stdio.h>
class CFileStream
{
public:
	CFileStream(void);
	virtual ~CFileStream(void);
	bool openOutStream(const char* outFileName);
	int closeOutStream(void);
private:
	FILE* fout;
	char buffer;
	int usedBuffer;
	int writedLen;
public:
	bool pushABit(bool theBit);
};
