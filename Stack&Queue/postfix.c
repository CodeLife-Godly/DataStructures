#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 30
int stack[MAX];
int top = -1;

void push(int item){
    if(top == MAX-1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}
int pop(){
    if(top == -1){
        printf("Stack underflow\n");
        return 0;
    }
    return stack[top--];
}
int evaluate(char *exp){
    for(int i=0;i<strlen(exp);++i){
        if(isdigit(exp[i])){
            push(exp[i]-'0');    
        }
        else{
            char operand2 = pop();
            char operand1 = pop();
            switch(exp[i]){
                case '+': push(operand1+operand2); break;
                case '-': push(operand1-operand2);  break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1/operand2); break;
            }
        }

    }
    return pop();
}
int main(){
    printf("Enter the string:");
    char exp[MAX];
    scanf("%s",exp);

    int result = evaluate(exp);
    printf("The result of %s is:%d\n",exp,result);
    return 0;
}
