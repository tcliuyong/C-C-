#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include<stdlib.h>  //要加
#include <time.h>   //一定要加上，不然后面的srand((int)time(0))不能用
using namespace std;
#define Max 10000
int a[Max],j[Max]; //不知道你取的数组是多大，这里用50个吧
struct point
{
	int x,y;
};

int main()
{
	int m,n,sum;
	struct point p[Max];
	ofstream fWrite("coffee.txt",ios::out);
	ifstream fRead("hostel.txt",ios::in);
	cin>>m>>n;
  void shuiji(int ,int );
  shuiji(m,n);
  for(int i=0;i<n-m+1;i++)
  {
  	if(!fWrite) cout<<"fail"<<endl;
  	if(i%2==0)
  	{
		fWrite<<endl;
  	}
		fWrite<<j[i]<<" ";
  }
  	fWrite.close();
  	string temp;
  	char t[100];
  	    int flag=0;
   while(getline(fRead,temp))
   {
   int i=0;
   char* c,*t;
   const int len = temp.length();
   c = new char[len+1];
   strcpy(c,temp.c_str());
   	t=strtok(c," ");
   	while(t!=NULL)
   	{
	  if(flag==0)
	  {
  	   p[i].x=atoi(t);
	   cout<<"x "<<p[i].x<<endl;
       flag++;
  	  }

	  else
	 {
       p[i].y=atoi(t);
	   cout<<"y "<<p[i].y<<endl;
	   flag=0;
 	}

	  //printf( "%s\n ",t);
	 t=strtok(NULL," ");

    }
   	  i++;
   }

  //  for(int i=0;i<(n-m+1)/2;i++)
//	cout<<p[i].x<<" "<<p[i].y<<endl;
 }

void shuiji(int min,int max)
{
  int num=max-min+1; //要随机数的个数
  int index;         //随机下标
  for(int i=0;i<num;i++)    //准备要被随机的数
    a[ i ]=i+min;
  srand((int)time(0));      //随机种子
  for(int i=0;i<num;i++)
  {
    index=(int)((float)(num-i)*rand()/(RAND_MAX+1.0));     //产生随机下标
    j[i]=a[index];          //把不重复的随机数下标保存到数组中
    a[ index ]=a[ num-1-i ];    //用随机范围内的最后一个随机下标对应的值,去替换己用过的值.这样就不重复了.（即把上面用过的a[index]丢掉。）
  };
}
