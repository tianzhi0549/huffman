#include "FileBitStream.h"


CFileStream::CFileStream(void)
{
	fout=0;
	buffer=0;
	usedBuffer=0;
	writedLen=0;
}


CFileStream::~CFileStream(void)
{
}


bool CFileStream::openOutStream(const char* outFileName)
{
	fout=fopen(outFileName,"ab");
	if(fout) return true;
	return false;
}


int CFileStream::closeOutStream(void)
{
	if(usedBuffer>0)
	{
		fputc(buffer,fout);
		writedLen++;
	}
	fclose(fout);
	return writedLen;
}


bool CFileStream::pushABit(bool theBit)
{
	usedBuffer++;
	buffer=buffer|(theBit<<(8-usedBuffer));
	if(usedBuffer==8)
	{
		fputc(buffer,fout);
		usedBuffer=0;
		buffer=0;
		writedLen++;
	}
	return true;
}
