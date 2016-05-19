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
#include <time.h>
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
	char *srvr_port="9099";
	struct sockaddr_in adr_srvr;
	struct sockaddr_in adr_clnt;
	int len_inet;
	int s;
	int c;
	int n;
	time_t td;
	char dtbuf[128];
		if(argc>=2)
	{
	srvr_addr=argv[1];
	}
	else 
	{
		srvr_addr="127.0.0.1";
	}
	if(argc>=3)
	srvr_port=argv[2];
	s=socket(PF_INET,SOCK_STREAM,0);
	if(s==-1)
	{
		bail("socket()");
	}
	memset(&adr_srvr,0,sizeof(adr_srvr));
	adr_srvr.sin_family=AF_INET;
	adr_srvr.sin_port=htons(atoi(srvr_port));
	if(strcmp(srvr_addr,"*")!=0)
	{
		adr_srvr.sin_addr.s_addr=inet_addr(srvr_addr);
		if(adr_srvr.sin_addr.s_addr==INADDR_NONE)
		bail("bad address.");
	}
	else
	{
		adr_srvr.sin_addr.s_addr=INADDR_ANY;
	}
	len_inet=sizeof(adr_srvr);
	z=bind(s,(struct sockaddr *)&adr_srvr,len_inet);
	if(z==-1)
	{
		bail("bind(2)");
	}
	z=listen(s,10);
	if(z==-1)
	{
		bail("listen(2)");
	}
	for(;;)
	{
		len_inet=sizeof(adr_clnt);
		c=accept(s,(struct sockaddr *)&adr_clnt,(socklen_t *)&len_inet);
		if(c==-1)
		{
			bail("accept(2)");
		}
		time(&td);
		n=(int)strftime(dtbuf,sizeof(dtbuf),"%A %b %d %H:%M:%S%Y\n",localtime(&td));
		localtime(&td);
		
		z=write(c,dtbuf,n);
		if(z==-1)
		{
			bail("write(2)");
		}
		close(c);
		}
	return 0;
}
