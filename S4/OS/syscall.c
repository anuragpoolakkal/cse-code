#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<dirent.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid==-1)
	{
		printf("failed to create child process!!!\n");
		exit(EXIT_FAILURE);
	}
	else if(pid==0)
	{
		printf("Child process with PID %d is running...",getpid());
		execl("/bin/ls","ls","-l",NULL);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("parent process with PID %d is waiting for child to complete...\n",getpid());
		wait(NULL);
		printf("parent process is done\n");
		exit(EXIT_SUCCESS);
	}
	DIR *dir=opendir(".");
	if(dir==NULL)
	{
		printf("Failed to open directory\n");
		exit(EXIT_FAILURE);
	}
	struct dirent *entry;
	while((entry==readdir(dir))!=NULL)
	{
		printf("%s\n",entry->d_name);
	}
	closedir(dir);
	exit(EXIT_SUCCESS);
}
