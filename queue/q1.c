#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int enqueue(int);
int dqueue(void);
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
    if (rear == MAX_SIZE - 1){
        printf("Error. Overflow\n");
        return -1;
    }
    else {
        if ((front == -1) && (rear == -1)){
            front++;
            rear++;
        }
        else {
            rear++;
        }
        queue[rear] = data;
        return 0;
    }
}

int dqueue(){
    if (front == -1 && rear == -1){
        printf("Error. Underflow\n");
        return -1;
    }
    else {
        if (front == rear){
            front = -1;
            rear = -1;
        }
        else
            front++;
        return 0;
    }
}

void display(){
    int i;
    if ((front == -1) && (rear == -1)){
        printf("Error. Underflow\n");
        return;
    }
    else {
        i = front;
        while (i <= rear){
            printf("%d ", queue[i]);
            i++;
        }
        printf("\n");
    }   
}