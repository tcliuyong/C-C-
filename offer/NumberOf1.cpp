#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
	int n = 10;
	int sum = 0;
	while(n)
	{
		if(n & 1)
		sum ++;
		n = n >>1;	
		
	}
	printf("%d\n",sum);
	return 0;
}