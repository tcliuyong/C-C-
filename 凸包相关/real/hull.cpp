#include "hull.h"

Point pnt[MAXN];
vector<int>result;

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
bool cmpXY(const Point & lhs, const Point & rhs)
{
	return lhs.y != rhs.y ? lhs.y < rhs.y : lhs.x < rhs.x;
}
bool cmpPK(const Point & lhs, const Point & rhs)
{
	return (Segment(pnt[0], lhs) ^ Segment(pnt[0], rhs)) > 0;	//逆时针的极角排序，>改<就是顺时针的了
}
bool inPolygon(const Point & pt,int n)
{

	int low = 1, high = n - 2, mid = (low + high) / 2, res = -1;
	bool sign = false;
	int token;
	LL flag[2];
	while (low <= high)
	{
		mid = (low + high) / 2;
		flag[0] = (Segment(pnt[0], pt) ^ Segment(pnt[0], pnt[mid]));
		if (0 == flag[0])
		{
			sign = true;
			token = mid;
			break ;
		}
		flag[1] = (Segment(pnt[0], pt) ^ Segment(pnt[0], pnt[mid + 1]));
		if (0 == flag[1])
		{
			sign = true;
			token = mid + 1;
			break ;
		}
		//if (flag[0] * flag[1] < 0)	//NX的数据点，在这WA了两次
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
		if ((Segment(pnt[0], pt) * Segment(pnt[token], pt)) <= 0)
		{
			return true;
		}
		return false;
	}
	if (-1 == res)
	{
		return false;
	}
	return (Segment(pnt[mid], pt) ^ Segment(pnt[mid], pnt[mid + 1])) <= 0;
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

void ace(Point pnt[],int n)
{
		Point pt;
		int cnt;
		sort(pnt, pnt + n, cmpXY);
		sort(pnt + 1, pnt + n, cmpPK);
		pnt[n] = pnt[0];
		for (int i = 0; i < n; ++i)
		{
		cout<<pnt[i].x<<" "<<pnt[i].y<<endl;
		}
		cnt = 0;
		cout<<"test:"<<endl;
		scanf("%d %d", &pt.x, &pt.y);
			if (inPolygon(pt,n))
			{
			cout<<"Yes"<<endl;
			}
			else
			{
			cout<<"No"<<endl;	
			}
	return ;
}