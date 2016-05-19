#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
int main(int argc,char *argv[])
{
	int z;
	int s[2];
	char *msgp;
	int mlen;
	char buf[80];
	pid_t chpid;
	//create socket
	z=socketpair(AF_LOCAL,SOCK_STREAM,0,s);
	if(z==-1)
	{
		fprintf(stderr,"%s:socketpair(2)\n",strerror(errno));
		exit(1);
	}
	
	//fork() create process
	if((chpid=fork())==(pid_t)-1)
	{
		fprintf(stderr,"%s:fork(2)\n",strerror(errno));
		exit(1);
	}
	else if(chpid==0)
	//child process
	{
		char rxbuf[80];
		printf("Parent PID is %ld\n",(long)getppid());
		close(s[0]);
		s[0]=-1;
		//create message and record count
		msgp="%A%d-%b-%Y%1:%M%p";
		mlen=strlen(msgp);
		printf("Child sending request '%s\n'",msgp);
		fflush(stdout);
		//write request to server
		z=write(s[1],msgp,mlen);
		if(z<0)
		{
		fprintf(stderr,"%s:write(2)\n",strerror(errno));
		exit(1);
		}
		//don't write info through close write
		if(shutdown(s[1],SHUT_WR)==-1)
		{
			fprintf(stderr,"%s:shutdown(2)\n",strerror(errno));
			exit(1);
		}
		//receive request from server
		z=read(s[1],rxbuf,sizeof(rxbuf));
		if(z<0)
		{
			fprintf(stderr,"%s:read(2)\n",strerror(errno));
			exit(1);
		}
		//add a NULL from the information from server
		rxbuf[z]=0;
		
		//result
		printf("Server returned '%s'\n",rxbuf);
		fflush(stdout);
		close(s[1]);
	}
	else
	{
		//father server
		int status;
		char txbuf[80];
		time_t td;
		printf("Child PID is %ld\n",(long)chpid);
		fflush(stdout);
		s[1]=-1;
		//wair for request
		z=read(s[0],buf,sizeof(buf));
		if(z<0)
		{
			fprintf(stderr,"%s:read(2)\n",strerror(errno));
			exit(1);
		}
		buf[z]=0;
		time(&td);
		
		strftime(txbuf,sizeof(txbuf),buf,localtime(&td));//缓冲区 输入格式 输入时间
		z=write(s[0],txbuf,strlen(txbuf));
			if(z<0)
		{
			fprintf(stderr,"%s:write(2)\n",strerror(errno));
			exit(1);
		}
		
		close(s[0]);
		waitpid(chpid,&status,0);
	}
	return 0;
}
