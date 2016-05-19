/**
求最大子数组的问题 复杂度的O（n平方） 
**/
#include <iostream>
#include <fstream>
using namespace std;
#define N 17
//100 113 110 85 105 102 86 63 81 101 94 106 101 79 94 90 97 

int *a;
void init()
{
		fstream in;
		in.open("data.txt",ios::in);
		a=(int *)malloc(sizeof(int)*N);
		for(int i=0;i<N;i++)
		in>>*(a+i);	
}
int MaxSubArry(int a[])
{
	int i,j,k;
	int result=-65535;
	for(int i=0;i<N;i++)
	{
		int temp=a[i];
		int mx=a[i];//
		for(int j=i+1;j<N;j++)
		{
			temp+=a[j];
			if(temp>=mx)
			{
				mx=temp;
			}
		}
		if(result<mx)
		{
			result=mx;
		}				
	}
	return result;
} 

int main(int argc,char *argv[])
{
	init();
	cout<<MaxSubArry(a)<<endl;
	return 0;
}