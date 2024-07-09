#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_FRAMES 10
#define WINDOW_SIZE 4
//#define ERROR_PROBABILITY 0.2

int main() {
    int frames[TOTAL_FRAMES];
    int ack[TOTAL_FRAMES];
    int window_start = 0;
    int i, j;
    int errors[TOTAL_FRAMES];
    int er, no_error;

    printf("Enter the number of errors: ");
    scanf("%d", &no_error);
    for (i = 0; i < TOTAL_FRAMES; i++) {
        errors[i] = 0;
        ack[i] = 0;
    }

    for (i = 0; i < no_error; i++) {
        printf("Enter the error frame: ");
        scanf("%d", &er);
        errors[er - 1] = 1;
    }

    for (i = 0; i < TOTAL_FRAMES; i++) {
        frames[i] = i + 1;
    }

    while (window_start < TOTAL_FRAMES) {
        printf("Sending frames: ");
        for (i = window_start; i < window_start + WINDOW_SIZE && i < TOTAL_FRAMES; i++) {
            if (ack[i] == 0) {
                printf("%d ", frames[i]);
            }
        }
        printf("\n");

        for (i = window_start; i < window_start + WINDOW_SIZE && i < TOTAL_FRAMES; i++) {
            if (ack[i] == 0) {
                if (errors[i] == 1) {
                    printf("Error detected in frame %d, retransmitting...\n", frames[i]);
                    errors[i] = 0;  // Reset the error after detection
                } else {
                    printf("Frame %d acknowledged\n", frames[i]);
                    ack[i] = 1;
                }
            }
        }

        // Move the window
        while (ack[window_start] == 1 && window_start < TOTAL_FRAMES) {
            window_start++;
        }
    }

    printf("All frames sent and acknowledged successfully.\n");
    return 0;
}