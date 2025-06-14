#include <stdio.h>

#define INF 999 //Infinity is regarded as 999
#define MAXN 50 //maximum number of vertices handled by the graph

int W[MAXN][MAXN]; // Adjacency matrix
int d[MAXN];      // Distance array
int p[MAXN];      // Parent array
int flag[MAXN];   // Visited flag
int n;           // Number of vertices

void initialize(int src) {
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        p[i] = -1;
        flag[i] = 0;
    }
    d[src] = 0;
}

int extractmin() {
    int min = INF, v = -1;
    for (int i = 0; i < n; i++) {
        if (!flag[i] && d[i] < min) {
            min = d[i];
            v = i;
        }
    }
    if (v != -1){
        flag[v] = 1;
    }
    return v;
}

void relax(int u, int v) {
    if (d[v] > d[u] + W[u][v]) {
        d[v] = d[u] + W[u][v];
        p[v] = u;
    }
}

void djikstra(int src) {
    initialize(src);
    for (int i = 0; i < n; i++) {
        int u = extractmin();
        if (u == -1) break;
        for (int v = 0; v < n; v++) {
            if (W[u][v] != INF && !flag[v]) {
                relax(u, v);
            }
        }
    }
}

int main() {
    int src;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 999 for no direct edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &W[i][j]);
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    djikstra(src);

    printf("Shortest distances and parents from source %d: ", src);
    for (int i = 0; i < n; i++) {
        if (p[i] == -1)
            printf("[Vertex%d: Distance=%d, Parent=None] ", i, d[i]);
        else
            printf("[Vertex%d: Distance=%d, Parent=%d] ", i, d[i], p[i]);
    }

    return 0;
}
