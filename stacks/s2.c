#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* top = NULL;

int push(int);
node* pop(void);
int peek(void);
void display(void);

int main(){
    int c, n;
    while (1){
        printf("\n1.push data\n2.pop data\n3.peek data\n4.display\n5.exit\n");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Enter data: ");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Enter a valid option\n");
                break;
        }
    }
}


int push(int value){
    node* ptr;
    if ((ptr = (node*)malloc(sizeof(node))) == NULL){
        printf("Error allocating memory heap. Overflow\n");
        return -1;
    }

    else {
        ptr->data = value;
        ptr->next = NULL;
        if (top == NULL){
            top = ptr;
        }
        else {
            ptr->next = top;
            top = ptr;
        }
        return 0;
    }
}

node* pop(){
    node* temp;
    if (top == NULL){
        printf("Error. Stack empty. Underflow\n");
        return NULL;
    }
    else {
        temp = top;
        top = top->next;
        return temp;
    }
}


int peek(){
    if (top == NULL){
        printf("Error. Stack empty. Underflow\n");
        return -1;
    }
    else {
        printf("The top element is: %d\n", top->data);
        return 0;
    }
}

void display(){
    node* ptr;
    if (top == NULL){
        printf("Error. Stack empty.\n");
        return;
    }
    else {
        printf("The stack is:\n");
        for (ptr = top; ptr != NULL; ptr = ptr->next)
            printf("%d\n", ptr->data);
    }
}