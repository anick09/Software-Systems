//Anick Bhattacharya MT2022168
#include<stdio.h>
#include <errno.h>
#include<string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
   int P[2];
   char s[100];
   if (pipe(P) == -1){
      perror("Failed to create pipe");
      exit(1);
   }
   scanf("%s", s);
   write(P[1], s, strlen(s)+1);
   printf("\n");
   read(P[0], s, 5);
   printf("%s", s);
}
