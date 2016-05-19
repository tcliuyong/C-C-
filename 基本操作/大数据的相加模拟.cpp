#include <stdio.h>
#include <stdlib.h>
#define NUM_LEN 100
 
int add_str(char * pch1,char * pch2 , char * chResult){
    chResult[NUM_LEN-1]='\0';
    int idx=NUM_LEN-2;
 
    char *pEnd1=pch1,*pEnd2=pch2;
    for(;*pEnd1!='\0';pEnd1++);
    for(;*pEnd2!='\0';pEnd2++);
    pEnd1--;
    pEnd2--;
    short flag=0;     //是否有进位
    for(;(pEnd1!=pch1-1) || (pEnd2!=pch2-1);){
        short b1=0;
        if(pEnd1!=pch1-1){
            b1= (short)(*pEnd1)-(short)'0'; // '0' -> 0
            pEnd1--;
        }
        short b2=0;
        if(pEnd2!=pch2-1){
            b2= (short)(*pEnd2)-(short)'0'; // '0' -> 0
            pEnd2--;
        }
        short sResult = b1+b2+flag;
        flag=0;
        if(sResult>9){flag=sResult/10;sResult %=10;}
        chResult[idx--] =(char)( sResult+(short)'0');
    }
    if(flag)chResult[idx--]=flag+(short)'0';
    return idx+1;
}
 
int main()
{
    char ch1[NUM_LEN],ch2[NUM_LEN],chResult[NUM_LEN];
    printf("Num1:");
    scanf("%s",ch1);
 
    printf("\nNum2:");
    scanf("%s",ch2);
 
    printf("\nNum1=%s",ch1);
    printf("\nNum2=%s",ch2);
 
    int idx=add_str(ch1,ch2,chResult);
    printf("\n结果:%s",(char*)chResult+idx);
 
    return 0;
}