#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 30

int top = -1;
int stack[MAX];

void push(int item){
    if(top == MAX-1){
        printf("Stack overflow");
        return;
    }
    stack[++top] = item;
}
int pop(){
    if(top == -1){
        return 0;
    }
    return stack[top--];
}
int evaluate(char *exp){
    for(int i=strlen(exp)-1;i>=0;--i){
        if(isdigit(exp[i])){
            push(exp[i]-'0');
        }
        else{
            int operand1 = pop();
            int operand2 = pop();

            switch(exp[i]){
                case '+':push(operand1+operand2); break;
                case '-':push(operand1-operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1/operand2); break;
            }
        }
    }
    return pop();
}

int main(){
    char exp[MAX];

    printf("Enter the expression:");
    scanf("%s",exp);

    int result = evaluate(exp);
    printf("The result of %s is:%d\n",exp,result);

    return 0;
}