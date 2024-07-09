#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>

void main() {
    int server, newsock;
    char buffer[1024];
    struct sockaddr_in serveraddr;
    struct sockaddr_storage store;
    socklen_t addrsize;

    server = socket(AF_INET, SOCK_STREAM, 0);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(6000);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(server, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    
    if (listen(server, 5) == 0) {
        printf("Listening.. \n");
    } else {
        printf("Error\n");
    }

    newsock = accept(server, (struct sockaddr *)&store, &addrsize);

    recv(newsock, buffer, sizeof(buffer), 0);
    printf("Message received: %s", buffer);

    strcpy(buffer, "Hey, this is server\n");
    send(newsock, buffer, 21, 0);

    close(newsock);
    close(server);
}