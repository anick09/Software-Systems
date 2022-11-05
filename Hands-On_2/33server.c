#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<net/ethernet.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
int sock_fd,new_sock;
struct sockaddr_in server,client;
char *message,server_reply[2048];

//part1
sock_fd=socket(AF_INET,SOCK_STREAM,0);
if(sock_fd==-1){
	puts("Socket failed\n");
	exit(1);
}

//part2

server.sin_addr.s_addr= INADDR_ANY;
server.sin_port=htons(9999);
server.sin_family=AF_INET;

//bind
if(bind(sock_fd,(struct sockaddr *)&server, sizeof(server))<0){
	printf("Bind failed\n");
	exit(1);
}
//listen
listen(sock_fd,4);//at a time 4 connections can be handled by some queue

//wait for connection(Accept)
int c=sizeof(client);
while(1){
new_sock=accept(sock_fd,(struct sockaddr *)&client,(socklen_t *)&c);
if(new_sock<0)
	printf("Accept failed\n");
	
//part: Send and recieve
message="Hello client...This is Server\n";
write(new_sock,message,strlen(message));
}
return 0;
}
