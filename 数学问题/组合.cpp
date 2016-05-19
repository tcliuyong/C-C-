#include <iostream>
using namespace std;
#define N 100
int a[N];
void C(int n, int r)
{
	int num = r, i = 0, j = 0;
	for(i = n; i >= r; i--)
	{
		a[r] = i;
		if(r == 1)
		{
			for(j = 1; a[j] > 0; j++)
			{
				cout<<a[j]<<" ";
			}
			cout<<endl;
			continue;
		}
		else
		{
			C(i -1, r -1);
		}
	}
}
int main()
{
	int i;
	for(i = 0; i < N; i++)
	a[i] = 0;
	C(5,3);
	return 0;
}