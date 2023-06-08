// Experiment 5 - Circular Queue Using Array

#include <stdio.h>
#include <stdlib.h>
#define n 5

int queue[n], front = -1, rear = -1, data;

void enqueue();
void dequeue();
void display();

void main() {
	int a = 0;
	while (a != 4) {
		printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		
		scanf("%d", &a);
		switch (a) {
			case 1: enqueue(); display();
				break;
			case 2:	dequeue(); display();
				break;
			case 3:	display();
				break;
			case 4:	exit(-1);
			default: printf("Enter a valid choice! \n");
		}
	}
}

void enqueue() {
	if (front == -1 && rear == -1){
		front = 0;
	}
	
	if ((front == 0) && (rear == (n - 1)) || (front != 0 && front == rear + 1)) {
		printf("Queue overflow \n");
	} else {
		rear = (rear == n - 1 && front != 0) ? 0 : rear + 1;
		printf("Enter data: ");
		scanf("%d", &data);
		queue[rear] = data;
		printf("Data inserted! \n");
	}
}

void dequeue() {
	if (front == -1 && rear == -1) {
		printf("Queue underflow \n");
		return;
	}
	
	
	if (front == rear){
		printf("Removed element is %d\n", queue[rear]);
		front = rear = -1;	
	} else {
		printf("Removed element is %d\n", queue[front]);
		front = (front == n - 1) ? 0 : front + 1;
	}
}

void display() {
	if (front == -1 && rear == -1){
		printf("Queue empty \n");
		return;
	}
	
	int i;
	printf("Your queue is: ");
		
	if (front <= rear) {
		for (i = front; i <= rear; i++) {
			printf("%d ", queue[i]);
		}
		printf("\n");
	} else {
		for (i = front; i <= n - 1; i++) {
			printf("%d ", queue[i]);
		}
		for (i = 0; i <= rear; i++) {
			printf("%d ", queue[i]);
		}
		printf("\n");
	}
}