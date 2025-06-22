#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

char stack[MAX];
int top = -1;

void push(int item){
    if(top == MAX-1){
        printf("Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop(){
    if(top == -1){
        printf("Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int main(){
    printf("Enter the string:");
    char *str = (char*)malloc(sizeof(char)*MAX);
    fgets(str,MAX,stdin);
    str[strcspn(str,"\n")] = '\0';

    for(int i = 0;i<strlen(str);++i){
        push(str[i]);
    }
    printf("String in reverse:");
    while(top != -1){
        printf("%c",pop());
    }
    printf("\n");
    free(str);
    return 0;
}