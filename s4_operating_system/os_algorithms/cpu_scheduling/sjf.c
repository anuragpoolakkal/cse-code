#include<stdio.h>
#include<stdlib.h>

struct sjf {
    int pid, bt, wt, tat;
} p[10];

int main() {
    int i, j, n, total_wt = 0, total_tat = 0;

    struct sjf tmp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter process Id: ");
        scanf("%d", &p[i].pid);
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
    }

    p[0].wt = 0;
    p[0].tat = p[0].bt;

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (p[i].bt > p[j].bt) {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
        p[i].tat = p[i].wt + p[i].bt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nTotal waiting time: %d", total_wt);
    printf("\nTotal turn around time: %d", total_tat);
    printf("\nAverage waiting time: %d", total_wt/n);
    printf("\nAverage turn around time: %d", total_tat/n);

    printf("\nGantt Chart\n");
    printf("\n-------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("P%d", p[i].pid);
        printf("\t");
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d", p[i].tat);
        printf("\t");
    }
    printf("\n-------------------------------------------------\n");
    printf("\n");

    return 0;
}