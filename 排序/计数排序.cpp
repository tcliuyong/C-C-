/*
 *
 *计数排序算法 数组c记下每个a中每个元素的个数 然后c负责把每个元素记住比他大和比他 
 *小的部分，b是最终的数组 
 * 2 5 3 0 2 3 0 3
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring> 
#include <algorithm>
#define N 8
#define M 100
using namespace std;
class Count
{
	public:
	void init();
	void countSort();
	void raidxSort();
	void showArray();
	private:
	int *a;
	int *b;
	int *c;
	int k;
}; 
void Count::init()
{
	fstream in;
	k=5;
	a=(int *)malloc(sizeof(int)*N);
	b=(int *)malloc(sizeof(int)*N);
	c=(int *)malloc(sizeof(int)*k);
	in.open("data.txt",ios::in);
	memset(b,0,sizeof(int));
	memset(c,0,sizeof(int));
	for(int i =1;i <= N ; i ++ )
	{
		in>>*(a+i);
	//	cout<<*(a+i)<<"";
	}
}
void Count::countSort()
{
	for(int i=0;i<=k;i++)
	{
		c[i]=0;
	}
	for(int i=1;i<=N;i++)
	{
		c[a[i]]++;	
	}
	for(int j=1;j<=k;j++)
	{
		c[j]+=c[j-1];
	}
	for(int i=N;i>=1;i--)
	{
		b[c[a[i]]]=a[i];
		c[a[i]]=c[a[i]]-1;	
	}
}
void Count::showArray()
{
	for(int i=1;i<=N;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
}
int main(int argc, char * argv[])
{
	Count C;
	C.init();
	C.countSort();
	C.showArray();
	return 0;
}