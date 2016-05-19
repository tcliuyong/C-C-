#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>

int main(int argc,char * argv[])
{
	int x;
	int sck_inet;
	struct sockaddr_in adr_inet;
	int len_inet;
	char classes;
	unsigned msb;
	char *netmask;
	static struct{
		unsigned char ip[4];
	}addresses[]={
		{{44,135,86,12}},
		{{127,0,0,1}},
		{{172,16,23,95}},
		{{192,168,9,1}}
	};
	for(x=0;x<4;x++)
	{
		memset(&adr_inet,0,sizeof(adr_inet));
		adr_inet.sin_family=AF_INET;
	   adr_inet.sin_port=htons(9000);
	   memcpy(&adr_inet.sin_addr.s_addr,addresses[x].ip,4);
		msb=*(unsigned char *)&adr_inet.sin_addr.s_addr;
		if((msb&0x80)==0x00)
		{
			classes = 'A';
			netmask="255.0.0.0";
		}
		else if((msb&0xC0)==0x80)
		{
			classes = 'B';
			netmask="255.255.0.0";
	  }
	  else if((msb&0xE0)==0xC0)
		{
			classes = 'C';
			netmask="255.255.255.0";
	  }
	  else if((msb&0xF0)==0xE0)
		{
			classes = 'D';
			netmask="255.255.255.255";
	  }
	  else
	  {
		  classes = 'E';
			netmask="255.255.255.255";
		}
		printf("Address %u.%u.%u.%u is class %c ""netmask %s\n",addresses[x].ip[0],addresses[x].ip[1],addresses[x].ip[2],addresses[x].ip[3],classes,netmask);
	}
	 return 0;
		
}
