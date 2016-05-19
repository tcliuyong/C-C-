#include <iostream>
#include <algorithm>
using namespace std;

int main(int args,char* argc[])
{
	char A[10] = "abcdefgh";
	int len = 8;
		char tmp;
		for(int i = 0; i < len/2; i++)
		{
			cout<<A[i]<<A[len-i-1]<<len-i-1<<endl;
			tmp = A[i];
			A[i]= A[len-i-1] ;
			A[len-i-1] = tmp;		
		}
		cout<<A<<endl;
	return 0;
} 