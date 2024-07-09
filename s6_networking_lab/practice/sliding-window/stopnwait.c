#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main() {
    srand(time(0));
    int flength;
    printf("Enter number of frames to send: ");
    scanf("%d", &flength);

    for (int i = 1; i <= flength; i++) {
        printf("\n\nSending frame %d", i);

        if (rand() % 2) {
            printf("\nFrame %d sent", i);
        } else {
            printf("\nFailed to send frame");
            i--;
            continue;
        }

        if (rand() % 2) {
            printf("\nACK received");
        } else {
            printf("\nFailed to send ACK");
            i--;
            continue;
        }
    }

    return 0;
}