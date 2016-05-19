#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{	int *a,*b;
	a=(int *)malloc(sizeof(int)*10);
	a=static_cast<int *>malloc(sizeof(int)*10);
	b=new int;
	b=new int(888)//³õÊ¼»¯ 
	b=new int[10]; 
	delete b;
	delete [] b;
	free(a);
	malloc ->free
	new ->delete
	return 0;
}