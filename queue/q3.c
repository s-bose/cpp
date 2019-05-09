//dequeue using array
#include <stdio.h>
#include <stdlib.h>

typedef struct deq{
    int* arr;
    int size;
    int front, rear;
}deque;

deque* init(int asize){
    deque* temp = (deque*)malloc(sizeof(deque));
    temp->arr = (int*)malloc(sizeof(int)*asize);
    temp->front = 0;
    temp->rear = temp->size - 1;
    return temp;
}

void ins_front(deque* dq, int data){
    //inserts data at the front of the dqueue
    if (dq->front == dq->rear){
        printf("Error. Overflow\n");
        return;
    }
    else 
        dq->arr[dq->front++] = data;
        
}

void ins_rear(deque* dq, int data){
    //inserts data at the rear of the deque
     if (dq->front == dq->rear){
        printf("Error. Overflow\n");
        return;
    }
    else {
        dq->arr[dq->rear--] = data;
    }
}

int del_front(deque* dq){
    int temp;
    if (dq->front == -1){
        printf("Error. Underflow\n");
        return -1;
    }
    else {
        temp = dq->arr[dq->front--];
        return temp;
    }
}

int del_rear(deque* dq){
    int temp;
    if (dq->rear == dq->size - 1){
        printf("Error. Underflow\n");
        return -1;
    }
    else {
        temp = dq->arr[dq->rear++];
        return temp;
    }
}

void display_front(deque* dq){
    int i;
    for (i = 0; i < dq->front; i++)
        printf("%d ", dq->arr[i]);
    
    printf("\n");
}


void display_rear(deque* dq){
    int i;
    for (i = dq->size - 1; i > dq->rear; i--)
        printf("%d ", dq->arr[i]);
    printf("\n");
}


int main(){
    int i, n, c;
    printf("Enter the size of dequeue\n");
    scanf("%d", &n);
    deque* dq = init(n);

    while (1){
        printf("\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display front queue\n6.Display rear queue\n7.Exit\n");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Enter data: ");
                scanf("%d", &n);
                ins_front(dq, n);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &n);
                ins_rear(dq, n);
                break;
            case 3:
                del_front(dq);
                break;
            case 4:
                del_rear(dq);
                break;
            case 5:
                display_front(dq);
                break;
            case 6:
                display_rear(dq);
                break;
            case 7:
                exit(0);
        }
    }
    
    return 0;
}