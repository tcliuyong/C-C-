#include <iostream>
using namespace std;
void build(char *str,int *tag,int n)
{
	int len = strlen(str) - 1;
  if(n==len)
  {
    cout<<"{";
    for(int i=0;i<len;i++)
      if(tag[i]==1)
        cout<<str[i];
    cout<<"}"<<endl;
    return;
  }
  tag[n] = 0;
  build(str,tag,n+1);
  tag[n] = 1;
  build(str,tag,n+1);
}
int main()
{
  char a[6]={'a','b','c','d','e','f'};
  int tag[6];
  build(a,tag,0);
  return 0;
}