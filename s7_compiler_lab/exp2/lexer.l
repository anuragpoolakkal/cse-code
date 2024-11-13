%{
int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*

%%
#.* { 
    printf("\n %s is a preprocessor directive", yytext); 
}

int|float|char|double|while|for|struct|typedef|do|if|break|continue|void|switch|return|else|goto { 
    printf("\n\t %s is a keyword", yytext); 
}

"/*" { 
    COMMENT = 1; // Start of a multi-line comment
}

{identifier}$ { 
    if(!COMMENT) printf("\n Function %s \n\t", yytext); // Function declaration
}

\{ { 
    if(!COMMENT) printf("\n BLOCK BEGINS"); // Start of a block
}

\} { 
    if(!COMMENT) printf("\n BLOCK ENDS"); // End of a block
}

{identifier}($$0-9]*$$)? { 
    if(!COMMENT) printf("\n %s is an IDENTIFIER", yytext); // Identifier or array
}

\".*\" { 
    if(!COMMENT) printf("\n %s is a STRING", yytext); // String literal
}

[0-9]+ { 
    if(!COMMENT) printf("\n %s is a NUMBER", yytext); // Numeric literal
}

$(\:)? { 
    if(!COMMENT) printf("\n\t"); ECHO; printf("\n"); // Closing parenthesis
}

\( ECHO; // Opening parenthesis

= { 
    if(!COMMENT) printf("\n\t %s is an ASSIGNMENT OPERATOR", yytext); // Assignment operator
}

\<=|\>=|\<|\>|== { 
    if(!COMMENT) printf("\n\t %s is a RELATIONAL OPERATOR", yytext); // Relational operators
}
%%


int main() {
	FILE *file;
	file = fopen("code.c", "r");
	if(!file) {
		printf("Could not open the file");
		exit(0);
	}
	yyin = file;
	yylex();
	printf("\n");
	return 0;
}
int yywrap() {
	return 1;
}