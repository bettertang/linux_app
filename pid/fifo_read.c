#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define FIFOPATH "/tmp/myfifo"
int main()
{
	char buf[100];
	int nread;
	int fd;

	if((mkfifo(FIFOPATH,O_CREAT|O_EXCL)<0)&&(errno!=EEXIST))
	{
		printf("FIFO error!\n");
		exit(EXIT_FAILURE);
	}

	printf("Preparing reading the bytes...\n");
	memset(buf,0,sizeof(buf));
	//open the pipline 
	fd = open(FIFOPATH,O_RDONLY|O_NONBLOCK,0);

	if(-1==fd)
	{
		printf("open failed!\n");
		exit(1);
	}

	//read the bytes
	while(1)
	{
		memset(buf,0,sizeof(buf));

		nread =read(fd,buf,100);
		if(nread ==-1)
		{
			if(errno==EAGAIN)
				printf("no data yet\n");
		}
		if(sizeof(buf)>0)	
		printf("read %s from FIFO\n",buf);
		sleep(1);
	}

	pause();
	unlink(FIFOPATH);


}
