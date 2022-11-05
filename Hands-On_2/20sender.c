//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main(void){
	int res,n;
	res=open("fifo",O_WRONLY);
	write(res,"Message from sender",sizeof("Message from sender"));
	printf("Sender process with pid: %d sent message\n",getpid());
}
