#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

//create two polynomials and perform addition subtraction and product
int main(){
  int i, n, value;
  int idx;
  List* poly = list_init();
  printf("Enter the degree of the first polynomial: ");
  scanf("%d", &n);
  for (i = 0; i <= n; i++){
    printf("Enter co-efficient for x^%d", i);
    scanf("%d", &value);
    list_ins_front(list, value);
  }

  struct node* ptr = (struct node*)malloc(sizeof(struct node));
  idx =
  for (ptr = list->head; ptr != NULL; ptr = ptr->next){
    
    printf("%dx^%d + ", ptr->data, )
  }
}
