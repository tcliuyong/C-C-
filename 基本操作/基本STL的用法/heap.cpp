/**
 * 注意heap括号内的下标值变化 似乎要比
 * 原有长度大1
 * */
#include <algorithm>
#include <iostream>
#include <fstream>
#define N 10
//-13 -3 -25 -20 -3 -4 -16 -23 -18 -20
using namespace std;
int *a;
bool cmp(int a,int b)
{
	return a<b;
}
void init()
{
	a=(int *)malloc(sizeof(int)*N);
	fstream in;
	in.open("data.txt",ios::in);
	for(int i=0;i<N;i++)
	in>>*(a+i);
}
int main(int argc,char * argv[])
{
	init();
	make_heap(&a[0],&a[9],cmp);
	cout<<"build a heap:";
	for(int i=0;i<N;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	cout<<"add a element heap:";
	a[10]=8;
	push_heap(&a[0],&a[11],cmp);
	for(int i=0;i<=N;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	cout<<"delete a element heap:";
	pop_heap(&a[0],&a[11],cmp);
	for(int i=0;i<N;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
	
}
