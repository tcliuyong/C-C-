#include<stdio.h>
int main()
{
 int t,n,i,j,a[111111],sum,max,start,end,l;
 scanf("%d",&t);
 for(j=1;j<=t;j++)
 {
  scanf("%d",&n);
  sum=0;
  l=0;
  max=-1001;    //���ϸ�������ֵ��Χ����һ����С��ȷ�����ܽ������㣻
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
   if(sum>=0)   //�Ѷ�sum=0��Ҳ����˵Ҫ�ӵ�һ������ʼ����1��
    sum=sum+a[i];
   else         //��a[0]�����ж�ʱֱ��������һ������������sum��<0��ͬʱȷ���˿�ʼλ�ã���2��
   {
    sum=a[i];
    l=i;
   }
   if(sum>max)  //һ.�ɣ�1����ʼ��ʼĩ����.�ı�����㣻
   {
    max=sum;
    start=l;
    end=i;
   }
  }
  printf("Case %d:\n",j);
  printf("%d %d %d\n",max,start+1,end+1);   //+1���ý���......
  if(j!=t)
   printf("\n");
 }
 return 0;
}