/**
求最大子数组的问题 复杂度的O（nlgon） 
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
int MaxSubArr(int a[],int low,int high)
{
	int sum ,max_left=-65535,max_right=-65535,mid=(low+high)/2;//1
	if(low==high)	//1
	{				
		return a[low];
	}
	
	if(high-low==1)
	{
		return max(max(a[low],a[high]),a[low]+a[high]);
	}
	int lmax=MaxSubArr(a,low,mid);   //T(n/2)
	int rmax=MaxSubArr(a,mid+1,high);//T(n/2)
	for(int i=mid,sum=0;i>=0;i--)//O(n)
	{
		sum+=a[i];
		if(sum>max_left)
		{
			max_left=sum;
		}
	}
	for(int i=mid+1,sum=0;i<N;i++)
	{
		sum+=a[i];
		if(sum>max_right)
		{
			max_right=sum;
		}
	}
	return max(max(lmax,rmax),max_right+max_left);
} 

int main(int argc,char *argv[])
{
	init();
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"result:"<<MaxSubArr(a,0,N-1)<<endl;
	return 0;
}