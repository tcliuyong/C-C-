#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

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
	char *srvr_addr =NULL;
	struct sockaddr_in adr_srvr;
	int len_inet;
	int s;
	struct servent *sp;
	char dtbuf[128];
	
	if(argc>=2)
	{
	srvr_addr=argv[1];
	}
	else 
	{
		srvr_addr="127.0.0.1";
	}
	
	
	//search tcp serivce
	sp=getservbyname("daytime","tcp");
	if(!sp)
	{
		fputs("Unknow service:daytime tcp\n",stderr);
		exit(1);
	}
	
	//create address socket
	memset(&adr_srvr,0,sizeof(adr_srvr));
	adr_srvr.sin_family=AF_INET;
	adr_srvr.sin_port=sp->s_port;
	adr_srvr.sin_addr.s_addr=inet_addr(srvr_addr);
	if(adr_srvr.sin_addr.s_addr==INADDR_NONE)
	{
		bail("bad address.");
	}
	len_inet=sizeof(adr_srvr);
	//create a way to service
	s=socket(PF_INET,SOCK_STREAM,0);
	if(s==-1)
	{
		bail("socket()");
	}
	//printf("%ls",( const struct sockaddr *)&adr_srvr);
	z=connect(s,( const struct sockaddr *)&adr_srvr,sizeof(adr_srvr));
	if(z==-1)
	{
		bail("connect(2)");
	}
	z=read(s,&dtbuf,sizeof(dtbuf));
	if(z==-1)
	{
		bail("read(2)");
	}
	dtbuf[z]=0;
	printf("Date & Time is:%s\n",dtbuf);
	
	close(s);
	putchar('\n');
	return 0;
}
