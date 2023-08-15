#include<stdlib.h>
#include<stdio.h>

int main() {
    int n, i, initial, total;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);
    
    for (i = 0; i < n; i++) {
        total = total + abs(requests[i] - initial);
        initial = requests[i];
    }

    printf("Total headmoment is %d\n", total);

    return 0;
}