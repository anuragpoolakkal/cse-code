// 7.IMPLEMENT SIMPLE MAIL TRANSFER PROTOCOL (USING UDP)

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>

#define max 1024
int fdl, l;
struct sockaddr_in server, client;
transfer() {
    int n, retval, fd;
    char * data;
    data = ((void * ) malloc(max));
    fd = open("mailbox", O_RDWR || O_APPEND);
    retval = recvfrom(fdl, data, max, 0, (struct sockaddr * ) & client, & l);
    write(fd, data, retval);
    printf("\n recevd 1 mail\n");
}

main() {
    int l = 0;
    server.sin_family = AF_INET;
    server.sin_port = htons(6299);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    fdl = socket(AF_INET, SOCK_DGRAM, 0);
    l = sizeof(client);
    bind(fdl, (struct sockaddr * ) & server, l);
    transfer();
}