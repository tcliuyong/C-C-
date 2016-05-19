/*做了两天，终于AC了。各种参考啊，判段点是否在多边形内是参考的网上的代码；
求点到直线的距离是师兄传授的一套模板，只能说有好的模板就是好啊，自己写了好几遍
没过，用师兄的模板写了一遍过了。

思路：

1、用叉积判断点是否在多边形内。

2、求点到每个边的距离的最小值。*/

//My Code:

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-6;
const double inf = 1e+8;

struct point {
    double x;
    double y;
}p[N], c;

int n;

double cross_product(point a, point b){
    return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}

int in_circle() {
    int i; p[n] = p[0]; p[n+1] = p[1];
    for(i = 0; i < n; i++)
        if(cross_product(p[i], p[i+1]) * cross_product(p[i+1], p[i+2]) < eps)
            return false;
    return true;
}

double distan(point a, point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

//好模板啊。。。
double dis(point pa, point pb) {
    double A, B, C, l, s;

    A = distan(pb, c);
    if(A < eps)    return 0;
    
    B = distan(pa, c);
    if(B < eps)    return 0;
    
    C = distan(pa, pb);
    if(C < eps)    return A;

    if(B*B >= A*A + C*C)    return A;
    if(A*A >= B*B + C*C)    return B;

    l = (A+B+C)/2;
    s = sqrt(l*(l-A)*(l-B)*(l-C));
    return 2*s/C;
}

int main() {
    //freopen("data.in", "r", stdin);

    int i;
    scanf("%lf%lf%d", &c.x, &c.y, &n);
    for(i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    if(in_circle()){
        printf("0.000\n"); return 0;
    }

    double ans = inf; p[n] = p[0];
    for(i = 0; i < n; i++)
        if(ans - dis(p[i], p[i+1]) > eps)
            ans = dis(p[i], p[i+1]);
    printf("%.3lf\n", 2*ans);
    return 0;
}