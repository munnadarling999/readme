#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    char data[MAX_SIZE][MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char item[]) {
    if (is_full(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->top++;
    strcpy(stack->data[stack->top], item);
}

char* pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Function to check if character is operator or not
bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            return true;
    }
    return false;
}

// Convert prefix to Infix expression
char* preToInfix(char* pre_exp) {
    Stack s;
    initialize(&s);

    // length of expression
    int length = strlen(pre_exp);

    // reading from right to left
    for (int i = length - 1; i >= 0; i--) {
        // check if symbol is operator
        if (isOperator(pre_exp[i])) {
            // pop two operands from stack
            char* op1 = pop(&s);
            char* op2 = pop(&s);

            // concat the operands and operator
            char temp[MAX_SIZE];
            sprintf(temp, "(%s%c%s)", op1, pre_exp[i], op2);

            // Push string temp back to stack
            push(&s, temp);
        } else {
            // push the operand to the stack
            char operand[MAX_SIZE];
            operand[0] = pre_exp[i];
            operand[1] = '\0';
            push(&s, operand);
        }
    }

    // Stack now contains the Infix expression
    return pop(&s);
}

// Driver Code
int main() {
    char pre_exp[MAX_SIZE] = "*-A/BC-/AKL";
    printf("Infix : %s\n", preToInfix(pre_exp));
    return 0;
}
