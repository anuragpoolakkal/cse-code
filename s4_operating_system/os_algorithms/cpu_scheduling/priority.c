#include<stdio.h>
#include<stdlib.h>

struct sjf {
    int pid, pr, bt, wt, tat;
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
        printf("Enter priority: ");
        scanf("%d", &p[i].pr);
    }

    p[0].wt = 0;
    p[0].tat = p[0].bt;

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (p[i].pr > p[j].pr) {
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
}