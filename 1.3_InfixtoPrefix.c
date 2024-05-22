#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}

int is_full(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, char item) {
    if (is_full(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = item;
}

char pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

// Function to get the priority of operators
int getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

// Function to convert the infix expression to postfix
char* infixToPostfix(char* infix) {
    Stack char_stack;
    initialize(&char_stack);
    int l = strlen(infix);
    char output[MAX_SIZE] = "";
    strcat(output, "(");
    strcat(output, infix);
    strcat(output, ")");
    l += 2;
    int output_index = 0;

    for (int i = 0; i < l; i++) {
        // If the scanned character is an operand, add it to output.
        if (isalpha(output[i]) || isdigit(output[i]))
            output[output_index++] = output[i];

        // If the scanned character is an ‘(‘, push it to the stack.
        else if (output[i] == '(')
            push(&char_stack, '(');

        // If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
        else if (output[i] == ')') {
            while (char_stack.data[char_stack.top] != '(') {
                output[output_index++] = pop(&char_stack);
            }
            // Remove '(' from the stack
            pop(&char_stack);
        }

        // Operator found
        else {
            if (isOperator(char_stack.data[char_stack.top])) {
                if (output[i] == '^') {
                    while (getPriority(output[i]) <= getPriority(char_stack.data[char_stack.top])) {
                        output[output_index++] = pop(&char_stack);
                    }
                }
                else {
                    while (getPriority(output[i]) < getPriority(char_stack.data[char_stack.top])) {
                        output[output_index++] = pop(&char_stack);
                    }
                }
                // Push current Operator on stack
                push(&char_stack, output[i]);
            }
        }
    }
    output[output_index] = '\0';
    return strdup(output);
}

// Function to convert infix to prefix notation
char* infixToPrefix(char* infix) {
    // Reverse String and replace ( with ) and vice versa
    // Get Postfix
    // Reverse Postfix
    int l = strlen(infix);

    // Reverse infix
    strrev(infix);

    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char* prefix = infixToPostfix(infix);

    // Reverse postfix
    strrev(prefix);

    return prefix;
}

// Driver code
int main() {
    char infix[MAX_SIZE] = "x+y*z/w+u";

    // Function call
    printf("Prefix expression: %s\n", infixToPrefix(infix));
    return 0;
}
