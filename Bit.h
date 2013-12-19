#pragma once
#include <stdlib.h>
class CBit
{
	int len;//������λ����
	unsigned char* lpBuffer;
	int bufferLen;//��������С
public:
	CBit(void);
	CBit(CBit& bit);
	void clear()
	{
		if(lpBuffer) free(lpBuffer);
		lpBuffer=0;
		bufferLen=0;
		len=0;
	}
	bool isEmpty()
	{
		return len==0;
	}
	int getLength()
	{
		return len;
	}
	int getBufferLength()
	{
		return bufferLen;
	}
	bool getABit(int pos);
	void setABit(int pos,bool bit);
	virtual ~CBit(void);
	void appendABit(bool bit);
};
