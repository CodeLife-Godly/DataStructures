
#include <stdio.h>

#define MAX 10

int queue[MAX];
int rear = -1,front = -1;

int isFull(){
    return (rear == MAX-1);
}
int isEmpty(){
    return (front == -1 || front == rear+1);
}

void enqueue(int item){
    if(rear == MAX-1){
        printf("Queue overflow\n");
        return;
    }
    //if queue is empty
    if(isEmpty()){
        front = 0;
        rear = 0;
        queue[rear] = item;
    }
    else{
        rear = rear+1;
        queue[rear] = item;
    }
}

int dequeue(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        return 0;
    }
    //only one element
    if(front == rear){
        int temp = queue[front];
        //reset front and rear
        front = -1;
        rear = -1;
        return temp;
    }
    else{
        int temp = queue[front];
        front = front+1;
        return temp;
    }
}
int peek(){
    if(isEmpty()){
        printf("Underflow\n");
        return 0; 
    }
    return queue[front];
}

void display(){
    if(isEmpty()){
        printf("Underflow\n");
        return;
    }
    printf("Queue elements are:\n");
    for(register int i = front;i<=rear;++i){
        printf("| %d ",queue[i]);
    }
    printf("\n");
}

int main(){
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    int x = dequeue();
    printf("x = %d\n",x);
    display();

    return 0;
}