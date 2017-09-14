#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *create()
{
	printf("create new thread..\n");
	printf("this is my thread id = %u \n",(unsigned long)pthread_self());
	printf("this is the process id =%d \n",getpid());
	return (void *)0;
}


int main()
{
	pthread_t id;
	int ret;
	

	ret = pthread_create(&id,NULL,create,NULL);
	if(ret)
	{
		printf("create thread error!\n");
		return 1;
	}

	printf("this is a main process id = %d \n",getpid());


	return 0;
}

