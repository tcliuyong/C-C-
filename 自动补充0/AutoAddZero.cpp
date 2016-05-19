#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
using namespace std;
template <typename T , typename S>
T fill_cast(const S v , const int width , const char c)
{
	T result;
	stringstream inter;
	inter << setw(width) << setfill(c) << v ;
	inter >> result ;
	return result;	
	
}
int main()
{
	string  s = "12";
	string x = fill_cast<string>(s , 3 , '0');
	cout<<x<<endl;
	return 0;	
	
}
