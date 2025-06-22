#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 30

//if operator then if precedence(stack[top]) > precedence(expr[i]) then pop until this and push(expr[i])
//infix to prefix

char stack[MAX];
char prefix[MAX];
int top_pre = -1;
int top = -1;

void push(char *stack,char item,int *top){
    if(*top == MAX-1){
        printf("Overflow\n");
        return;
    }
    stack[++(*top)] = item;
}

char pop(char *stack,int *top){
    if(*top == -1){
        printf("Underflow\n");
        return '\0';
    }
    return stack[(*top)--];
}

int precedence(char op){
    if(op == '+' || op == '-') return 1;
    else if(op == '*' || op == '/') return 2;
    else if(op == '^') return 3;
    return 0;
}

void reverse(char *expr){
    //changing the brackets
    for(int i = 0;i<strlen(expr);++i){
        if(expr[i] == '(') expr[i] = ')';
        else if(expr[i] == ')') expr[i] = '(';
    }
    //now reversing
    int high = strlen(expr)-1;
    int low = 0;

    while(low < high){
        char temp = expr[low];
        expr[low] = expr[high];
        expr[high] = temp;

        ++low;
        --high;
    }
}

int is_operator(char op){
    if(op == '+'  || op == '-' || op == '*' || op == '/' || op == '^'){
        return 1;
    }
    return 0;
}

int main(){
    printf("Infix:");
    char *expr = (char*)malloc(sizeof(char)*MAX);
    fgets(expr,MAX,stdin);

    expr[strcspn(expr,"\n")] = '\0';

    reverse(expr);
    //now to postfix
    for(int i = 0;i<strlen(expr);++i){
        if(isspace(expr[i])) continue;
        
        if(isalpha(expr[i])){
            push(prefix,expr[i],&top_pre);
        }
        else if(expr[i] == '('){
            push(stack,expr[i],&top);
        }
        else if(expr[i] == ')'){
            char op;
            while((op = pop(stack,&top)) != '('){
                push(prefix,op,&top_pre);
            }
        }
        else if(is_operator(expr[i])){
            while(precedence(stack[top]) >= precedence(expr[i])){
                char temp = pop(stack,&top);
                push(prefix,temp,&top_pre);
            }
            push(stack,expr[i],&top);
        }
    }
    while(top != -1){
        push(prefix,pop(stack,&top),&top_pre);
    }
    //now pop prefix to get the prefix expression
    printf("Prefix:");
    while(top_pre != -1){
        printf("%c",pop(prefix,&top_pre));
    }
    printf("\n");
    return 0;
}