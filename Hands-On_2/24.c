//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg{
long type;
char text[100];
}message;

void main(void){
key_t key;
int id;
key=ftok("progfile",65);
id=msgget(key,0666|IPC_CREAT);

printf("Key:%d\nmsggId:%d\n",key,id);
}
