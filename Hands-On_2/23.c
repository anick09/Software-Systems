#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void main(){
	int fd[2];
	pipe(fd);
	int c=0;
	while(1){
		write(fd[1],"A",1);
		c++;
		printf("%d\n",c);
	}
}
