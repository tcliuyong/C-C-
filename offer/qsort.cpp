#include<stdio.h>
#include<stdlib.h>
void qsort(int *a,int left,int right)
{
	int i = left;
	int j = right;
	int key = *(a + left);
	if(left > right )
	{
		return ;
	}
	else
	{
		while(i < j && key <= *( a + j))
		{
			j--;	
		}
		*( a + i) = *( a + j);
		while(i < j && key > *( a + i))
		{
			i++;
		}
		  *( a + j) = *( a + i);
	}
	  *( a + i) = key;
	  qsort(a,left,i - 1);
	  qsort(a,i + 1 ,right);
}
int main()
{
	int i;
	int a[5] = {1,2,3,4,0};
	qsort(a,0,5);
	for(i = 0; i < 5; i++)
	printf("%d\n",a[i]);	
	return 0;
}