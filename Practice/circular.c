#include <stdio.h>
#define SIZE 4


int queue[SIZE];
int rear = -1,front = -1;

//circular queue
void enqueue(int value){
  if((rear+1)%SIZE == front){
    //queue is full
    printf("Queue is full\n");
    return;
  }
  rear = (rear+1)%SIZE;
  //front only changes when queue was empty
  if(front == -1) front = 0;
  
  queue[rear] = value;
}

void dequeue(){
  if(front == -1){
    printf("Queue is empty\n");
    return;
  }
  if(front == rear){
    //only one element
    front = rear = -1;
    return;
  }
  front = (front+1)%SIZE;
}

void display(){
  int i=front;
  while(i != rear){
    printf("%d ",queue[i]);
    i = (i+1)%SIZE;
  }
  printf("%d\n",queue[i]);
}

int main(){
  enqueue(20); 
  enqueue(4);
  enqueue(5);
  enqueue(6);
  
  display();
  dequeue();
  enqueue(10);
  display();
  
  return 0;
}

