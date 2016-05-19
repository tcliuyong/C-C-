#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	char a[100] = "test";
	char b[100] = "t";
	string str1 = "test1";
	string str2 = "test2";
	//a[] = b[] is wrong
	str1 = str2;
	string str3 = str1 + str2;
	cout<<str3<<endl;
	string s = strcpy(b, a);
	cout<<s<<endl;
	string str4 = strcat(b,a);
	cout<<str4<<endl;
	cout<<strlen(a)<< " " <<str1.size()<<endl;
}
