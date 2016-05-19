#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
enum extd{user=1,admin=0};
typedef struct A
{
	char a[10];
	int x;
};
int a1=1,a2=1;
int A[100];
int heno(int n)
{
	if(n<=2)
	{
		return 1;
	}
	else
	{
		
		return heno(n-2)+heno(n-1);
	}
	
}
int main()
{
int n;
while(1)
{	cin>>n;
	cout<<heno(n)<<endl;
}
}