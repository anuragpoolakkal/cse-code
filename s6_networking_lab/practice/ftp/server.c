// Implement file transfer system in which client request file and server responds 
// with file content and the process ID, or a message if file does not exists.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#define MAX 1024
#define PORT 6001

int main () {
    char buff[MAX];
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    listen(sockfd, 5);
    printf("Listening.../n");
    
    int connfd = accept(sockfd, (struct sockaddr *)&client, &len);

    if (connfd != -1)
        printf("Client accepted");

    while (1) {
        memset(buff, 0, MAX);
        read(connfd, buff, MAX);
        printf("From client: %s\n", buff);
        buff[strcspn(buff, "\r\n")] = 0;
        int file = open(buff, O_RDONLY);
        
        fork();

        if (file >= 0) {
            read(file, buff, MAX);
            int pid = getpid();
            sprintf(buff + strlen(buff), "\nProcess ID: %d", pid);
            printf("File content: %s\n", buff);
            write(connfd, buff, sizeof(buff));
        } else {
            sprintf(buff, "File not found");
            printf("File not found\n");
            write(connfd, buff, sizeof(buff));
        }
    }

    close(sockfd);
    return 0;
}