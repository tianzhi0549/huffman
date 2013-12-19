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
void compress(const char* inFileName,const char* outFileName)
{
	CHuffman huffman;
	 char ch=0;
	int map[256]={0};
	ifstream fin(inFileName);
	if(!fin) return;
	while(!fin.eof())
	{
		fin.get(ch);
		map[(unsigned char)ch]++;
	}
	fin.close();
	huffman.createByMap(map);
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
}
int main()
{
	compress("1.txt","2.txt");
	getchar();
	return 0;
}
