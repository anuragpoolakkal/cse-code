//priority queue using arrays
#include <stdio.h>
#define max_size 3

void enqueue(int data);
void dequeue(int data);
void display();
int isEmpty();
int isFull();

int pQueue[max_size];
int front = -1, rear = -1;

void main(){
	int choice, a;
	
	do{
		printf("Enter your choice: \n1.Add\n2.Remove\n3.Display\n4.Exit\n\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enter the element to insert:");
				scanf("%d", &a);
				enqueue(a);
				break;
			case 2:
				printf("Enter the element to remove:");
				scanf("%d", &a);
				dequeue(a);
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("Invalid Input");
		}
	}
	while(choice != 4);
}

void enqueue(int data){
	if(front == -1){
		front = 0;
		rear = 0;
		pQueue[rear] = data;
		printf("Element inserted");
	}
	else{
		if(isFull()){
			printf("Queue overflow");
		}
		else{
			rear++;
			for(int i=front; i <= rear; i++){
				if(data < pQueue[i]){
					for(int j = rear - 1; j >= i; j--){
						pQueue[j+1] = pQueue[j];
					}
					pQueue[i] = data;
					break;
				}
				else if(i == rear){
					pQueue[i] = data;
				}
				printf("Element inserted");
			}
		}
	}
}

void dequeue(int data){
	if(isEmpty()){
		printf("Queue underflow");
	}
	else{
		int flag = 0;
		for(int i = 0; i <= rear; i++){
			if(data == pQueue[i]){
				printf("%d has been removed from the queue", pQueue[i]);
				for(int j = i; j < rear; j++){
					pQueue[i] = pQueue[j+i];
				}
				rear--;
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			printf("%d not found in queue", data);
		}
	}
}

void display(){
	if(isEmpty()){
		printf("The queue is empty");
	}
	else{
		int i;
		for(i=front; i <= rear; i++){
			printf("%d, ", pQueue[i]);
		}
	}
}

int isFull(){
	return rear >= max_size - 1 ? 1 : 0;
}

int isEmpty(){
	return front > rear ? 1 : 0;
}

