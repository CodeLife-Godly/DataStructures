#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

int isEmpty(){
    return (top == -1);
}
int isFull(){
    return (top == MAX-1);
}

void push(int item){
    if(isFull()){
        printf("Stack overflow\n");
    }
    else{
        stack[++top] = item;
    }
}

int pop(){
    if(isEmpty()){
        printf("Stack underflow\n");
        return 0;
    }
    else{
        return stack[top--];
    }
}

int peek(){
    if(isEmpty()){
        printf("Emtpy stack\n");
        return 0;
    }
    return stack[top];
}

void display(){
    for(int i=0;i<=top;++i){
        printf("| %d ",stack[i]);
    }
    printf("\n");
}

int main(){
    push(20);
    push(40);
    push(10);
    push(90);

    display();
    int y = pop();
    display();
    printf("peek = %d",peek());
    return 0;
}