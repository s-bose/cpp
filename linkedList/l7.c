#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
List* list_add_end(List*, List*);
//add an SLL to its end
int main(){
  int i, n, value;
  List* list1 = list_init();
  List* list2 = list_init();
  printf("Enter the size of first SLL: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &value);
    list_ins_last(list1, value);
  }
  printf("Enter the size of second SLL: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &value);
    list_ins_last(list2, value);
  }

  printf("The two lists are: \n");
  list_display(list1);
  list_display(list2);
  printf("adding list2 at the end of list1 produces:\n");
  list1 = list_add_end(list1, list2);
  list_display(list1);
  return 0;
}

List* list_add_end(List* list1, List* list2){
  struct node* ptr = list1->tail;
  ptr->next = list2->head;
  return list1;
}
