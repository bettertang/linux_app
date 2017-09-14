#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<signal.h>
#include<sys/wait.h>
int main()
{
	pid_t childpid;
	int status,retval;


	childpid = fork();

	if(-1==childpid)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (0==childpid)
	{
		printf("I am a child pid!\n");
		sleep(100);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if(0==waitpid(childpid,&status,WNOHANG))
		{
			retval = kill(childpid,SIGKILL);

			if(retval)
			{
				puts("kill failed!\n");
				perror("kill!");
				waitpid(childpid,&status,0);
			}
			else
			{
				printf("%d killed\n",childpid);
			}
		}


     }

	exit(EXIT_SUCCESS);
}
