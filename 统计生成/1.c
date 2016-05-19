#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define N 100
//s.txt文件的行数 
#define M 100
//size文件的行数 

struct jiyin
{    char  type[15];
	 char chrs[15];
     int  size;
}jy[N];
struct bianjie
{
     int  min;
     int max;
}bj[N];
int main(void)
{
	int count[N]={0};
    char ch[100], ch1[10], ch2[10], ch3[10];
    char tmp[10]={0};
    FILE * fp,* fp1,*fp2,*fp3;
    int i=0, j=0,n=0,k=0,a=0;
    fp = fopen("s.txt" , "r");
	fp1 = fopen("type.txt" , "r");
	fp2 = fopen("chrs.txt" , "r");
	fp3 = fopen("size.txt" , "r");
    if(fp == NULL)
    {
        printf("没有找到文件!\n");
        exit(1);
    }
    while(fgets(ch,30,fp)!=NULL)
  	{
  	 sscanf(ch,"%s %s %*d %*s %*d %d %*s", jy[i].type,jy[i].chrs,&jy[i].size);
  	 i++;
 	}
  	fclose(fp);
	fgets(ch1,10,fp1);
	fgets(ch2,10,fp2);
	while(fgets(ch3,10,fp3)!=NULL)
	{
	 sscanf(ch3,"%d-%d", &bj[j].min,&bj[j].max);
	 
	 j++;
	}
	  	
	for(n=0;n<i;n++)
	{
		//printf("n=%d\n",n);	
		for(k=0 ;k<j;k++)
		{

			//printf("k=%d\n",k);
			//printf("ch1=%s jy.type=%s ch2=%s jy.chrs=%s %d %d %d %d\n", ch1, jy[n].type, ch2, jy[n].chrs, jy[n].size, bj[k].min, jy[n].size,bj[k].max);
			if(!strcmp(ch1,jy[n].type)&& !strcmp(ch2,jy[n].chrs) &&jy[n].size>bj[k].min&&jy[n].size<bj[k].max)
			{
				count[k]++;
			//	printf("%d %d\n",k,count[k]-1);
			}
		}
	
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	printf("变异类型 染色体号 范围   计数\n");
	for(a=0;a<j;a++) 
	
	printf("%s       %s    %d-%d    %d \n",ch1,ch2,bj[a].min,bj[a].max,count[a]);
    return 0;
}
