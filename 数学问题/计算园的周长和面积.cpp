#include<iostream>
#include <cmath>
using namespace std;
double const  pi=acos(double(-1));

double zhouchang(double r)
{
	return(2.0*pi*r);
} 
double mianji(double r)
{
	return (pi*r*r);
}

int main()
{
	double  r;
	double  h;
	while(cin>>r>>h)
	{
		cout<<"周长"<<zhouchang(r)<<endl;
		cout<<"面积"<<mianji(r)<<endl;
		cout<<"体积" <<mianji(r)*h<<endl;
	}
	return 0;
} 