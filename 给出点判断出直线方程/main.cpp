#include "PointOfLine.h"
#include <iostream>
using namespace std;
int main()
{
	point p1,p2;
	p1.x=1.0;
	p1.y=2.0;
	p2.x=0.0;
	p2.y=0.0;
	PoiontOfLine pol(p1,p2);
	Line l = pol.GetLine(p1,p2);
	cout<<l.a<<endl;
	cout<<l.a<<"x +"<<l.b<<"y + "<<l.c<<" = 0"<<endl;
	return 0;
}