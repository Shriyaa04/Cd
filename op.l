#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OPERATORS 7
#define TABLE_SIZE 10

// Function to initialize operator precedence table
void initializeTable(char table[][TABLE_SIZE], char operators[], int num_operators) {
    for (int i = 0; i < num_operators; i++) {
        for (int j = 0; j < num_operators; j++) {
            table[i][j] = '=';
        }
    }

    for (int i = 0; i < num_operators; i++) {
        table[i][NUM_OPERATORS] = '>';
        table[NUM_OPERATORS][i] = '<';
        table[i][i] = '=';
    }

    for (int i = 0; i < num_operators; i++) {
        if (operators[i] == '(' || operators[i] == ')') {
            table[NUM_OPERATORS][i] = '<';
            table[i][NUM_OPERATORS] = '>';
        }
    }
}

// Function to print operator precedence table
void printTable(char table[][TABLE_SIZE], char operators[], int num_operators) {
    printf("Operator Precedence Table:\n");
    printf("    ");
    for (int i = 0; i < num_operators; i++) {
        printf("%c  ", operators[i]);
    }
    printf("$\n");

    for (int i = 0; i < num_operators + 1; i++) {
        printf("%c   ", operators[i]);
        for (int j = 0; j < num_operators + 1; j++) {
            printf("%c  ", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char operators[NUM_OPERATORS] = {'+', '-', '*', '/', '^', '(', ')'};
    char table[TABLE_SIZE][TABLE_SIZE];
    initializeTable(table, operators, NUM_OPERATORS);
    printTable(table, operators, NUM_OPERATORS);

    return 0;
}
