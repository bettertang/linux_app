#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>


#define FIFOPATH "/tmp/myfifo"


int main(int argc,char *argv[])
{
	int fd;
	char buf[100];
	int nwrite;	

    fd =open(FIFOPATH,O_WRONLY|O_NONBLOCK,0);

	if(fd<0)
	{
		printf("open write error!\n");
	}

	if(argc<2)
	{
		printf("please input something!\n");
		exit(1);
	}
	strcpy(buf,argv[1]);
	nwrite = write(fd,buf,sizeof(buf));
	if(nwrite==-1)
	{
		if(errno=EAGAIN)
		{
			printf("The FIFO has not been read yet.Please try again\n");
		}
	}
	else
	{
		printf("write %s to the FIFO\n",buf);
	}
return 0;
}
