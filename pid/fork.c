#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<math.h>
#include<errno.h>

int main()
{
	pid_t child;

	int status;


	child = fork();

	if(child == -1)
		printf("fork error!%s\n",strerror(errno));
	else if(child ==0)
	{
		printf("this is a child pid!\n");
		int i ;
		printf("I am a child %d \n",getpid());
		for(i=0;i<1000000;i++) sin(i);
		i=5;
		printf("I exit with %d\n",i);
		exit(i);
	}

    while(((child = wait(&status))==-1)&&(errno=EINTR));

	if(child ==-1) printf("error");
	else if(!status) 
		printf("%ld normal",child);
	else if(WIFEXITED(status))
		printf("%ld normal status is %d\n",child,WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("%ld normal signal %d\n",child,WTERMSIG(status));
}
