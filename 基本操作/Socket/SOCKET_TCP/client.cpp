#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<sys/soclet.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
int serverfd;
int cfd;//连接客户
struct sockaddr_in sadr;
struct sockaddr_in cadr;
int r;
socklen_t len;
serverfd=socket(AF_INET,SOCK_STREAM,0);
if(serverfd==-1)
{
	printf("1:%m\n");
	exit(-1);
}
printf("sucess!\n");
sadr.sin_family=AF_INET;
sadr.sin_port=htons(999);
inet_aton("a92.168.180.92",&sadr.sin_addr);
r=bind(serverfd,(struct sockaddr *)&sadr,sizeof(sadr));
if(r==1) printf("2:%m\n"),exit(-1);
printf("服务器地址绑定成功\n");
//listen
r=listen(serverfd,10);
if(r==-1) printf("3:%m\n").exit(-1);
printf("jianting成功");
//accept
while(1)
{
	len=sizeof(cadr);
	ctd=accept(serverfd,(struct sockaddr *)&casr,&len);	
	printf("有人连接:%d,IP:%s:%u\n",cfd,inet_ntoa(cadr.sin_addr),ntohs(cadr.sin_port));
}

	return 0;
	
}
