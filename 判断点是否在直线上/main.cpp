
#include "CheckPointOnLine.h"


int main()
{
	CheckPointOnLine cpol;
	point p1,p2,p;
	p1.x= 0.0;
	p1.y= 0.0;
	p2.x= 2.0;
	p2.y= 4.0;
	p.x= 1.0;
	p.y= 2.0;
	if(cpol.Check(p1,p2,p))
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}
	return 0;
}