/*
æÿ’Ûœ‡≥À  O£®n3£© 
*/ 
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#define N 2
#define M 2
using namespace std;
int a[N][N];
int b[N][N];
int c[N][N];
void init()
{
		fstream matrix1;
		fstream matrix2;
		matrix1.open("matrix1.txt",ios::in);
		matrix2.open("matrix2.txt",ios::in);
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				matrix1>>a[i][j];		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				matrix2>>b[i][j];
}
int main(int argc,char * argv[])
{
		init();
		int k=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				for(int k=0;k<N;k++)
				{
					c[i][j]+=a[i][k]*b[k][j];
				}
			//c[i][j]=a[i][j]*b[j][i]+a[][]*b[][];	
			
			}	
		}
		for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					if(k%N==0)
					cout<<endl;
					cout<<c[i][j]<<" ";
					k++;		
				}
			//c[i][j]=a[i][j]*b[j][i]+a[][]*b[][];	
			
			}	
	return 0;
} 