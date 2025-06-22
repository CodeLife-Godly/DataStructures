#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int value,priority;
  struct Node *next;
}Node;

Node *createnode(int val,int pr){
  Node *newnode = (Node*)malloc(sizeof(Node));
  
  newnode->value = val;
  newnode->priority = pr;
  newnode->next = NULL;
  
  return newnode;
}

//remove highest priority one first
//first node is highest priority
//front points to highest priority
Node *head = NULL;


void enqueue(int data,int priority){
  Node *temp = createnode(data,priority);
  
  if(head == NULL || priority > head->priority){
    //add at first
    temp->next = head;
    head = temp;
  }
  else{
    Node *ptr = head;
    while(ptr->next && ptr->next->priority >= priority) 
      {
        ptr = ptr->next;
      }
    temp->next = ptr->next;
    ptr->next = temp;
  }
}

void dequeue(){
  if(head == NULL) return;
  Node *temp = head;
  
  head = head->next;
  free(temp);
}

void display(){
  Node *ptr = head;
  while(ptr){
    printf("Data = %d Priority = %d\n",ptr->value,ptr->priority);
    ptr = ptr->next;
  }
}

int main(){
    enqueue(10, 2);
    enqueue(20, 4);
    enqueue(30, 1);
    enqueue(40, 3);

    printf("Priority Queue:\n");
    display();
    
    dequeue();
    
    printf("Priority Queue:\n");
    display();
    
    return 0;
}

