#include <stdio.h>
#include <stdlib.h>

#define MAXV 100

void bfs(int graph[][MAXV], int n, int start) {
    int visited[MAXV] = {0};
    int queue[MAXV];
    int front = -1, rear = -1;

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS traversal: ");
    while (front != rear) {
        int vertex = queue[++front];
        printf("%d ", vertex);
        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

void dfs(int graph[][MAXV], int n, int start) {
    int visited[MAXV] = {0};
    int stack[MAXV];
    int top = -1;

    stack[++top] = start;

    printf("DFS traversal: ");
    while (top != -1) {
        int vertex = stack[top--];

        if (!visited[vertex]) {
            visited[vertex] = 1;
            printf("%d ", vertex);

            // Push adjacent vertices to stack in reverse order for consistent traversal
            for (int i = n - 1; i >= 0; i--) {
                if (graph[vertex][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}


int main() {
    int n, start;
    int graph[MAXV][MAXV];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    bfs(graph, n, start);
    dfs(graph, n, start);

    return 0;
}
