#include <stdio.h>
#include <string.h>

#define NUM_NON_TERMINALS 5
#define NUM_TERMINALS 6
#define MAX_RULE_LEN 10

// Define terminals and non-terminals
char terminals[NUM_TERMINALS][MAX_RULE_LEN] = {"+", "*", "(", ")", "id", "$"};
char non_terminals[NUM_NON_TERMINALS][MAX_RULE_LEN] = {"E", "E'", "T", "T'", "F"};

// Parsing table
char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][MAX_RULE_LEN];

// Initialize parsing table with empty strings
void initializeParsingTable() {
    for (int i = 0; i < NUM_NON_TERMINALS; ++i) {
        for (int j = 0; j < NUM_TERMINALS; ++j) {
            strcpy(parsingTable[i][j], "");
        }
    }
}

// Fill in the parsing table based on the grammar rules
void fillParsingTable() {
    // Replace the empty strings with the right-hand side of the corresponding productions

    // E -> TE'
    strcpy(parsingTable[0][0], "T");
    strcpy(parsingTable[0][4], "T");
   
    // E' -> +TE' | epsilon
    strcpy(parsingTable[1][0], "");
    strcpy(parsingTable[1][1], "+TE'");
    strcpy(parsingTable[1][2], "");
    strcpy(parsingTable[1][3], "epsilon");
    strcpy(parsingTable[1][4], "");
    strcpy(parsingTable[1][5], "epsilon");

    // T -> FT'
    strcpy(parsingTable[2][0], "F");
    strcpy(parsingTable[2][4], "F");
   
    // T' -> *FT' | epsilon
    strcpy(parsingTable[3][0], "");
    strcpy(parsingTable[3][1], "");
    strcpy(parsingTable[3][2], "");
    strcpy(parsingTable[3][3], "*FT'");
    strcpy(parsingTable[3][4], "");
    strcpy(parsingTable[3][5], "epsilon");

    // F -> (E) | id
    strcpy(parsingTable[4][0], "(E)");
    strcpy(parsingTable[4][4], "id");
}

// Print the parsing table
void printParsingTable() {
    printf("Parsing Table:\n");
    printf("\t");
    for (int i = 0; i < NUM_TERMINALS; ++i) {
        printf("%s\t", terminals[i]);
    }
    printf("\n");

    for (int i = 0; i < NUM_NON_TERMINALS; ++i) {
        printf("%s\t", non_terminals[i]);
        for (int j = 0; j < NUM_TERMINALS; ++j) {
            printf("%s\t", parsingTable[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeParsingTable();
    fillParsingTable();
    printParsingTable();

    return 0;
}
