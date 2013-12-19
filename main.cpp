#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <iostream>
#include "FileBitStream.h"
#include "Bit.h"
#include <fstream>
#include "Huffman.h"
using namespace std;
typedef struct
{
	char id[2];//标识
	int len;//原文件长度
	int map[256];//码表
}FileHeader;
void compress(const char* inFileName,const char* outFileName)
{
	int fSize=0;
	CHuffman huffman;
	int ch=0;
	int map[256]={0};
	FILE* fin=fopen(inFileName,"rb");
	if(!fin) return;
	while((ch=fgetc(fin))!=-1)
	{
		map[(unsigned char)ch]++;
	}
	fclose(fin);
	huffman.createByMap(map);
	/*
	for(int i=0;i<256;i++)
	{
		if(!huffman.code[i].isEmpty())
		{
			cout<<(char)i<<' ';
			for(int j=0;j<huffman.code[i].getLength();j++)
			{
				cout<<huffman.code[i].getABit(j);
			}
			cout<<endl;
		}
	}
	*/
	FileHeader header;
	memset(&header,0,sizeof(header));
	header.id[0]='H';header.id[1]='F';
	memcpy(header.map,map,256);
	FILE* fout=fopen(outFileName,"wb");
	if(!fout) return;
	fin=fopen(inFileName,"rb");
	fwrite(&header,sizeof(header),1,fout);
	fclose(fout);
	CFileStream fileStream;
	if(fileStream.openOutStream(outFileName))
	{
		while((ch=fgetc(fin))!=-1)
		{
			fSize++;
			fileStream.pushBits(huffman.code[(unsigned char)ch]);
		}
		fileStream.closeOutStream();
	}
	fout=fopen(outFileName,"rb+");
	header.len=fSize;
	fwrite(&header,sizeof(header),1,fout);
	fclose(fout);
	fclose(fin);
}
int main()
{
	compress("1.txt","2.txt");
	printf("finished!");
	return 0;
}
