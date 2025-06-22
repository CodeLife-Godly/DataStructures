#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

//infix to postfix

char operator[MAX];
int top = -1;

void push(char item){
    if(top == MAX-1){
        printf("Overflow\n");
        return;
    }
    operator[++top] = item;
}

char pop(){
    if(top == -1){
        printf("Underflow\n");
        return '\0';
    }
    return operator[top--];
}

int precedence(char op){
    if(op == '+' || op == '-'){
        return 1;
    }
    else if(op == '*' || op == '/'){
        return 2;
    }
    else if(op == '^'){
        return 3;
    }
    return 0;
} 

int is_operator(char op){
    if(op == '+'  || op == '-' || op == '*' || op == '/' || op == '^'){
        return 1;
    }
    return 0;
}

int main(){
    printf("Enter the expression:");
    char *expr = (char*)malloc(sizeof(char)*MAX);
    fgets(expr,MAX,stdin);
    expr[strcspn(expr,"\n")] = '\0';

    for(int i = 0;i<strlen(expr);++i){
        if(isspace(expr[i])) continue;

        if(isdigit(expr[i])){
            //for multidigit numbers
            int num = 0;

            while(isdigit(expr[i])){
                num = num*10 + (expr[i]-'0');
                ++i;
            }
            --i;
            //push(num+'0',postfix,&top_postfix);
            printf("%d ",num);
        }
        else if(expr[i] == '('){
            push(expr[i]);
        }
        else if(expr[i] == ')'){
            while(operator[top] != '('){
                printf("%c ",pop());
            }
            pop();
        }
        else if(is_operator(expr[i])){
            while(top != -1 && precedence(operator[top]) >= precedence(expr[i])){
                printf("%c ",pop());
            }
            push(expr[i]);
        }
    }
    while(top != -1){
        printf("%c ",pop());
    }
    free(expr);
    return 0;
}

