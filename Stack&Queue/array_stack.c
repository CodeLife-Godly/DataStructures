#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int item){
    if(top == MAX-1) return 0;
    stack[++top] = item;
}
int pop(){
    if(top == -1){
        printf("Stack underflow\n");
        return 0;
    }
    return stack[--top];
}
void display(){
    for(int i=0;i<=top;++i){
        printf("| %d ",stack[i]);
    }
    printf("\n");
}
int main(){
    push(10);
    push(100);
    push(1000);

    display();

    return 0;
}