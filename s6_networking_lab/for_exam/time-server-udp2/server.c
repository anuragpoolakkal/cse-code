#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>
#define MAX 100
#define PORT 12345

int main()
{
    time_t ct = time(NULL);
    struct sockaddr_in server, client;
    socklen_t len = sizeof(server);
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    char buff[MAX];

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    printf("Server listening...\n");

    while(1){
        bzero(buff, MAX);
        recvfrom(sockfd, buff, MAX, 0, (struct sockaddr *)&client, &len);
        printf("From client: %s\nTo client: ", buff);
        if(strncmp("time", buff, 4) == 0){
            sprintf(buff, "%s", ctime(&ct));
        }
        else{
            sprintf(buff, "Invalid command");
        }
        printf("%s\n", buff);
        sendto(sockfd, buff, MAX, 0, (struct sockaddr *)&client, len);
    }

    close(sockfd);
    exit(0);
}