#include<stdio.h>
#include<stdlib.h>
bool binSearch(int a[],int len,int data)
{
	int start = 0;
	int end = len;
	int mid;
	while(start <= end)
	{
 		mid = (start + end)/2;
		if(data < a[mid])
		{
			end = mid;
		}
		else if(data > a[mid])
		{
			start = mid;	
		}
		else
		{
			printf("%d\n",mid);
			return true;
		}
	}

	return false; 
}
int main()
{
	int a[5] = {1,2,3,4,5};
	if(binSearch(a,5,4))
	{
		printf("success\n");
	}
	else
	{
		printf("fail\n");
	}
	return 0;
}