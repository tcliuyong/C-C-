/*
A number sequence is defined as follows:

f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

Given A, B, and n, you are to calculate the value of f(n).

*/
#include<stdio.h>
main()
{
	long int f[100];
	int a,b,i;
	long int n;
	scanf("%d%d%ld",&a,&b,&n);
	while(a>0&&b>0&&n>0)
	{
		f[0]=1;
		f[1]=1;
		for(i=2;i<48;i++)
		{
			f[i]=(a*f[i-1]+b*f[i-2])%7;
		}
		n=(n-1)%48;
		printf("%ld\n",f[n]);
		scanf("%d%d%ld",&a,&b,&n);
	}
}