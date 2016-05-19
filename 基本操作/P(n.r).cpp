#include <iostream>
using namespace std;
int main()
{
	int n,r;
	
	while(cin>>n>>r)
	{
	int result=1;
	 for(int i=n;i>n-r;i--)
		{
		result*=i;					
		}
	cout<<result<<endl;	
	
	}
	return 0;
}