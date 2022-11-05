//Anick Bhattacharya
//MT2022168
#include<sys/msg.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<error.h>
#include<stdio.h>
struct msgbuf{

    long mtype;
    char mtext[100];

};

int main(){

    int key = ftok(".",'zfr');
    if(key==-1)
        perror("Error in ftok");

    int msgq = msgget(key,0644|IPC_CREAT);

    if(msgq==-1)
        perror("Error in msgget");

    struct msgbuf msg;
    printf("Enter type of msg: \n");
    scanf("%ld",&msg.mtype);
    printf("Enter message that you want to send: \n");
    getchar();
    scanf("%[^\n]", msg.mtext);

    printf("Entered Message is: %s\n",msg.mtext);
    int ret = msgsnd(msgq,&msg,sizeof(msg),0);
    if(ret==-1)
        perror("Error in msgctl");


    return 0;
}
