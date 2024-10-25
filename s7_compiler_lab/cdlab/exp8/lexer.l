%{
    #include "y.tab.h"
%}

%%

[a-zA-Z_][a-zA-Z_0-9]*   { return ID; }
[0-9]+(\.[0-9]+)?        { return NUM; }
[+\-*/]                  { return OP; }
.                        { return yytext[0]; }
\n                       { /* Ignore newlines */ }

%%

int yywrap() {
    return 1;
}
