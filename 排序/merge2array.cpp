#include <iostream>
using namespace std;
#define n 5
#define m 5
#define x m+n
int a[n]={1,3,45,66,86};
int b[m]={2,4,12,23,33};
int c[m+n];
int w=0;
int i=0,j=0;
void merge(int a[n],int b[m],int c[x])
{
	for(;i<n&&j<m;)
	{
		if(a[i]<=b[j])
		{
			c[w++]=a[i++];
		}
		else
		{
			c[w++]=b[j++];
		}
	}
	if(i==n)
	{
		for(;j<m;)
		c[w++]=b[j++];
	}
	else
	{
		for(;i<n;)
		c[w++]=a[i++];

	}
}
int main(int argc,char *argv[])
{
	merge(a,b,c);
	for(int i=0;i<m+n;i++)
	cout<<c[i]<<" ";
	return 0;
}
