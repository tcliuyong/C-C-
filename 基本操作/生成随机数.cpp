#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	time_t y=time(0);
	cout<<y<<endl;
	srand(y);
	int x=rand()%10000;
	cout<<x<<endl;
}