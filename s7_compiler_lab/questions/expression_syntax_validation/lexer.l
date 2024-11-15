%{
// PROGRAM TO CHECK SYNTAX OF A SIMPLE EXPRESSION INVOLVING OPERATORS +,-,*,/
#include "y.tab.h"
%}

%%
[0-9]+ { return NUMBER; }
[a-zA_Z][a-zA-Z0-9_]* { return ID; }
\n { return NL; }
. { return yytext[0]; }
%%

int yywrap() {
    return 1;
}