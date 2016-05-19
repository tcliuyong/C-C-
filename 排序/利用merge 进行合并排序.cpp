#include <iostream>
using namespace std;
void merge(int A[],int p,int q,int r,int m)
{
 int *bp=new int [m];
int i,j,k;
 i=p;j=q+1;k=0;
 while(i<=q && j<=r){
 if(A[i]<=A[j])
	bp[k++]=A[i++];
 else
	bp[k++]=A[j++];
 }
 if (i==q+1)
 {
	 for (;j<=r;j++)
		 bp[k++]=A[j];
 }
 else{
	 for (;i<=q;i++)
		 bp[k++]=A[i];
	}
 k=0;
 for (i=p;i<=r;i++)
 {
	 A[i]=bp[k++];
 }
 delete bp;
}
void merge_sort(int A[],int n)
{
int i, s,t=1;
    while(t<n)
        {
        s=t;t=2*s;i=0;
            while(i+t<n)
            {
                merge(A,i,i+s-1,i+t-1,t);
                i+=t;
            }
            if(i+s<n)
            {
            merge(A,i,i+s-1,n-1,n-i);
            }
        }
}
int main()
{
int A[7]={1,4,3,2,6,68,9};
merge_sort(A,7);
for(int i=0;i<=6;i++)
{
    cout<<A[i]<<endl;
    }
}
