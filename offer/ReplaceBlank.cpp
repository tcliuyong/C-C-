#include<stdio.h>
#include<stdlib.h>
#include <string.h>
void ReplaceBlank(char *s)
{
	char str[100] ="";
	int i,j = 0;
	for(i = 0;i < strlen(s);i++)
	{
		if(s[i] != ' ')
		{
			str[j] = s[i];
			j++;
		}
		else
		{
			str[j] = '%';
			str[j + 1] = '2';
			str[j + 2] = '0';
			j = j + 3;			
		//	strcat(str,"%20");
		}
	}	
	printf("%s\n",str);
}
int main()
{
	char *str = "abc cde sdf";
	char *s;
	printf("%s\n",str);
	ReplaceBlank(str);
	
	return 0;
}