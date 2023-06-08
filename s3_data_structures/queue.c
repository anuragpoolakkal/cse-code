// Experiment 2 - Queue Implementation Using Array

#include <stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE];
int front=0;
int rear=-1;
int enqueue(int a);
int dequeue();
int display();
int isFull();
int isEmpty();

void main() {
	int a, m;
	
	do {
		printf ("\n Choose the option:");
		printf ("\n 1. Insert  2. Delete  3. Display 4. Exit: ");
		scanf ("%d",&m);
		switch (m) {
			case 1: printf("\n Enter the element to be inserted: ");
				scanf("%d",&a);
				enqueue(a);
				break;
			case 2: dequeue();
				break;
			case 3: display(); break;
			case 4: break;
			default: printf ("Invalid input \n"); break;
			}
	} while (m != 3);
}

int enqueue (int a) {
	if (isFull())
		printf ("Queue is full. Cannot insert \n");
	else {
		rear = rear + 1;
		queue[rear] = a;
		display();
	}
}

int dequeue () {
	if (isEmpty()) {
		printf ("Queue is empty \n");
	} else {
		printf ("\n The element is %d", queue[front]);
		front = front + 1;
		display();
	}
}

int display() {
	int i;
	if(isEmpty()) {
		printf("Queue is empty \n");
	}
	else {
		printf ("\n Queue elements are: ");
		for (i=front; i<=rear; i++)
		printf ("%d", queue[i]);
		printf ("\n");
	}
}

int isFull() {
	if (rear >= MAXSIZE - 1)
		return 1;
	else
		return 0;
}

int isEmpty() {
	if (front > rear)
		return 1;
	else
		return 0;
}
