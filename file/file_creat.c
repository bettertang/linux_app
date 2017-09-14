#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


void  creat_file(char *filename)
{
	if(creat(filename,0755)<0)
	{
		printf("creat %s file failure!\n",filename);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("creat %s file success!\n",filename);
	}
	
	
}






int main(int argc,char *argv[])
{
	
	int i;

	if(argc <2)
	{
		printf("./file_creat a.txt\n");
		exit(EXIT_FAILURE);	
	}

	for(i=1;i<argc;i++)
	{
		creat_file(argv[i]);	
	}

	exit(EXIT_SUCCESS);
}
