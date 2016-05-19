#include<iostream>
#include<algorithm>
#include<vector>
#include <functional>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <limits>
#include <memory>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
vector<int>result;
#define LOWBIT(x) ( (x) & ( (x) ^ ( (x) - 1 ) ) )
#define CLR(x, k) memset((x), (k), sizeof(x))
#define CPY(t, s) memcpy((t), (s), sizeof(s))
#define SC(t, s) static_cast<t>(s)
#define LEN(s) static_cast<int>( strlen((s)) )
#define SZ(s) static_cast<int>( (s).size() )

typedef double LF;
typedef __int64 LL;		//VC
typedef unsigned __int64 ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<double> VF;
typedef vector<string> VS;

template <typename T>
T sqa(const T & x)
{
	return x * x;
}
template <typename T>
T gcd(T a, T b)
{
	if (!a || !b)
	{
		return max(a, b);
	}
	T t;
	while (t = a % b)
	{
		a = b;
		b = t;
	}
	return b;
};

//const int INF_INT = 0x3f3f3f3f;
//const LL INF_LL = 0x7fffffffffffffffLL;		//15f
const double oo = 10e9;
const double eps = 10e-7;
const double PI = acos(-1.0);

#define  ONLINE_JUDGE

const int MAXN = 100004;

int n, m, k;
struct Point
{
	int x, y;
};
Point pnt[MAXN];
Point qnt[MAXN];
struct Segment
{
	int vx, vy;
	Segment() {}
	Segment(Point po, Point pt)
	{
		vx = pt.x - po.x;
		vy = pt.y - po.y;
	}
	LL operator * (const Segment & rhs) const
	{
		return LL(vx) * LL(rhs.vx) + LL(vy) * LL(rhs.vy);
	}
	LL operator ^ (const Segment & rhs) const
	{
		return LL(vx) * LL(rhs.vy) - LL(vy) * LL(rhs.vx);
		cout<<"vx"<<LL(vx)<<endl;
	}
};

