#include<iostream>
#include <cstring>
#include <stdlib.h>
#define N 10
using namespace std;
char *a;

bool compare(char a[],char b[])
{
	for(int i=0,j;i<N;i++)
	{
	 j=0;
		int x=i;
		if(a[i]!=b[j])
		{
			continue;	
		}
		while(a[x]==b[j])
		{
			x++;
			j++;
			if(j>=3)
			{
				return true;
			}
		}			
	}
	return false;
}
int main()
{
	a=(char *)malloc(sizeof(char)*N);
	char b[3]={'a','b','c'};
	for(int i=0;i<N;i++)
	cin>>*(a+i);
	//if(sizeof(a)<sizeof(b))
	//cout<<"No"<<endl;
	if(compare(a,b))
	cout<<"OK"<<endl;
	else
	cout<<"not OK"<<endl;
		
}