/*
����һ������ͼ  ��m����ɫ Ϊͼ�е�ÿ��������ɫ Ҫ��ÿ�����ڽڵ����ɫ������ͬ �������� ���ǵ�ͼ����ɫ���� 
Լ������ x[i} != x[j] ��i j �ڵ����� 
n ��󶥵��� 
m �����ɫ�� 
x[] �������ɫ 
c[][] ͼ���ڽӾ��� 
*/
#include <iostream>
#include <cmath>
using namespace std;
bool ok(int x[],int k,bool c[5][5],int n)
{
	int i;
	for(i=0;i<k;i++)
	{
		if(c[k][i]&&(x[k]==x[i]))
		{
			return false;

		}
	}
	return true;
}  
void m_color(int n,int m ,int x[],bool c[5][5])
{
	int i,k;
	for(i=0;i<n;i++)
	{
		x[i]=0;
	}
	k=0;
	while(k>=0)
	{
		x[k]++;
		while((x[k]<=m)&&(!ok(x,k,c,n)))
		{
			x[k]++;
		}
		if(x[k]<=m)
		{
			if(k==n-1)
			break;
			else
				k++;
		}
		else
		{
			x[k]=0;
			k--;
		}
	}
}
int main()
{
	int n=5,m=3;
	int x[5]={0,0,0,0,0};
 	bool c[5][5]={{false,true,true,false,false},{true,false,true,true,true},{true,true,false,false,true},{false,true,false,false,true},{false,true,true,true,false}}; 
	m_color(n,m,x,c);
	for(int i=0;i<5;i++)
	{
		cout<<x[i]<<endl;
	}
	return 0;
}