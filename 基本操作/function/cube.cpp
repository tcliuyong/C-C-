#include <iostream>
using namespace std;
double cube(double x);
double refcube(double &x);
int main()
{
	double a = 3.0;
	cout<<cube(a)<<" ";
	cout<<a<<endl;
	cout<<refcube(a)<<" ";
	cout<<a<<endl;
	
	return 0;
}
double cube(double a)
{
	
	return a *= a * a;
	 
}
double refcube(double &a)
{
	
	return a *= a * a;
}