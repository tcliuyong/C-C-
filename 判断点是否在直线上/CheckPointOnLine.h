#include <iostream>
#include <cmath>
using namespace std;
struct point
{
double x;
double y;
};
class CheckPointOnLine
{
	public:
	bool Check(point p1,point p2 , point p); 
	//叉积 
	private: 
	point p1;
	point p2;
	point p;
};
bool CheckPointOnLine::Check(point p1,point p2,point p)
{
	//计算叉积 是否为0 判断是否是同一条直线 
	
	double tmp = -32768.0; 
	tmp =abs((p1.x - p.x)*(p2.y - p.y) ) - abs((p2.x - p.x)*(p1.y - p.y));

	if(tmp != 0)
	{
		
		return false;
	}
	//判断是否在线段上 
	if((p.x > p1.x &&  p.x > p2.x) || (p.x < p1.x && p.x < p2.x))
	{	
		cout<<1<<endl;
		return false;
	}
	if((p.y > p1.y && p.y > p2.y) || (p.y < p1.y && p.y < p2.y))
	{	
		cout<<2<<endl;
		return false;
	}
	return true; 
}
