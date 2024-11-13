// Implementation of DFA

#include<string.h>
#include<stdio.h>

typedef struct DFA {
    int noi;
    int nos;
    int nof;
    int delta[10][10];
    int final[10];
    char inputSymbols[10];
}
DFA;

int checkSymbol(char ch, DFA d) {
    for (int i = 0; i < d.noi; i++) {
        if (ch == d.inputSymbols[i]) {
            return i;
        }
    }
    return -1;
}

int checkFinal(int state, DFA d) {
    for (int i = 0; i < d.nof; i++) {
        if (state == d.final[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    DFA d;
    printf("Enter number of states: ");
    scanf("%d", & d.nos);
    printf("Enter number of final states: ");
    scanf("%d", & d.nof);
	printf("Enter number of input symbols: ");
    scanf("%d", & d.noi);

    // input input symbols
    for (int i = 0; i < d.noi; i++) {
        printf("Enter input symbol %d: ", i+1);
        scanf(" %c", &d.inputSymbols[i]);
    }

    // input final states
    for (int i = 0; i < d.nof; i++) {
        printf("Enter final state %d: ", i+1);
        scanf(" %d", &d.final[i]);
    }

    // input transition table
    for (int i = 0; i < d.nos; i++) {
        for (int j = 0; j < d.noi; j++) {
            printf("d(q%d, %c): ", i, d.inputSymbols[j]);
            scanf("%d", &d.delta[i][j]);
        }
    }

    // display transition table
    for (int i = 0; i < d.noi; i++) {
        printf("\t%c", d.inputSymbols[i]);
    }
    printf("\n");
    for (int i = 0; i < d.nos; i++) {
        printf("\nq%d", i);
        for (int j = 0; j < d.noi; j++) {
            printf("\t%d", d.delta[i][j]);
        }
        printf("\n");
    }

    // infinitely loop to accept input string
    do {
        char string[10];
        printf("Enter input string: ");
        scanf("%s", string);

        int stateCounter = 0;
        int flag = 1;

        for (int i = 0; i < strlen(string); i++) {
            int symPos = checkSymbol(string[i], d);
			if (symPos == -1) {
				flag = 0;
				break;
			}
			stateCounter = d.delta[stateCounter][symPos];
        }

		if (flag == 1 && checkFinal(stateCounter, d) == 1) {
			printf("%s is accepted\n", string);
		} else {
			printf("%s is not accepted\n", string);
		}
    } while (1);

	return 0;
}

// Example input --
// Enter number of states: 3
// Enter number of final states: 1
// Enter number of input symbols: 2
// Enter input symbol 1: a
// Enter input symbol 2: b
// Enter final state 1: 2
// d(q0, a): 1
// d(q0, b): 0
// d(q1, a): 1
// d(q1, b): 2
// d(q2, a): 1
// d(q2, b): 0
//         a       b

// q0      1       0

// q1      1       2

// q2      1       0
// Enter input string: aab
// aab is accepted
// Enter input string: abba
// abba is not accepted
// Enter input string: ab
// ab is accepted
// Enter input string: 