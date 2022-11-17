#include <stdio.h>
char a[50], b[50], c[50];

int e[10];

void push(char c);
void pop(int a);
void display(char a[], int b);
void evaluate(char c[], int j);
char c, d;

int btop = -1, j = -0, i;

void main(){
	int n;
	printf("Enter number of terms: ");
	scanf("%d", &n);
	printf("Enter infix expression: ");
	scanf("%d", &a);
	
	for(i = 0; i < n; i++){
		if(a[i] == '(' || a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/'){
			c = a[i];
			push(c);
		}
		else if(a[i] != '(' && a[i] != '+' && a[i] != '-' && a[i] != '*' && a[i] != '/' && a[i] != ')' ){
			c = a[i];
			a[j] = c;
			j++;
		}
		else{
			pop(i);
		}
	}
	
	while(btop != -1){
		pop(i);
	}
}

