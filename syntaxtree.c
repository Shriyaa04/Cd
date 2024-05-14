#include <stdio.h>
#include <stdlib.h>

// Define the structure for the syntax tree node
struct Node {
    char op;        // Operator ('+', '-', '*', '/')
    int value;      // Value (if it's a leaf node)
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(char op, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->op = op;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to evaluate the syntax tree
int evaluate(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    // If the node is a leaf node (value), return its value
    if (node->op == '0') {
        return node->value;
    }
    // If the node is an operator, evaluate its left and right subtrees
    int left_val = evaluate(node->left);
    int right_val = evaluate(node->right);
    // Perform the operation based on the node's operator
    switch(node->op) {
        case '+':
            return left_val + right_val;
        case '-':
            return left_val - right_val;
        case '*':
            return left_val * right_val;
        case '/':
            if (right_val != 0) {  // Check for division by zero
                return left_val / right_val;
            } else {
                printf("Error: Division by zero\n");
                exit(1);
            }
        default:
            printf("Error: Invalid operator\n");
            exit(1);
    }
}

int main() {
    // Example syntax tree:
    //      '+'
    //     /   \
    //    3     '*'
    //         /   \
    //        4     5
    struct Node* root = createNode('+', 0);
    root->left = createNode('0', 3);
    root->right = createNode('*', 0);
    root->right->left = createNode('0', 4);
    root->right->right = createNode('0', 5);

    // Evaluate the syntax tree
    int result = evaluate(root);
    printf("Result: %d\n", result);  // Output: 23 (3 + (4 * 5) = 23)

    // Free allocated memory
    // Note: In a real-world application, proper memory management would be needed
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);
    
    return 0;
}
