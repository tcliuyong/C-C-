#include <iostream>
using namespace std;
namespace ly
{
double f;	
void test()
{
	
	cout<<"test"<<endl;
}
};
int main()
{
	using namespace ly;
	ly::f = 10;
	ly::test();
	cout<<f<<endl;
	return 0;
	
}