#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>


int main()
{
	pid_t pid;
	int pip_fd[2];
	char buf[100];
	char *p_buf;
	int r_num;


	if(pipe(pip_fd)<0)
	{
		printf("create pipe error!\n");
		return -1;
	}

	pid = fork();

	if(pid == 0)
	{
			close(pip_fd[1]);
			//read the pipe
			sleep(1);
			if((r_num = read(pip_fd[0],buf,100))>0)
			printf("read the %s from the %d pipe\n",buf,r_num);
			close(pip_fd[0]);
	}
	else if(pid >0)
	{
		close(pip_fd[0]);
		if((write(pip_fd[1],"hello",5))!=-1)
			printf("parent write1 hello \n");
		if((write(pip_fd[1],"world",5))!=-1)
			printf("parent write2 world \n");

		close(pip_fd[1]);
		sleep(3);
		waitpid(pid,NULL,0);
		exit(0);
	}
	return 0;

}


