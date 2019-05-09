#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

int push(int);
int pop(void);
int peek(void);
void display(void);
#define isempty() ((top == -1)? 1 : 0)
#define isfull() ((top == MAX_SIZE-1)? 1 : 0)


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
    


    return 0;
}

int push(int data){
    if (isfull()){
        printf("Error. Overflow\n");
        return -1;
    }
    else {
        top++;
        stack[top] = data;
        return 0;
    }
}

int pop(){
    int temp;
    if (isempty()){
        printf("Error. Underflow\n");
        return -1;
    }
    else {
        temp = stack[top];
        stack[top] = 0;
        top--;
        return 0;
    }
}

int peek(){
    if (isempty()){
        printf("Error. Underflow\n");
        return -1;
    }
    else {
        printf("stack[top] = %d\n", stack[top]);
        return 0;
    }
}

void display(void){
    int i = top;
    if (isempty()){
        printf("Empty stack\n");
        return;
    }
    else {
        printf("The stack is: \n");
        while (i != -1){
            printf("%d\n", stack[i]);
            i--;
        }  
    }
}

