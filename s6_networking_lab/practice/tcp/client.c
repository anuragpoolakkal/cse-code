#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>

void main() {
    int client;
    char buffer[1024];
    struct sockaddr_in serveraddr;

    client = socket(AF_INET, SOCK_STREAM, 0);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(6000);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    strcpy(buffer, "Hey, this is client\n");
    send(client, buffer, 21, 0);

    recv(client, buffer, 1024, 0);
    printf("Message received: %s", buffer);

    close(client);
}