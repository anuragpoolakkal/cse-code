%{
  #include<stdio.h>
  #include <string.h>
  int vow_count = 0;
  int con_count = 0;
%}

%%
[aeiouAEIOU] { vow_count++; }
[a-zA-Z] {
  if (!strchr("aeiouAEIOU", yytext[0])) {
    con_count++;
  }
}
%%

int yywrap() {
  return 1;
}


int main()
{
    yylex();
    printf("Vowels = %d and Consonants = %d\n",vow_count,con_count);
    return 0;
}
