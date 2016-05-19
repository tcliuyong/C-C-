#include <iostream>
#include <algorithm>
using namespace std;
struct A
{
	int a;
	int b;
}test[100];
bool cmpa(A T1,A T2)
{
	if(T1.a>T2.a)
	return true;
	return false;
}
int main()
{
for(int i=0;i<=3;i++)
{
	cin>>test[i].a>>test[i].b;
}	
sort(test,test+3,cmpa);
for(int i=0;i<=3;i++)
{
	cout<<test[i].a<<endl;
}	
	return 0;
}