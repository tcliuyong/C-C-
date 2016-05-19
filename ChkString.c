/*
检查已知字符串是否是回文字符串
*/
#include <stdio.h>
int main()
{
	char a[] = "haha";
	int len = strlen(a),start = 0,end =len - 1,mid ;
	while(start < len)
	{
		if(start == end)
		{
			printf("yes");
		}
		if(*(a + start ) == *(a + end))
		{
			start++;
			end--;
		}
		else
		{
			printf("no");
			break;
		}
		
	}
	return 0;
}
