#include<stdio.h>
#include<stdlib.h>

struct process {
    int bt, wt, pid, tat;
} p[10];

int main () {
    int n, i, total_wt = 0, total_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    p[0].wt = 0;
    p[0].tat = p[0].bt;

    for (i = 0; i < n; i++) {
        p[i].pid = 1;
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &p[i].bt);
        p[i].wt = p[i-1].wt + p[i-1].bt;
        p[i].tat = p[i].wt + p[i].bt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nTotal waiting time is %d", total_wt);
    printf("\nTotal turn around time is %d", total_tat);
    printf("\nAverage waiting time is %d", total_wt/n);
    printf("\nAverage turn around time is %d\n\n", total_tat/n);
}