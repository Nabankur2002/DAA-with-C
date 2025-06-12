#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void sortArray(int arr[], int size);
int linearSearch(int arr[], int size, int key, int *comparisons);
int binarySearch(int arr[], int size, int key, int *comparisons);

// Bubble Sort (ascending)
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int size, int key, int *comparisons) {
    for (int i = 0; i < size; i++) {
        (*comparisons)++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key, int *comparisons) {
    int start = 0, end = size - 1, mid;
    while (start <= end) {
        (*comparisons)++;
        mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int size, key, liComparisons = 0, biComparisons = 0;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the integer to search for: ");
    scanf("%d", &key);

    int linearResult = linearSearch(arr, size, key, &liComparisons);
    if (linearResult != -1) {
        printf("In Linear Search, the key found at index %d after %d comparisons\n", linearResult, liComparisons);
    } else {
        printf("Linear Search: Key not found after %d comparisons\n", liComparisons);
    }

    sortArray(arr, size);

    int binaryResult = binarySearch(arr, size, key, &biComparisons);
    if (binaryResult != -1) {
        printf("In Binary Search, the key found at index %d after %d comparisons\n", binaryResult, biComparisons);
    } else {
        printf("Binary Search: Key not found after %d comparisons\n", biComparisons);
    }

    // Determine better search
    if (liComparisons < biComparisons) {
        printf("Linear Search is better in this case.\n");
    } else {
        printf("Binary Search is better in this case.\n");
    }

    return 0;
}
