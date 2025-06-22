#include <stdio.h>

#define MAX 7
int stack[MAX],top = -1;

void push(int item){
    if(top == 6){
        printf("Overflow,can't store more than 7 elements\n");
        return;
    }
    ++top;
    stack[top] = item;
} 

int pop(){
     if(top == -1){
        printf("Underflow\n");
        return -999;
    }
    return stack[top--];
}

void display(){
    if(top == -1){
        printf("Empty stack\n");
        return;
    }
    for(int i=0;i<=top;++i){
        printf("%d ",stack[i]);
    }
    printf("\n");
    printf("Index of top:%d\n",top);
}
int main(){
    push(9);
    push(9);
    push(3);
    push(0);

    display();
    push(5);
    push(7);
    display();
    
    pop();
    pop();
    pop();

    display();
    return 0;
}