#include <stdio.h>
#include <stdlib.h>


void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

int main(){
    int i, n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int* arr = malloc(n*sizeof(int));
    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    insertionSort(arr, n);
    printf("The sorted array is: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}