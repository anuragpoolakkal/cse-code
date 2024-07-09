#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#define MAX 100
#define PORT 12345

int main()
{
    struct sockaddr_in server;
    socklen_t len = sizeof(server);
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    char buff[MAX];

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    sendto(sockfd, "join", MAX, 0, (struct sockaddr *)&server, len);

    if (fork() == 0) {
        while (1) {
            puts("#");
            recvfrom(sockfd, buff, MAX, 0, (struct sockaddr *)&server, &len);
            if (strncmp("ACK", buff, 3) != 0) {
                printf("\n%s", buff);
            }
        }
    } else {
        while (1) {
            fgets(buff, MAX, stdin);
            sendto(sockfd, buff, MAX, 0, (struct sockaddr *)&server, len);
        }
    }

    close(sockfd);
}