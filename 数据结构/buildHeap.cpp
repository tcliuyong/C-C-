#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
//-13 -3 -25 -20 -3 -4 -16 -23 -18 -20
#define N 10
int *a;
void init()
{
	a=(int *)malloc(sizeof(int)*N);
	fstream in;
	in.open("data.txt",ios::in);
	for(int i=1;i<=N;i++)
	in>>*(a+i);
}
void upHeap(int i)
{
	if(i/2==0)
	{
		return ;
	}
	while(a[i]>a[i/2])
	{
		if(i/2==0)
		{
			return ;
		}
		swap(a[i],a[i/2]);
		i/=2;
	}
}
void downHeap(int i)
{
	if(i/2==0)
	{
		return ;
	}
	while(a[i]<=a[i/2])
	{
		if(i/2==0)
		{
			return ;
		}
		swap(a[i],a[i/2]);
		i/=2;
	}
}
/**
 * 同样适合调整堆的结构
 *
 */
void buildMaxHeap(int a[])
{
	for(int i=1;i<=N;i++)
	{
		upHeap(i);
		//cout<<a[i]<<endl;
	}
}
void buildMinHeap(int a[])
{
	for(int i=1;i<=N;i++)
	{
		downHeap(i);
		//cout<<a[i]<<endl;
	}
}
void showHeap()
{
	for(int i=1;i<=N;i++)
	{
		cout<<a[i]<<" ";
	}
}

int main(int argc,char * argv[])
{
	init();
	//buildMaxHeap(a);
	buildMinHeap(a);
	showHeap();
	return 0;
}
