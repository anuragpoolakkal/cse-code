%{
    // SIMPLE SENTENCE AND COMPOUND SENTENCE
    int simple = 1;
%}

%%
(" ")(and|or|but)(" ") {
    simple = 0;
}

\n {return 0;}

. {}

%%

int main(){
    printf("Enter a sentence:\n");
    yylex();

    if(simple){
        printf("\nSimple Sentence.\n");
    }
    else{
        printf("\nCompound Sentence.\n");
    }

    return 0;
}

int yywrap(){
    return 1;
}