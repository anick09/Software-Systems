//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>

void main(void){
	if(mknod("myfifo",S_IFIFO|0777,0)==-1){
		printf("could not create fifo file\n");
		return ;
	}
}

