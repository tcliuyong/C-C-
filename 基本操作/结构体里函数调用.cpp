#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct A
{
	int a;
    void print()
	{
    cout<<"sdf"<<endl;	
    }
};
int main()
{	
	A a;
	//a->print();
	a.a=10;
	cout<<a.a<<endl;
	a.print();
	return 0;
}