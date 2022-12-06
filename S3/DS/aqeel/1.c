#include <stdio.h>

int max = 8;
int stack[8];
int top = -1;

int isEmpty(){
	return top <= -1 ? 1 : 0;
}

int isFull(){
	return top >= max ? 1 : 0;
}

void pop(){
	if(!isEmpty()){
		int data;
		data = stack[top];
		printf("%d\n", data);
		top -= 1;
	}
	else{
		printf("Couldn't pop\n\n");
	}
}

void push(int data){
	top += 1;
	if(!isFull()){
		stack[top] = data;
	}		
	else{
		top -= 1;
		printf("Couldn't insert\n\n");
	}
}

void display(){
	for(int i = 0; i <= top; i++){
		printf("%d", stack[i]);
		if(i < top){
			printf(", ");
		}
	}
	printf("\n");
}

void main(){
	int choice = 0, a = 0;
	
	do{
		printf("Enter choice: \n1.Push\n2.Pop\n3.Display\n4.Exit\n\n");\
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enter the element to insert: ");
				scanf("%d", &a);
				push(a);
				break;
			case 2:
				pop();
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


