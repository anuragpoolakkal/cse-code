%token A B

%% 
S -> A S B
   | /* epsilon */ 

%% 

#include <stdio.h>

int main(void) {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}