#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

int main () {
    void *shared_memory;
    char buffer[100];
    int shmid;
    shmid = shmget((key_t)1222, 1024, 0666);
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    printf("Shared memory attached at %p\n", shared_memory);
    printf("Data in shared memory: %s\n", (char *)shared_memory);
    return 0;
}