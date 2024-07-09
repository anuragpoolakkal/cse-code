#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

void main () {
    int client;
    struct sockaddr_in serveraddr, clientaddr;
    char servermsg[1024], clientmsg[1024];
    int serveraddr_length = sizeof(serveraddr);

    client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (client < 0) {
        printf("Error while creating socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(6002);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter message: ");
    fgets(clientmsg, sizeof(clientmsg), stdin);

    if (sendto(client, clientmsg, strlen(clientmsg), 0, (struct sockaddr *)&serveraddr, serveraddr_length) < 0) {
        printf("Error in sending\n");
        exit(1);
    }

    if (recvfrom(client, servermsg, sizeof(servermsg), 0, (struct sockaddr *)&serveraddr, &serveraddr_length) < 0) {
        printf("Error receiving\n");
        exit(1);
    }
    printf("Message received: %s", clientmsg);

    close(client);  
}