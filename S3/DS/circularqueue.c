// Experiment 5 - Circular Queue Using Array

// Experiment 5 - Circular Queue Using Array

#include<stdlib.h>
#include<stdio.h>
#define n 10

int queue[n], front = -1, rear = -1, data;

void enqueue();
void dequeue();
void display();

void main() {
	int a;
	while (a != 4) {
		printf("\n 1. Enqueue \n 2. Dequeue \n 3. Display \n 4. Exit \n Enter your choice: ");
		scanf("%d", &a);
		switch (a) {
		case 1: enqueue(); display(); break;
		case 2: dequeue(); display(); break;
		case 3: display(); break;
		case 4: return;
		default: printf("\n Enter valid choice!"); break;
		}
	}
}

void enqueue() {
	if (front == -1 && rear == -1) {
		front = 0;
	}	
	if (((front == 0) && (rear == (n - 1))) || ((front != 0) && (front == rear+1))) {
		printf("\n Queue overflow!");
		return;
	} else if (rear == (n-1) && front != 0) {
		rear = 0;
		printf("Enter data: ");
		scanf("%d", &data);
		queue[rear] = data;
	} else {
		rear = rear++;
		printf("Enter data: ");
		scanf("%d", &data);
	}
}

void dequeue() {
	if (front == -1 && rear == -1) {
		printf(" \n Queue is underflow!");
		return;
	} else if (front == rear) {
		printf("\n Your element is %d", queue[rear]);
		front = -1;
		rear = -1;
	} else {
		if (front = n - 1)
			front = 0;
		else {
			front = front + 1;
		}
	}
}

void display() {
	int i;
	if (front == -1 && rear == -1) {
		printf("\n Queue empty!");
		return;
	} else if (front <= rear) {
		printf("\n %d", queue[i]);
		printf("\n");
	} else {
		printf("\n Your queue is: ");
		for (i = front; i <= n-1; i++)
			printf ("%d", queue[i]);
		}
		
		for (i = 0; i <= rear; i++)
			printf ("%d", queue[i]);
		printf ("\n");
}
