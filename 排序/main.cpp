#include  "innersort.h"
int main()
{
	int A[5] = {4,2,6,1,7};
	
	innersort I;
	//cout<<"t"<<endl;
	//I.insertsort(A,5);
	I.bubblesort(A,5);
	for(int i = 0; i < 5; i++)
	{
			cout<<A[i]<<endl;
	}
	
}
