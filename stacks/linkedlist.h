#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 99999

struct pair{
  int min;
  int max;
};

struct node {
    int data;
    struct node* next;
};

typedef struct list {
  struct node* head;
  struct node* tail;
  int size;
}List;

void init_list(List*);
int list_ins_next(List*, struct node*, int);
int list_ins_front(List*, int);
int list_ins_second(List*, int);
int list_ins_last(List*, int);
int list_ins_before(List*, struct node*, int);
void list_display(List*);
int list_int_ins_next(List*, int, int);
struct node* list_search(List*, int);
struct pair list_min_max(List*);
int list_del_next(List*, struct node*);
int list_del_front(List*);
int list_del_second(List*);
int list_del_prev(List*, struct node*);
int list_del_last(List*);
int list_del_sec_last(List*);

List* list_init(void){
  List* temp = (List*)malloc(sizeof(List));
  init_list(temp);
  return temp;
}

void init_list(List* list){
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

int list_ins_next(List* list, struct node* element, int data){
  struct node* new_element = (struct node*)malloc(sizeof(struct node));
  if (new_element == NULL)
    return -1;
  new_element->data = data;
  new_element->next = NULL;
  if (element == NULL)    //no element given, insert at the head
  {
    if (list->size == 0)    //list is empty
      list->tail = new_element;
    new_element->next = list->head;
    list->head = new_element;
  }
  else                    //insert after the specified element
  {
    if (element->next == NULL)
      list->tail = new_element;
    new_element->next = element->next;
    element->next = new_element;
  }

  list->size++;
  return 0;
}

int list_ins_front(List* list, int data){
  //insert at the head
  if (list_ins_next(list, NULL, data) != 0)
    return -1;
  return 0;
}

int list_ins_second(List* list, int data){
  //insert at the second position
  if (list_ins_next(list, list->head, data) != 0)
    return -1;
  return 0;
}

int list_ins_last(List* list, int data){
  //insert at the end
  if(list_ins_next(list, list->tail, data) != 0)
    return -1;
  return 0;
}

int list_ins_before(List* list, struct node* element, int data){
  //insert before the given element
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  for (iter = list->head; iter != NULL; iter = iter->next){
    if (iter->next == element)
      return list_ins_next(list, iter, data);
  }
  return -1;
}
  //return 0;

void list_display(List* list){
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  for (iter = list->head; iter != NULL; iter = iter->next)
    printf("[  %d  ]-->", iter->data);
  printf("\n");
}

int list_int_ins_next(List* list, int element_data, int data){
  //inserts data after the node containing 'element_data'
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  for (iter = list->head; iter != NULL; iter = iter->next){
    if (iter->data == element_data){
      list_ins_next(list, iter, data);
      return 0;
    }
  }
  return -1;
}

int list_int_ins_prev(List* list, int element_data, int data){
  //inserts data before the node containing 'element'
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  for (iter = list->head; iter != NULL; iter = iter->next){
    if (iter->next->data == element_data){
      list_ins_next(list, iter, data);
      return 0;
    }
  }
  return -1;
}

struct node* list_search(List* list, int data){

    struct node* iter = (struct node*)malloc(sizeof(struct node));
    struct node* save = (struct node*)malloc(sizeof(struct node));
    for (iter = list->head; iter != NULL; iter = iter->next){
      if (iter->data == data)
      {
        printf("[  *%d*  ]-->", iter->data);
        save = iter;
        continue;
      }
      printf("[  %d  ]-->", iter->data);
    }
    return save;
}

struct pair list_min_max(List* list){
    struct pair minmax;
    if (list->size == 1)
    {
      minmax.min = (list->head)->data;
      minmax.max = (list->head)->data;
    }
    else {
      minmax.max = (list->head)->data;
      minmax.min = ((list->head)->next)->data;
    }
    struct node* iter = (struct node*)malloc(sizeof(struct node));

    for (iter = ((list->head)->next)->next; iter != NULL; iter = iter->next){
      if (iter->data > minmax.max)
        minmax.max = iter->data;
      else if (iter->data < minmax.min)
        minmax.min = iter->data;
    }
    return minmax;
}



int list_del_next(List* list, struct node* element){
  //deletes the node next to 'element'
  struct node* old_element;
  if (list->size == 0)
    return -1;
  if (element == NULL){
      //NULL element is passes, delete from the head
      old_element = list->head;
      list->head = list->head->next;

    if (list->size == 1)
      list->tail = NULL;

    }

    else {
      //element is given, delete the node next to 'element'
      if (element->next == NULL)
        return -1;
      old_element = element->next;
      element->next = element->next->next;
      if (element->next == NULL)
        list->tail = element;
    }
  list->size--;
  free(old_element);
  return 0;
}

int list_del_front(List* list){
  //delete from the front, i.e head
  return list_del_next(list, NULL);
}

int list_del_second(List* list){
  //delete the second position
  return list_del_next(list, list->head);
}

int list_del_prev(List* list, struct node* element){
  //deletes the node preceding 'element'
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  for (iter = list->head; iter != NULL; iter = iter->next){
    if (iter->next == element)  //capture the previous node
      return list_del_next(list, iter);
  }
  return -1;
}

int list_del_last(List* list){
  //deletes from the last, i.e, the tail
  return list_del_prev(list, list->tail);
}

int list_del_sec_last(List* list){
  //deletes the second last element
  //identify the second last element
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  for(iter = list->head; iter != NULL; iter = iter->next){
    if (iter->next->next == list->tail)
      return list_del_next(list, iter);
  }
  return 0;
}

int list_int_del_next(List* list, int element_data){
  //deletes the node next to the node containing 'element'
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  for (iter = list->head; iter != NULL; iter = iter->next){
    if (iter->data == element_data){
      list_del_next(list, iter);
      return 0;
    }
  }
  return -1;
}

int list_int_del_prev(List* list, int element_data){
  //deletes the node before the node containing 'element'
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  for (iter = list->head; iter != NULL; iter = iter->next){
    if (iter->data == element_data){
      list_del_prev(list, iter);
      return 0;
    }
  }
  return -1;
}
