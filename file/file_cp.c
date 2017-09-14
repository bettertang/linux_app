#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>

#define MAX 1024
int main(int argc,char *argv[])
{
	int from_fd,to_fd;
	int byte_read,byte_write;
	char buf[MAX];
	char *ptr;


	//open source file

	if((from_fd = open(argv[1],O_RDONLY))==-1)
	{
		fprintf(stderr,"Usage:%s fromfile tofile \n ",argv[1]);
		exit(1);
	}

	//creat soure file 
	 if((to_fd = open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-1)
	 {
	 	fprintf(stderr,"Open %s error\n",argv[2]);
		exit(1);	
	 }

	while(byte_read = read(from_fd,buf,sizeof(buf)))
	{
		if(byte_read==-1 && errno!=EINTR ) break;
		else if (byte_read>0)
		{
			
			ptr = buf;
			while(byte_write = write(to_fd,ptr,byte_read))//pay attention!
			{
				if(byte_write==-1 && errno!=EINTR) break;
				else if(byte_write == byte_read) break;
				else if(byte_write>0)
				{
						ptr+=byte_write;
						byte_read -= byte_write;

				}
			
			}
			if(byte_write ==1) break;
		}
	
	
	}
close(from_fd);
close(to_fd);

exit(0);

}
