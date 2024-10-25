%{
    #include <stdio.h>
    #include <stdlib.h>
    int flag = 0;
%}

%token NUMBER

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%% 

ArithmeticExpression:
    E {
        printf("\nResult = %d\n", $1);
        return 0;
    }
;

E:
    E '+' E { $ = $1 + $3; }
    | E '-' E { $ = $1 - $3; }
    | E '*' E { $ = $1 * $3; }
    | E '/' E { 
        if ($3 == 0) {
            yyerror("Division by zero");
            YYABORT;
        }
        $ = $1 / $3; 
    }
    | E '%' E { 
        if ($3 == 0) {
            yyerror("Division by zero");
            YYABORT;
        }
        $ = $1 % $3; 
    }
    | '(' E ')' { $ = $2; }
    | NUMBER { $ = $1; }
;

%% 

int main() {
    printf("\nEnter an arithmetic expression (Addition, Subtraction, Multiplication, Division, Modulus, and Parentheses):\n");
    yyparse();
    if (flag == 0) {
        printf("\nEntered arithmetic expression is valid\n\n");
    }
    return 0;
}

void yyerror(const char *s) {
    printf("\nError: %s\n", s);
    flag = 1;
}
