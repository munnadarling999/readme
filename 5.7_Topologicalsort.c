#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Stack structure
typedef struct Stack {
    int data[MAX_VERTICES];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (stack->top == MAX_VERTICES - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = item;
}

int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Function to perform DFS and topological sorting
void topologicalSortUtil(int v, int adj[][MAX_VERTICES], bool visited[], Stack* Stack, int V) {
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            topologicalSortUtil(i, adj, visited, Stack, V);
        }
    }

    // Push current vertex to stack which stores the result
    push(Stack, v);
}

// Function to perform Topological Sort
void topologicalSort(int adj[][MAX_VERTICES], int V) {
    Stack Stack; // Stack to store the result
    initialize(&Stack);
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Call the recursive helper function to store
    // Topological Sort starting from all vertices one by
    // one
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, &Stack, V);
        }
    }

    // Print contents of stack
    printf("Topological sorting of the graph: ");
    while (!is_empty(&Stack)) {
        printf("%d ", pop(&Stack));
    }
    printf("\n");
}

int main() {
    // Number of nodes
    int V = 4;

    // Edges
    int edges[][2] = { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };

    // Graph represented as an adjacency matrix
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};

    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        adj[edges[i][0]][edges[i][1]] = 1;
    }

    topologicalSort(adj, V);

    return 0;
}
