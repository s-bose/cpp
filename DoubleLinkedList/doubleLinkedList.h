#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
  struct node* prev;
};

typedef struct DList_{
  int size;
  struct node* head;
  struct node* tail;
}DList;

DList* dlist_init(void);
void dlist_destroy(DList*);
int dlist_ins_next(DList*, struct node*, int);
int dlist_ins_prev(DList*, struct node*, int);
int dlist_ins_front(DList*, int);
int dlist_ins_end(DList*, int);
int dlist_remove(DList*, struct node*);
void dlist_display(DList* dl);
struct node* dlist_search_print(DList*, int);
struct node* dlist_search(DList*, int);



DList* dlist_init(void){
  DList* ptr = (DList*)malloc(sizeof(DList));
  ptr->size = 0;
  ptr->head = NULL;
  ptr->tail = NULL;
  return ptr;
}

int dlist_ins_next(DList* dl, struct node* element, int data){
  //inserts 'data' after the given 'element' in the dl
  struct node* new_element;
  if (element == NULL && dl->size != 0)
    return -1; //if 'element' is NULL and the list is empty, no insertion can happen
  if ((new_element = (struct node*)malloc(sizeof(struct node))) == NULL)
    return -1;
  new_element->data = data;
  if (dl->size == 0){
    //empty DList
    dl->head = new_element;
    new_element->next = NULL;
    new_element->prev = NULL;
    dl->tail = new_element;
    }
  else {
    new_element->next = element->next;
    new_element->prev = element;
    if (element->next == NULL)
      dl->tail = new_element;
    else
      element->next->prev = new_element;
    element->next = new_element;
  }
  dl->size++;
  return 0;
}

int dlist_ins_prev(DList* dl, struct node* element, int data){
  //inserts 'data' before the given 'element' in the dl
  struct node* new_element;
  if (element == NULL && dl->size != 0)
    return -1; //if 'element' is NULL and the list is empty, no insertion can happen
  if ((new_element = (struct node*)malloc(sizeof(struct node))) == NULL)
    return -1;
  new_element->data = data;
  if (dl->size == 0){
      //empty DList
      dl->head = new_element;
      new_element->next = NULL;
      new_element->prev = NULL;
      dl->tail = new_element;
      }
  else {
    new_element->next = element;
    new_element->prev = element->prev;
    if (element->prev == NULL)
      dl->head = new_element;
    else
      element->prev->next = new_element;
    element->prev = new_element;
  }
  dl->size++;
  return 0;
}

int dlist_ins_front(DList* list, int data){
  //inserts 'data' at the front
  return dlist_ins_prev(list, list->head, data);
}

int dlist_remove(DList* dl, struct node* element){
  if (element == NULL || dl->size == 0)
    return -1; //NULL element and empty list not viable for deletion
  if (element == dl->head){
    //delete the head
    dl->head = element->next;
    if (dl->head == NULL) //after deletion if the list is empty
      dl->tail = NULL;
    else
      element->next->prev = NULL;
  }
  else {
    element->prev->next = element->next;
    if (element->next == NULL)
      dl->tail = element->prev;
    else
      element->next->prev = element->prev;

  }
  free(element);
  dl->size--;
  return 0;
}





int dlist_ins_end(DList* list, int data){
  //inserts 'data' at the end
  return dlist_ins_next(list, list->tail, data);
}

void dlist_display(DList* dl){
  struct node* ptr = (struct node*)malloc(sizeof(struct node));
  for (ptr = dl->head; ptr != NULL; ptr = ptr->next){
    printf(" [ %d ] <--> ", ptr->data);
  }
  printf("\n");
}


struct node* dlist_search_print(DList* dl, int data){
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  struct node* save = (struct node*)malloc(sizeof(struct node));
  for (iter = dl->head; iter != NULL; iter = iter->next){
    if (iter->data == data)
    {
      printf("[ *%d* ] <-->", iter->data);
      save = iter;
      continue;
    }
    printf("[  %d  ] <-->", iter->data);
  }
  return save;
}

struct node* dlist_search(DList* dl, int data){
  struct node* iter = (struct node*)malloc(sizeof(struct node));
  struct node* save = (struct node*)malloc(sizeof(struct node));
  for (iter = dl->head; iter != NULL; iter = iter->next){
    if (iter->data == data)
      return iter;
  }
  return NULL;
}
