/*
n后问题就是在国际象棋的棋盘中摆放n个皇后 使他们不再同一个行上 也不再同一个列上 然后也不在斜率为+-1的位置上
这样他们就不能相互厮杀 

*/
#include <iostream>
#include <cmath>
using namespace std;
bool place(int x[],int k)//解向量x[]，和皇后的行号k作为参数 
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