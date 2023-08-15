#include<stdio.h>

int main() {
    int i, j, k, n, m, y, flag, ind = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m];

    printf("Enter allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("Enter max matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    printf("Enter available matrix:\n");
    for (i = 0; i < m; i++) 
        scanf("%d", &avail[i]);

    int finish[n], safeseq[n], need[n][m];

    for (k = 0; k < n; k++)
        finish[k] = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    safeseq[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }
        }     
    }

    flag = 1;
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            flag = 0;
            printf("System is not in safe state!");
            break;
        }
    }

    if (flag == 1) {
        printf("\nSafe sequence\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", safeseq[i]);
        printf(" P%d", safeseq[n - 1]);
        printf("\n");
    }

    return 0;

}