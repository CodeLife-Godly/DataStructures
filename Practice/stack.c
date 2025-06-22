#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int value;
  struct Node *next;
}Node;

typedef struct Stack{
  struct Node *head;
  struct Node *top;
}stack;

Node *createnode(int value){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->value = value;
  temp->next = NULL;;
  
  return temp;
}

void push(stack *s,int value){
  Node *newnode = createnode(value);
  
  if(s->top == NULL){
    s->top = newnode;
    s->head = newnode;
    return;
  }
  s->top->next = newnode;
  s->top = newnode;
}

int pop(stack *s){
  Node *temp = s->head;
  if(temp == s->top){
    int res = temp->value;
    s->top = s->head = NULL;
    return res;
  }
  
  while(temp->next != s->top){
    temp = temp->next;
  }
  int res = s->top->value;
  free(s->top);
  temp->next = NULL;
  s->top = temp;
  
  return res;
}

void display(stack s){
  Node *start = s.head;
  while(start){
    printf("%d->",start->value);
    start = start->next;
  }
  printf("NULL\n");
}

int main(){
  stack s = {NULL,NULL};
  push(&s,10);
  push(&s,20);
  push(&s,1);
  push(&s,5);
  
  display(s);
  int t = pop(&s);
  display(s);
  
  t = pop(&s);
  display(s);
  return 0;
}



