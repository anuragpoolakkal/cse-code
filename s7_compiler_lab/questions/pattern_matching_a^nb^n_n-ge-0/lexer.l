%{
// a^nb^n, n >= 0
#include "y.tab.h"
%}

%% 
a       { return A; }
b       { return B; }
[ \t\n] ;
.       { printf("Unexpected character: %s\n", yytext); }

%% 

int yywrap(void) {
    return 1;
}

int main(void) {
    yylex();
    return 0;
}