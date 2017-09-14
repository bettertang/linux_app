#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(int argc,char *argv[])
{
	int fd;

	if(argc<2)
	{
		printf("open %s file error!\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	
	if(fd = open(argv[1],O_RDWR)<0)
	{
		printf("open %d file error!\n",fd);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("open %d file success!\n",fd);
	}
	exit(EXIT_SUCCESS);
}
