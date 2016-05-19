#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#define N 10
int *a;
void swap(int *x,int  *y)
{
int *temp;
temp=x;
x=y;
y=temp;
}
void init()
{
	a=(int *)malloc(sizeof(int)*N);
	fstream in;
	in.open("data.txt",ios::in);
	for(int i =0;i<N;i++)
	in>>*(a+i);
}
int split(int A[],int low ,int high)
{
int k,i=low;
int x=A[low];
    for(k=low+1;k<=high;k++)
    {
        if(A[k]<x)
        {
        i=i+1;
        if(i!=k)
        swap(A[i],A[k]);
        }
    }
    swap(A[low],A[i]);
    return i;
}
void quick_sort(int A[],int low,int high)
{
int k;
	if(low<high)
	{
		k=split(A,low,high);
		quick_sort(A,low,k-1);
		quick_sort(A,k+1,high);
	}
}
int main()
{
	init();
quick_sort(a,0,9);
for(int i=0;i<N;i++)
{
cout<<a[i]<<" "<<endl;
}
return 0;
}
