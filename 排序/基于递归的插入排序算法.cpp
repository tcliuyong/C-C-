#include <iostream>
using namespace std;
void insert_sort_rec(int A[],int n)
{
    int k;
    int a;
    n-=1;
    if(n>0)
    {
    insert_sort_rec(A,n);
    a=A[n];
    k=n-1;
    while(k>=0&&A[k]>a)
        {
            A[k+1]=A[k];
            k-=1;
        }
        A[k+1]=a;
    }
}
int main()
{
    int A[3]={1,3,2};
    insert_sort_rec(A,3);
    for(int i=0;i<=2;i++)
    {
        cout<<A[i]<<" "<<endl;
    }
    return 0;
}
