#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct stk{
    char* Stack;
    int top;
}stack;

void stack_init(stack* s){
    s->Stack = (char*)malloc(sizeof(char)*MAX_SIZE);
    s->top = -1;
}

int push(stack* s, char data){
    if (s->top == MAX_SIZE - 1){
        printf("Error. Overflow\n");
        return -1;
    }
    else {
        s->Stack[++(s->top)] = data;
        return 0;
    }
}

char pop(stack* s){
    char temp;
    if (s->top == -1){
        printf("Error. Underflow\n");
        return -1;
    }
    else {
        temp = s->Stack[(s->top)--];
        return temp;
    }
}

int main(){
    int i, j = 0;
    char str[MAX_SIZE];
    stack* s1 = (stack*)malloc(sizeof(stack));
    stack_init(s1);
    printf("Enter a string\n");
    fgets(str, MAX_SIZE, stdin);
    for (i = 0; i < strlen(str); i++)
        push(s1, str[i]);

    i = s1->top;
    for (;i != -1; i--){
        str[j] = pop(s1);
        j++;
    }

    printf("The reverse string is: %s\n", str);
    
    return 0;
}