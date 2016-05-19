#include <iostream>
#include <algorithm>
using namespace std;
#define N 10
int a[N]={12,1,23,34,5,45,122,56,3,9};
int b[N];
void select()
{
	int j=0,i=0;
	for(;j<N-1;j++)
	{
		int k=j;
		int min=a[j];
		for(i=j+1;i<N;i++)
		{
			if(a[i]<=min)
			{
				min=a[i];
				k=i;
				
			}
		}
	swap(a[j],a[k]);
	}
}
int main(int argc, char * argv[])
{
	select();
		for(int w=0;w<N;w++)
		{
			cout<<a[w]<<endl;
		}
	return 0;
}

