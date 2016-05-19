#include <iostream>
#include <cmath>
using namespace std;
class turnOnLight
{
	public:
	void init();
	void  run();
	void outPut();
	private:	
	int *a;
	int n;
	int k;	
};

void turnOnLight::init()
{
	cin>>n>>k;
	a=new int[n+1];
	a[0]=0;
	for(int i=1;i<n+1;++i)
	*(a+i)=1;
}
void turnOnLight::run()
{
	for(int i=2;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j%i==0)
			{
				a[j]+=1;
			}
		}
	}
}
void turnOnLight::outPut()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]%2!=0)
		{
			cout<<i<<endl;
		}	
	}
	delete []a;
}
int main()
{
	turnOnLight TL;
	TL.init();
	TL.run();
	TL.outPut();
	return 0; 
}