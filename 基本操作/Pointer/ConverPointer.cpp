#include <iostream>
using namespace std;
int main()
{
	int i =7;
	char *cp =(char*) &i;
	cout<<"Integer at"<<&i<<" == "<<i<<endl;
	for(int n = 0; n < sizeof(i); n++)
	{
		cout<<"The byte at "<< (void *)(cp+n)<<" == "<<int(*(cp + n))<<endl;
	}
}