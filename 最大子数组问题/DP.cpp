/**
求最大子数组的问题 复杂度的O（n） 
**/
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#define N 17
//100 113 110 85 105 102 86 63 81 101 94 106 101 79 94 90 97 

int *a;
void init()
{
		fstream in;
		in.open("data1.txt",ios::in);
		a=(int *)malloc(sizeof(int)*N);
		for(int i=0;i<N;i++)
		in>>*(a+i);		
}
int MaxSubArrDP(int a[])
{
	int sumPre=0 ,max=-65535;
	for(int i=0;i<N;i++)
	{
		if(sumPre>0)	sumPre+=a[i];	
		else	        sumPre=a[i];	
		if(sumPre>max)  max=sumPre;
	}
	return max;
} 

int main(int argc,char *argv[])
{
	init();
	cout<<MaxSubArrDP(a)<<endl;
	return 0;
}