#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

int stack[MAX];
int top = -1;

void push(int item){
    if(top == MAX-1){
        printf("Overflow\n");
        return;
    }
    stack[++top] = item;
}   

int pop(){
    if(top == -1){
        printf("Underflow");
        return -1;
    }
    return stack[top--];
}

int main(){
    printf("Enter the expression:");
    char *str = (char*)malloc(sizeof(char)*MAX);
    fgets(str,MAX,stdin);
    str[strcspn(str,"\n")] = '\0';
    //strcat(str,")"); 

    for(int i = 0;i<strlen(str);++i){
        if(isdigit(str[i])){
            //pushing the digit as integer
            push(str[i]-'0');
        }
        else{
            int right = pop();
            int left = pop();
            int result;
            switch(str[i]){
                case '+': result = left+right; break;
                case '-': result = left-right; break;
                case '*': result = left*right; break;
                case '/': result = left/right; break;
                default:
                    printf("Invalid operator\n");
                    return 0;
            }
            push(result);
        }
    }
    printf("The result is :%d\n",pop());
    return 0;       
}