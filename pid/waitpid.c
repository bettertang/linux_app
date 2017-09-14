#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void die(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void child2_do()
{
	printf("child2 execuate 'date'\n");
	sleep(5);
	if(execlp("date","date",NULL)<0)
	{
		die("child2 execlp!");
	}
}

void child1_do(pid_t child2,char *argv)
{

	pid_t pw;
	
	do
	{
		if(*argv == '1')
		{
			pw = waitpid(child2,NULL,0);
		}
		else
		{
			pw = waitpid(child2,NULL,WNOHANG);
		}

		if(0==pw)
		{
			printf("In child1 process:\n The child2 process has not exited \n");
		}
	}while(pw ==0);
	

	if(pw =child2)
	{
	
		printf("Get child2 %d. \n",pw);
		sleep(5);
		if(execlp("pwd","pwd",NULL)<0)
		{
			die("child1");
		}
	}
	else
	{
		printf("error occured \n");
	}

}

void father_do(pid_t child1,char *argv)
{
	pid_t pw;

	do
	{
		if(*argv =='1')
		{
		
			pw = waitpid(child1,NULL,0);
		}
		else
		{
			pw = waitpid(child1,NULL,WNOHANG);
		}

		if(pw ==0)
		{
			printf("The father process: \n The child1 has not exited!\n");
			sleep(1);
		}
	
	}while(pw==0);

	if(pw = child1)
	{
		printf("Get child1 process %d \n",pw);
		if(execlp("ls","ls","-l",NULL)<0)
		{
			die("father");
		}
		
	}
	else
	{
		printf("error occured!");
	}	

}

int main(int argc,char *argv[])
{
	pid_t child1,child2;
	if(argc<3)
	{
		printf("Usage ./waidpid [0 1] [0 1]\n");
		exit(EXIT_FAILURE);
	}
	child1 = fork();

	if(-1==child1)
	{
		die("child1");
	}
	else if(0==child1)
	{
		child2 = fork();

		if(-1==child2)
		{
			die("child2");	
		}
		else if(0==child2)
		{
			child2_do();
		}
		else
		{
			child1_do(child2,argv[1]);
		}
	}
	else
	{
	    father_do(child1,argv[2]);
		
	}


exit(EXIT_FAILURE);
}
