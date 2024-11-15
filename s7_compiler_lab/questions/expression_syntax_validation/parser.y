%{
// PROGRAM TO CHECK SYNTAX OF A SIMPLE EXPRESSION INVOLVING OPERATORS +,-,*,/
#include<stdio.h>
#include<stdlib.h>
%}

%token NUMBER ID NL
%left '+' '-'
%left '*' '/'

%%
stmt: exp NL { printf("Valid expression\n"); exit(0); };

exp: exp '+' exp | exp '-' exp | exp '*' exp | exp '/' exp | '(' exp ')' | ID | NUMBER;
%%

int yyerror() {
    printf("Invalid expression\n");
    exit(0);
}

int main() {
    printf("Enter the expression: ");
    yyparse();

    return 0;
}

