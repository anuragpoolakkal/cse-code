%{
	#include<stdio.h>
	int lc = 0, sc = 0, tc = 0, ch = 0, wc = 0;
%}

%%
\n {lc++; ch += yyleng;}
. {ch += yyleng;}
%%

int yywrap() {
	return 1;
}

int main () {
	printf("Enter the sentence: ");
	yylex();
	printf("Number of lines: %d\n", lc);
	printf("Number of characters: %d\n", ch);
	
	return 0;
}

// Ctrl+D to end input
	


