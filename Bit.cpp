#include "Bit.h"
#include <stdlib.h>
CBit::CBit(void):len(0),lpBuffer(0),bufferLen(0)
{

}


CBit::~CBit(void)
{
}


void CBit::appendABit(bool bit)
{
	if(len%8==0)
	{
		bufferLen++;
		if(lpBuffer)
		{
			lpBuffer=(unsigned char*)realloc(lpBuffer,bufferLen);
		}else
		{
			lpBuffer=(unsigned char*)malloc(bufferLen);
		}
	}
	lpBuffer[bufferLen-1]=(unsigned char)(bit<<(len%8));
	len++;
}
