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
	return (Segment(pnt[0], lhs) ^ Segment(pnt[0], rhs)) > 0;	//��ʱ��ļ�������>��<����˳ʱ�����
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
		//if (flag[0] * flag[1] < 0)	//NX�����ݵ㣬����WA������
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

int findmax(Point a[],int left,int right)//�������Զ��ĺ���
{
 double smax=0;//���������ε���С���Ϊ0
 int max=left;
 for(int i=left+1;i<right;i++)//��������ʱ���Ҫ�������������㻹����������һ��ֱ���ϣ������������Ҫ�����ǵ�����Ϊ���ģ�������
         //�Ͳ�����������˵������ˣ������������һ��ֱ���ϣ����ǵĽ������0����ô���жϵ�ʱ���Ҫ����0
 {
  
  int s=a[left].x*a[right].y+a[i].x*a[left].y+a[right].x*a[i].y-a[i].x*a[right].y-a[right].x*a[left].y-a[left].x*a[i].y;
  if(s>=0&&s>=smax) //�������ұߵĵ�   �����һ��ֱ������õĽ������0����ô�ж��������㻹����һ��ֱ���ϵ������㣬�����s>=���ͱ�ʾҲ��������������һ��ֱ�ߵ��������Ȼ���ټ�������һ�ߵ����
  {
   smax=s;
   max=i;  //max ���������ĵ�����ţ���smax �������������ıȽϣ�����������������õĽ��һ�������������
  }
 }
 
 if(max==left)
  return -1;
 else
  return max;
}
int findmin(Point a[],int left,int right)//���ұ߾�����Զ���Ǹ���
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
void findleft(Point a[],int left,int right)//��ֱ����ߵĵ㲢�ݹ�
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
void findright(Point a[],int left,int right)//��ֱ���ұߵĵ㲢�ݹ�
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