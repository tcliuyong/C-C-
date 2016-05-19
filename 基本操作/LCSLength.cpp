#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#define N 100
void LCSLength(char *x,char *y,int m,int n,int c[][N],int b[][N])
{
	int i,j;
	for(i=0;i<=m;i++)
	c[i][0]=0;
	for(j=0;j<=n;j++)
	c[0][j]=0;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]= c[i-1][j-1]+1;
				b[i][j]=0;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=1;
			}
			else
			{
			c[i][j]=c[i][j-1];
			b[i][j]=-1;	
			}
		}
	
	}
}
void printLCS(int b[][N],char *x,int i,int j)
{
	if(i==0||j==0)
	return ;
	if(b[i][j]==0)
	{
		printLCS(b,x,i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if(b[i][j]==1)
	{
		printLCS(b,x,i-1,j);
	}
	else
	{
		printLCS(b,x,i,j-1);
	}
}
int main(int argc,char *argv)
{
char x[N]={"ABCBDAB"};
char y[N]={"BDCABA"};
int b[N][N];
int c[N][N];
int m,n;
m=strlen(x);
n=strlen(y);
LCSLength(x,y,m,n,c,b);
printLCS(b,x,m,n);
	return 0;
}