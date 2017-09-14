#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int a =8;

void *create()
{
	printf("create new thread \n");
	printf("a = %d \n",a++);
	return (void *)0;
}


int main()
{
	pthread_t id;
	int ret;
	printf("main1 a = %d\n",a);	
	ret = pthread_create(&id,NULL,create,NULL);
	
	pthread_join(id,NULL);
	printf("main2 a = %d\n",a);	
	sleep(1);

	return 0;
}
