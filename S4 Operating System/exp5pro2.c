#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>

int main () {
	fork();
	
	if (fork == 0) {
		printf("Hello from child");
	} else {
		printf("Hello from parent");
		wait(NULL);
		printf("Child is terminated");
	}
	printf("Bye");
	return 0;
}
