//qsort 用法
#include <iostream>
#include <algorithm>
using namespace std;
int  cmp(const  void *a,const void *b )
{
	return *(int *)b-*(int *)a ; //从大到小的排序 
}
int main()
{
	int A[10]={100,12,455,212,78,2,4578,12,1,87};
	qsort(A,10,sizeof(A[0]),cmp); 
	for(int i=0;i<10;i++) 
	cout<<A[i]<<" ";
	return 0;
} 