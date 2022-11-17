#include <stdio.h>
#define MAXSIZE 5

int queue[5];
int rear = -1;
int front = 0;

void display();

int isFull(){
	return rear >= MAXSIZE - 1 ? 1 : 0;
}

int isEmpty(){
	return front > rear ? 1 : 0;
}

void enqueue(int a){
	if(isFull()){
		printf("Queue overflow");
	}
	else{
		rear++;
		queue[rear] = a;
		printf("Element inserted");
	}
}

void dequeue(){
	if(isEmpty()){
		printf("Queue underflow");
	}
	else{
		printf("The popped element is %d", queue[front]);
		front++;
	}
}

void display(){
	int i;
	printf("The queue is\n");
	for(i = front; i <= rear; i++){
		printf("%d, ", queue[i]);
	}
}

void main(){
	int choice, a;
	do{
		printf("Enter your choice:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enter element to insert: ");
				scanf("%d", &a);
				enqueue(a);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
		}
		
	}
	while(choice != 4);
}
