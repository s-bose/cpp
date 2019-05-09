#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

int main(){
  int i, n, value, c, elem_data;
  struct node* ptr;
  DList* list = dlist_init();
  printf("Enter how many data do you want to enter initially: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &value);
    dlist_ins_end(list, value);
  }
  printf("The initial list is: \n");
  dlist_display(list);
  printf("Do you want to modify y/n: ");
  fflush(stdin);
  c = getchar();
  if (c == 'y' || c == 'Y'){
    while (1){
      printf("\n1.display the list\n2.search a node\n3.insert at the front\n4.insert at the end\n5.delete from front\n6.delete from the rear\n7.insert at any position\n8.delete from any position\n9.insert before a given data\n10.delete before a given data\n11.insert after a given data\n12.delete after a given data\n13.exit\n");
      scanf("%d", &c);
      switch(c){
        case 1:
          //display the list
          dlist_display(list);
          break;
        case 2:
          //search a node
          printf("Enter the element you want to search: ");
          scanf("%d", &value);
          dlist_search_print(list, value);
          break;
        case 3:
          //insert at the front
          printf("Enter the data you want to enter: ");
          scanf("%d", &value);
          dlist_ins_front(list, value);
          dlist_display(list);
          break;
        case 4:
          //insert at the end
          printf("Enter the data you want to enter: ");
          scanf("%d", &value);
          dlist_ins_end(list, value);
          dlist_display(list);
          break;
        case 5:
          //delete from the front
          dlist_remove(list, list->head);
          dlist_display(list);
          break;
        case 6:
          //delete from the rear
          dlist_remove(list, list->tail);
          dlist_display(list);
          break;
        case 7:
          //insert at any position
          printf("Enter the data you want to insert and at what position: ");
          scanf("%d %d", &value, &elem_data);
          {
            ptr = dlist_search(list, elem_data);
          }
          dlist_ins_prev(list, ptr, value);
          dlist_remove(list, ptr);
          dlist_display(list);
          break;
        case 8:
          //delete at any position
          printf("Enter the position where you want to delete: ");
          scanf("%d", &elem_data);
          dlist_remove(list, dlist_search(list, elem_data));
          dlist_display(list);
          break;
        case 9:
          //insert before any given data
          printf("Enter the data you want to insert and the node data before which you want to insert: ");
          scanf("%d %d", &value, &elem_data);
          dlist_ins_prev(list, dlist_search(list, elem_data), value);
          dlist_display(list);
          break;
        case 10:
          //delete before any given data
          printf("Enter the node data before which you want to delete: ");
          scanf("%d", &elem_data);
          dlist_remove(list, (dlist_search(list, elem_data))->prev);
          dlist_display(list);
          break;
        case 11:
          //insert after any given data
          printf("Enter the data you want to insert and the node data after which you want to insert: ");
          scanf("%d %d", &value, &elem_data);
          dlist_ins_next(list, dlist_search(list, elem_data), value);
          dlist_display(list);
          break;
        case 12:
          //delete after any given data
          printf("Enter the node data after which you want to delete: ");
          scanf("%d", &elem_data);
          dlist_remove(list, dlist_search(list, elem_data)->next);
          dlist_display(list);
          break;
        case 13:
          //exit
          exit(0);

      }
    }
  }
  return 0;
}
