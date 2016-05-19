#include <iostream>
#include <stack.h>
using namespace std;
stack <int> S;
int temp;
void init()
{
	while(!S.empty())
	{
		S.pop();
	}
}
void change(int n)
{
	while(n)
		{
			temp=n%2;
			n/=2;
			S.push(temp);
		}
}
int main()
{
	init();
	int m;
	int x=0;
	cin>>m;
	cout<<"0";
	while(1)
	{
		change(x);
		if(S.size()>m)
		{
			return 0;
		}
		else
		{
			while(!S.empty())
			{
				cout<<S.top();
				S.pop();
			}			
				cout<<endl;	
		}
			x++;	
	}
	return 0;
}
