#include<stdio.h>

struct rr {
    int pid, bt, tbt, wt, tat;
} p[10];

int main() {
    int n, x = 0, y = 0, i, tq; // x : present time, y : completed processes, i : present process

    printf("Enter number of processes: ");
    scanf("%d", &n);

    ;
    for(i = 0; i < n; i++) {
        printf("Enter process id and burst time of P%d: ", i+1);
        scanf("%d%d", &p[i].pid, &p[i].bt);
        p[i].tbt = p[i].bt;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    i = 0;

    while(1) {
        if (p[i].bt > 0) {
            if (p[i].bt > tq) {
                p[i].bt -= tq;
                x += tq;
            } else {
                x += p[i].bt;
                p[i].bt = 0;
                
                p[i].tat = x;
                p[i].wt = p[i].tat - p[i].tbt;

                y++;
                
                if (y == n) break;
            }
        }
        i == n-1 ? i = 0 : i++;
    }

    printf("\nProcess Id\tBurst time\tWaiting time\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].tbt, p[i].wt, p[i].tat);
    }

    return 0;
}