#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
class person
{
	public:
	void show();
	int max(int ,int );
	private:
	string name;
	int  age;
	int a;
	
};
void person::show()
{
	name="sdf";
	age=10;
	cout<<name <<" "<<age<<endl;
}
int person::max(int a1,int a2)
{
	int a=a1,age=a2;
	if(a>age)	return a;
	else
	return age;
}
int main()
{
	person P;
	//P.show();	
	int a1=10,a2=30;
	cout<<P.max(a1,a2)<<endl;
	return 0;
}