#pragma once
class CBit
{
	int len;
	unsigned char* lpBuffer;
	int bufferLen;
public:
	CBit(void);
	virtual ~CBit(void);
	void appendABit(bool bit);
};

