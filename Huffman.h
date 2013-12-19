#pragma once
class CHuffman
{
	typedef struct _Node
	{
		_Node(int value,char data,_Node* l,_Node* r)
		{
			this->value=value;
			this->data=data;
			this->l=l;
			this->r=r;
		}
		int value;//ШЈжи
		unsigned char data;
		_Node* l;
		_Node* r;
	}Node,*LPNODE;
public:
	CHuffman(void);
	virtual ~CHuffman(void);
	void createByMap(int  map[]);
	void qsort(LPNODE* ppNodes, int start, int end);
	LPNODE root;
	void destoryTree(void);
private:
	int destoryTreeR(LPNODE root);
public:
	int getDataByCode(CBit& code);
};
