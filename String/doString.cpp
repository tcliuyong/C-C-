#include <iostream>
#include <string.h>
using namespace std;
int main (int argc,char * argv[])
{
	char str[] = "test123test456test789";
	char A[21];
	string str1 = "1234567890";

	cout<<str<<endl;
	/* strlen() */
	cout<<" str[] length:"<<strlen(str)<<endl;
	cout<<"str1 length:"<<str1.length()<<endl;
	/* strcpy() */
	strcpy(A,str);
	cout<<A<<endl;
	/* strcat()*/
	strcat(A,"ttt");//string conver to char
	cout<<A<<endl;;
	/* strcat()*/
	cout<<strcat(str,A)<<endl;
	/* strchr*/
	char *str2 = strchr(str,'11');
	cout<<*str2<<endl;
	return 0;
}