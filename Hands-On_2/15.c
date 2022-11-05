//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	int p[2],n;
	pid_t f=fork();

	char buffer[100];
	if(pipe(p)==-1){printf("Pipe Unsucessful\n");exit(0);};
	if(f>0){
		printf("passing value to child\n");
		write(p[1],"Hello\n",6);
		close(p[1]);
	}
	else{
		printf("Data recieved from parent\n");
		n=read(p[0],&buffer,100);
		write(1,&buffer,n);
		
	}
}
