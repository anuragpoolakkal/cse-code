#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define BUFFER_SIZE 1024
int main()
{
	int file_descriptor,read_bytes,write_bytes;
	char buffer[BUFFER_SIZE];
	file_descriptor=open("input.txt",O_RDONLY);
	if(file_descriptor<0)
	{
		printf("Failed to open the file!\n");
		exit(EXIT_FAILURE);
	}
	while((read_bytes=read(file_descriptor,buffer,BUFFER_SIZE))>0)
	{
		write_bytes=write(STDOUT_FILENO,buffer,read_bytes);
		if(write_bytes<0)
			{
				printf("Failed to write standard output!\n");
				exit(EXIT_FAILURE);
			}
	}
	close(file_descriptor);
	return 0;
}
