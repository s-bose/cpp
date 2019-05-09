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


void postfixToInfix(char* postExp){
    int i;
    char temp[MAX];
    int size = strlen(postExp);
    for (i = 0; i < size; i++){
        if (isOp(postExp[i])){
            char* op2 = pop();
            char* op1 = pop();
            sprintf(temp, "(%s %c %s)", op1, postExp[i], op2);
            push(temp);
        }
        else {
            sprintf(temp, "%c", postExp[i]);
            push(temp);
        }
    }

    printf("The Infix expression is: %s\n", pop());
}


int main(){
	int i;
	char post[MAX];
    printf("Enter the postfix expression\n");
    scanf("%s", post);
	postfixToInfix(post);
	
	return 0;
}
