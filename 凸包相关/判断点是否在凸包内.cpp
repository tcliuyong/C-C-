#include <iostream>
#include <functional>
#include <algorithm>
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
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

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

const int INF_INT = 0x3f3f3f3f;
const LL INF_LL = 0x7fffffffffffffffLL;		//15f
const double oo = 10e9;
const double eps = 10e-7;
const double PI = acos(-1.0);

#define  ONLINE_JUDGE

const int MAXN = 100004;

int n, m, k;
struct Point
{
	int x, y;
}pnt[MAXN];
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
	}
};

bool cmpXY(const Point & lhs, const Point & rhs)
{
	return lhs.y != rhs.y ? lhs.y < rhs.y : lhs.x < rhs.x;
}
bool cmpPK(const Point & lhs, const Point & rhs)
{
	return (Segment(pnt[0], lhs) ^ Segment(pnt[0], rhs)) > 0;	//逆时针的极角排序，>改<就是顺时针的了
}
bool inPolygon(const Point & pt)
{

	int low = 1, high = n - 2, mid = (low + high) / 2, res = -1;
	
	bool sign = false;
	int token;
	LL flag[2];
		cout<<low<<" "<<high<<endl;
	while (low <= high)
	{
		mid = (low + high) / 2;
		flag[0] = (Segment(pnt[0], pt) ^ Segment(pnt[0], pnt[mid]));
		cout<<"flag0"<<flag[0]<<endl;
		if (0 == flag[0])
		{
			sign = true;
			token = mid;
			break ;
		}
		flag[1] = (Segment(pnt[0], pt) ^ Segment(pnt[0], pnt[mid + 1]));
		cout<<"flag1"<<flag[1]<<endl;
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
			cout<<"1"<<endl;
			return true;
		}
		return false;
	}
	if (-1 == res)
	{
			cout<<"2"<<endl;
		return false;
	}
	return (Segment(pnt[mid], pt) ^ Segment(pnt[mid], pnt[mid + 1])) <= 0;
}
void ace()
{
	Point pt;
	int cnt;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &pnt[i].x, &pnt[i].y);
		}
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
			if (inPolygon(pt))
			{
				//++cnt;
				cout<<"Yes"<<endl;
			}
			else
			{
			cout<<"No"<<endl;	
			}
		//puts(cnt >= k ? "YES" : "NO");
	}
	return ;
}
int main()
{

	ace();
	return 0;
}