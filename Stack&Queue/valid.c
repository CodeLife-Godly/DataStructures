#include <stdio.h>
#include <string.h>
#define MAX 30

char stack[MAX];
int top = -1;

void push(char item){
    if(top == MAX-1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop(){
    if(top == -1){
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

int match(char a,char b){
    if(a == '{' && b == '}'){
        return 1;
    }
    else if(a == '[' && b == ']'){
        return 1;
    }
    else if(a == '(' && b == ')'){
        return 1;
    }
    return 0;
}
int check(char exp[]){
    for(int i=0;i<strlen(exp);++i){
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
            push(exp[i]);
        }
        if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']'){
            if(top == -1){
                return 0;
            }
            char item = pop();
            if(match(item,exp[i]) == 0){
                return 0;
            }
        }
    }
    return (top == -1);   //if stack is empty then 1 or else 0
}

int main(){
    int valid;
    printf("Enter the string:");
    char exp[MAX];

    scanf("%s",&exp);

    if(check(exp) == 1){
        printf("Valid expression");
    }
    else{
        printf("Invalid\n");
    }
    return 0;
}