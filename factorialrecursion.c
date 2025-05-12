#include<stdio.h>
#include<stdlib.h>
 
int factorial(int n){
    if(n>=1){
        return n*factorial(n-1);
    }
    else{
        return 1;
    }
}

int main(){
    int n;
    printf("Enter the positive number: ");
    scanf("%d", &n);
    printf("The factorial of the number is: %d", factorial(n));
    return 0;
}