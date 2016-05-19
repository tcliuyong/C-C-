#include <iostream>
using namespace std;
#define N 10
int a[N]={0,1,2,4,5,6,7,8,9,10}; 
int search2part(int left, int right,int n)
{
	
	int mid=(left+right)/2;	
		
	if(a[mid]==n)
	{
		return mid;
	}
	if(left<right)
	{
		if(a[mid]>n)
		{
			return  search2part(left,mid,n);
		}
		else
		//if(a[mid]>n)
		{
			return  search2part(mid+1,right,n);	
		}	
	}
	
	return -1;
}
int main(int argc,char *argv[])
{
	int n;
	cout<<"input a number:"<<endl;
	cin>>n;
	if(search2part(0,N-1,n)==-1)
	cout<<"can not find "<<endl;
	else
	cout<<search2part(0,N-1,n)<<endl;
	return 0;
}