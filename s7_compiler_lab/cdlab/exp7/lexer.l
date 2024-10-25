%{
    #include "y.tab.h"
%}

%% 

[a-zA-Z_][a-zA-Z_0-9]* {
    printf("Token: id, Value: %s\n", yytext);
    return id;
}

[0-9]+(\.[0-9]*)? {
    printf("Token: num, Value: %s\n", yytext);
    return num;
}

[+/*-] {
    printf("Token: op, Value: %s\n", yytext);
    return op;
}

\n {
    return 0; // End of input
}

. {
    return yytext[0]; // Return single characters
}

%% 

int yywrap() {
    return 1;
}
