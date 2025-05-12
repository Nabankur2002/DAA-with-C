//This merge sort is done using only one temporary array

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int a[MAX];
void merge();

void merge_sort(int low, int high) {
    int mid;
    if(low!=high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}

void merge(int low,int mid, int high) {
    int i,j,k, temp[MAX];
    i=low;
    k=low;
    j=mid+1;
    while((i<=mid)&&(j<=high)) {
        if(a[i]>=a[j])
            temp[k++]=a[j++];
        else
            temp[k++]=a[i++];
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=high)
    {
        temp[k++]=a[j++];
    }
    for(i=low; i<=high; i++) {
        a[i]=temp[i];
    }
}


int main()

{
    int n;
    printf("Enter no of elements\n");
    scanf("%d",&n);
    printf("Enter elements of array\n");
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    merge_sort(0,n-1);
    printf("Sorted array:");
    for(int j=0; j<n; j++)
        printf("%d ",a[j]);
    return 0;
}