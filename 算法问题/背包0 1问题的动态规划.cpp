#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdio>
using namespace std;
int knapsack_dynamic(int w[],int p[],int n,int m, bool x[])
{
	int i,j,k;
	//int v,(*optp)[m+1] =new int[n+1][m+1];
	int v=0;
	int optp[n+1][m+1];
	 for(i=0;i<=n;i++)
	 {
 		optp[i][0]=0;
 		x[i]=false;
 	}
 	 for(i=0;i<=m;i++)
	 {
 		optp[0][i]=0;
 	}
 	for(i=1;i<=n;i++)
 	{
	 	for(j=1;j<=m;j++)
	 	{
	 		optp[i][j]=optp[i-1][j];
	 		if((j>=w[i])&&(optp[i-1][j-w[i]]+p[i])>optp[i-1][j])
                optp[i][j]=optp[i-1][j-w[i]]+p[i];
	 	}
	 }
	 j=m;
	 for(i=n;i>0;i--)
	 {
 		if(optp[i][j]>optp[i-1][j])
 		{
	 		x[i]=true;
 			j=j-w[i];
	 	}	 	
 	}
 	v=optp[n][m];
 
 	return v;
}
int main()
{
	int w[6]={0,2,2,6,5,4};
	int p[6]={0,6,3,5,4,6};
	int m=10;
	int n=5; 
	bool x[5];
	cout<<knapsack_dynamic(w,p,n,m,x)<<endl;
	return 0;
}

/*******************************************

#include <iostream>
#include <stdint.h>
using namespace std;
int knapsack_dynamic(int n,int m)
{
	int i,j,w[6],p[6];
	int optp[n+1][m+1];
	for(i = 1; i <= n; i++)
        scanf("%d%d", &w[i], &p[i]);
	for(i = 0; i <= n; ++i)
        for(j = 0; j <= m; j++)
            optp[i][j] = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            optp[i][j]=optp[i-1][j];
	 		if((j>=w[i])&&(optp[i-1][j-w[i]]+p[i])>optp[i-1][j])
                optp[i][j]=optp[i-1][j-w[i]]+p[i];
	 	}
    }
	return optp[n][m];
}
int main()
{
	int m=10;
	int n=5;
	cout<<knapsack_dynamic(n,m)<<endl;
	return 0;
}
	//int w[5]={2,2,6,5,4};
	//int p[5]={6,3,5,4,6};


*******************************************/