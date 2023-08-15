#include<stdlib.h>
#include<stdio.h>

int mutex = 1, full = 0, empty = 5, x = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
    ++x;
    printf("Producer produces item %d\n", x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    --x;
    printf("Consumer consumes item %d\n", x);
    ++mutex;
}

int main() {
    int choice, i;
    printf("\n1 Producer\n2 Consumer\n3 Exit\n");
    
    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: if ((mutex == 1) && (empty != 0)) {
                        producer();
                    } else {
                        printf("Buffer is full!");
                    }
                    break;
            case 2: if ((mutex == 1) && (full != 0)) {
                        consumer(); 
                    } else {
                        printf("Buffer is empty!");
                    }
                    break;
            case 3: exit(0);
            default: printf("Invalid choice!");
                    break;
        }
    }
}