#include <iostream>
#include <cstring >
#include <cmath>
using namespace std;
#define N 20
int main(int argc,char * argv[])
{
	char str[N]; 
//	memset(str,' ',N*sizeof(char));

	gets(str);
		int n=strlen(str);
	int k;
	int result=0;
	for(int i=0;i<n;i++)
	{
		k=str[i]-'0';		
		if(k==1)
		result+=pow	(2.0,n-i-1);
	}
	cout<<result<<endl;
		return 0;
}