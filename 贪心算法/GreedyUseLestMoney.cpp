/*
��1 5 10 50 100 500 ԪǮ ������� ���������ٵ�Ǯ֧����Щ���� ǰ6 ������ֱ���ÿ����ֵ��Ǯ������
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
	int t = min(N/c[i],a[i]);//�㾦 
	N -= t * c[i];
	ans += t;  
	}
	cout<<ans<<endl; 
	
}