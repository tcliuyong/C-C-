#include <iostream>
#include <cstdio>
#include <memory>
using namespace std;
#define MAX 1010 //最大点的个数
struct point
{
int x,y;
}num[MAX];
int used[MAX][MAX*2]; //条件中点的左边不会大于1000,just equal MAX
int countN[MAX][MAX*2];
#define abs(a) (a>0?a:(-a)) 
int GCD(int x, int y)
{
	int temp;
	if(x < y)
	{
	   temp = x; x = y; y = temp;
	}
	while(y != 0)
	{
		   temp = y;
		   y = x % y;
		   x = temp;
	}
	return x;
}

int main()
{
int n,i,j;
int a,b,d,ans;
while(scanf("%d", &n)==1)
{
   //inite
   ans = 1;
   memset(used, 0, sizeof(used));
   memset(countN, 0, sizeof(countN));
  
   //read
   for(i = 0; i < n; i++)
    scanf("%d%d", &num[i].x, &num[i].y);
   for(i = 0; i < n-1; i++)
   {
    for(j = i+1; j < n; j++)
    {
     b = num[j].y-num[i].y;
     a = num[j].x-num[i].x;
     if(a < 0) //这样可以让（2，3）（－2，－3）等价
     {a = -a; b = -b;}
     d = GCD(a,abs(b));
     a /= d; 
     b /= d; b += 1000;//条件中点的左边不会大于1000
     if(used[a][b] != i+1)
     {
      used[a][b] = i+1;
      countN[a][b] = 1;
     }
     else
     {
      countN[a][b]++;
      if(ans < countN[a][b])
       ans = countN[a][b];
     }
    }//for
   }//for
   printf("%d\n", ans+1);
}
return 0;
}
