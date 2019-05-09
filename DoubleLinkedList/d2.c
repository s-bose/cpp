#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

DList* dlist_merge(DList*, DList*);

int main(){
  int i, n, value;
  DList* d1 = dlist_init();
  DList* d2 = dlist_init();
  DList* d3;
  printf("Enter data size for dlist 1: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &value);
    dlist_ins_end(d1, value);
  }
  printf("Enter data size for dlist 2: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &value);
    dlist_ins_end(d2, value);
  }

  printf("Before merging, two lists are: \n");
  dlist_display(d1);
  dlist_display(d2);
  d3 = dlist_merge(d1, d2);
  printf("The merged list is: \n");
  dlist_display(d3);
  return 0;
}


DList* dlist_merge(DList* d1, DList* d2){
  DList* d3 = dlist_init();
  d3->head = d1->head;
  d3->tail = d1->tail;
  d3->tail->next = d2->head;
  d2->head->prev = d3->tail;
  return d3;
}
