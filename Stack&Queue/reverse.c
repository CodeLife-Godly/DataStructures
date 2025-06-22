#include <stdio.h>
#include <string.h>

#define MAX 20

char string[MAX];
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
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}
void display(){
    for(int i=top;i>=0;--i){
        printf("%c",stack[i]);
    }
    printf("\n");
}
int main(){
    printf("Enter the string:");
    fgets(string,MAX,stdin);

    string[strcspn(string,"\n")] = '\0';

    for(int i=0;i<strlen(string);++i){
        push(string[i]);
    }
    
    printf("String in reverse is:\n");

    for(int i=0;i<strlen(string);++i){
        printf("%c",pop());
    }
    printf("\n");
    return 0;
}