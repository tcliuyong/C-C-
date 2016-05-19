#include "test.h"
using namespace std;
int main()
{
	extern Point p;
	while(cin>>p.x>>p.y)
	{
		cout<<add(p)<<endl;	
	}
}