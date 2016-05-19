#include <iostream>
using namespace std;
int min(int x,int y)
{
    if(x<y)
    return x;
    else
    return y;
}
int max(int x,int y)
{
    if(x>y)
    return x;
    else
    return y;
}
void maxmin(int A[],int &e_max,int &e_min,int low,int high)
{
int mid,x1,y1,x2,y2;
    if((high-low)<=1)
    {

            if(A[high]>A[low])
        {
            e_max=A[high];
            e_min=A[low];
        }
        else
        {
            e_max=A[low];
            e_min=A[high];
        }
    }
    else
    {
        mid=(low+high)/2;
        maxmin(A,x1,y1,low,mid);
        maxmin(A,x2,y2,mid,high);
        e_max=max(x1,x2);
        e_min=min(y1,y2);
    }
}
int main()
{
    int a,b;
    int A[5]={1,8,4,0,3};
    maxmin(A,a,b,0,4);
    cout<<a<<endl;
    cout<<b<<endl;
return 0;
}
