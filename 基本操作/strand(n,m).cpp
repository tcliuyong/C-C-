#include <iostream>
#include <time.h>
using namespace std;
void strand(int n,int m)
{
	time_t s=time(0);
	srand(s);
	int x;
	for(int i=0;i<=100;i++)
	cout<<rand()%(m+1-n)+n<<" ";
}
int main(int argc,char *argv[])
{
	int m;
	int n;
	cin>>n>>m;

	strand(n,m);
	return 0;
}