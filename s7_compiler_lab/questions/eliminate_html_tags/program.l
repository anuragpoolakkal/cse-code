%{
// program to eliminate HTML tags
%}

%%
\<[^\>]+\> {

}

[^\<]+ {
    fprintf(yyout, "%s", yytext);
}

. {
}
%%

int main(){
    extern FILE *yyin, *yyout;
    yyin = fopen("index.html", "r");
    yyout = fopen("output.txt","w");

    yylex();

    return 0;
}

int yywrap(){
    return 1;
}