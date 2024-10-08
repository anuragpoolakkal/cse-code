#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>

#define SIZE 1024

int main () {
    char *ip = "127.0.0.1";
    int port = 8080, e;

    int sockfd, new_socket;
    struct sockaddr_in server_addr, new_addr
    socklen_t addr_size;
    char buffer[SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("[.]Error in socket");
        exit(1);
    }
    printf("[+]Server socket created.");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = 8080;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    e = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    if (e < 0) {
        perror("[.]Error in binding");
        exit(1);
    }
    printf("[+]Binding successful\n");

    e = listen(sockfd, 10);
    if (e == 0) {
        printf("[+]Listening...\n");
    } else {
        perror("[.]Error in listening");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    new_socket = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);
    
    return 0;
}