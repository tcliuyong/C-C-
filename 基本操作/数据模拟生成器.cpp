#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include<stdlib.h>  //Ҫ��
#include <time.h>   //һ��Ҫ���ϣ���Ȼ�����srand((int)time(0))������
using namespace std;
#define Max 10000
int a[Max],j[Max]; //��֪����ȡ�������Ƕ��������50����
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
  int num=max-min+1; //Ҫ������ĸ���
  int index;         //����±�
  for(int i=0;i<num;i++)    //׼��Ҫ���������
    a[ i ]=i+min;
  srand((int)time(0));      //�������
  for(int i=0;i<num;i++)
  {
    index=(int)((float)(num-i)*rand()/(RAND_MAX+1.0));     //��������±�
    j[i]=a[index];          //�Ѳ��ظ���������±걣�浽������
    a[ index ]=a[ num-1-i ];    //�������Χ�ڵ����һ������±��Ӧ��ֵ,ȥ�滻���ù���ֵ.�����Ͳ��ظ���.�����������ù���a[index]��������
  };
}
