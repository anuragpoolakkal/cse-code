// a^nb, n>=10

#include <stdio.h>
#include <string.h>
typedef struct DFA
{
    int nos;
    int noi;
    int nof;
    int delta[100][100];
    int final[10];
    char inputSymbols[10];
} DFA;

int checkSymbol(char ch, DFA d)
{
    for (int i = 0; i < d.noi; i++)
    {
        if (ch == d.inputSymbols[i])
        {
            return i;
        }
    }
    return -1;
}

int checkFinalState(int st, DFA d)
{
    for (int i = 0; i < d.nof; i++)
    {
        if (st == d.final[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    DFA d;
    d.nos = 12;
    d.nof = 1;
    d.noi = 2;
    d.inputSymbols[0] = 'a';
    d.inputSymbols[1] = 'b';
    d.final[0] = 11;

    for (int i = 0; i <= 9; i++)
    {
        d.delta[i][0] = i + 1;
        d.delta[i][1] = -1;
    }

    d.delta[10][0] = 10;
    d.delta[10][1] = 11;

    d.delta[11][0] = -1;
    d.delta[11][1] = -1;

    do
    {
        char string[10];
        printf("\nEnter a string: ");
        scanf(" %s", string);
        int stateCounter = 0;
        int flag = 1;
        for (int i = 0; i < strlen(string); i++)
        {
            int symPos = checkSymbol(string[i], d);
            if (symPos == -1)
            {
                flag = 0;
                break;
            }
            stateCounter = d.delta[stateCounter][symPos];
        }
        if (flag == 1 && checkFinalState(stateCounter, d) == 1)
        {
            printf("%s is accepted. ", string);
        }
        else
        {
            printf("%s is not accpeted. ", string);
        }
    } while (1);

    return 0;
}