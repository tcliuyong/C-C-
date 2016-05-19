#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;	
	while(cin>>n)
	{
		char s[1010][16];
		int i,j,max=0;
		int a[1010]={0};
		if(n==0)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			cin>>s[i];	
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1,a[i]=0;j<n;j++)
			{
				if(strcmp(s[i],s[j])==0)
				{
					a[i]++;
				}
			}
			if(a[i]>max)
			max=a[i];
		}
		for(i=0;i<n;i++)
		{
			if(a[i]==max)
			cout<<s[i]<<endl;
		}
		
	}
	return 0;
}