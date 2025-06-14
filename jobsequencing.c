#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a Job
typedef struct Jobs {
    char id;     // Job ID
    int dead;    // Deadline of Job
    int profit;  // Profit if Job is completed before or on deadline
} Jobs;

// Function to sort jobs in descending order of profit
int compare(const void *a, const void *b) {
    Jobs *temp1 = (Jobs *)a;
    Jobs *temp2 = (Jobs *)b;
    return (temp2->profit - temp1->profit);
}

int min(int num1, int num2) {
    // Check if num1 is greater than num2
    if (num1 > num2) {
        return num2; // If yes, return num2 as it is smaller
    } 
    else {
        return num1; // Otherwise, return num1
    }
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Jobs arr[n];
    printf("Enter job details (ID Deadline Profit):\n");

    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf(" %c %d %d", &arr[i].id, &arr[i].dead, &arr[i].profit); // note space before %c to consume any leftover newline
    }

    // Sort jobs by profit in descending order
    qsort(arr, n, sizeof(Jobs), compare);

    int result[n];    // To store result sequence of jobs
    bool slot[n];     // To keep track of free time slots

    for (int i = 0; i < n; i++){
        slot[i] = false;
    }
    
    
    int totalProfit = 0;

    // Find suitable slots for each job
    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    printf("Following is the maximum profit sequence of jobs:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i])
            printf("%c ", arr[result[i]].id);
    }

    printf("\nTotal Maximum Profit: %d\n", totalProfit);

    return 0;
}
