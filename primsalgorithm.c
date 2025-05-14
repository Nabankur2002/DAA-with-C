#include <stdio.h>
#include <limits.h>
#define MAXV 100
void primMST(int cost[MAXV][MAXV], int N)
{
    int p[MAXV];
    int key[MAXV];
    int inMST[MAXV];
    int tc = 0;
    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }
    key[0] = 0;
    p[0] = -1;
    for (int c = 0; c < N - 1; c++)
    {
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < N; v++)
        {
            if (inMST[v] == 0 && key[v] < minKey)
            {
                minKey = key[v];
                minIndex = v;
            }
        }
        inMST[minIndex] = 1;
        for (int v = 0; v < N; v++)
        {
            if (cost[minIndex][v] && inMST[v] == 0 && cost[minIndex][v] < key[v])
            {
                p[v] = minIndex;
                key[v] = cost[minIndex][v];
            }
        }
    }
    printf("Selected edges with their weights:\n");
    for (int i = 1; i < N; i++)
    {
        printf("%d %d %d\n", p[i], i, cost[p[i]][i]);
        tc+= cost[p[i]][i];
    }
    printf("Total minimum cost: %d\n", tc);
}
int main()
{
    int N;
    int cost[MAXV][MAXV];
    printf("Enter the number of vertices: ");
    scanf("%d", &N);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    primMST(cost, N);
    return 0;
}