#include <iostream>
using namespace std;
#define SWAP(T,a,b){T t=a;a=b;b=t;}
int main()
{
char a[10]={'a','b'};
char *p;
*p='w';
//p=&a[0];
cout<<*p<<endl;
	
	return 0;
}