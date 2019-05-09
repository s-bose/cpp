#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

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
    	case '(':
    		return 0;
    	case ')':
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

void push(char data){
	stack[++top] = data;
}

int pop(){
	return stack[top--];
}

void infixToPrefix(char* infix){
	int i, k = 0;
	char prefix[MAX];
	push(')');
	for (i = strlen(infix) - 1; i >= 0; i--){
		if (infix[i] == ')')
			push(infix[i]);
		else if (infix[i] == '('){
			while (stack[top] != ')')
				prefix[k++] = pop();
			pop();
		}
		else if (isalnum(infix[i]))
			prefix[k++] = infix[i];
		else if (isOp(infix[i])){
			while (prec(infix[i]) <= prec(stack[top])){
				prefix[k++] = pop();
			}
			push(infix[i]);
		}
		
	}
	while (top > 0)
		prefix[k++] = pop();
		
	strrev(prefix);
	
	printf("%s", prefix);
}

int main(){
	char inf[MAX];
    printf("Enter the infix expression: \n");
    scanf("%s", inf);
    infixToPrefix(inf);
	return 0;
}

