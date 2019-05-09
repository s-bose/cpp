#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char* stack[MAX];
int top = -1;

void push(char* str){
	top++;
	stack[top] = (char*)malloc(sizeof(char));
	strcpy(stack[top], str);
}

char* pop(){
	char *temp = (char*)malloc(sizeof(char));;
	strcpy(temp, stack[top]);
	top--;
	return temp;
}

int isOp(char ch){
    switch(ch){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '$':
            return 1;
    }
    return 0;
}

void prefixToInfix(char* preExp){
    int i;
    char temp[MAX];
    int size = strlen(preExp);
    for (i = size - 1; i >= 0; i--){
        if (isOp(preExp[i])){
            char* op1 = pop();
            char* op2 = pop();
            sprintf(temp, "(%s %c %s)", op1, preExp[i], op2);
            push(temp);
        }
        else {
            sprintf(temp, "%c", preExp[i]);
            push(temp);
        }
    }
    printf("The Infix expression is: %s\n", pop());
}


int main(){
    int i;
    char pre[MAX];
    printf("Enter the prefix expression\n");
    scanf("%s", &pre);
    prefixToInfix(pre);
    
    return 0;
}
