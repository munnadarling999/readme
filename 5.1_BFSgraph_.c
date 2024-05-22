#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Define maximum number of vertices in the graph

// Function prototype for BFS
void bfs(int graph[MAX][MAX], int n, int start);

int main() {
    int n, start;
    int graph[MAX][MAX];

    // Prompt the user to enter the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Prompt the user to enter the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Prompt the user to enter the starting vertex for BFS
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    // Perform BFS traversal starting from the given vertex
    bfs(graph, n, start);

    return 0;
}

// Function to perform BFS on the graph
void bfs(int graph[MAX][MAX], int n, int start) {
    int queue[MAX], front = 0, rear = -1; // Initialize the queue
    int visited[MAX] = {0}; // Array to keep track of visited vertices, initialized to 0

    // Add the start vertex to the queue and mark it as visited
    queue[++rear] = start;
    visited[start] = 1;

    // Print the starting message for BFS traversal
    printf("BFS traversal starting from vertex %d: ", start);

    // Continue the BFS until the queue is empty
    while (front <= rear) {
        // Dequeue the current vertex
        int current = queue[front++];
        printf("%d ", current); // Print the current vertex

        // Enqueue all adjacent unvisited vertices
        for (int i = 0; i < n; i++) {
            // Check if there is an edge from the current vertex to vertex i
            // and if vertex i is not visited
            if (graph[current][i] == 1 && !visited[i]) {
                queue[++rear] = i; // Enqueue vertex i
                visited[i] = 1; // Mark vertex i as visited
            }
        }
    }
    printf("\n"); // Print newline after traversal
}

/*
Example Input:
Enter the number of vertices: 5
Enter the adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
Enter the starting vertex: 0

Expected Output:
BFS traversal starting from vertex 0: 0 1 2 3 4

Graph Representation:
0
   / \
  1   2
 / \
3   4
*/

/*
Explanation of the Code:
1. Define constants and function prototypes.
2. Main function: 
   - Reads the number of vertices and the adjacency matrix from the user.
   - Calls the BFS function with the graph, number of vertices, and starting vertex.
3. BFS function:
   - Uses a queue to keep track of vertices to visit.
   - Uses an array visited to track which vertices have been visited.
   - Starts from the given vertex, enqueues it, and marks it as visited.
   - Enters a loop to dequeue a vertex, print it, and enqueue all its unvisited neighbors.
   - Continues until all reachable vertices have been visited and printed.
*/