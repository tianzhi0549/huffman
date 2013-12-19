#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <iostream>
#include "FileBitStream.h"
#include "Bit.h"
using namespace std;
int main()
{
	CBit a;
	for(int i=0;i<a.getLength();i++)
	{
		cout<<a.getABit(i);
	}
	getchar();
	return 0;
}
