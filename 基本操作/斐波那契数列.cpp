#include <iostream>
using namespace std;
#define N 10
class fib
{
public:
void init();
void fibArry();
void outPut();
private:	
int *a;	
};
void fib::init()
{
	//a=(int *)malloc(sizeof(int)*N);
	
	a=new int[N];
	a[0]=1;
	a[1]=1;
	for(int i =2 ;i<N;i++)
	*(a+i)=0;
}
void fib::fibArry()
{
	for(int i=2;i<N;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
}
void fib::outPut()
{
	for(int i=0;i<N;i++)
	cout<<a[i]<<endl;
}
int main()
{
	fib F;
	F.init();
	F.fibArry();
	F.outPut();
	return 0;
}