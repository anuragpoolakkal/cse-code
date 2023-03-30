#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main () {
	int ret = fork();
	if (fork == 0) {
		printf("Child process\n");
		printf("Child ID: %d\n", getpid());
		printf("Parent ID: %d\n", getppid());	
	} else {
		printf("Parent process\n");
		printf("Process ID: %d\n", getpid());
		printf("Parent ID: %d\n", getppid());
	}
	return 0;
}
