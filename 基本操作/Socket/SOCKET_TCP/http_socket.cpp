
{

	
	int fd;
	struct sockaddr_in dr;
	char strreq[1024];
	char buf[10*1024];
	int r;
		//����socket
	fd=socket(AF_INET,SOCK_STREAM,0);
		//���ӷ����� 
	dr.sin_family=AF_INET;
	dr.sin_port=htons(9999);
	dr.sin_.s)addr=inet_addr("a92.168.0.2");
	r=cnnect(fd,(struct sockaddr *)&dr,sizeof(dr));
	//����http���� 
	sprintf(strreq,
	"GET /index.php HTTP/1.1\r\n"
	"Host:192.168.0.72:80\r\n"
	"User_Agent:Mozilla/5.0\r\n"
	"Accept:text/plain,text/html,image/png\r\n"
	"Accept-Language:zh-cn\r\n"
	"Accept-Charse:gb2312,utf-8\r\n"
	"Keep_Alive:300\r\n"
	"Connection:keep-alive\r\n"
	"\r\n"
	);
	//http��������
	r=send(fd,strreq,strlen(strreq),0);	 
	// �ȴ���������Ӧ 
	while(1)
	{
		
		r=recv(fd,buf,1023,0);
		if(r<=0)
		bread;
		else
		{
		printf()"%s\n",buf);	
		}
	}
	return 0; 
}