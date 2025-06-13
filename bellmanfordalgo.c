//Write a program for Bellman Ford Algorithm

#include <stdio.h>
#include <limits.h>

#define N 10
int n;

int d[N];  
int pi[N];

int W[N][N];

void Initialize_Singlesource(int S) {
    for (int i = 0; i < n; i++) {
        d[i] = 999;    // Infinite cost
        pi[i] = -1;    // No predecessor
    }
    d[S] = 0;
}

void RELAX(int u, int v) {
    if (W[u][v] != 999) { // Edge exists
        if (d[v] > d[u] + W[u][v]) {
            d[v] = d[u] + W[u][v];
            pi[v] = u;
        }
    }
}

int bellmanFordAlgorithm(int S) {
    Initialize_Singlesource(S);

    // Step 1: Relax all edges V - 1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (W[u][v] != 999) {
                    RELAX(u, v);
                }
            }
        }
    }

    // Step 2: Check for negative weight cycle
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (W[u][v] != 999) {
                if (d[v] > d[u] + W[u][v]) {
                    return 0; // Negative cycle found
                }
            }
        }
    }

    return 1; // Success
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the graph weight matrix (use 999 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &W[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (!bellmanFordAlgorithm(source)) {
        printf("Negative weight cycle detected. Cannot compute shortest paths.\n");
        return 1;
    }

    printf("Vertex\tDistance from source\tPredecessor\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t\t", i, d[i]);
        if (pi[i] == -1) {
            printf("None");
        } else {
            printf("%d", pi[i]);
        }
        printf("\n");
    }

    return 0;
}