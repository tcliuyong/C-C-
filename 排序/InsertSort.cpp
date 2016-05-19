#include <iostream>
using namespace std;
void InsertSort(int *A,int len)
{
	int j;
	for(int i = 1; i < len; i++)
	{
		int v = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > v)
		{
			A[j + 1] = A[j];
			--j;
		}
		A[j + 1] = v;

	}

}
int main()
{
	int A[] = {4,3,6,1,0};
	InsertSort(A,5);
	for(int i = 0; i < 5; i++)
	{
		cout<< A[i]<<endl;
	}
	return 0;
}
