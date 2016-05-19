#include <iostream>
using namespace std;
void swapr(int &a, int &b);
void swapp(int *p, int *q);
void swapv(int a, int b);
int main()
{
	int a = 100;
	int b = 200;
	 swapr(a, b);
	cout<<a<<" "<<b<<endl;
	 swapp(&a, &b);
	cout<<a<<" "<<b<<endl;
	 swapv(a, b);
	cout<<a<<" "<<b<<endl;
	
	return 0;
}
void swapr(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void swapp(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
void swapv(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;	
}