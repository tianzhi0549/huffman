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
	char id[2];//��ʶ
	int len;//ԭ�ļ�����
	int map[256];//���
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
	FileHeader header;
	memset(&header,0,sizeof(header));
	header.id[0]='H';header.id[1]='F';
	memcpy(header.map,map,256*sizeof(int));
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
void unCompress(const char* inFileName,const char* outFileName)
{
	FILE* fin=fopen(inFileName,"rb");
	if(!fin) return;
	FileHeader header;
	CHuffman huffman;
	CFileStream fileStream;
	fread(&header,sizeof(header),1,fin);
	fclose(fin);
	int decodedSize=0;//�ѽ����С
	int ch=0;
	if(header.id[0]=='H'&&header.id[1]=='F')
	{
		FILE* fout=fopen(outFileName,"wb");
		huffman.createByMap(header.map);
		if(fileStream.openInStream(inFileName))
		{
			fileStream.skip(sizeof(header));
			while(decodedSize!=header.len)
			{
				while((ch=huffman.locateByABit(
							fileStream.getCurrentBit()))==-1);
				fputc(ch,fout);
				decodedSize++;
			}
		}
		fileStream.closeInStream();
		fclose(fout);
	}else
	{
		cout<<"������ѹ���ļ���"<<endl;
	}
}
int main()
{
	char inFileName[1024]={0};
	char outFileName[1024]={0};
	int choose=0;
	do
	{
		cout<<"1.ѹ�� "<<"2.��ѹ"<<endl;
		cin>>choose;
	}while(choose!=1&&choose!=2);
	cout<<"�����ļ���";
	cin>>inFileName;
	cout<<"����ļ���";
	cin>>outFileName;
	cout<<"����ִ�г���..."<<endl;
	if(choose==1)
	{
		compress(inFileName,outFileName);
	}else if(choose==2)
	{
		unCompress(inFileName,outFileName);
	}
	cout<<"ִ����ɣ�"<<endl;
	system("pause");
	return 0;
}
