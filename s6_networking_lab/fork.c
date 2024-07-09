// Program to implement child and parent process using fork system call 

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<ctype.h>

#define MAX_COUNT 200
#define BUF_SIZE 100

int main(void) {
    pid_t pid;
    int i;
    char buf[BUF_SIZE];

    fork();
    pid = getpid();

    for (i = 0; i < MAX_COUNT; i++) {
        sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
        write(1, buf, strlen(buf));
    }

    return 0;
}