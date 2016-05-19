#include <stdio.h>
#include <stdlib.h>
void Merge(int A[],int lenA,int B[],int lenB)
{
	int i,j;
	int lA = lenA -1;
	int lB = lenB -1;
	for(i = lenA + lenB - 1; i>=0; --i)
	{
		if(A[lA] >= B[lB])
		{
			A[i] = A[lA];
			lA--;
			if(lA < 0)
			{
				while(lB >= 0)
				{
					A[--i] = B[lB];
					lB--;
				}
				break;
			}
		}
		else
		{
			A[i] = B[lB];
			lB--;
			if(lB < 0)
			{
				while(lA >= 0)
				{
					A[--i] = A[lA];
					lA--;
				}
				break;
			}
		}
		
	}
	for(i = 0; i < lenA + lenB - 1; i++)
	{
		printf("%d\n",A[i]);
	}
}
int main()
{
	int i,j;
	int A[100] = {3,4,5,10,20};
	int B[5] = {2,6,15,16,30};
	Merge(A,5,B,5);
	return 0;
}