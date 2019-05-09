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

int main(){
	char ans;
	int a, n;
	int data, node_data;
	struct node* last = NULL, *ptr, *x, *temp, *new_node;
	while (1){
		ptr = (struct node*)malloc(sizeof(struct node));
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
		printf("Do you want to continue(Y/N): ");
		fflush(stdin);
		scanf("%c", &ans);
		if (ans != 'Y' && ans != 'y')
			break;
	}
	while (1){
		printf("\n1.Enter at the beginning\n2.Enter at the end\n3.Delete from the beginning\n4.Delete from the end\n5.Display\n6.Search an element\n7.Insert at any position\n8.Delete from any position\n9.Insert before any given data\n10.insert after a given data\n11.Delete before a given data\n12.Delete after a given data\n13.Exit\n");
		scanf("%d", &a);
		switch (a){
			case 1:
				last = ins_beg(last);
				break;
			case 2:
				last = ins_end(last);
				break;
			case 3:
				last = del_beg(last);
				break;
			case 4:
				last = del_end(last);
				break;
			case 5:
				display(last);
				break;
			case 6:
		        printf("Enter the data you want to search\n");
		        scanf("%d", &n);
		        temp = find(last, n);
		        break;
		    case 7:
				printf("Enter the data you want to insert and at which node: ");
				scanf("%d %d", &data, &node_data);
				temp = (struct node*)malloc(sizeof(struct node));
				temp->data = data;
				temp->next = temp;
				 x = last->next;
				 while (x->next->data != node_data)
				 	x = x->next;
				ptr = x->next;
				if (x->next == last)
					last = temp;
				
				temp->next = x->next->next;
				x->next = temp;
				free(ptr);
				break;
			case 8:
				//delete from any position
				printf("Enter the node you want to delete: ");
				scanf("%d", &node_data);
				 x = last->next;
				 while (x->next->data != node_data)
				 	x = x->next;
				ptr = x->next;
				if (x->next == last)
					last = x;
				x->next = ptr->next;
				free(ptr);
				break;
			case 9:
				//insert before
			case 10:
				//insert after
			case 11:
				//delete before
			case 12:
				//delete after
	
			case 13:
				exit(0);
		}
	}
	return 0;
}


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
	printf("%d", last->data);
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
