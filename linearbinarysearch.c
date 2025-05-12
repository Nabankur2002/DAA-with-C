#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

// Global array
int arr[SIZE]={-100,-89,-56, -5,0,6,10,75, 99};

//Function prototypes
void sortArray();
int linearSearch(int key, int *comparisons);
int binarySearch(int key, int *comparisons);

//Here we use Bubble Sort technique
void sortArray() {
    for(int i=0; i<SIZE-1; i++){ // passes
        for(int j=0; j<SIZE-i-1; j++){ //comparisons
            if(arr[j]<arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int linearSearch(int key, int *comparisons){
    for (int i = 0; i < SIZE-1; i++)
    {
        (*comparisons)++;
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int binarySearch(int key, int *comparisons){
    int start=0; 
    int end=SIZE -1;
    int mid;
    while (start<=end)
    {
        (*comparisons)++;
        mid=start+(end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    int key, liComparisons=0, biComaprisons=0;
    printf("Enter the integer to search for: ");
    scanf("%d", &key);

    int linearResult= linearSearch(key, &liComparisons);
    
    if(linearResult!=-1){
        printf("In linear Search the key found at index %d after %d comparisons\n", linearResult, liComparisons);
    }
    else{
        printf("The key is not found with %d comparisons\n", liComparisons);
    }

    sortArray();
    int binaryResult=binarySearch(key, &biComaprisons);
        if(binaryResult!=-1){
            printf("In binary Search the key found at index %d after %d comparisons\n", binaryResult, biComaprisons);
        }
        else{
            printf("The key is not found with %d comparisons\n", biComaprisons);
        }
    
    
    //Condition to find which one is good
    if(liComparisons<biComaprisons){
        printf("Linear Search is good\n");
    }
    else{
        printf("Binary Search is good\n");
    }
    return -1;
}
