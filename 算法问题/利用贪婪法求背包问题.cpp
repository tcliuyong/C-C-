#include <iostream>
#include <algorithm>
using namespace std;
typedef struct{
float p;//n个物体的价值
float w;//n个物体的重量
float v;//n个物体价值重量比
}OBJECT;
int n;
bool cmp(OBJECT a,OBJECT b)
{
if(a.v<b.v)
return false;
return true;
}
float knapsack_greedy(float M,OBJECT instance[],float x[])
{

int i;
float m,p=0;

	for(i=0;i<n;i++)
	{
		instance[i].v=instance[i].p/instance[i].w;
		x[i]=0;
	}
	sort(instance,instance+n,cmp);
	//merge_sort(instance,n);
	m=M;
	for(i=0;i<n;i++)
	{
	if(instance[i].w<=m)
		{
		x[i]=1;
		m-=instance[i].w;
		p+=instance[i].p;
		}
	else
		{
		x[i]=m/instance[i].w;
		p+=x[i]*instance[i].p;
		break;
		}
	}
	return p;
}
int main()
{
	int M=100, i;
	cin>>n;
	float *x = (float *)malloc(sizeof(float)*n);
	OBJECT *instance = (OBJECT *)malloc(sizeof(OBJECT)*n);
	for(i=0;i<n;i++)
	{
		cin>>instance[i].p>>instance[i].w;
	}
	for(i=0;i<n;i++)
	{
		cout<<instance[i].p<<" "<<instance[i].w<<endl;
	}
	cout<<knapsack_greedy(M,instance,x)<<endl;
	system("pause");
	cout<<"n="<<n<<endl;
	for(i=0;i<n;i++)
	{
		cout<<instance[i].p<<" "<<instance[i].w<<endl;
	}
	return 0;
}