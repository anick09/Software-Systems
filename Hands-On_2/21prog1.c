//Anick Bhattacharya MT2022168
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
void main(void){
	int res,n;
	printf("prog1\n");
	char buff[100];
	res=open("fifo",O_RDONLY);
	n=read(res,buff,100);
	printf("Prog1 process : %d started and recieved data\n",getpid());
	printf("Message recieved from prog2: %s\n",buff);
	
	res=open("fifo2",O_WRONLY);
	write(res,"Message from Prog1\n",sizeof("Message from Prog1\n"));
	printf("Message sent to prog2\n");
}
