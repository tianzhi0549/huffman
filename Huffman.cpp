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
	for(;pNodes[len]->value!=0;len++);
	if(len==0) return;
	while(len>1)
	{
		LPNODE pTmpNode=new Node(pNodes[len-1]->value+pNodes[len-2]->value,
								0,pNodes[len-2],pNodes[len-1]);
		pNodes[len-2]=pTmpNode;
		len--;
	}
	root=pNodes[0];
}


void CHuffman::qsort(LPNODE* ppNodes, int start, int end)
{
	if(end-start<=0) return;
	int i=0;
	int j=0;
	for(j=0;j<end;j++)
	{
		if(ppNodes[j]->value>ppNodes[end]->value)
		{
			swap(ppNodes[j],ppNodes[i]);
			i++;
		}
	}
	if(i!=end)	swap(ppNodes[i],ppNodes[end]);
	qsort(ppNodes,0,i-1);
	qsort(ppNodes,i+1,end);
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


int CHuffman::getDataByCode(CBit& code)
{
	return 0;
}
