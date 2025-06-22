#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 30
char stack[MAX];
int top = -1;

void push(char item){
    if(top == MAX-1){
        return;
    }
    stack[++top] = item;
}
char pop(){
    if(top == -1){
        return '0';
    }
    return stack[top--];
}
int precedence(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}
int isoperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return 1;
    }
    return 0;
}
char* infix_postfix(char *infix){
    int i = 0;
    char postfix[MAX];

    for(int i=0;i<strlen(infix);++i){
        if(isdigit(infix[i])){
            postfix[i++] = infix[i];
        }
        //if operator and ( then put in stack
        if(infix[i] == '('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(top != -1 && infix[i] != ')'){
                postfix[i++] = pop();
            }
            pop();
        }
        else if(isoperator(infix[i])){
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i])){
                postfix[i++] = pop();
            }
            push(infix[i]);
        }
    }
    while(top != -1){
        postfix[i++] = pop();
    }
    return postfix;
}
int main(){
    char infix[MAX];
    printf("Enter infix expression:");
    scanf("%s",infix);

    char *post = infix_postfix(infix);
    printf("Infix = %s\n",infix);
    printf("Postfix = %s\n",post);

    return 0;
}
