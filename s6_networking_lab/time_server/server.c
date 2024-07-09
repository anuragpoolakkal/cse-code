#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<strings.h>
#include<arpa/int.h>
#include<time.h>

int main() {
    char buf[1024];
    struct sockaddr_in server, client;
    time_t ct;

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
}