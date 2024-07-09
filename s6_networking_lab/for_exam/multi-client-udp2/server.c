#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#define MAX 80
#define PORT 12345

int main()
{
    char buff[MAX];
    struct sockaddr_in server, client;
    struct sockaddr_in clients[20];
    int clients_count = 0;
    socklen_t len = sizeof(client);
    int sockfd;

    // socket creation
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    // config
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    // bind
    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    while (1)
    {
        recvfrom(sockfd, buff, MAX, 0, (struct sockaddr *)&client, &len);
        if (strncmp("join", buff, 4) == 0) {
            clients[clients_count] = client;
            clients_count++;
            printf("Client joined! (%s:%d)\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        } else {
            printf("Client (%s:%d): %s\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port), buff);
            sendto(sockfd, "ACK", MAX, 0, (struct sockaddr *)&client, len);
            for (int i = 0; i < clients_count; i++) {
                char msg[MAX];
                if (clients[i].sin_port == client.sin_port) {
                    sprintf(msg, "You: %s", buff);
                } else {
                    sprintf(msg, "Client (%s:%d): %s", inet_ntoa(client.sin_addr), ntohs(client.sin_port), buff);
                }
                sendto(sockfd, msg, sizeof(msg), 0, (struct sockaddr *)&clients[i], len);
            }
        }
    }
}