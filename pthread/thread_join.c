#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void *thread(void *str)
{
	int i;
	for(i=0;i<10;i++)
	{
		sleep(2);
		printf("this is a thread %d \n",i);
	}
	return NULL;
}


int main()
{
	pthread_t id;
	int ret;
	int i;

	ret = pthread_create(&id,NULL,thread,(void *)i);

	pthread_join(id,NULL);
	for(i=0;i<10;i++)
	{
		printf("this is a main thread :%d \n",i);
	}

	return 0;

}
