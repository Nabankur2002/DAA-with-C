#include <stdio.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n, W, i;

    // User input for number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    // Input weights and values
    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the profit of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    // Input knapsack capacity
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int maxValue = knapsack(W, wt, val, n);
    printf("Maximum profit in knapsack = %d\n", maxValue);

    return 0;
}