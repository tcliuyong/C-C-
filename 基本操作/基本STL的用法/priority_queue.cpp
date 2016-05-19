#include <iostream>
#include <queue>
#include <stdlib.h>
#include <fstream>
using namespace std;
#define N 10
int *a;
void init()
{
	a=(int *)malloc(sizeof(int)*N);
	fstream in;
	in.open("data.txt",ios::in);
	for(int i=0;i<N;i++)
	in>>*(a+i);
}
int main(int argc,char *argv[])
{
	init();
	priority_queue<int ,vector<int>,less<int> > q;
	//priority_queue<int > q;
	for(int i=0;i<N;i++)
	{
		q.push(a[i]);
	}
	
	while(!q.empty())
	{
		cout<<q.top()<<" ";
		q.pop();
	}
	return 0;
}

