#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main () {
	int fd;
	char buffer[50] = "Hello how are you";
	fd = open("check1.txt", O_RDWR | O_CREAT);
		printf("fd = %d", fd);
	if (fd != -1) {
		printf("\ncheck1.txt opened, read, write access\n");
		write(fd, msg, sizeof(msg));
		seek(fd, 0, SEEK_SET);
		read(fd, buffer, sizeof(msg));
		printf("\n%d was written to the file\n", buffer);
		close(fd);
	}
	return 0;
}
