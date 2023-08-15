#include<stdio.h>

struct block {
    int id, size, allc;
} b[10];

struct process {
    int id, size, bno;
} p[10];

int main() {
    int i, j, n, m;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter id and size of process %d: ", i + 1);
        scanf("%d%d", &p[i].id, &p[i].size);
        p[i].bno = -1;
    }

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter id and size of block %d: ", i + 1);
        scanf("%d%d", &b[i].id, &b[i].size);
        b[i].allc = -1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (b[j].allc == -1 && b[j].size >= p[i].size) {
                p[i].bno = b[j].id;
                b[j].allc = 1;
                break;
            }
        }
    }

    printf("Process No.\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t", p[i].id);
        if (p[i].bno != -1) {
            printf("%d\n", p[i].bno);
        } else {
            printf("Not Allocated\n");
        }
    }
    return 0;
}
