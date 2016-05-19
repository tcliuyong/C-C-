#include <iostream>
#include <algorithm>
#include <stack>
#include <iomanip> 
using namespace std;

struct point
{
	int x, y;
};

point pot[10000];
point p0;

int dis(const point &p1, const point &p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

bool cmp(const point &p1, const point &p2)
{
	int t;
	t = (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
	if(t > 0 || (t == 0 && dis(p1, p0) < dis(p2, p0)))
		return true;
	else
		return false;
}

int main()
{
	int n, i, x, y, p;
	stack<point> s;
	cin>>n;
	for(i = 0; i < n; i++)
		cin>>pot[i].x>>pot[i].y;

	x = pot[0].x;
	y = pot[0].y;
	p = 0;
	for(i = 1; i < n; i++)      //寻找最左上的点
	{
		if(pot[i].y < y || (pot[i].y == y && pot[i].x < x))
		{
			x = pot[i].x;
			y = pot[i].y;
			p = i;
		}
	}
	p0.x = x;
	p0.y = y;

	swap(pot[0], pot[p]);
	sort(pot + 1, pot + n, cmp);        //排序

	s.push(p0);
	s.push(pot[1]);
	s.push(pot[2]);

	point t;
	for(i = 3; i < n; i++)       //凸包
	{
		 while(!s.empty())
		{
			t = s.top(); 
			s.pop();
			p = ( pot[i].x-s.top().x)*(t.y-s.top().y) - (t.x-s.top().x)*(pot[i].y-s.top().y );
			if(p < 0)
			{
				s.push(t);
				break;
			}
		}
		s.push(pot[i]);
	}

	double area = 0;
	t = s.top();
	s.pop();
	area += (p0.x * t.y - p0.y * t.x)/2.0;
	while(!s.empty())
	{
		area += (t.x * s.top().y - t.y * s.top().x)/2.0;
		t = s.top();
		s.pop();
	}
	if(area < 0)
		area = -area;
	cout<<fixed<<setprecision(3)<<area<<endl;
	return 0;
} 
 