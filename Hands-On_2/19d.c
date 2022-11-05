//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>

void main(void){
	if(mkfifo("myfifo1",0777)==-1){
		printf("could not create fifo file\n");
		return ;
	}
	
}


