#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include "FileBitStream.h"
using namespace std;

void compress(const char* inFileName,const char* outFileName)
{
	FILE* fp=fopen(inFileName,"rb");
	char ch;
	if(fp)
	{
		int fSize=0;
		LPNODE p=createTree(fp,&fSize);
		show(p,0);
		FILE* fout=fopen(outFileName,"wb");
		char ch=0;
		fseek(fp,0,SEEK_SET);
		char b=0;
		int i=0;
		while((ch=fgetc(fp))!=-1)
		{
			b&=code[ch][i];
		}
		destroyTree(p);
		fclose(fout);
		fclose(fp);
	}
}
int main()
{
	compress("1.txt","2.txt");
	/*
	CFileStream a;
	a.openOutStream("2.txt");
	a.pushABit(0);
	a.pushABit(1);
	a.pushABit(0);
	a.pushABit(0);
	a.pushABit(0);
	a.pushABit(0);
	a.pushABit(0);
	a.pushABit(1);

	a.pushABit(0);
	a.pushABit(1);
	a.pushABit(0);
	a.pushABit(0);
	a.pushABit(0);
	a.pushABit(0);
	a.pushABit(1);
//	a.pushABit(0);
	*/
	//printf("%d",a.closeOutStream());
	getchar();
	return 0;
}
