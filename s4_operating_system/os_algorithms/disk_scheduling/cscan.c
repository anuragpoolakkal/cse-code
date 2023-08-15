#include<stdio.h>
#include<stdlib.h>

int main() {
    int i, j, n, initial, thm = 0, index, size;

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

    thm = abs(initial - rq[index]);
    thm += size - rq[n - 1];
    thm += size - rq[index - 1];

    printf("Total head movement is %d\n", thm);
    return 0;
}
