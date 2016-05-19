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
  max=-1001;    //题上给出了数值范围，定一个更小的确保都能进行运算；
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
   if(sum>=0)   //已定sum=0；也就是说要从第一个数开始；（1）
    sum=sum+a[i];
   else         //由a[0]往后判断时直到遇到第一个正数，否则sum恒<0，同时确定了开始位置；（2）
   {
    sum=a[i];
    l=i;
   }
   if(sum>max)  //一.由（1）初始化始末；二.改变结束点；
   {
    max=sum;
    start=l;
    end=i;
   }
  }
  printf("Case %d:\n",j);
  printf("%d %d %d\n",max,start+1,end+1);   //+1不用解释......
  if(j!=t)
   printf("\n");
 }
 return 0;
}