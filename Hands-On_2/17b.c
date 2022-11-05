//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
void main()
{

	int p[2];
	pipe(p);
	
	if (!fork()) {
		close(p[0]);
		dup2(p[1], 1);
		execl("/bin/ls", "ls", "-l", (char *) 0);
	}
	else
	{
		close(p[1]);
		dup2(p[0], 0);
		execl("/bin/wc", "wc", (char *)0);
	}
	wait(0);
}
