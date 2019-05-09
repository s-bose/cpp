#include <stdio.h>
#include <stdlib.h>

typedef struct q_type{
    int* arr;
    int size;
    int front, rear;
}queue;

queue* queue_init(int qsize){
    queue* temp = (queue*)malloc(sizeof(queue));
    temp->arr = (int*)malloc(sizeof(int)*qsize);
    temp->size = qsize;
    temp->front = temp->rear = 0;
    return temp;
}



void enqueue(queue* q, int data){
    //rear holds the next free position in the array
    //front stays same
    if (q->rear == q->size){
        printf("Error. Overflow\n");
        return;
    }
    q->arr[q->rear++] = data;
}

int dequeue(queue* q){
    int i, temp;
    if (q->rear == q->front){
        printf("Error. Underflow\n");
        return -1;
    }
    else{
        temp = q->arr[q->front];
        for (i = 0; i < q->rear-1; i++)
            q->arr[i] = q->arr[i+1];
        q->rear--;
        return temp;
    }
}

void queue_display(queue* q){
    int i;
    if (q->front == q->rear){
        printf("Error. Empty queue\n");
        return;
    }
    else {
        for (i = q->front; i < q->rear; i++)
            printf("%d , ", q->arr[i]);
        printf("\n");
    }
}

int qempty(queue* q){
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

int queue_front(queue* q){
    return q->arr[q->front];
}

typedef struct stack_t {
    queue* q1, *q2;
    int size;
}stack;

stack* stack_init(int ssize){
    stack* s = (stack*)malloc(sizeof(stack));
    s->q1 = queue_init(ssize);
    s->q2 = queue_init(ssize);
    s->size = 0;
    return s;
}

void push(stack* s, int data){
    s->size++;
    enqueue(s->q2, data);
    while (!qempty(s->q1)){
        enqueue(s->q2, queue_front(s->q1));
        dequeue(s->q1);
    }

    queue* q = s->q1;
    s->q1 = s->q2;
    s->q2 = q;
}

void pop(stack* s){
    if (qempty(s->q1))
        return;
    else
        dequeue(s->q1);
    s->size--;
}

void s_display(stack* s){
    queue_display(s->q1);
}

int top(stack* s){
    if (qempty(s->q1))
        return -1;
    else
        return queue_front(s->q1);
}

int main(){
    int i, size, val;
    stack* s;
    printf("Enter the size: ");
    scanf("%d", &size);
    s = stack_init(size);
    printf("Enter the data: \n");
    for (i = 0; i < size; i++){
        scanf("%d", &val);
        push(s, val);
    }
    s_display(s);
    return 0;
}