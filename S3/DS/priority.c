// Experiment 3 - Priority Queue
// Experiment 3 - Priority Queue Using Array

#include <stdio.h>
#include <stdlib.h>
#define n 10
int queue[n], front = -1, rear = -1, temp, x = 0, i, j, data;

void insert();
void delete();
void display();

int main() {
	int ch;
	while (ch != 4){		
		printf (" MENU \n 1. Insert  2. Delete  3. Display  4. Exit: ");
		scanf ("%d",&ch);
		switch (ch) {
			case 1: insert(); display();
				break;
			case 2: delete(); display();
				break;
			case 3: display(); break;
			case 4: break;
			default: printf ("Invalid input \n"); break;
			}
		}
}

void insert() {
	if (front == -1 && rear == -1) {
		front = 0;
	}
		
	if (rear== (n-1)) {
		printf("Queue overflow");
		return;
	} else {
		rear++;
		printf("Enter data: ");
		scanf("%d", &data);
		queue[rear] = data;
		for (i = 0; i <= rear; i++) {
			for (j = 0; j <= rear-1-i; j++) {
				if ((queue[j]) > (queue[j+1])) {
				temp = queue[j];
				queue[j] = queue[j+1];
				queue[j+1] = temp;
				}
			}
		}
	}
}


void delete() {
	int item;
	if (rear == 0) {
		printf("Element deleted is %d", queue[rear]);
		printf("Queue empty");
		rear--;
		return;
	}
	
	if (rear < 0) {
		printf("Queue underflow");
		return;
	} else {
		printf("Enter element to be deleted: ");
		scanf("%d", &item);
		
		for (i = 0; i <= rear; i++) {
			if (queue[i] = item) {
				x++;
				for (j = 0; j <= rear; j++) {
					queue[j] =  queue [j+1];
				}
				
				rear--;
				
				printf("Element deleted successfully \n");
				}
			if (x == 0) {
				printf("Element not found");
			}
		}
	}
}


void display() {
	 printf("Your queue is: ");
	 for (i = 0; i <= rear; i++) {
	 	printf("%d ", queue[i]);
	 	}
	 printf("\n");
}
