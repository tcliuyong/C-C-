#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
void scan_dir(char * dir, int depth)
{
		DIR *dp;
		struct dirent * entry;
		struct stat statbuf;
		if((dp = opendir(dir)) == NULL)
		{
			puts("can not open dir");
			return ;
		}
		chdir(dir);
		while((entry = readdir(dp)) != NULL)
		{
			lstat(entry -> d_name,&statbuf);
			if(S_IFDIR & statbuf.st_mode)
			{
				if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)
				{
					continue;
				}
				//printf("%*s%s/\n",depth, "",entry->d_name);
				scan_dir(entry->d_name,depth + 4);
			}
			else
			{
				//printf("%*s%s\n",depth, " ",entry->d_name);
			}
		}
		chdir("..");
		closedir(dp);
}
void deldir()
{
	if(mkdir("testdir",0774) != -1)
	{
		puts("create dir success");
	}
	else
	{
		return ;
	}
	if(creat("test1",0664) != -1)
	{
		puts("create file success");
	}
	else
	{
		return ;
	}
	if(unlink("test1") != -1)
	{
		puts("rm file success");
	}
	else
	{
		return ;
	}
	if(rmdir("testdir") != -1)
	{
		puts("rm dir success");
	}
	else
	return ;
}
int main()
{
	deldir();
	//puts("scan liuyong");
	//scan_dir("/home/liuyong",0);
	//puts("ok");
	return 0;
}
