#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class BitonicSort
{
public:
	BitonicSort();
	~BitonicSort();
	void InitRandData(int n);
	void SortUp(int beg,int n);//beg开始的位置，n为要排序的数量
	void SortDown(int beg,int n);//beg开始的位置，n为要排序的数量
	void MergeUp(int beg,int n);//beg开始的位置，n为要排序的数量
	void MergeDown(int beg,int n);//beg开始的位置，n为要排序的数量
	void OutputArray();//输出array
	void Exchange(int &a,int &b);
	bool CheckResult();
private:
	vector<int> array;
};

void BitonicSort::Exchange(int &a,int &b)
{
	int tmpValue;
	tmpValue=a;
	a=b;
	b=tmpValue;
	return;
}

BitonicSort::BitonicSort()
{
	array.clear();
}

BitonicSort::~BitonicSort()
{
	array.clear();
}

void BitonicSort::SortUp(int beg,int n)
{
	if(n==1)return;
	SortUp(beg,n/2);
	SortDown(beg+n/2,n/2);
	MergeUp(beg,n);
	return;
}

void BitonicSort::SortDown(int beg,int n)
{
	if(n==1)return;
	SortUp(beg,n/2);
	SortDown(beg+n/2,n/2);
	MergeDown(beg,n);
}

void BitonicSort::MergeUp(int beg,int n)
{
	if(n==1)return;
	int halfN=n>>1;
	for(int i=beg;i<beg+halfN;i++)
	{
		if(array[i]>array[i+halfN])Exchange(array[i],array[i+halfN]);
	}
	MergeUp(beg,halfN);
	MergeUp(beg+halfN,halfN);
	return;
}

void BitonicSort::MergeDown(int beg,int n)
{
	if(n==1)return;
	int halfN=n>>1;
	for(int i=beg;i<beg+halfN;i++)
	{
		if(array[i]<array[i+halfN])Exchange(array[i],array[i+halfN]);
	}
	MergeDown(beg,halfN);
	MergeDown(beg+halfN,halfN);
	return;
}


void BitonicSort::InitRandData(int n)
{
	for(int i=0;i<n;i++)
	{
		array.push_back(rand()%10000);
	}
	return;
}

void BitonicSort::OutputArray()
{
	for(vector<int>::iterator iter=array.begin();iter!=array.end();iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
	return;
}


bool BitonicSort::CheckResult()
{
	for(int i=0;i<array.size()-1;i++)
	{
		if(array[i]>array[i+1])return false;
		else continue;
	}
	return true;
}


int main()
{
	BitonicSort biSort;

	int n=11000;

	biSort.InitRandData(n);

	biSort.SortUp(0,n);

	cout<<"The Sorted Result is:"<<endl;
	biSort.OutputArray();

	if(biSort.CheckResult())
	{
		cout<<"Sort Successfully"<<endl;
	}
	else
	{
		cout<<"Sort Falied"<<endl;
	}
}