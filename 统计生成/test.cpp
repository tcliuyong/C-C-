#include<stdlib.h>
#include<stdio.h>
#define MAXLINE 100
int main()
{
    FILE *fp;
    char aa[10], bb[10], dd[10], gg[10];
    int cc, ee, ff;
    int sum0, sum1, sum2;
    sum0 = 0;
    sum1 = 0;
    sum2 = 0;
    char arr[MAXLINE+1];
    if((fp=fopen("s.txt", "r")) == NULL)
    {
        perror("File open error!\n");
        exit(1);
    }
    while((fgets(arr, MAXLINE, fp))!=NULL)
    {
        sscanf(arr,"%s %s %d %s %d %d %s", aa, bb, &cc, dd, &ee, &ff, gg);
        if(ff>=0 && ff<= 7)
            sum0++;
        else if(ff<=15)
            sum1++;
        else
            sum2++;
        //printf("%s %s %d %s %d %d %s\n", aa, bb, cc, dd, ee, ff, gg);
    }
    printf("sum0=%d,sum1=%d,sum2=%d\n", sum0, sum1, sum2);
    return 0;
}