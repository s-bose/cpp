#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
  int i, n, value;
  List* list = (List*)malloc(sizeof(List));
  List* even_list = (List*)malloc(sizeof(List));
  List* odd_list = (List*)malloc(sizeof(List));
  init_list(list);
  init_list(even_list);
  init_list(odd_list);
  printf("Enter how many data you want to enter : ");
  scanf("%d", &n);
  printf("\nEnter the values: \n");
  for (i = 0; i < n; i++){
    scanf("%d", &value);
    list_ins_last(list, value);
  }
  printf("Status before spliting: \n");
  list_display(list);
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  iter = list->head;
  while (iter != NULL){
      if (iter->data % 2)
        //odd_list
        list_ins_last(odd_list, iter->data);
      else {
        //even_list
        list_ins_last(even_list, iter->data);
      }
      iter = iter->next;
      list_del_front(list);
  }

  printf("Status after the spliting:\noriginal list:\n");
  list_display(list);
  printf("Even_list\n");
  list_display(even_list);
  printf("Odd list\n");
  list_display(odd_list);

  return 0;
}
