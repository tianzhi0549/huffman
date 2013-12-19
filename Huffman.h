#pragma once
#include "Bit.h"
class CHuffman
{
	bool stageCode[255];//码字暂存区
	typedef struct _Node
	{
		_Node(int value,char data,_Node* l,_Node* r)
		{
			this->value=value;
			this->data=data;
			this->l=l;
			this->r=r;
		}
		int value;//权重
		unsigned char data;
		_Node* l;
		_Node* r;
	}Node,*LPNODE;
public:
	CHuffman(void);
	virtual ~CHuffman(void);
	void createByMap(int  map[]);
	void qsort(LPNODE* ppNodes, int start, int end,bool isDesc=1);
	LPNODE root;
	CBit code[256];
	void destoryTree(void);
	int locateByABit(bool bit)
	{
		if(root==NULL) return -1;
		if(curNode==0) curNode=root;
		if(bit==0)
		{
			curNode=curNode->l;
		}else
		{
			curNode=curNode->r;
		}
		if(curNode->r==NULL&&curNode->l==NULL)
		{
			unsigned char ch=curNode->data;
			curNode=NULL;
			return ch;
		}else
		{
			return -1;
		}
	}
private:
	int destoryTreeR(LPNODE root);
	void generateCode(LPNODE root,int pos);
	void stageCodetoCode(unsigned char data,int len);
	LPNODE curNode;//当前定位到的节点
public:
	unsigned char getDataByCode(CBit& code);
};
