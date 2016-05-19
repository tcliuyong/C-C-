/********************************
目的:合并二个有序的数组
A[p]到A[q]有序 A[q+1]到A[r]有序
输出合并整个数组 并且达到整个数组有序
**************************************/


#include <iostream>
using namespace  std;
void merge(int A[],int p,int q,int r,int m)
{
 int *bp=new int [m];
int i,j,k;/
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
int main()
{
	int A[6]={1,2,5,3,4,6};
	merge(A,0,2,5,6);
	for (int i=0;i<=5;i++)
	{
		cout<<A[i];
	}
	cout<<endl;
	return 0;
}
