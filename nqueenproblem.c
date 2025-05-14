#include <stdio.h>
#include <stdbool.h>
#define MAXN 20
bool place(int board[MAXN][MAXN], int row, int col, int N)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)

        {
            return false;
        }
    }
    return true;
}

bool Nqueen(int board[MAXN][MAXN], int row, int N)
{
    if (row == N)
    {
        return true;
    }
    for (int col = 0; col < N; col++)
    {
        if (place(board, row, col, N))
        {
            board[row][col] = 1;
            if (Nqueen(board, row + 1, N))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void printSolution(int board[MAXN][MAXN], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
            {
                printf("%d ", j + 1);
            }
        }
    }
    printf("\n");
}

int main()
{
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    if (N <= 0)
    {
        printf("N must be a positive integer.\n");
        return 1;
    }
    int board[MAXN][MAXN] = {0};
    if (Nqueen(board, 0, N))
    {
        printSolution(board, N);
    }
    else
    {
        printf("Solution does not exist for N = %d\n", N);
    }
    return 0;
}