#include<stdio.h>
#include<sys/time.h>




void func()
{
	int i,j;
	double y=0;

	for(i=0;i<1000;i++)
		for(j=0;j<1000;j++)
			y++;
}



int main()
{
	struct timeval tpstart,tpend;
	float timeuse;
	
	gettimeofday(&tpstart,NULL);
	func();
	gettimeofday(&tpend,NULL);

	timeuse = 1000000*(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec-tpstart.tv_usec;
	timeuse = timeuse/1000000;


	printf("use time is %f \n",timeuse);

	return 0;

}
