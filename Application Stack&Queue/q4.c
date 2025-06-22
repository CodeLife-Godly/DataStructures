#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

int operand[MAX];
char operator[MAX];
int top_operator = -1;
int top_operand = -1;

void pushInt(int item){
    if(top_operand == MAX-1){
        printf("Overflow\n");
        return;
    }
    operand[++top_operand] = item;
}

int pop_int(){
    if(top_operand == -1){
        printf("Underflow\n");
        return -1;
    }
    return operand[top_operand--];
}

void pushChar(char item){
    if(top_operator == MAX-1){
        printf("Overflow\n");
        return;
    }
    operator[++top_operator] = item;
}

char pop_Char(){
    if(top_operator == -1){
        printf("Underflow\n");
        return '\0';
    }
    return operator[top_operator--];
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

int exponential(int base,int power){
    int temp = 1;
    while(power > 0){
        --power;
        temp = temp*base;
    }
    return temp;
}

int is_operator(char op){
    if(op == '+' || op == '-' || op == '/' || op == '*' || op == '^'){
        return 1;
    }
    return 0;
}

int evaluate(int left,int right,char op){
    int result;
    switch(op){
        case '+': result = left+right; break;
        case '-': result = left-right; break;
        case '*': result = left*right; break;
        case '/': 
            if(right == 0){
                printf("Error in division by 0\n");
                return -1;
            }
            result = left/right; 
            break;
        case '^': result = exponential(left,right); break;
        default:
            printf("Invalid operator\n");
            return 0;
    }
    return result;
}

int main(){
    printf("Enter the expression:");
    char *expression = (char*)malloc(sizeof(char)*MAX);
    fgets(expression,MAX,stdin);
    expression[strcspn(expression,"\n")] = '\0'; //replace newline with null operator

    //scan from left to right
    for(int i = 0;i<strlen(expression);++i){
        if(isspace(expression[i])) continue;

        if(isdigit(expression[i])){
            //parsing whole number
            int num = 0;
            while(isdigit(expression[i])){
                num = num*10 + (expression[i]-'0');
                ++i;
            }
            --i; //as loop will be incremented so reducing by one
            pushInt(num);
        }
        else if(expression[i] == '('){
            pushChar(expression[i]);
        }
        //important
        else if(is_operator(expression[i])){
            while((precedence(operator[top_operator]) >= precedence(expression[i])) && operator[top_operator] != '('){
                int right = pop_int();
                int left = pop_int();
                char op = pop_Char();

                //evaluate higher precedence operator first
                pushInt(evaluate(left,right,op));
            }
            //now push higher precedence from expression onto the stack
            pushChar(expression[i]);
        }
        else if(expression[i] == ')'){
            while(operator[top_operator] != '('){
                int right = pop_int(); 
                int left = pop_int();
                char op = pop_Char();
        
                pushInt(evaluate(left,right,op));
            }
            pop_Char();
        }
    }
    while(top_operator != -1){
        int right = pop_int();
        int left = pop_int();
        char op = pop_Char();

        pushInt(evaluate(left,right,op));
    }
    printf("The result of expression is:%d\n",pop_int());  
    free(expression);
    return 0;
}