#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void *create(void *argc)
{
	printf("thread create!\n");
	return (void *)8;
}



int main()
{
	int error;
	pthread_t id;
	void *temp;

	error = pthread_create(&id,NULL,create,NULL);
	printf("main thread ...\n");

	if(error)
	{
		printf("create thread error!\n");
		return 1;
	}

	error = pthread_join(id,&temp);


	if(error)
	{
	
		printf("thread exit error!\n");
		return 2;
	}
	printf("the thread exit code %d \n",(int)temp);

	return 0;
}

