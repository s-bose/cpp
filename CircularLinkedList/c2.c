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

struct node* find(struct node* last, int data){
	struct node* temp = last->next;
	struct node* save;
	while (temp != last){
		if (temp->data == data){
			printf(" *%d* ", temp->data);
			save = temp;
      temp = temp->next;
			continue;
		}
		printf(" %d ", temp->data);
		temp = temp->next;
	}
  printf(" %d ", last->data);
	return save;
}


int main(){
  int i, n;
  char ans;
  struct node* l1 = NULL, *ptr, *temp;
  struct node* l2 = NULL;
  while (1){
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("Enter the info for 1st CLL\n");
		scanf("%d", &ptr->data);
		ptr->next = ptr;
		if (l1 == NULL)
			l1 = ptr;
		else {
			ptr->next = l1->next;
			l1->next = ptr;
			l1 = ptr;
		}
		printf("Do you want to continue(Y/N): ");
		fflush(stdin);
		scanf("%c", &ans);
		if (ans != 'Y' && ans != 'y')
			break;
	}

  while (1){
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("Enter the info for the 2nd CLL\n");
		scanf("%d", &ptr->data);
		ptr->next = ptr;
		if (l2 == NULL)
			l2 = ptr;
		else {
			ptr->next = l2->next;
			l2->next = ptr;
			l2 = ptr;
		}
		printf("Do you want to continue(Y/N): ");
		fflush(stdin);
		scanf("%c", &ans);
		if (ans != 'Y' && ans != 'y')
			break;
	}
  display(l1);
  display(l2);
  temp = l2->next;
  l2->next = l1->next;
  l1->next = temp;
  l1 = l2;
  display(l1);
  return 0;
}
