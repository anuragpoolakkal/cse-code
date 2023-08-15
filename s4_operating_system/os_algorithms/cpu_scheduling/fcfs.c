#include<stdlib.h>
#include<stdio.h>

struct fcfs {
        int pid, bt, wt, tat;
} p[10];

int main() {
    int i, n, total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &p[i].bt);
    }

    p[0].wt = 0;
    p[0].tat = p[0].bt;

    for(i = 0; i < n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
        p[i].tat = p[i].wt + p[i].bt;
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    printf("\nTotal waiting time: %d", total_wt);
    printf("\nTotal turn around time: %d", total_tat);
    printf("\nAverage waiting time: %d", total_wt/n);
    printf("\nAverage turn around time: %d\n\n", total_tat/n);

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
}