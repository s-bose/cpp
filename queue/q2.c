#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* f = NULL;
node* r = NULL;

int enqueue(int);
node* dqueue(void);
void display(void);


int main(){
    int c, n;
    while (1){
        printf("\n1.push data\n2.pop data\n3.display\n4.exit\n");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Enter data: ");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2:
                dqueue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a valid option\n");
                break;
        }
    }
    return 0;
}


int enqueue(int data){
    node* ptr = (node*)malloc(sizeof(node));
    if (ptr == NULL){
        printf("Error. Overflow\n");
        return -1;
    }
    else {
        ptr->data = data;
        ptr->next = NULL;
        if ((f == NULL) && (r == NULL)){
            f = ptr;
            r = ptr;
        }
        else {
            r->next = ptr;
            r = ptr;
        }
        return 0;
    }
}

node* dqueue(void){
    node* temp;
    if ((f == NULL) && (r == NULL)){
        printf("Error. Underflow\n");
        return NULL;
    }
    temp = f;
    f = f->next;
    return temp;
}

void display(void){
    node* temp;
    if ((f == NULL) && (r == NULL)){
        printf("Error. Underflow\n");
        return;
    }
    else {
        temp = f;
        while (temp != r){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", r->data);
    }
}

