#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;
#define N 10

class heap
{
	public:
	void init();
	void MAX_HEAPIFY(int );
	void BUILD_MAX_HEAP();
	void heapSort();
	void showArray();
	private:
		int *a;
		int Heap_Size;
};
void  heap::init()
{
	Heap_Size=10;
	a=(int *)malloc(sizeof(int)*N);
	fstream in;
	in.open("data.txt",ios::in);
	for(int i=1;i<=N;i++)
	in>>*(a+i);
}
void heap:: MAX_HEAPIFY(int i)  
{
        int l = 2 * i ;                     
        int r = 2 * i + 1;                    
        int largest, tmp;
        if(l <= Heap_Size && a[i] < a[l])       
        {
            largest = l;
        }
        else                                   
        {
            largest = i;
        }
        if(r <= Heap_Size&& a[largest] < a[r]) 

        {
            largest = r;
        }

        if(largest != i)
        {
            tmp = a[i];
            a[i] = a[largest];
            a[largest] = tmp;
            MAX_HEAPIFY(largest); 
        }
}
void heap:: BUILD_MAX_HEAP()
{
        int i;
        for (i=Heap_Size/2; i>=1; i--)
        {
            MAX_HEAPIFY(i);
        }
}
void heap:: heapSort()
{
	BUILD_MAX_HEAP();
	for(int i=N;i>=2;i--)
	{
		swap(a[1],a[i]);
		Heap_Size--;
		MAX_HEAPIFY(1);
	}
}
void  heap::showArray()
{
		for(int i=1;i<=N;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}

int main(int argc,char * argv[])
{
	//-13 -3 -25 -20 -3 -4 -16 -23 -18 -20
	heap H;
	H.init();
	H.BUILD_MAX_HEAP();
	H.showArray();
	H.heapSort();
	H.showArray();
	return 0;
}

