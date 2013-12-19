#include "Huffman.h"
#include <iostream>
using namespace std;

CHuffman::CHuffman(void):root(0)
{

}


CHuffman::~CHuffman(void)
{
	destoryTree();
}

void CHuffman::createByMap(int map[])
{
	LPNODE pNodes[256]={0};
	for(int i=0;i<256;i++)
	{
		pNodes[i]=new Node(map[i],i,0,0);
	}
	qsort(pNodes,0,255);
	int len=0;
	for(;len<256&&pNodes[len]->value!=0;len++);
	if(len==0) return;
	while(len>1)
	{
		LPNODE pTmpNode=new Node(pNodes[len-1]->value+pNodes[len-2]->value,
								0,pNodes[len-2],pNodes[len-1]);
		pNodes[len-2]=pTmpNode;
		len--;
		qsort(pNodes,0,len-1);
	}
	root=pNodes[0];
	if(root->r==NULL&&
		root->l==NULL)
	{
		code[root->data].appendABit(0);
		return;
	}
	memset(stageCode,0,256);
	generateCode(root,0);
}


void CHuffman::qsort(LPNODE* ppNodes, int start, int end,bool isDesc)
{
	if(end-start<=0) return;
	int i=start;
	int j=0;
	for(j=start;j<end;j++)
	{
		if(isDesc)
		{
			if(ppNodes[j]->value>ppNodes[end]->value)
			{
				swap(ppNodes[j],ppNodes[i]);
				i++;
			}
		}else
		{
			if(ppNodes[j]->value<ppNodes[end]->value)
			{
				swap(ppNodes[j],ppNodes[i]);
				i++;
			}
		}
	}
	if(i!=end)	swap(ppNodes[i],ppNodes[end]);
	CHuffman::qsort(ppNodes,start,i-1,isDesc);
	CHuffman::qsort(ppNodes,i+1,end,isDesc);
}


void CHuffman::destoryTree(void)
{
	destoryTreeR(root);
}


int CHuffman::destoryTreeR(LPNODE root)
{
	if(root)
	{
		destoryTreeR(root->l);
		destoryTreeR(root->r);
		delete root;
	}
	return 0;
}


unsigned char CHuffman::getDataByCode(CBit& code)
{
	LPNODE lpNode=root;
	for(int i=0;i<code.getLength();i++)
	{
		if(code.getABit(i)==0)
		{
			lpNode=root->l;
		}else
		{
			lpNode=root->r;
		}
	}
	return lpNode->data;
}

void CHuffman::generateCode(LPNODE root,int pos)
{
	if(root!=NULL)
	{
		if(root->l)
		{
			stageCode[pos]=0;
			generateCode(root->l,pos+1);
		}else
		{
			stageCodetoCode(root->data,pos);
			return;
		}
		if(root->r)
		{
			stageCode[pos]=1;
			generateCode(root->r,pos+1);
		}else
		{
			stageCodetoCode(root->data,pos);
		}
	}
}

void CHuffman::stageCodetoCode(unsigned char data,int len)
{
	for(int i=0;i<len;i++)
	{
		code[data].appendABit(stageCode[i]);
	}
}
