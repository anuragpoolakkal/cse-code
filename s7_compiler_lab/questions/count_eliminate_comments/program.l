%{

    // LEX PROGRAM TO COUNT THE NUMBER OF COMMENT LINE IN A GIVEN C PROGRAM. ALSO ELIMINATE THEM AND COPY THAT PROGRAM INTO A SEPARATE FILE.
    int count = 0;
%}

%%
\/\/.* {
    count++;
}

\/\*([^*]|\*+[^/])*\*\/ {
    int i;
    for (i = 0; i < yyleng; i++) {
        if (yytext[i] == '\n') {
            count++;
        }
    }
    count++;
}

\n {}

. {
    fprintf(yyout, "%s", yytext);
}

%%

int main(){
    extern FILE *yyin, *yyout;
    yyin = fopen("input.c", "r");
    yyout = fopen("output.c", "w");

    yylex();

    printf("No. of comment lines: %d", count);
}

int yywrap(){
    return 1;
}