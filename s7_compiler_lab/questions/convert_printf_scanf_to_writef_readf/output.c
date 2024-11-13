#include <stdio.h>

int main(){
    int a;
    writef("Enter a number: ");
    readf("%d", &a);

    writef("You entered %d\n", a);
}