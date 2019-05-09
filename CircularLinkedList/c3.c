#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

void display(struct node*);
struct node* ins_beg(struct node*);
struct node* ins_end(struct node*);
struct node* del_beg(struct node*);
struct node* del_end(struct node*);
struct node* find(struct node*, int);




struct node* ins_end(struct node* last){

		struct node* ptr = (struct node*)malloc(sizeof(struct node));
		printf("Enter the info\n");
		scanf("%d", &ptr->data);
		ptr->next = ptr;
		if (last == NULL)
			last = ptr;
		else {
			ptr->next = last->next;
			last->next = ptr;
			last = ptr;
		}
		return last;
}

struct node* ins_beg(struct node* last){

		struct node* ptr = (struct node*)malloc(sizeof(struct node));
		printf("Enter the info\n");
		scanf("%d", &ptr->data);
		ptr->next = ptr;
		if (last == NULL)
			last = ptr;
		else {
			ptr->next = last->next;
			last->next = ptr;
		}
		return last;
}

struct node* del_beg(struct node* last){
	struct node* x;
	x = last->next;
	last->next = x->next;
	free(x);
	return last;
}


struct node* del_end(struct node* last){
	struct node* x;
	x = last->next;
	while (x->next != last)
		x = x->next;
	x->next = last->next;
	free(last);
	last = x;
	return last;
}

void display(struct node* last){
	struct node* x;
	printf("The elements are: ");
	x = last->next;
	while (x != last){
		printf("%d ", x->data);
		x = x->next;
	}
	printf("%d\n", last->data);
}


int main(){
  int i, n;
  char ans;
  struct node* last = NULL, *ptr;

  while (1){
		printf("Do you want to enter data(Y/N): ");
    fflush(stdin);
    scanf("%c", &ans);
    if (ans != 'Y' && ans != 'y')
      break;
		else {
			ptr = (struct node*)malloc(sizeof(struct node));
			scanf("%d", &ptr->data);
			ptr->next = ptr;
			if (last == NULL){
				last = ptr;
			}
    	else {
				if (last->data > ptr->data)
				{
					ptr->next = last->next;
					last->next = ptr;
				}
				else
				{
					ptr->next = last->next;
					last->next = ptr;
					last = ptr;
				}
			}
		}
  }
  display(last);
  return 0;
}
