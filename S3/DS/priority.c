// Experiment 3 - Priority Queue

#include <stdio.h>
#define MAXSIZE 5
int prior[MAXSIZE];
int front=-1, rear=-1;
int enqueue(int a);
int dequeue(int b);
int display();
int isFull();
int isEmpty();

void main() {
	int a, m, b;
	
	do {
		printf (" \n Choose the option:");
		printf ("\n 1. Insert  2. Delete  3. Display  4. Exit: ");
		scanf ("%d",&m);
		switch (m) {
			case 1: printf("\n Enter the element to be inserted: ");
				scanf("%d",&a);
				enqueue(a);
				break;
			case 2: printf("\n Enter the element to be deleted: ");
				scanf("%d",&b);
				dequeue(b);
				break;
			case 3: display(); break;
			case 4: break;
			default: printf ("Invalid input \n"); break;
			}
	} while (m != 4);
}

int enqueue (int a) {
	int i,j;
	if (front = -1) {
		front =0;
		rear = 0;
		prior[rear] = a;
	} else {
		if (isFull()) {
			printf ("\n Queue is full. Cannot insert. \n");
		} else {
			rear = rear + 1;
			for (i=front; i <= rear; i++) {
				if (a<prior[i]) {
					for (j=rear-1; j>=1; j++) {
						prior[j+1] = prior[j];
						prior[j] = a;
						break;
					}
				}
				else if (i = rear) {
					prior[i] = a;
					break;
				}	
			}
		}
	}					 
			
}

int dequeue (int b) {
	int i, j, flag = 0;
	if (isEmpty()) {
		printf ("\n Queue is empty \n");
	} else {
		for (i=0; i <= rear; i++); {
			if (prior[i] = b) {
				printf ("\n Element has been removed \n ");
				for (j=1; j<rear; j++) {
					prior[j+1];
					rear--;
					flag = 1;
					break;
				}
			}
			if (flag = 0)
				printf (" \n Element not found \n");
		}
	}			
}

int display() {
	 int i;
	 if (isEmpty()) {
	 	printf ("\n Queue is empty \n");
	 } else {
	 	printf ("\n Queue elements are: ");
	 	for (i=front; i<=rear; i++)
	 		printf	("%d", prior[i]);
	 }
}

int isFull() {
	if (rear >= MAXSIZE - 1)
		return 1;
	else
		return 0;

}

int isEmpty() {
	if (rear < 0)
		return 1;
	else
		return 0;
}
