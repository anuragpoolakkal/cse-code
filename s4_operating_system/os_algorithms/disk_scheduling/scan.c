#include<stdio.h>
#include<stdlib.h>

int main() {
    int i, j, n, move, initial, thm = 0, index, size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int rq[n];

    printf("Enter request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rq[i]);

    printf("Initial head position: ");
    scanf("%d", &initial);
    
    printf("Enter total disk size: ");
    scanf("%d", &size);

    printf("Initial head movement. '0' for low and '1' for high: ");
    scanf("%d", &move);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (rq[j] > rq[j+1]) {
                int temp;
                temp = rq[j];
                rq[j] = rq[j+1];
                rq[j+1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (initial < rq[i]) {
            index = i;
            break;
        }
    }

    if (move == 1) {
        for (i = index; i < n; i++) {
            thm += abs(rq[i] - initial);
            initial = rq[i];
        }

        thm += abs(size - rq[i-1] - 1);
        initial = size-1;

        for (i = index-1; i >= 0; i--) {
            thm += abs(rq[i] - initial);
            initial = rq[i];
        }

    } else {
        for (i = index-1; i >= 0; i--) {
            thm += abs(rq[i] - initial);
            initial = rq[i];
        }

        thm += abs(rq[i+1] - 0);
        initial = 0;

        for (i = index; i < n; i++) {
            thm += abs(rq[i] - initial);
            initial = rq[i];
        }
    }

    printf("Total head movement is %d\n", thm);
    return 0;
}