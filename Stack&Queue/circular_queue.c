#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int rear = -1;
int front = -1;
int circular[MAX];

int isFull(){
    //if front = 0 then there exists a value at 0 so can't put there
    int condition1 = (rear == MAX-1) && (front == 0);
    int condition2 = (front == rear+1);

    return condition1 || condition2;
}
int isEmpty(){
    return (front == -1);
}

void enqueue(int item){
    if(isFull()){
        printf("Stack overflow\n");
        return;
    }

    if(isEmpty()){
        front = 0;
    }

    if(rear == MAX-1){
        rear = 0;
    }
    else{
        rear = rear+1; //even works for rear = -1
    }
    circular[rear] = item;
}

int dequeue(){
    if(isEmpty()) return 0;

    //if only one element
    int temp = circular[front];

    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(front == MAX-1){
        front = 0;
    }
    else{
        front = front+1;
    }
    return temp;
}
int peek(){
    if(isEmpty()) return 0;
    return circular[front];
}

void display(){
    if(isEmpty()){
        printf("Emtpy queue\n");
    }

    int i = front;
    while(i!=rear){
        printf("| %d ",circular[i]);
        if(i == MAX-1){
            i = 0;
        }
        ++i;
    }

    printf("| %d\n",circular[i]);
}

int main(){
    enqueue(5);
    enqueue(10);
    dequeue();
    dequeue();
    enqueue(15);
    enqueue(20);
    enqueue(25);
    enqueue(30);
    display();

    int x = dequeue();
    printf("x = %d\n",x);
    display();

    return 0;
}