bool cmpXY(const Point & lhs, const Point & rhs)
{
	return lhs.y != rhs.y ? lhs.y < rhs.y : lhs.x < rhs.x;
}
bool cmpPK(const Point & lhs, const Point & rhs)
{
	return (Segment(pnt[0], lhs) ^ Segment(pnt[0], rhs)) > 0;	//逆时针的极角排序，>改<就是顺时针的了
	// return atan2(lhs.y, lhs.x) < atan2(rhs.y, rhs.x);
}
bool inPolygon( Point A[],Point & pt,int n)
{

	sort(A, A + n, cmpXY);
	sort(A + 1, A + n, cmpPK);
	for(int i=0;i<result.size();i++)
    {
    	cout<<A[i].x<<A[i].y<<endl;
    }
	A[n] =A[0];
	int low = 1, high = n - 2, mid = (low + high) / 2, res = -1;
	bool sign = false;
	int token;
	LL flag[2];
	while (low <= high)
	{
		mid = (low + high) / 2;
		flag[0] = (Segment(A[0], pt) ^ Segment(A[0], A[mid]));
		cout<<"flag0"<<flag[0]<<endl;
		if (0 == flag[0])
		{
			sign = true;
			token = mid;
			break ;
		}
		flag[1] = (Segment(A[0], pt) ^ Segment(A[0], A[mid + 1]));
			cout<<"flag1"<<flag[1]<<endl;
		if (0 == flag[1])
		{
			sign = true;
			token = mid + 1;
			break ;
		}
		if (flag[0] < 0 && flag[1] > 0 || flag[0] > 0 && flag[1] < 0)
		{
			res = mid;
			break ;
		}
		if (flag[0] < 0 && flag[1] < 0)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	if (sign)
	{
		if ((Segment(A[0], pt) * Segment(A[token], pt)) <= 0)
		{
			return true;
		}
		return false;
	}
	cout<<res<<endl;
	if (-1 == res)
	{
		return false;
	}
	return (Segment(A[mid], pt) ^ Segment(A[mid], A[mid + 1])) <= 0;
}

int findmax(Point a[],int left,int right)//求左边最远点的函数
{
 double smax=0;//定义三角形的最小面积为0
 int max=left;
 for(int i=left+1;i<right;i++)//在条件的时候会要求区分是两个点还是三个点在一个直线上，区分两个点就要让它们的区间为开的，这样就
         //就不会出现两个端点的情况了，如果三个点在一个直线上，它们的结果会是0，那么在判断的时候就要包括0
 {
  
  int s=a[left].x*a[right].y+a[i].x*a[left].y+a[right].x*a[i].y-a[i].x*a[right].y-a[right].x*a[left].y-a[left].x*a[i].y;
  if(s>=0&&s>=smax) //表明是右边的点   如果在一个直线上求得的结果会是0，怎么判断是两个点还是在一个直线上的三个点，这里的s>=０就表示也包括了三个点在一条直线的情况，不然会少计算三点一线的情况
  {
   smax=s;
   max=i;  //max 保存是最大的点在序号，　smax 是用于最大面积的比较，并保存最大面积，求得的结果一定会是最大的面积
  }
 }
 
 if(max==left)
  return -1;
 else
  return max;
}
int findmin(Point a[],int left,int right)//求右边距离最远的那个点
{
 double smin=0;
 int min=left;
 for(int i=left+1;i<right;i++)
 {
  
 int s=a[left].x*a[right].y+a[i].x*a[left].y+a[right].x*a[i].y-a[i].x*a[right].y-a[right].x*a[left].y-a[left].x*a[i].y;
  if(s<=0&&s<=smin)
  {
   smin=s;
   min=i;
  }
}
 if(min==left)
  return -1;
 else
  return min;
}
void findleft(Point a[],int left,int right)//找直线左边的点并递归
{
 int max,min;
 max=findmax(a,left,right);
 //cout<<"max:"<<max<<endl;
 if(max!=-1)
 {
  result.push_back(max);
  findleft(a,left,max);
  findleft(a,max,right);
 }

}
void findright(Point a[],int left,int right)//找直线右边的点并递归
{
 int min;
 min=findmin(a,left,right);
 if(min!=-1)
 {
  result.push_back(min);
  findright(a,left,min);
  findright(a,min,right);
 }
}
bool compare(Point a,Point b)
{
 return a.x<b.x;
}


int main()
{

 Point p[100];
 Point q[100];
 Point r[100];
 int a=0,b=0;
 //输入测试数据的组数
 int n,m;
 cin>>n;
 //下面开始输入测试数据
  for(int i=0;i<n;i++)
  {
   cin>>p[i].x>>p[i].y;
  }
  sort(p,p+n,compare);

  //这是两上端点，不用比较，直接保存
  result.push_back(0);
  result.push_back(n-1);
  findleft(p,0,n-1);
  findright(p,0,n-1);
   /* for(int i=0;i<result.size();i++)
    {
    	cout<<"result[i]"<<result[i]<<endl;
    }*/
  cout<<"组成凸包的点为："<<endl;
  for(int i=0;i<result.size();i++)
  {
  	pnt[i].x=p[result[i]].x;
  	pnt[i].y=p[result[i]].y;
  	cout<<i<<"("<<pnt[i].x<<","<<pnt[i].y<<")"<<" ";
  	a++;
  }
  
  cout<<a<<endl;
  Point pp;
  cin>>pp.x>>pp.y;
  if(inPolygon(pnt,pp,a))
  {
  	cout<<"Yes"<<endl;
  }
  else
  {
  	cout<<"No"<<endl;
  }
  /*
//	ace(pnt,len);
  
  result.clear();
  
  //第二个测试数据
  cout<<endl;
  cin>>m;

  for(int i=0;i<m;i++)//下面开始输入测试数据
  {
   cin>>q[i].x>>q[i].y;
  }
  sort(q,q+m,compare);
  result.push_back(0);//这是两上端点，不用比较，直接保存
  result.push_back(m-1);
  findleft(q,0,m-1);//调用函数
  findright(q,0,m-1);
  cout<<"组成凸包的点为："<<endl;
  for(int i=0;i<result.size();i++)
  {
  	qnt[i].x=q[result[i]].x;
  	qnt[i].y=q[result[i]].y;
  	cout<<i<<"("<<qnt[i].x<<","<<qnt[i].y<<")"<<" ";
  	b++;
  }
int x=0;

for(int i=0;i<b;i++)
 {	
 	if(inPolygon(pnt,qnt[i],n))
  	{
	  r[x].x=qnt[i].x;
	  r[x].y=qnt[i].y;
	  x++;
	 // cout<<"pnt"<<qnt[i].x<<" "<<qnt[i].y<<endl;
	   //cout<<"qnt"<<pnt[i].x<<" "<<pnt[i].y<<endl;
	}
 }

 for(int i=0;i<a;i++)
 {
	if(inPolygon(qnt,pnt[i],m))
	{
 		r[x].x=pnt[i].x;
	    r[x].y=pnt[i].y;  	
	    x++;
	  // cout<<"qnt"<<pnt[i].x<<" "<<pnt[i].y<<endl;

	}
}

 cout<<endl;
 cout<<endl;
  result.clear();
  //合并节点集合 

   sort(r,r+x,compare);
  result.push_back(0);//这是两上端点，不用比较，直接保存
  result.push_back(x-1);
  findleft(r,0,x-1);//调用函数
  findright(r,0,x-1);
  cout<<"组成凸包的点为："<<endl;
  for(int i=0;i<result.size();i++)
  {
  	qnt[i].x=r[result[i]].x;
  	qnt[i].y=r[result[i]].y;
  	cout<<i<<"("<<qnt[i].x<<","<<qnt[i].y<<")"<<" ";
  	b++;
  }
   */
}