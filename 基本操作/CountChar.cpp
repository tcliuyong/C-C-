#include <stdio.h>
#include <string.h>
int countChar(char *s)
{
	int i,count=0;
	for(i = 0; i < strlen(s); i++)
	{
		if(*(s+i) != ' ' && *(s+i) != '\t'&& *(s+i) != '\n')
		count++;
		
	}
	return count;

}
int main()
{
	char *s = "test sdf\tsdf\nsf";
	int t = countChar(s); 
	printf("%d",t);
}