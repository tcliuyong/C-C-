#include <stdio.h>
#include <unistd.h>
#include <sting.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
	int fd;
	int opt=1;
	struct sockaddr_in dr;
	fd=socket(AF_INET,SOCK_DGRAM,0);
	dr.sin_family=AF_INET;
	dr.sin_port=htons(9999);
	dr.sin_addr.s_addr=inet_addr("192.168.180.255");
	sendtp(fd,"hello",5,0,(struct sockaddr *)&dr,sizeof(dr));
	setsocketopt(fd,SOL_SOCKET,SO_BROADCAST,&opt,sizeof(opt));
	
}


/*

{
	int fd;
	int type;
	int len;
	len=sizeof(type);
	fd=socket(AF_INET,SOCK_STREAM,0);
	getsockopt(fd,SOL_SOCK,SO_TYPE,&type,&len);//getsockopt
	if(type & SOCK_STREAM)
	{	
		printf("liu");
	}
	if(type & SOCK_DGRAM)
	{
		printf("baowen\n");
	}
	
	return 0; 
}
*/