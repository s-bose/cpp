#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

List* list_reverse(List*);
//list reversal

int main(){
  int i, n, value;
  List* list = list_init();
  printf("How many data you want to enter: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &value);
    list_ins_last(list, value);
  }
  printf("List before reversal: \n");
  list_display(list);
  list = list_reverse(list);
  printf("List after reversal: \n");
  list_display(list);
  return 0;
}

List* list_reverse(List* list){
  List* temp = list_init();
  struct node* iter = list->head;
  for (; iter != NULL; iter = iter->next)
    list_ins_front(temp, iter->data);
  return temp;

}
