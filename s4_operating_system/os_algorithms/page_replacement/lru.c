#include <stdio.h>

int main() {
    int i, j, k, n, min, f, pf = 0, next = 1;

    printf("Enter length of reference string: ");
    scanf("%d", &n);

    int rs[n], flag[n];

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int count[f], m[f];

    for (i = 0; i < f; i++) {
        count[i] = 0;
        m[i] = -1;
    }

    for (i = 0; i < n; i++) {
        flag[i] = 0; // Initialize the flag
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;
                count[j] = next;
                next++;
                break;
            }
        }

        if (flag[i] == 0) {
            if (i < f) {
                m[i] = rs[i];
                count[i] = next;
                next++;
            } else {
                min = 0;
                for (j = 1; j < f; j++) {
                    if (count[j] < count[min])
                        min = j;
                }
                m[min] = rs[i];
                count[min] = next;
                next++;
            }

            pf++;
        }

        for (j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        if (flag[i] == 0 && m[j] != -1)
            printf("PF %d", pf);
        printf("\n");
        
    }
    }

    printf("Page faults: %d\n", pf);
    printf("Page hits: %d\n", n - pf);

    return 0;
}