// Experiment 4 - Deque

#include<stdio.h>
#include<stdlib.h>
#define n 10

int deque[10], front = -1, rear = -1, data;
void insertrear();
void insertfront();
void deleterear();
void deletefront();
void display();

void main() {
	int a = 0;
	while (a != 6) {
		printf("\n 1. Insert ar rear \n 2. Insert at front \n 3. Delete at front \n 4. Delete at rear \n 5. Display \n 6. Exit \n Enter your choice: ");
		scanf("%d", &a);
		switch (a) {
			case 1: insertrear(); display(); break;
			case 2: insertfront(); display(); break;
			case 3: deletefront(); display(); break;
			case 4: deleterear(); display(); break;
			case 5: display(); break;
			case 6: exit(-1);
			default: printf("\n Enter valid choice!");
		}
	}
}

void insertrear() {
	if (front == -1 && rear == -1) {
		front = 0;
	} else if (rear == n-1) {
		printf("\n Queue overflow!");
		exit(-1);
	} else {
		printf("\n Enter data: ");
		scanf("%d", &data);
		rear++;
		deque[rear] = data;
	}
}

void insertfront() {
	if (front <= 0) {
		printf("\n Cannot insert element");
		exit(-1);
	} else {
		printf("\n Enter data: ");
		scanf("%d", &data);
		front--;
		deque[front] = data;
	}
}

void deleterear() {
	if (rear == -1) {
		printf("\n Cannot delete element!");
		exit(-1);
	} else {
		printf("\n Your element is %d", deque[rear]);
		if (rear == front) {
			front = -1; rear = -1;
			printf(" \n Queue is empty!");
			exit(-1);
		} else {
			rear--;
		}
	}
}

void deletefront() {
	if (front < 0) {
		printf("\n Queue underflow!");
		exit(-1);
	} else {
		printf("\n Your element is %d", deque[front]);
		front++;
		if (front > rear) {
			front = -1; rear = -1;
			printf("\n Queue empty!");
			exit(-1);
		}
	
	}
}

void display() {
	printf(" \n Your queue is : ");
	for (int i = front; i <= rear; i++) {
		printf("%d", deque[i]);
	}
	printf("\n");
}
