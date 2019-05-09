#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int exp){
	stack[++top] = exp;
}

int pop(){
	return stack[top--];
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


int expGen(char exp, int a, int b){
	if (exp == '+')
		return (a+b);
	if (exp == '-')
		return (a-b);
	if (exp == '*')
		return (a*b);
	if (exp == '/')
		return (a/b);
	if (exp == '^')
		return pow(a, b);
}

void postfixEval(char* postExp){
	int i;
    int temp;
    int size = strlen(postExp);
    for (i = 0; i < size; i++){
        if (isOp(postExp[i])){
            int op2 = pop();
            int op1 = pop();
            temp = expGen(postExp[i], op1, op2);
            push(temp);
        }
        else {
            temp = (int)(postExp[i] - 48);
            push(temp);
        }
    }

    printf("The Infix evaluation is: %d\n", pop());
}

int main(){
	int i;
	char post[MAX];
    printf("Enter the postfix expression\n");
    scanf("%s", post);
	postfixEval(post);
}
