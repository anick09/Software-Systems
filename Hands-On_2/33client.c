#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<net/ethernet.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
int sock_fd;
struct sockaddr_in server;
char *message,server_reply[2048];

//part1
sock_fd=socket(AF_INET,SOCK_STREAM,0);
if(sock_fd==-1){
	puts("Socket failed\n");
	exit(1);
}

//part2

server.sin_addr.s_addr=inet_addr("127.0.0.1");
server.sin_port=htons(9999);
server.sin_family=AF_INET;

//part: Connect to the server.
//3 way handshaking and stores server info
if(connect(sock_fd,(struct sockaddr*) &server,sizeof(server))<0){
	puts("connection failed\n");
	exit(1);
}
puts("Connected\n");

//part4: Craft a message to send
message="GET/HTTP/1.1\r\n\r\n";
if(send(sock_fd,message,strlen(message),0)<0)
{printf("Send failed\n");
exit(1);
}

//part5:Recieve response from server
if(recv(sock_fd,server_reply,2048,0)<0)
{printf("Recieve failed\n");
exit(1);
}

puts(server_reply);

return (0);
}
