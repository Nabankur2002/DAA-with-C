#include <stdio.h>

// Function to find pair
int* findpair(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    static int result[2];

    // Assuming array is sorted, otherwise sort it first
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            result[0] = arr[left];
            result[1] = arr[right];
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return NULL; // return NULL if not found
}

int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    int* pair = findpair(arr, size, target);
    if (pair != NULL) {
        printf("The pair is: %d %d\n", pair[0], pair[1]);
    } else {
        printf("Pair not found\n");
    }

    return 0;
}
