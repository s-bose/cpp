#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char data){
    stack[++top] = data;
}

char pop(){
    return stack[top--];
}

char top_(){
    return stack[top];
}


isOp(char ch){
    switch(ch){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '$':
        case '%':
            return 1;
    }
    return 0;
}

int prec(char ch){
    switch(ch){
    	case ')':
    		return 0;
    	case '(':
    		return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '^':
        case '$':
        case '%':
            return 4;
    }
}

void infixToPostfix(char* infix){
    int i, k = 0;
    char postfix[MAX];
    push('(');
    for (i = 0; infix[i] != '\0'; i++){
        if (infix[i] == '(')
            push(infix[i]);
        else if(isalnum(infix[i]))
            postfix[k++] = infix[i];
        else if (infix[i] == ')'){
            while (top_() != '(')
                postfix[k++] = pop();
            pop();
        }
        else if (isOp(infix[i])){
            while (prec(infix[i]) <= prec(top_())){
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
        
    }
    while (top > 0){
    	postfix[k++] = pop();
    }
    postfix[k] = '\0'; 
    printf("The postfix expression is: %s\n", postfix);
}

int main(){
    char inf[MAX];
    printf("Enter the infix expression: \n");
    scanf("%s", inf);
    infixToPostfix(inf);
    return 0;
}
