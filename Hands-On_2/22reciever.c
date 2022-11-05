//Anick Bhattacharya MT2022168
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
void main(void){
	
	fd_set fd;
	FD_ZERO(&fd);
	FD_SET(0,&fd);
	//int fd=0;

	struct timeval tv;
	tv.tv_sec=5;
	tv.tv_usec=0;
	
	int res,n;
	res=open("fifo",O_RDONLY);
	int ret=select(res,&fd,NULL,NULL,&tv);
	if(ret){
	char buff[100];
	//res=open("fifo",O_RDONLY);
	n=read(res,buff,100);
	printf("Reader process : %d started and recieved data\n",getpid());
	printf("Message from sender: %s",buff);
	}
	else{
		printf("Data not available\n");
	}
}
