#include <iostream>
using namespace std;
#define SWAP(T,a,b){T t=a;a=b;b=t;}
int main()
{
	int a=2,b=3;
	SWAP(int,a,b);
	cout<<a<<b<<endl;
	return 0;
}

