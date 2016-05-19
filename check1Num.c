/*
检查n中二进制1的个数
*/
#include <stdio.h>
int main()
{
	int n = 8;
	int sum = 0;
	while(n != 0)
	{
		sum++;
		n = n & (n -1);
	}
	printf("%d\n",sum);
	return 0;
}
