/*
����һ���ַ� �ֱ� �Ա���ʼλ�� �� ����Ϊֹ ��С�����
*/ 

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int start = 0,end = n - 1;
	int p = 0;
	char A[n];
	char B[n];
	for(int i = 0; i < n ;i++)
	{
		cin>>A[i];
	}
	//cout<<('A'>'B')<<endl;
	for(int i = 0; i < n; i++)
	{
		if(A[start] >= A[end])
		{
			cout<<p<<endl;
			B[p] = A[end];
			p++;
			end--;		
		}	
		else if(A[start] < A[end])
		{
			B[p] = A[start];
			p++;
			start++;		
		}
	}
	for(int i = 0; i < n; i++)
		cout<<B[i]<<endl;
}