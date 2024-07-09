#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_FRAMES 10
#define WINDOW_SIZE 4
//#define ERROR_PROBABILITY 0.2

int main() {
    int frames[TOTAL_FRAMES];
    int window_start = 0;
    int ack_received = 0;
    int i;
    int errors[TOTAL_FRAMES+1];
    int er;
    int no_error;
    printf("Enter the number of errors");
    scanf("%d",&no_error);
    for(int i=0;i<TOTAL_FRAMES;i++){
        errors[i]=0;
            }
    for(i=0;i<no_error;i++){
        printf("Enter the error frame");
        scanf("%d",&er);
        errors[er-1] =1;
    }

    for (i = 0; i < TOTAL_FRAMES; i++) {
        frames[i] = i + 1;
    }

    while (ack_received < TOTAL_FRAMES) {
        printf("Sending frames: ");
       
        for (i = window_start; i < window_start + WINDOW_SIZE && i < TOTAL_FRAMES; i++) {
            printf("%d ", frames[i]);
        }
        printf("\n");
           if(errors[ack_received]==1) {
                printf("Error detected in frame %d, retransmitting window...\n", frames[ack_received]);
               errors[ack_received]=0;
                continue;
            }
             else {
                printf("Frame %d acknowledged\n", frames[ack_received]);
                ack_received++;
               window_start++;
            }
    }

    printf("All frames sent and acknowledged successfully.\n");
    return 0;
}