#include  "innersort.h"
void innersort::insertsort(int A[],int len)
{
	int i,j,key;
	 for(j=1;j<=len;j++)
	 {
			key=A[j];
			i=j-1;  
		  while((A[i]>0)&&(A[i]>key))
		  {
			A[i+1]=A[i];
			i--;
		  }
		A[i+1]=key;
	 }
}
void innersort::bubblesort(int arr[],int len)
{
		for(int i = 0; i < len; i++)
			for(int j = 0; j < len; j++)
			{
				int tmp;
				if(arr[i] < arr[j])
				{
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
}
