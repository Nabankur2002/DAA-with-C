#include <stdio.h>
#include <limits.h>

// Function to compute the minimum number of multiplications
void matrixChainOrder(int d[], int n) {
    int m[n][n];
    int i, j, k, L, q;

    // cost is zero when multiplying one matrix
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is chain length
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++) {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);
}

int main() {

    int no;
    printf("Enter the size of the array: ");
    scanf("%d ",&no);
    int arr[no];
    for(int i=0; i<no; i++) {
        scanf("%d", &arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, size);

    return 0;
}