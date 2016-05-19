#include <iostream>
#include <cmath>
using namespace std;
int main(int argc,char * argv[])
{

	int m,n;

	while(cin>>m>>n)	
	{
		if(m>=n)
		{
			int result=1;
			for(int i=m;i>n;i--)
			{
				//cout<<i<<endl;
				result*=i;				
			}		
			cout<<result<<endl;	
		}
		else
		{
			cout<<"m must bigger than n"<<endl;
		}
		

	}
			return 0;
}