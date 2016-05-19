#include <iostream>
#include <stdlib.h>
using namespace std;
class Color{
	friend int mColoring(int ,int ,int **);
private:
	bool Ok(int k);
	void Backtrack(int t);
	int n,m,**a,*x, sum;
};
bool Color::Ok(int k)
{
	for(int j=1;j<=n;j++)
	{
		if(a[k][j]==1&&x[j]==x[k])
			return false;
	}
		return true;
}
	void Color::Backtrack(int t)
	{
		if(t>n)
		{
			sum++;
			for(int i=1;i<=n;i++)
			{
				cout<<x[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			for(int i=1;i<=m;i++)
			{
			//	x[i]=i;
				x[t]=i;
				if(Ok(t))
					Backtrack(t+1);
				x[t]=0;
			}

		}
	}
int mColoring(int n,int m,int **a)
{
	Color X;
	X.n=n;
	X.m=m;
	X.a=a;
	X.sum=0;
	int *p=new int [n+1];
	for(int i=0;i<=n;i++)
	{
		p[i]=0;
	}
	X.x=p;
	X.Backtrack(1);
	delete [] p;
	return X.sum;
}
int main()
{
	int n,c,i,j;
	cin>>n>>c;
	int **M;
	M=(int **)new (int* [n+1]);
	for( i=1;i<=n;i++)
		M[i]=(int *)new (int [n+1]);
	for( i=1;i<=n;i++)
	{
		for( j=1;j<=n;j++)
		{
		cin>>M[i][j];
		}
	}
	int t=mColoring(n,c,M);
	
	if(t)
	{
		cout<<t<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}

return 0;
}
