#include <stdio.h>
#include <string.h>
int gcd(int a,int b)
{
	int min;
	int g;
	if(a<=0 || b <= 0)return -1;
	if(a > b)
	{
		min = b;
	}
	else
	{
		min = a;
	}
	
	while(min)
	{
		if(a % min == 0 && b % min == 0)
		{
			return min;
		}
		else
		{
			min--;
		}
	}
	return -1;
}
int lcm(int a,int b)
{
	int max;
	if(a<=0 || b <= 0)return -1;
	if(a > b)
	{
		max = a;
	}
	else
	{
		max = b;
	}
		while(max)
	{
		
		if(max % a == 0 && max % b == 0)
		{
			return max;
		}
		else
		{
			max++;
		}
	
	}
	return -1;
}
int main()
{
	int a = 12,b = 5;
	int g  = gcd(a,b);
	printf("%d\n",g); 
	int l  = lcm(a,b);
	printf("%d\n",l); 
	
}

