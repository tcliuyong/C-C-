/*
n����������ڹ�������������аڷ�n���ʺ� ʹ���ǲ���ͬһ������ Ҳ����ͬһ������ Ȼ��Ҳ����б��Ϊ+-1��λ����
�������ǾͲ����໥��ɱ 

*/
#include <iostream>
#include <cmath>
using namespace std;
bool place(int x[],int k)//������x[]���ͻʺ���к�k��Ϊ���� 
{
	int i;
	for(i=1;i<k;i++)
	{
		if((x[i]==x[k])||(abs(x[i]-x[k])==abs(i-k)))
		{
			return false;
		}
	}
	return true;
}
void n_queens(int n,int x[])
{
	int k=1;
	x[0]=0;
	while(k>0)
	{
		x[k]++;
		while((x[k]<=n)&&(!place(x,k)))
		{
			x[k]++;
		}
		if(x[k]<=n)
		{
			if(k==n)
			break;
			else
			{
				k++;
				x[k]=0;
			}
		}
			else{
			x[k]=0;
			k--;
		}
		
	}
}
int main()
{
	int x[5]={0,0,0,0,0};
	int n=4;
	n_queens(n,x);
	for(int i=1;i<=4;i++)
	{
		cout<<x[i]<<" ";	
	}

	return 0;
} 