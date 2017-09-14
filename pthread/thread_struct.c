#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

struct member
{
	int a;
	char *str;
};


void *create(void *argc)
{
	struct member *temp;
	temp = (struct member *)argc;
	printf("temp ->a =%d \n",temp->a);
	printf("temp->str =%s \n",temp->str);
	return (void *)0;
}


int main()
{
	pthread_t id;
	int ret;

	struct member *c;
	c= (struct member *)malloc(sizeof(struct member ));
	c->a = 8;
	c->str = "YST";

	ret = pthread_create(&id,NULL,create,(void *)c);
	
	if(ret)
	{
		printf("create thread error!\n");
		return 1;
	}


	pthread_join(id,NULL);
	return 0;

	
}
