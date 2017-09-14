#include<stdio.h>
#include<time.h>

int main()
{
	struct tm *local;
	time_t t;


	t = time(NULL);

	local = gmtime(&t);

	printf(asctime(local));

	printf(ctime(&t));

	return 0;

}
