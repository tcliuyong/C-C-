#include "hull.h"
extern Point pnt[MAXN];
extern vector<int>result;
int main()
{
Point p[100];
 int n;//输入测试数据的组数
 cin>>n;

  for(int i=0;i<n;i++)//下面开始输入测试数据
  {
   cin>>p[i].x>>p[i].y;
  }
  sort(p,p+n,compare);
  result.push_back(0);//这是两上端点，不用比较，直接保存
  result.push_back(n-1);
  findleft(p,0,n-1);//调用函数
  findright(p,0,n-1);
  cout<<"组成凸包的点为："<<endl;
  int len=result.size();
  cout<<len<<endl;
  for(int i=0;i<len;i++)
  {
  	pnt[i].x=p[result[i]].x;
  	pnt[i].y=p[result[i]].y;
  	cout<<i<<"("<<pnt[i].x<<","<<pnt[i].y<<")"<<" ";
  }
  cout<<"fsd"<<endl;
  	ace(pnt,len);
  
  result.clear();
}