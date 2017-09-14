#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void *create(void *argc)
{
	int *num;
	num = (int *)argc;
	printf("create the parameter is %d \n",*num);
	return (void *)0;
}



int main()
{
	pthread_t id;
	int ret;
	
	int test =8;
	int *attr = &test;
	ret = pthread_create(&id,NULL,create,(void *)attr);

	sleep(1);
	return 0;
	
}
