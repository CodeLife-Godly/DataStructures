#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int value;
  struct Node *next;
}Node;

typedef struct Queue{
  struct Node *rear,*front;
  //remove from front and add to rear
}queue;

Node *createnode(int value){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->value = value;
  temp->next = NULL;;
  
  return temp;
}

void enqueue(queue *q,int value){
  Node *newnode = createnode(value);
  
  if(q->rear == NULL){
    q->rear = q->front = newnode;
    return;
  }
  q->rear->next = newnode;
  q->rear = newnode;
}

int dequeue(queue *q){
  if(q->front == NULL) return -999;
  int t;
  
  if(q->front == q->rear){
    t = q->front->value;
    free(q->front);
    q->front = q->rear = NULL;
    return t;
  }
  
  //free from front
  Node *ptr = q->front;
  q->front = q->front->next;
  t = ptr->value;
  
  free(ptr);
  return t;
}

void display(queue q){
  Node *start = q.front;
  while(start){
    printf("%d->",start->value);
    start = start->next;
  }
  printf("NULL\n");
}

int main(){
  queue q = {NULL,NULL};
  enqueue(&q,10);
  enqueue(&q,20);
  enqueue(&q,5);
  
  display(q);
  int t = dequeue(&q);
  display(q);
  
  t = dequeue(&q);
  display(q);

  return 0;
}
