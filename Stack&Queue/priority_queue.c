#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node *link;
};

struct Node *front = NULL;

int isEmpty(){
    return (front == NULL);
}

void enqueue(int item, int priority){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = item;
    newnode->priority = priority;

    newnode->link = NULL;

    if(isEmpty() || priority < front->priority){
        newnode->link = front;
        front = newnode;
    }
    else{
        struct Node *p = front;
        while(p->link != NULL && p->link->priority <= priority){
            p = p->link;
        }
        newnode->link = p->link;
        p->link = newnode;
    }
}

int dequeue(){
    if(isEmpty()){
        printf("Queue underflow\n");
        return 0;
    }

    struct Node *p = front;
    int temp = front->data;

    front = front->link;
    free(p);
    return temp;
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
    enqueue(30,2);
    enqueue(60,1);
    enqueue(70,3);
    enqueue(100,0);

    display();
    printf("x = %d\n",dequeue());
    display();
}