#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
using namespace std;
int main(int argc,char *argv[])
{
	int z;
	int s[2];
	char *cp;
	char buf[80];
	//create local socket
	z=socketpair(AF_LOCAL,SOCK_STREAM,0,s);
	if(z==-1)
	{
		fprintf(stderr,"%s:socketpair(AF_LOCAL,SOCK_STREAM,""0)\n",strerror(errno));
		return 1;
	}
	//write to s[1]
	z=write(s[1],cp="hello?",6);
	if(z<0)
	{
		fprintf(stderr,"%s:write(%d,\"%s\",%d)\n",strerror(errno),s[1],cp,strlen(cp));
		return 2;
	}
	printf("Wrote message '%s' on s[1]\n",cp);
	//read from s[0]
	z=read(s[0],buf,sizeof(buf));
	if(z<0)
	{
		fprintf(stderr,"%s:read(%d,buf,%d)\n",strerror(errno),s[0],sizeof(buf));
		return 3;
	}
	//record received information
	buf[z]=0;
	printf("Received message'%s'from socket s[0]\n",buf);
	//send s[0] s[1] information
	z=write(s[0],cp="go away!",8);
	if(z<0)
	{
		fprintf(stderr,"%s:write(%d,\"%s\",%d)\n",strerror(errno),s[0],cp,strlen(cp));
		return 4;
	}
	printf("wrote message '%s' on s[0]\n",cp);
	//read s[1] information
	z=read(s[1],buf,sizeof(buf));
	if(z<0)
	{
		fprintf(stderr,"%s:read(%d,buf,%d)\n",strerror(errno),s[1],sizeof(buf));
		return 3;
	}
	//record received s[0] information
	buf[z]=0;
	printf("Received message'%s'from socket s[1]\n",buf);
	//close socket
	close(s[0]);
	close(s[1]);
	puts("Done");
	
	return 0;
}


