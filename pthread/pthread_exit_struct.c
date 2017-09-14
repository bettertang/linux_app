#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


struct member
{
	int a;
	char *str;
}temp ={8,"YST"};


void *create()
{
	printf("create new thread!\n");
	return (void *)&temp;
}


int main()
{
	pthread_t id;
	int error;
	struct member *p;

	error = pthread_create(&id,NULL,create,NULL);
	printf("main thread ...\n");

	if(error)
	{
		printf("create thread error!\n");
		return 1;
	}

	error = pthread_join(id,(void *)&p);

	if(error)
	{
		printf("thread exit error!\n");
		return 2;
	}

	printf("p->a = %d\n",p->a);
	printf("p->str= %s\n",p->str);
	sleep(1);
	return 0;
}
