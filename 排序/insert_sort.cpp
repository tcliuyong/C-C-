#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	int A[11]={1,56,4,5,8,7,4,11,12,0,6};
	int key,i;
	int len = sizeof(A)/sizeof(int);  
	
	for(int j=2;j<len;j++)
	{
		key=A[j];
		i=j-1;
		while(i>=0&&A[i]>key)
		{
			A[i+1]=A[i];
			i--;
			A[i+1]=key;
		}
	
	}	
	for(int k=0;k<10;k++)
	cout<<A[k]<<endl;
	return 0;
}
