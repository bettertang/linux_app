#include<stdio.h>
#include<time.h>

int main()
{
	struct tm *local;

	time_t t;


	t = time(NULL);


	local = localtime(&t);

	printf("Local hour is %d \n",local->tm_hour);

	local = gmtime(&t);

	printf("UTC hour is %d \n",local->tm_hour);

	return 0;

}
