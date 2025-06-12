//Given a sorted array 'X'. Write a function that counts the occurrence of 'X' in an array.The time complexity must be O(logn) 

#include<stdio.h>
int countfreq(int arr[], int size, int x)
{
    int count = 0;
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            count = 1;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && arr[left] == x)
            {
                count++;
                left--;
            }
            while (right < size && arr[right] == x)
            {
                count++;
                right++;
            }
            return count;
        }
        else if (arr[mid]<x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0;
}

int main()
{
    int size, x;
    printf("Enter the size of the array: ");
    scanf("%d ", &size);

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element to be counted ");
    scanf("%d", &x);
    int count = countfreq(arr, size, x);
    printf("Occurence if the target is: %d", count);
    return 0;
}
