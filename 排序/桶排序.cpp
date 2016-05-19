#include <iostream>
#include <cstdlib>
using namespace std;
#define N 1000
bool *a;
int main(int argc,char *argv[])
{
	int n;
	a=(bool *)malloc(N  * sizeof(bool));
	for(int i=0;i<N;i++)
	*(a+i)=false;
	for(int i=0;i<=10;i++)
	{
		cin>>n;
		*(a+n)=true;
		
	}
	for(int i=0;i<N;i++)
	{
		if(*(a+i)==true)
		{
			cout<<i<<" ";
		}
	}
	
	
	return 0;
}
