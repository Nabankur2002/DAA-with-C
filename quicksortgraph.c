//Write a program in C that implements the following
//1. A one dimensional array defined globally containing a list of unsorted integers.
//2. Module Quick_sort() when called sorted lists.
//3. Sorted elements are displayed in the main module.
//4. Record the time duration to sort the elements(start time-end time) for different values of n i.e 500, 1000, 5000. Plot it on a graph , Time(ns) vs Input site (n) and comment to the asymptocity.

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX 10000

int arr[MAX];

void quick_sort(int arr[], int first, int last) {
    int i, j, pivot, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (arr[i] < arr[pivot] && i <= last) {
                i++;
            }
            while (arr[j] > arr[pivot]) {
                j--;
            }
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quick_sort(arr, first, j - 1);
        quick_sort(arr, j + 1, last);
    }
}

int main() {
    int n;
    printf("Enter number of elements (30,40,50,60,70,90,110,125): ");
    scanf("%d", &n);
    srand(time(0));
    printf("Generated random elements of array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
        printf("%d ", arr[i]);
    }
    printf("\n");
    clock_t start_time = clock();
    quick_sort(arr, 0, n-1);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
                        printf("\nSorted array: ");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
    printf("Time taken to sort the array: %.2f nanoseconds\n", time_taken);

    return 0;

}