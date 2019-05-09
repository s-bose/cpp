#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;

void display(node*);


int main(){
	char c;
	int a, n;
	node* last = NULL, *last1 = NULL, *temp, *new_node;
	printf("Enter data for first CDLL: \n");
	while (1){
		new_node = (node*)malloc(sizeof(node));
		printf("Enter the data: ");
		scanf("%d", &new_node->data);
		new_node->next = new_node;
		new_node->prev = new_node;
		if (last == NULL)
			last = new_node;
		else {

			new_node->next = last->next;
			(last->next)->prev = new_node;
			last->next = new_node;
			new_node->prev = last;
        	last = new_node;
		}
		printf("\nDo you want to conitnue(Y/N): ");
		fflush(stdin);
		scanf("%c", &c);
		if (c != 'Y' && c != 'y')
			break;		
	}
	printf("Enter data for second CDLL: \n");
	while (1){
		new_node = (node*)malloc(sizeof(node));
		printf("Enter the data: ");
		scanf("%d", &new_node->data);
		new_node->next = new_node;
		new_node->prev = new_node;
		if (last1 == NULL)
			last1 = new_node;
		else {

			new_node->next = last1->next;
			(last1->next)->prev = new_node;
			last1->next = new_node;
			new_node->prev = last1;
        	last1 = new_node;
		}
		printf("\nDo you want to conitnue(Y/N): ");
		fflush(stdin);
		scanf("%c", &c);
		if (c != 'Y' && c != 'y')
			break;		
	}
	
	display(last);
	display(last1);
	temp = last1->next;
	last1->next = last->next;
	last->next->prev = last1;
	last->next = temp;
	temp->prev = last;
	
	display(last1);  
	return 0;
}



void display(node* last){
    node* x;
    printf("The elements are\n");
	x = last->next;
	while (x != last){
		printf("%d ", x->data);
		x = x->next;
	}
	printf("%d\n", last->data);
}



