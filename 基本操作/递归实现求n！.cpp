#include <iostream>
using namespace std;
long long  factorial(int n)
{
long long result=1;
if(n==0)
return 1;
else
return factorial(n-1) * n;
}
int main()
{
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
return 0;
}
