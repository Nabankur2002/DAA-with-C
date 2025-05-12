#include <stdio.h>
#include <limits.h>

void findSecondSmallestAndLargest(int arr[], int n) {
    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return;
    }

    int smallest = INT_MAX, secondSmallest = INT_MAX;
    int largest = INT_MIN, secondLargest = INT_MIN;

    // Traverse the array to find second smallest and second largest
    for (int i = 0; i < n; i++) {
        // Find smallest and second smallest
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }

        // Find largest and second largest
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    // Output results
    if (secondSmallest == INT_MAX) {
        printf("No second smallest element exists.\n");
    } else {
        printf("Second smallest element: %d\n", secondSmallest);
    }

    if (secondLargest == INT_MIN) {
        printf("No second largest element exists.\n");
    } else {
        printf("Second largest element: %d\n", secondLargest);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findSecondSmallestAndLargest(arr, n);

    return 0;
}