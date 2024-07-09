// 5. SIMULATE SLIDING WINDOW FLOW CONTROL PROTOCOLS. (STOP AND WAIT, GO BACK N, SELECTIVE REPEAT ARQ PROTOCOLS)

#include<stdio.h>

int main() {
    int w, i, f;

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("Enter number of frames to transit: ");
    scanf("%d", &f);
    int frames[f];

    printf("\nEnter %d frames: ", f);
    for (i - 0;  i < f; i++) {
        scanf("%d", &frames[i]);
    }

    printf("For sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n\n");
    printf("After sending %d frames, at each stage sender waits for the acknowledgement sent by the receiver\n\n", w);

    for (i = 1; i <= f; i++) {
        if (i % w == 0) {
            printf("%d\n", frames[i]);
            printf("Acknowledgement of aboue frames received by the sender");
        } else {
            printf("%d\n", frames[i]);
        }

        if (f % w != 0) {
            printf("\nAcknowledgement of above frames sent is received by sender\n");
        }
    }

    return 0;
}