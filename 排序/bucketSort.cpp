#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define Max 100
#define N 10
class buckSort
{
	public:
	void init();
	void bSort();
	void showArray();
	private:
	int *a;
	int *b;
	
};
void buckSort::init()
{
	fstream in;
	in.open("data.txt",ios::in);
	a=(int *)malloc(sizeof(int)*N);
	b=(int *)malloc(sizeof(int)*Max);
	//memset(b,0,sizeof(int));
	for(int i =0;i<Max;i++)
	*(b+i)=0;
	for(int i =0;i<N;i++)
	in>>*(a+i);
}
void buckSort::bSort()
{
	for(int i=0;i<N;i++)
	{
		b[a[i]]++;		
	}	
}
void buckSort::showArray()
{
	for(int i=0;i<Max;i++)
	{
		while(b[i]!=0)
		{
			cout<<i<<" ";
			cout<<b[i]<<" ";
			b[i]--;	
			system("pause");
		}
	}
	
}
int main(int argc,char * argv[])
{
	buckSort B;
	B.init();
	B.bSort();
	B.showArray();
	return 0;
}