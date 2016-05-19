/*
将字符串转换成整数 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int StrToInt(char *s)
{
	int num = 0;
	bool flag = false;
	while(*s != '\0')
	{
		if(*s == '-')
		{
			++s;
			flag = true;
			continue;
		}
		num = num *10 + *s - '0';
		++s;
	}
	if(flag == false)
	return num;
	else
	return 0-num;
}
int main()
{
	char *s = "-1";
	int n = StrToInt(s);
	printf("%d\n",n);
	return 0;
} 