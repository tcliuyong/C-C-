#include "hull.h"
extern Point pnt[MAXN];
extern vector<int>result;
int main()
{
Point p[100];
 int n;//����������ݵ�����
 cin>>n;

  for(int i=0;i<n;i++)//���濪ʼ�����������
  {
   cin>>p[i].x>>p[i].y;
  }
  sort(p,p+n,compare);
  result.push_back(0);//�������϶˵㣬���ñȽϣ�ֱ�ӱ���
  result.push_back(n-1);
  findleft(p,0,n-1);//���ú���
  findright(p,0,n-1);
  cout<<"���͹���ĵ�Ϊ��"<<endl;
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