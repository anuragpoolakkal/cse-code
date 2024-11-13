%{
    // Nested if and print level of nesting
    int open = 0, max = 0;
%}

%%
if.*\{ {
    open++;
    max = open;
}

\} {
    if(open != 0) open--; 
    if(open == 0){
        printf("Nested level: %d\n", max);
        max = 0;
    }
}

[\n\t ]+ {
}

. {}

%%

int main(){
    FILE *fp = fopen("program.txt", "r");
    yyin = fp;

    yylex();

    return 0;
}

int yywrap(){
    return 1;
}