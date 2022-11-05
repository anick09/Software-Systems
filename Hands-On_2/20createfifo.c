//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
void main(void){
	int res;
	res=mkfifo("fifo",0777);
	printf("Fifo created\n");
}
