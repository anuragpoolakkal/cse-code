#include<stdio.h>
#include<unistd.h>

int main () {
	printf("\nexec1.c\n");
	char * args[] = {"\nexec2", NULL};
	exec(args[0], args);
	return 0;
}
