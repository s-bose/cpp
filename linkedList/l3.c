#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


//asume two l.l. exist in sorted order, merge them into a third list

int main(){
  int i, n, value;
  List* list1 = list_init();
  List* list2 = list_init();
  List* list3 = list_init();
  printf("Enter the size of list1: ");
  scanf("%d", &n);
  printf("Enter data in sorted order for list1:\n");
  for (i = 0; i < n; i++){
    scanf("%d", &value);
    list_ins_last(list1, value);
  }
  printf("Enter the size of list2: ");
  scanf("%d", &n);
  printf("Enter data in sorted order for list2:\n");
  for (i = 0; i < n; i++){
    scanf("%d", &value);
    list_ins_last(list2, value);
  }
  printf("Before merging the two lists are: \n");
  list_display(list1);
  list_display(list2);
  struct node* i1 = list1->head;
  struct node* i2 = list2->head;
  while (i1 != NULL && i2 != NULL){
    if (i1->data < i2->data){
      list_ins_last(list3, i1->data);
      i1 = i1->next;
    }
    else{
      list_ins_last(list3, i2->data);
      i2 = i2->next;
    }
  }

  if (i1 == NULL){
    for ( ;i2 != NULL; i2 = i2->next)
      list_ins_last(list3, i2->data);
  }
  else if (i2 == NULL){
    for ( ;i1 != NULL; i1 = i1->next)
      list_ins_last(list3, i1->data);
  }

  printf("After merging:\n");
  list_display(list3);
  return 0;
}
