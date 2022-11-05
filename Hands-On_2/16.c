//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<unistd.h>

void main(void){
int p[2],n;
if(pipe(p)==-1){return;}

int pid=fork();
if(pid==-1){return;}

if(pid==0){
//child process
int x;
read(p[0],&x,sizeof(x));
//modifyig x
printf("recieved from parent:%d\n",x);
x=x+5;
write(p[1],&x,sizeof(x));
}

else{
int y=168;
write(p[1],&y,sizeof(y));
printf("Wrote:%d\n",y);
read(p[0],&y,sizeof(y));
printf("Recieved from child:%d\n",y);
}

}
