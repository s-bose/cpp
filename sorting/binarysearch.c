#include <stdio.h>
#include <stdlib.h>

int binarysearch(int* arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarysearch(arr, l, mid - 1, x); 
        return binarysearch(arr, mid + 1, r, x); 
    }
    return -1; 
}

int main(){
    int i, n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int* arr = malloc(n*sizeof(int));
    printf("Enter the elements in sorted order: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the item you want to search: ");
    scanf("%d", &i);
    if (binarysearch(arr, 0, n-1, i) == -1)
        printf("Item not found\n");
    else 
        printf("Item %d found on index %d", i, binarysearch(arr, 0, n-1, i));
    return 0;
}