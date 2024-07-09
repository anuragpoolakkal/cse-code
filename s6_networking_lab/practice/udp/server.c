#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void main () {
    int server;
    struct sockaddr_in serveraddr, clientaddr;
    char servermsg[1024], clientmsg[1024];
    int clientaddr_length = sizeof(clientaddr);

    server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (server < 0) {
        printf("Error while creating socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(6002);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(server, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error binding to port\n");
        exit(1);
    }
    printf("Binded to port\nListening..\n");

    if (recvfrom(server, clientmsg, sizeof(clientmsg), 0, (struct sockaddr *)&clientaddr, &clientaddr_length) < 0) {
        printf("Error receiving\n");
        exit(1);
    }
    printf("Message received: %s", clientmsg);

    strcpy(servermsg, clientmsg);

    if (sendto(server, servermsg, strlen(servermsg), 0, (struct sockaddr *)&clientaddr, clientaddr_length) < 0) {
        printf("Error in sending\n");
        exit(1);
    }
    close(server);
}