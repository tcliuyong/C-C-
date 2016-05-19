#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
#define N 10
int *a;
void init()
{
	fstream in;
	a=(int *)malloc(sizeof(int)*N);
	in.open("data.txt",ios::in);
	for(int i=0;i<N;i++)
	in>>*(a+i);
}
bool cmp(int a,int b)
{
	return a>b;
}
//-13 -3 -25 -20 -3 -4 -16 -23 -18 -20
void heapSort()
{
	for(int i=0;i<N;i++)
	{
		make_heap(&a[0],&a[N-i-1],cmp);
		pop_heap(&a[0],&a[N-i],cmp);
		cout<<a[N-i-1]<<endl;
	}
}
int main(int argc ,char * argv[])
{
	init();
	heapSort();
	return 0;
}
