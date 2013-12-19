#include "Bit.h"
#include <string.h>
#include <stdlib.h>
CBit::CBit(void):len(0),lpBuffer(0),bufferLen(0)
{

}

CBit::CBit(CBit& bit)
{
	len=bit.len;
	bufferLen=bit.bufferLen;
	lpBuffer=(unsigned char*)malloc(bufferLen);
	memcpy(lpBuffer,bit.lpBuffer,bufferLen);
}

CBit::~CBit(void)
{
	clear();
}


void CBit::appendABit(bool bit)
{
	if(len%8==0)
	{
		bufferLen++;
		if(lpBuffer)
		{
			lpBuffer=(unsigned char*)realloc(lpBuffer,bufferLen);
			memset(lpBuffer+bufferLen-1,0,1);
		}else
		{
			lpBuffer=(unsigned char*)malloc(bufferLen);
			memset(lpBuffer,0,bufferLen);
		}
	}
	len++;
	setABit(len-1,bit);
}

bool CBit::getABit(int pos)
{
	if(pos<len)
	{
		return (lpBuffer[(pos)/8]&
			((unsigned char)
			(1<<(7-pos%8))))!=0;
	}
	return false;
}

void CBit::setABit(int pos,bool bit)
{
	lpBuffer[(pos)/8]|=
			((unsigned char)
			(bit<<(7-pos%8)));
}
