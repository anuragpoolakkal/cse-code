#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#define MAX 1024
#define PORT 6001

int main () {
    char buff[MAX];
    struct sockaddr_in server;
    socklen_t len = sizeof(server);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr=htonl(INADDR_ANY);

    connect(sockfd, (struct sockaddr *)&server, len);

    while (1) {
        memset(buff, 0, MAX);
        printf("From client: ");
        fgets(buff, MAX, stdin);
        write(sockfd, buff, MAX);
        read(sockfd, buff, MAX);
        printf("From server: %s\n", buff);
    }

    close(sockfd);
    return 0;
}