#include<stdio.h>

void main() {
    int i, j, k, f, n, pf, count = 0, rs[25], m[10];

    printf("Enter length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0;i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        m[i] = -1;

    for (i = 0; i < n; i++) {
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i])
                break;
        }
            
        if (k == f) {
            m[count++] = rs[i];
            pf++;
        }            
        
        for (j = 0; j < f; j++)
            printf("\t%d", m[j]);

        if (k == f)
            printf("\tPF No. %d", pf);
        
        printf("\n");

        if (count == f)
            count = 0;
    }

    printf("Total Page Fault = %d", pf);
}