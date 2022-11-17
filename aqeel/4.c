#define n 5
#include <stdio.h>
#include <stdlib.h>

int dequeue[n], rear = -1, front = -1;

void addrear();
void delrear();
void addfront();
void delfront();

void display();

void main(){
	int c;
	do{
		printf("\nEnter your choice:\n");
		printf("1. Add rear\n2. Delete rear\n3. Add front\n4. Delete front\n5. Display\n6. Exit\n");
		scanf("%d", &c);
		switch(c){
			case 1:
				addrear();
				break;
			case 2:
				delrear();
				break;
			case 3:
				addfront();
				break;
			case 4:
				delfront();
				break;
			case 5:
				display();
				break;
			default:
				break;
		}
		
	}while(c != 6);
}

void addrear(){
	int data;
	if(rear == n - 1){
		printf("Overflow");	
	}		
	else{
		rear++;
		printf("Enter the element to be inserted: ");
		scanf("%d", &data);
		dequeue[rear] = data;
		printf("Element inserted.");
	}
}

void delrear(){
	int data;
	if(front == -1 && rear == -1){
		printf("Queue is empty");
	}else{
		data = dequeue[rear];
		printf("%d deleted", data);
		if(front == rear){
			front = rear = -1;
		}
		else{
			rear--;
		}
	}
}

void addfront(){
	int data;
	if(front == 0){
		printf("Insertion is not possible at front end");
	}
	else{
		printf("Enter the element to be inserted: ");
		scanf("%d", &data);
		if(front == -1 && rear == -1){
			front = rear = 0;
		}
		else{
			front--;
		}
		dequeue[front] = data;
		printf("Element inserted!");
	}
}

void delfront(){
	int data;
	if(rear == -1 && front == -1){
		printf("Queue is empty.");
	}else{
		data = dequeue[front];
		if(front == rear){
			front = rear = -1;
		}
		else{
			front++;
			printf("Deleted element is %d", data);
		}
	}
}

void display(){
	int i;
	if(rear == -1 && front == -1){
		printf("Queue is empty");
	}
	else{
		printf("\nQueue elements are:\n");
		for(int i = front; i <= rear; i++){
			printf("%d ", dequeue[i]);	
		}
	}
}


