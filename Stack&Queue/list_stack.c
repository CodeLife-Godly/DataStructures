#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};
struct Node *top = NULL;

int isEmpty(){
    return (top == NULL);
}

void enqueue(int item){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = item;
    newnode->link = NULL;

    if(isEmpty()){
        top = newnode;
        return;
    }
    //top points to first node and add here
    newnode->link = top;
    top = newnode;
}
int pop(){
    if(isEmpty()){
        printf("Stack underflow\n");
        return 0;
    }
    int temp = top->data;
    struct Node *p = top;
    top = top->link;

    free(p);
    return temp;
}

void display(){
    if(isEmpty()){
        printf("Empty stack\n");
        return;
    }
    struct Node *p = top;
    while(p!=NULL){
        printf("| %d ",p->data);
        p = p->link;
    }
    printf("\n");
}
int main(){
    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();
    int x = pop();
    printf("x = %d\n",x);
    display();

    return 0;
}
