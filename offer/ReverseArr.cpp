#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int FindReverseA(int a[],int len)
{
	int start = 0,end = len -1,middle = start;
	while(a[start] >= a[end])
	{
		if(end - start == 1)
		{
			middle = end;
			break;
		}
		middle = (start + end )/2;
		if(a[middle] >= a[start])
		start = middle;
		else if(a[middle] <= a[end])
		end = middle;
	}
	return a[middle];
}
int main()
{
	int a[] = {3,4,5,1,2};
	int b = FindReverseA(a,5);
	printf("%d\n",b);
}