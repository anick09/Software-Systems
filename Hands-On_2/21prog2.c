//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main(void){
	int res,n;
	char buff[100];
	printf("prog2\n");
	res=open("fifo",O_RDWR);
	write(res,"Message from prog2",sizeof("Message sent from prog2\n"));
	printf("prog2 process with pid: %d sent message\n",getpid());
	
	res=open("fifo2",O_RDONLY);
	n=read(res,buff,100);
	printf("Prog2 process : %d reading and recieved data\n",getpid());
	printf("Message recieved from prog1: %s\n",buff);
}
