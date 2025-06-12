//Write a program in C that implements the following:
//1. A one dimenstional array defined globa;;y containing the list of unsorted integers
//2. Module Heap_sort() when called sorts the list
//3. Sorted content is displayed in the main module.

#include<stdio.h>

int arr[]={9, 5, 10,  3, 8, 4, 2};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    // Finding the greatest among root, leftSide child, and rightSide child of the tree
    int greatest = i;
    int leftSide = 2 * i + 1;
    int rightSide = 2 * i + 2;
  
    if (leftSide < n && arr[leftSide] > arr[greatest])
      greatest = leftSide;
  
    if (rightSide < n && arr[rightSide] > arr[greatest])
      greatest = rightSide;
  
    // Swap and continue heapifying if the root is not the greatest
    if (greatest != i) {
      swap(&arr[i], &arr[greatest]);
      heapify(arr, n, greatest);
    }
}
  
void Heap_sort(int arr[], int n){
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  

    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      heapify(arr, i, 0);
    }
}
  
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n = sizeof(arr) / sizeof(arr[0]);
  
    Heap_sort(arr, n);
  
    printf("Sorted array is \n");
    printArray(arr, n);

    return 0;
}