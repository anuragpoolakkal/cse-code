%token A B

%% 
S -> A A A A A A A A A A B
   | A S B

%% 

#include <stdio.h>

int main(void) {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
