#include <iostream>
using namespace std;
void swap( int &a,  int &b)
{
		int tmp = a;
		a = b;
		b = tmp;
}
int main()
{ 
		int a = 1;
		int &a1 = a;
		int b = 2;
		int &a2 = b;
		swap(a1,a2);
		cout<<a<<b<<endl;
}
