//Anick Bhattacharya MT2022168
#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
void main()
{

	int p[2];
	pipe(p);
	
	if (!fork()) {
		close(1);//closing 1 so that dup can make a 1 as duplicate of p[1]
		dup(p[1]);
		execl("/bin/ls", "ls", "-l", (char *) 0);//execl will give output to p[1] since 1 is p[1] now.
	}
	else
	{
		close(0);//closing 0 so that 0 becomes the duplicate of p[0]
		dup(p[0]);
		close(p[1]);//closing p[1] so that 1 again becomes stdout
		execl("/bin/wc", "wc", (char *)0);
	}
	wait(0);
}
