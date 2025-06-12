//Write a C program to find the Bitonic Point from a bitonic sequence. 
//A Bitonic Sequence is a sequence of numbers which is first strictly increasing then, after a point (called the Bitonic Point) strictly decreasing. 
//A bitonic point does not exist if the sequence is only increasing or only decreasing.

#include <stdio.h>
#include<stdlib.h>

int bitonic(int arr[], int low,int high) {
    if(low==high)
        return arr[low];
    int mid=(low+high)/2;
    if((mid==0||arr[mid]>arr[mid-1])&&(mid==high||arr[mid]>arr[mid+1]))
        return arr[mid];
    if(arr[mid] <arr[mid+1]) {
        return bitonic(arr, mid+1,high);
    }
    return bitonic(arr, low,mid);
}
int main()
{
    int n;
    printf("Enter no of elements\n");
    scanf("%d",&n);
    int arr[n];

    printf("Enter elements of array\n");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int bp=bitonic(arr,0,n-1);
    printf("\nBitonic point:%d",bp);

    return 0;
}