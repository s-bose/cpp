#include <stdio.h>
#include <stdlib.h>

int lsearch(int* arr, int n){
    int i, key;
    printf("Enter the key you want to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++){
        if (arr[i] == key){
            printf("key: %d found on index: %d\n", key, i+1);
            return i;
        }
    }
    printf("Key not found\n");
    return -1;
}

int main(){
    int i, n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int* arr = malloc(n*sizeof(int));
    printf("Enter the elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    
    lsearch(arr, n);
    return 0;

}