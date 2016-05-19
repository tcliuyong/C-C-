#include <iostream>
using namespace std;
int main()
{
	int *pt = new int;
	*pt = 1001;
	int a = *pt;
	cout<<a<<endl;
	cout<<sizeof(*pt)<<endl;
	delete pt;
	return 0;
}