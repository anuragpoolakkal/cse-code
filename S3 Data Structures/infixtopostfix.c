// Experiment 7 - Infix to Postfix

#include<stdio.h>

char a[50], b[50], o[50];
int e[10];
void push(char c);
void pop(int a);
void display(char a[], int b);
void evaluate(char c[], int j);
char c;
char d;
int btop = -1;
int j = 0;
int i;
void main() {
        int n;
        printf("Enter infix expression: \n");
        printf("Enter number of terms: ");
        scanf("%d", & n);
        printf("Enter expression: ");
        scanf("%s", a);
        for (i = 0; i < n; i++) {
                if (a[i] == '(' || a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
                        c = a[i];
                        push(c);
                } else if (a[i] != '(' && a[i] != '+' && a[i] != '-' && a[i] != '*' && a[i] != '/' && a[i] != ')') {
                        c = a[i];
                        o[j] = c;
                        j++;
                } else {
                        pop(2);
                }
        }
        while (btop != -1) {
                pop(1);
        }

        printf("infix expression: ");
        display(a, n);
        printf("\n");
        printf("postfix expression: ");
        display(o, j);
        printf("\n");
        evaluate(o, j);
}

void push(char c) {
        if (c == '(') {
                btop++;
                b[btop] = c;
        } else if (c == '/') {
                if (btop >= 0) {
                        if (b[btop] != '*' && b[btop] != '/') {
                                btop++;
                                b[btop] = c;
                        } else {
                                pop(1);
                                push(c);
                        }

                } else {
                        btop++;
                        b[btop] = c;
                }
        } else if (c == '+') {
                if (btop >= 0) {
                        if (b[btop] != '*' && b[btop] != '/' && b[btop] != '+') {
                                btop++;
                                b[btop] = c;
                        } else {
                                pop(1);
                                push(c);
                        }

                } else {
                        btop++;
                        b[btop] = c;
                }
        } else if (c == '-') {
                if (btop >= 0) {
                        if (b[btop] != '*' && b[btop] != '/' && b[btop] != '+' && b[btop] != '+' && b[btop] != '-') {
                                btop++;
                                b[btop] = c;
                        } else {
                                pop(1);
                                push(c);
                        }

                } else {
                        btop++;
                        b[btop] = c;
                }
        } else {
                if (btop >= 0) {
                        if (b[btop] != '*') {
                                btop++;
                                b[btop] = c;
                        } else {
                                pop(1);
                                push(c);
                        }

                } else {
                        btop++;
                        b[btop] = c;
                }
        }
}

void pop(int a) {
        if (a == 2) {
                while (b[btop] != '(') {
                        d = b[btop];
                        o[j] = d;
                        j++;
                        btop--;
                }
                if (b[btop] == '(') {
                        btop--;
                        return;
                }
        } else {
                d = b[btop];
                o[j] = d;
                j++;
                btop--;
        }
}

void display(char a[], int b) {
        for (i = 0; i <= b; i++) {
                printf("%c", a[i]);
        }
}

void evaluate(char c[], int j) {
        int etop = -1, r;
        for (i = 0; i < j; i++) {
                if (c[i] != '+' && c[i] != '-' && c[i] != '*' && c[i] != '/') {
                        etop++;
                        e[etop] = c[i] - '0';
                } else if (c[i] == '+') {
                        r = e[etop - 1] + e[etop];
                        etop--;
                        e[etop] = r;
                } else if (c[i] == '-') {
                        r = e[etop - 1] - e[etop];
                        etop--;
                        e[etop] = r;
                } else if (c[i] == '*') {
                        r = e[etop - 1] * e[etop];
                        etop--;
                        e[etop] = r;
                } else {
                        r = e[etop - 1] / e[etop];
                        etop--;
                        e[etop] = r;
                }
        }
        printf("Result: %d", e[etop]);
}
