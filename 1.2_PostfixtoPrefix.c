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

bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

char* postToPre(char* post_exp) {
    Stack s;
    initialize(&s);

    int length = strlen(post_exp);

    for (int i = 0; i < length; i++) {
        if (isOperator(post_exp[i])) {
            char op1[MAX_SIZE];
            strcpy(op1, pop(&s));
            char op2[MAX_SIZE];
            strcpy(op2, pop(&s));

            char temp[MAX_SIZE];
            temp[0] = post_exp[i];
            temp[1] = '\0';
            strcat(temp, op2);
            strcat(temp, op1);

            push(&s, temp);
        } else {
            char operand[MAX_SIZE];
            operand[0] = post_exp[i];
            operand[1] = '\0';
            push(&s, operand);
        }
    }

    char* ans = (char*)malloc(MAX_SIZE * sizeof(char));
    ans[0] = '\0';
    while (!is_empty(&s)) {
        strcat(ans, pop(&s));
    }
    return ans;
}

int main() {
    char post_exp[MAX_SIZE] = "AB+CD-*";

    // Function call
    printf("Prefix : %s\n", postToPre(post_exp));
    return 0;
}
