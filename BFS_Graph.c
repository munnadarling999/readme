#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Define maximum number of vertices in the graph

// Function prototypes
void bfs(int graph[MAX][MAX], int n, int start);

int main() {
    int n, start;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bfs(graph, n, start);

    return 0;
}

// Function to perform BFS on the graph
void bfs(int graph[MAX][MAX], int n, int start) {
    int queue[MAX], front = 0, rear = -1;
    int visited[MAX] = {0};

    // Add the start vertex to the queue and mark it as visited
    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS traversal starting from vertex %d: ", start);

    while (front <= rear) {
        int current = queue[front++];  // Dequeue the current vertex
        printf("%d ", current);

        // Enqueue all adjacent unvisited vertices
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

/*Enter the number of vertices: 5
Enter the adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
Enter the starting vertex: 0
BFS traversal starting from vertex 0: 0 1 2 3 4 */

/*0
   / \
  1   2
 / \
3   4  */