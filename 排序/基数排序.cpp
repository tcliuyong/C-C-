#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
int rxsort(int *data, int size, int p, int k)  
{  
    int * counts,/*��������*/  
        * temp;/*��ʱ��������������*/  
    int index,pval,i,j, n; 
    /*����ռ�*/  
    if ((counts = (int *)malloc(k * sizeof(int))) == NULL)  
        return -1;  
    if ((temp = (int *)malloc(size * sizeof(int))) == NULL)  
        return -1;  
    /*�ӵ�λ����λ�ֱ��������*/  
    for (n = 0; n < p; n++){  
        /*���������ʼ��*/  
        for ( i = 0; i < k; i ++)  
            counts[i] = 0;  
        /*���㵱ǰλ�Ļ���*/  
        pval = (int) pow((double )k, (double)n);  
          cout<<pval<<endl;
  
        /*�����ʵ�ֲ����������򲿷�*/  
        for (j = 0; j < size; j ++){  
            index = (data[j]/pval)%pval;  
            cout<<index<<"sdf"<<endl;
            counts[index] += 1;  
        }  
        for (i = 1; i < k; i ++)  
            counts[i] += counts[i - 1];  
  
        for(j = size - 1; j >= 0; j --){  
            index = (data[j]/pval)%pval;  
            cout<<index<<"s"<<endl;
            temp[counts[index] - 1] = data[j];  
            counts[index] -= 1;  
        }  
  
        memcpy(data, temp, size *sizeof(int));  
    }  
  
    free(counts);  
    free(temp);  
    return 0;  
}  
  
  
int main()  
{  
    int a[3] = {50,41,15};  
    int i = 0;  
  
    rxsort(a,3,2,10);  
  
    for (i = 0; i< 3; i++)  
        printf ("a[%d] = %d\n",i,a[i]);  
}  
