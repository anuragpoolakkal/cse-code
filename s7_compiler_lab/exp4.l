%{ 
    
%}

%%
[ \n\t]+ {fprintf(yyout, "");}
. {fprintf(yyout, "%s", yytext);}
%%

int yywrap() {
    return 1;
}

int main () {
    extern FILE *yyin, *yyout;
    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "r);
    yylex();
    return 0;
}