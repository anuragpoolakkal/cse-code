%{
    // PROGRAM TO COUNT THE NUMBER OF POSITIVE AND NEGATIVE INTEGERS AND FRACTIONS
    int p, n, f;
%}

%%
[0-9] {
    p++;
}

-[0-9] {
    n++;
}

[0-9].[0-9] {
    f++;
}

[ \n] {}
%%

int main(){
    FILE *fp = fopen("data.txt", "r");
    yyin = fp;

    yylex();

    printf("\nPositive numbers: %d\nNegative numbers: %d\nFractions: %d\n", p, n, f);

    return 0;
}

int yywrap(){
    return 1;
}