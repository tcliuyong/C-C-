#include <iostream>
using namespace std;
int main()
{
	int n,tmp,k,sum = 0;
	cin>>n;

	int *a = new int[n];
	tmp = 0;
	int m = n;
	while(n--)
	{
		cin>>*(a + tmp);
		tmp++;	
	}
	cin>>k;
	
	for(int i = 0; i < m; i++)
	{
		sum += a[i];
	for(int j = i+1; j < m; j++)
		{
			sum += a[j];		
			if(sum == k)	
			{
				cout<<i<<" "<<j<<endl;
				break;
			}
			else if(sum > k)
			{
				sum = 0;
				break;	
						
			}		
		}	
	}
	return 0;
}