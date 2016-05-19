#include <iostream>
using namespace std;
class A
{
	public:
	virtual void print(){cout<<"This is A"<<endl;}
};
 
class B : public A
{
	public:
	void print(){cout<<"This is B"<<endl;}
};

/*
  class A
{
public:
void print()
{
cout<<"This is A"<<endl;
}
};
 
class B : public A
{
public:
void print()
{
cout<<"This is B"<<endl;
}
};
* 以上方式调用main 就会有不同的结果
* */
int main()
{
	A a;
	B b;
	A *p1 = &a;
	A *p2 = &b;
	p1->print();
	p2->print();
	return 0;
}
