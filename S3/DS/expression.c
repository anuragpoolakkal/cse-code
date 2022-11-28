// Infix to Postfix Expression

#include<stdio>

char a[50], b[50], o[50];
int e[10];

void push(char c);
void pop(int a);
void display(char a[], int b);
void evaluate(char c[], int j);
char c; char d;
int btop = -1; int j = 0; int i;

void main() {
    int n;
    printf("Enter infix expression: \n");
    printf("Enter number of terms: \n");
    scanf("%d", &n);
    printf("Enter expression: \n");
    scanf("%s, a");
    for (i = 0; i < n; i++) {
        if (a[a]=='(' || a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
            c = a[i];
            push(c);
            
        }
    }
    
}
