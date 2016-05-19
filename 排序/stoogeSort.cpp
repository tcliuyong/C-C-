/*
*
*
*≥Ù∆§Ω≥≈≈–Ú …ı÷¡¬˝”Î√∞≈›≈≈–Ú£¨œ»≈≈–Ú«∞2/3 ‘Ÿ ≈≈–Ú∫Û2/3 
*
*/
#include<iostream>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
using namespace std;
#define N 10
class stoogeSort
{
	public:	
	void init();
	void sSort(int,int );
	void showArray(); 
	private:
	int *a;
	int i,j;
	
};
void stoogeSort::init()
{
	fstream in;
	i=0;
	j=10;
	in.open("data.txt",ios::in);
	a=(int *)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++)
	in>>*(a+i);
	return ;
}
void stoogeSort::sSort(int i,int j)
{
	if(a[i]>a[j])
	swap(a[i],a[j]);
	if(i+1>=j)
	return ;
	int k=(j-i+1)/3;
	sSort(i,j-k);		
	sSort(i+k,j);
	sSort(i,j-k);
}
void stoogeSort::showArray()
{
	for(int i=0;i<N;i++)
	{
		cout<<*(a+i)<<" ";
	}	
}
int main(int argc,char * argv[])
{
	stoogeSort S;
	S.init();
	S.sSort(0,9);
	S.showArray();
	return 0;
}