#include <iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int count=0;
    int A[5]={2,3,5,4,1};
    int i,j,min;
    for(i=0;i<4;i++)
    {
        min=i;
        for(j=i+1;j<5;j++)
        {
            if(A[min]>A[j])
            {
                min=j;
            }
        }
          if(i!=min)
          {
              swap(A[i],A[min]);
                count++;
          }
}
       for(i=0;i<5;i++)
    {
        cout<<A[i]<<" ";

    }

            cout<<count<<endl;
    return 0;
}
