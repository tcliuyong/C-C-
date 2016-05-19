#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAX 1111
#define e 1e-8
using namespace std;
struct point
{
    double x,y;
};
point po[MAX];
int n;
double r,X,Y;
void input()
{
    int i,j;
    scanf("%lf%lf%lf",&r,&X,&Y);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&po[i].x,&po[i].y);
    }
}
int cross(point a,point b,point c)
{
    double flag=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    if(flag<0) return 0;
    else return 1;
}
bool is_convex(int num,point *p) //判断多边形是否为凸多边形，点集要按顺时针或者逆时针给出。
{
    int i;
    p[num]=p[0];
    num++;
    p[num]=p[1];
    num++;
    bool flag=cross(p[0],p[1],p[2]);
    for(i=3;i<num;i++)
    {
        if(cross(p[i-2],p[i-1],p[i])!=flag)
            return 0;
    }
    return 1;
}
bool pointis_in_polygon() //判断点是否在凸多边形内
{
    point p;
    p.x=X;
    p.y=Y;
    int i;
    bool flag=cross(p,po[0],po[1]);
    for(i=1;i<n;i++)
    {
        if(cross(p,po[i],po[i+1])!=flag)
            return 0;
    }
    return 1;
}
double Dot(point a,point b) //点积
{
    return a.x*b.x+a.y*b.y;
}
double Length(point a){return sqrt(Dot(a,a));} //向量的长度
double point_to_seg(point a,point b,point c)  //点a到线段bc的距离
{
    point v1,v2,v3;
    v1.x=c.x-b.x;
    v1.y=c.y-b.y;
    v2.x=a.x-b.x;
    v2.y=a.y-b.y;
    v3.x=a.x-c.x;
    v3.y=a.y-c.y;
    if(Dot(v1,v2)<0) return Length(v2);
    else if(Dot(v1,v3)>0) return Length(v3);
    else return fabs((v1.x*v2.y-v2.x*v1.y)/Length(v1));
}
bool circleis_in_polygon() //判断圆是否在凸多边形内
{
    int flag=0;
    point p;
    p.x=X;p.y=Y;
    int i;
    for(i=0;i<n;i++)
    {
        if(r>point_to_seg(p,po[i],po[i+1]))
            return 0;
    }
    return 1;
}
int main()
{
    int i,j;
    while(scanf("%d",&n))
    {
        if(n<3) break;
        input();
        if(is_convex(n,po)!=1)
        {
            printf("HOLE IS ILL-FORMED \n");
        }
        else if(pointis_in_polygon()!=1||circleis_in_polygon()!=1)
        {
            printf("PEG WILL NOT FIT \n");
        }
        else
            printf("PEG WILL FIT \n");
    }
    return 0;
}