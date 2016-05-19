/*
有1 5 10 50 100 500 元钱 给你个数 让你用最少的钱支付这些费用 前6 个输入分别是每种面值的钱的数量
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
	//int *a = new int[5];
	int ans = 0;
	int a[6],N;
	int c[6] = {1,5,10,50,100,500};
	for(int i = 0; i < 6; i++)
	{
		cin>>a[i];
	}
	cout<<endl;
	cout<<"input the sum money:";
	cin>>N;
		 
	
	for(int i = 5; i >= 0; i--)
	{
	//	cout<<a[i]<<" ";
	int t = min(N/c[i],a[i]);//点睛 
	N -= t * c[i];
	ans += t;  
	}
	cout<<ans<<endl; 
	
}