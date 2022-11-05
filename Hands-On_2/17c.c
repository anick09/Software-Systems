//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/wait.h>
void main()
{

	int p[2];
	pipe(p);
	
	if (!fork()) {
		close(1);
		fcntl(p[1], F_DUPFD);
		execl("/bin/ls", "ls", "-l", NULL);
	}
	else
	{
		close(0);
		fcntl(p[0], F_DUPFD);
		close(p[1]);
		execl("/bin/wc", "wc", NULL);
	}
	wait(0);
}
