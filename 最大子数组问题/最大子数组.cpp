#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#define N 17
int *a;
void init()
{
	
	fstream in;
	in.open("data1.txt",ios::in);
	a=(int *)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++)
	in>>*(a+i);		
	
}
int main(int argc,char *argv[])
{
	init();
	int i,j,k;
	int sum;
	int max=-65535;
	bool flag=false;
	for(i=0;i<N;i++)
	cout<<a[i]<<" ";
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(a[j]==0)
			{
				flag=true;
			}
			sum=0;
			for(k=i;k<=j;k++)
			{
				sum+=a[k];
			}  
			if(sum>max&&sum!=0)
			max=sum;
			if(max<=0&&flag)
			max=0;
			
		}
	}
	cout<<endl;
	cout<<"result:"<<max<<endl;

	return 0;
} 