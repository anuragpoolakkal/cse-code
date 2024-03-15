// 7.IMPLEMENT SIMPLE MAIL TRANSFER PROTOCOL (USING UDP)

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define max 1024
int sockfd, l;
struct sockaddr_in server, client;
char * buf, * str;
send_data() {
    char ch;
    buf = (void * ) malloc(max);
    str = (void * ) malloc(max);
    int fd, retval, len = 0;
    printf("CC:");
    sprintf(str, "\n CC:");
    len += strlen(str);
    strcat(buf, str);
    scanf("%s", str);
    len += strlen(str);
    strcat(buf, str);
    printf("From:");
    sprintf(str, "\nFrom:");
    len += strlen(str);
    strcat(buf, str);
    scanf("%s", str);
    len += strlen(str);
    strcat(buf, str);
    printf("\nSubject:");
    sprintf(str, "\nSubject:");
    len += strlen(str);
    strcat(buf, str);
    scanf("%s", str);
    len += strlen(str);
    strcat(buf, str);
    printf("msg:");
    sprintf(str, "\nMsg:");
    len += strlen(str);
    strcat(buf, str);
    while ((ch = getchar()) != '!') {
        buf[len] = ch;
        len++;
    }
    buf[len++] = '\0';
    sendto(sockfd, buf, len, 0, (struct sockaddr * ) & server, sizeof(struct sockaddr_in));
    printf("send one mail");
    close(sockfd);

}
main() {
    char ch;
    server.sin_family = AF_INET;
    server.sin_port = htons(6299);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    client.sin_family = AF_INET;
    client.sin_port = htons(6299);
    client.sin_addr.s_addr = htonl(INADDR_ANY);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    bind(sockfd, (struct sockaddr * ) & client, sizeof(client));
    printf("C:compose \n R:read mail \n");
    scanf("%c", & ch);
    switch (ch) {
    case 'C':
        send_data();
        break;
    case 'R':
        printf("pls check mailbox \n");
    }
}