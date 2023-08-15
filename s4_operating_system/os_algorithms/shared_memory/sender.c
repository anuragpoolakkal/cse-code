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
    shmid = shmget((key_t)1222, 1024, 0666 | IPC_CREAT);
    printf("\nKey of shared memory is %d", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    printf("\nShared memory attached at %p", shared_memory);
    printf("\nEnter data to share: ");
    read(0, buffer, 100);
    strcpy(shared_memory, buffer);
    printf("\nYou wrote: %s\n", (char *)shared_memory);
    return 0;
}