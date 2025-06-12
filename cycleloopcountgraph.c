//Write a program in C that accepts a graph as input from the user & find the number of cycles/self-loops existing and printing the same as output


#include <stdio.h>

#define MAXN 50
int cntLoops(int m[MAXN][MAXN], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[i][i] == 1)
        {
            c++;
        }
    }
    return c;
}

int dfs(int m[MAXN][MAXN], int n, int v, int vis[], int stk[]) {
    vis[v] = 1;
    stk[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (m[v][i] == 1)
        {
            if (!vis[i] && dfs(m, n, i, vis, stk))
            {
                return 1;
            }
            else if (stk[i])
            {
                return 1;
            }
        }
    }
    stk[v] = 0;
    return 0;
}

int cntCycles(int m[MAXN][MAXN], int n)
{
    int vis[MAXN] = {0};
    int stk[MAXN] = {0};
    int c = 0;
    for (int i = 0; i < n; i++)
    {

if (!vis[i])
        {
            if (dfs(m, n, i, vis, stk))
            {
                c++;
            }
        }
    }
    return c;
}

int main()
{
    int n;
    int m[MAXN][MAXN];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    int l = cntLoops(m, n);
    int c = cntCycles(m, n);
    printf("\nNumber of self-loops: %d\n", l);
    printf("Number of cycles: %d\n", c);
    
    return 0;
}