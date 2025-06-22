#include <stdio.h>
#define MAX 5

int circular_queue[MAX];
int front = -1,rear = -1;

void enqueue(int item){
    if(front == (rear+1)%MAX){
        printf("Overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    }
    else{
        rear = (rear+1)%MAX;
    }
    circular_queue[rear] = item;
}

int dequeue(){
    if(front == -1){
        printf("Underflow\n");
        return -999;
    }
    int item = circular_queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%MAX;
    }
    return item;
}