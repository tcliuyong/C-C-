#include<iostream>
#include<cstring>
using namespace std;
const int MAX=10;
int a[MAX][MAX];

int main()
{
	int n,x,y,tot=0;
	cin>>n;
	memset(a,0,sizeof(a));		//����
	tot=a[x=0][y=n-1]=1;		//��һ������1��ʼ�λ��Ϊx=0,y=n-1
	while(tot<n*n)
	{
		while(x+1<n && !a[x+1][y]) a[++x][y]=++tot; //��������
		while(y-1>=0 && !a[x][y-1]) a[x][--y]=++tot; //��������
		while(x-1>=0 && !a[x-1][y]) a[--x][y]=++tot;	//��������
		while(y+1<n && !a[x][y+1]) a[x][++y]=++tot; //��������
	}
	for(x=0;x<n;x++)
	{
		for(y=0;y<n;y++)
			cout<<a[x][y]<<" ";
		cout<<endl;
	}
	return 0;
}