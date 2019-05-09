#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble(int* arr, int n){
    int i, j, flag;
    for (i = 0; i < n-1; i++){
    	flag = 0;
    	for (j = 0; j < n-i-1; j++){
    		if (arr[j] > arr[j+1]){
    			swap(&arr[j], &arr[j+1]);
    			flag = 1;
    		}
    	}
    	if (flag == 0)
    		break;
    }
}

void print(int* arr, int n){
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
}

int main(){
	int i, n, *arr;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	arr = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
		
	bubble(arr, n);
	print(arr, n);
	return 0;
}
