#include<stdio.h>
#include<pthread.h>


void *fun1(void)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("this is a 1st thread!\n\n");
		sleep(1);
	}
}


void *fun2(void)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("this is a 2st thread!\n");
		sleep(1);
	}
}


int main()
{
	int ret ;
	pthread_t id1,id2;

	//create 1st pthread 

	ret = pthread_create(&id1,NULL,(void *)fun1,NULL);
	if(ret)
	{
		printf("Create thread error!\n");
		return 1;
	}

	//create 2st thread 
	ret = pthread_create(&id2,NULL,(void *)fun2,NULL);

	if(ret)
	{
		printf("Create thread error!\n");
		return 1;
	}

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);

return 0;
}

