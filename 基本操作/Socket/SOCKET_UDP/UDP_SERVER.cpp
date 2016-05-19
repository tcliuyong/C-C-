#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
static void
bail(const char *on_what)
{
	fputs(strerror(errno),stderr);
	fputs(":",stderr);
	fputs(on_what,stderr);
	fputs("\n",stderr);
	exit(1);
}

int main(int argc,char *argv[])
{
	int z;
	char *srvr_addr=NULL;
	struct sockaddr_in adr_inet;
	struct sockaddr_in adr_clnt;
	int len_inet;
	int s;
	char dgram[512];
	char dtfmt[512];
	time_t td;
	struct tm tm;
	if(argc>=2)
	{
	srvr_addr=argv[1];
	}
	else 
	{
		srvr_addr="127.0.0.23";
	}
	s=socket(AF_INET,SOCK_DGRAM,0);
	if(s==-1)
	{
		bail("socket()");
	}
	memset(&adr_inet,0,sizeof(adr_inet));
	adr_inet.sin_family=AF_INET;
	adr_inet.sin_port=htons(9090);
	adr_inet.sin_addr.s_addr=inet_addr(srvr_addr);
	if(adr_inet.sin_addr.s_addr==INADDR_NONE)
	{
		bail("bad address");
	}
	len_inet=sizeof(adr_inet);
	z=bind(s,(struct sockaddr *)&adr_inet,len_inet);
	if(z==-1)
	{
	     	bail("bind()");
	}
	//printf("sdf");
	for(;;)
	{
		len_inet=sizeof(adr_clnt);
		z=recvfrom(s,dgram,sizeof(dgram),0,(struct sockaddr *)&adr_clnt,(socklen_t *)&len_inet);
		if(z<0)
		{
			bail("recvfrom(2)");
		}
		dgram[z]=0;
		if(!strcasecmp(dgram,"QUIT"))
		{
			break;
		}
		time(&td);
		tm=*localtime(&td);
		
		strftime(dtfmt,sizeof(dtfmt),dgram,&tm);
		
		z=sendto(s,dtfmt,strlen(dtfmt),0,(struct sockaddr *)&adr_clnt,sizeof(adr_clnt))	;
		if(z<0)
		{
			bail("sendto(2)");
		}
		
	}
	close(s);
	
			return 0;
}
	

