#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int m;
cin>>m;
while(m--)
{
	int n;
	cin>>n;
   double bits=0;
   for(int i=1;i<=n;++i)
   {
    bits+=log10(i);
   }
   int bi;
   bi=static_cast<int>(bits)+1;
   cout<<bi<<endl;
}
return 0;
}