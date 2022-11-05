//Anick Bhattacharya MT2022168
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
void main(void){
	int res,n;
	char buff[100];
	res=open("fifo",O_RDONLY);
	n=read(res,buff,100);
	printf("Reader process : %d started and recieved data\n",getpid());
	printf("Message from sender: %s",buff);

}
