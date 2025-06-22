#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};
struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty(){
    return (front == NULL);
}

void enqueue(int item){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));

    if(newnode == NULL){
        printf("Memory not available\n");
        return;
    }
    newnode->data = item;
    newnode->link = NULL;

    if(isEmpty()){
        front = newnode;
        rear = newnode;
    }
    else{
        rear->link = newnode;
        rear = newnode;
    }
}

int dequeue(){
    if(isEmpty()){
        printf("Stack underflow\n");
        return 0;
    }

    //only one element
    if(front->link == NULL){
        int temp = front->data;
        free(front);

        front = NULL;
        rear = NULL;

        return temp;
    }
    //otherwise
    else{
        struct Node *temp = front;

        int value = front->data;
        front = front->link;
        free(temp);

        return value;
    }   
}

void display(){
    if(isEmpty()){
        printf("Empty queue\n");
        return;
    }
    struct Node *p = front;
    while(p!=NULL){
        printf("| %d ",p->data);
        p = p->link;
    }
    printf("\n");
}

int main(){
    enqueue(50);
    enqueue(60);
    enqueue(70);
    display();
    
    int x = dequeue();
    printf("x = %d\n",x);
    
    display();
    return 0;
}
