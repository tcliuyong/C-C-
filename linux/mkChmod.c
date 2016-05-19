#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int f;
	const char *f_path = "test";
	mode_t f_attrib;

	struct stat *buf = malloc(sizeof(stat));
	f_attrib = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	f = creat(f_path,f_attrib);
	if(f == -1)
	{
		puts("文件创建失败");
		return 1;
	}
	else
	{
		puts("文件创建成功");
	}
	fstat(f,buf);
	if(buf -> st_mode & S_IRUSR)
	{
		puts("文件所有者权限");
	}
	if(buf -> st_mode & S_IRGRP)
	{
		puts("群组权限");
	}
	close(f);
	chmod(f_path,0771);
	stat(f_path,buf);
	if(buf -> st_mode & S_IWUSR)
	{
		puts("所有者拥有写权限");
	}
	if(buf -> st_mode & S_IWGRP)
	{
		puts("群组拥有写权限");
	}
	free(buf);
	return 0;
}
