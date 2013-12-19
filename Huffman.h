#pragma once
#include "Bit.h"
class CHuffman
{
	bool stageCode[255];//¬Î◊÷‘›¥Ê«¯
	typedef struct _Node
	{
		_Node(int value,char data,_Node* l,_Node* r)
		{
			this->value=value;
			this->data=data;
			this->l=l;
			this->r=r;
		}
		int value;//»®÷ÿ
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
private:
	int destoryTreeR(LPNODE root);
	void generateCode(LPNODE root,int pos);
	void stageCodetoCode(unsigned char data,int len);
public:
	unsigned char getDataByCode(CBit& code);
};
