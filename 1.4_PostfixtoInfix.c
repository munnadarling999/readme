#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure of a stack node
struct StackNode {
  char data;
  struct StackNode *next;
};

// Define the stack pointer
struct StackNode *top = NULL;

// Function to push an element onto the stack
void push(char data) {
  struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
  newNode->data = data;
  newNode->next = top;
  top = newNode;
}

// Function to pop an element from the stack
char pop() {
  if (top == NULL) {
    printf("Stack is empty\n");
    return -1;
  } else {
    char data = top->data;
    top = top->next;
    return data;
  }
}

// Function to convert a postfix expression to an infix expression
char *postfixToInfix(char *postfix) {
  // Create a stack to store the operands
  struct StackNode *stack = NULL;

  // Iterate over the postfix expression
  int i = 0;
  while (postfix[i] != '\0') {
    // If the character is an operand, push it onto the stack
    if (postfix[i] >= 'a' && postfix[i] <= 'z') {
      push(postfix[i]);
    } else {
      // If the character is an operator, pop two operands from the stack and push the result of the operation onto the stack
      char operand1 = pop();
      char operand2 = pop();
      char operator = postfix[i];
      char *expression = (char *)malloc(sizeof(char) * 4);
      expression[0] = '(';
      expression[1] = operand2;
      expression[2] = operator;
      expression[3] = operand1;
      expression[4] = ')';
      push(expression);
    }
    i++;
  }

  // Pop the final expression from the stack and return it
  char *infixExpression = pop();
  return infixExpression;
}

// Main function
int main() {
  // Get the postfix expression from the user
  char postfix[MAX_SIZE];
  printf("Enter the postfix expression: ");
  scanf("%s", postfix);

  // Convert the postfix expression to an infix expression
  char *infixExpression = postfixToInfix(postfix);

  // Print the infix expression
  printf("The infix expression is: %s\n", infixExpression);

  return 0;
}