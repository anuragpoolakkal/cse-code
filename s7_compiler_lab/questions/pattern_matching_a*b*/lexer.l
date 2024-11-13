%{
// a*b*
#include<stdio.h>
%}

%token A B NL

%%
stmt: S NL { printf("valid string\n"); (0); };

S: A S | S B | ;

X:B;

%%
int yyerror(char *msg) {
    printf("invalid message\n");
    return 0;
}

int main() {
    printf("Enter string: ");
    yylex();
    return 0;
}