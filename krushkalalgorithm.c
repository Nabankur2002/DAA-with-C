#include <stdio.h>
#define MAXV 100
int p[MAXV], rank[MAXV];
int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void unionSets(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
    {
        if (rank[rootX] > rank[rootY])
            p[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            p[rootX] = rootY;
        else
        {
            p[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void kruskalMST(int cost[MAXV][MAXV], int n)
{
    struct Edge
    {
        int u, v, weight;
    } edges[MAXV * MAXV];
    int edgeCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cost[i][j] != 0)
            {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = cost[i][j];
                edgeCount++;
            }
        }
    }
    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = i + 1; j < edgeCount; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        rank[i] = 0;
    }
    int tc = 0;
    printf("Selected edges with their weights:\n");
    for (int i = 0; i < edgeCount; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        if (find(u) != find(v))
        {
            unionSets(u, v);
            printf("%d %d %d\n", u + 1, v + 1, weight);
            tc += weight;
        }
    }
    printf("Total minimum cost: %d\n", tc);
}
int main()
{
    int n, cost[MAXV][MAXV];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    kruskalMST(cost, n);
    return 0;
}
