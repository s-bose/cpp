#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void selectionsort(int arr[], int n) 
{ 
    int i, j, min; 
  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swap(&arr[min], &arr[i]); 
    } 
} 

void print(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main(){
    int i, n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int* arr = malloc(n*sizeof(int));
    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    selectionsort(arr, n);
    printf("The sorted array is: \n");
    print(arr, n);
    return 0;
}