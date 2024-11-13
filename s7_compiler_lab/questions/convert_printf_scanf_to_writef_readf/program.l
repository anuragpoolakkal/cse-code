%{
// Convert printf and scanf to writef and readf
%}

%%
printf {
    fprintf(yyout, "%s", "writef");
}

scanf {
    fprintf(yyout, "%s", "readf");
}

. {
    fprintf(yyout, "%s", yytext);
}
%%

int main(){
    extern FILE *yyin, *yyout;
    yyin = fopen("sample.c", "r");
    yyout = fopen("output.c", "w");

    yylex();

    return 0;
}

int yywrap(){
    return 1;
}